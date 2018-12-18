/*
 *
 *
 * Copyright  1990-2007 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 */

/**
 * @file
 * Implementation of the porting layer for generic fb application
 */

#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <sys/ipc.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <execinfo.h>
#include <signal.h>
#include <ucontext.h>

#include <gxj_putpixel.h>
#include <gxj_screen_buffer.h>
#include <midp_logging.h>
#include <midpMalloc.h>
#include <midp_constants_data.h>

#include <pthread.h>

#include <fbapp_device_type.h>
#include <fbapp_export.h>
#include "fb_port.h"

#include <keymap_input.h>

#include <dlfcn.h>
#include <execinfo.h>

#include <jni.h>

#include "portlibs/ansi_c/java.h"
#include "javavm/export/jni.h"

/**
 * By default use fast copying of rotated pixel data.
 * The assumptions required by fast copying implementation are supposed.
 */
#ifndef ENABLE_FAST_COPY_ROTATED
#define ENABLE_FAST_COPY_ROTATED    1
#endif

#define MOUSE_FD "/tmp/mouse_fd"
#define KEYBOARD_FD "/tmp/keyboard_fd"

static int keyboardFd = -1;
static int mouseFd = -1;

typedef void repaint_func(void *);
static repaint_func *repaintPixmap;

static int surface_width = 800;
static int surface_height = 480;

typedef void exit_func(int);
static exit_func *exitWrapper = NULL;

static int stop_repainting = 0;

typedef int invokeplatform_func(char **, int, char **);
static invokeplatform_func *invoke_platform = NULL;

/** System offscreen buffer */
gxj_screen_buffer gxj_system_screen_buffer;

/** Return file descriptor of keyboard device, or -1 in none */
int getKeyboardFd() {
    return keyboardFd;
}
/** Return file descriptor of mouse device, or -1 in none */
int getMouseFd() {
    return mouseFd;
}

/** Allocate system screen buffer according to the screen geometry */
void initScreenBuffer(int width, int height) {
    if (gxj_init_screen_buffer(width, height) != ALL_OK) {
        fprintf(stderr, "Failed to allocate screen buffer\n");
        exit(1);
    }

    midpFree(gxj_system_screen_buffer.pixelData);
    gxj_system_screen_buffer.pixelData = (gxj_pixel_type *)midpMalloc(sizeof(gxj_pixel_type) * 854 * 480); // This is a quick hack to deal with full-screen windows
}

void initKeyboard() {
    char buff[255];

    sprintf(buff, "%s.%d", KEYBOARD_FD, getpid());
    mkfifo(buff, 0777);
    if ((keyboardFd = open(buff, O_RDONLY | O_NONBLOCK, 0)) < 0) {
        fprintf(stderr, "ERROR: Open of %s failed\n", buff);
        exit(1);
    }
}

void initMouse() {
    char buff[255];

    sprintf(buff, "%s.%d", MOUSE_FD, getpid());
    mkfifo(buff, 0777);
    if ((mouseFd = open(buff, O_RDONLY | O_NONBLOCK, 0)) < 0) {
        fprintf(stderr, "ERROR: Open of %s failed\n", buff);
        exit(1);
    }
}

static void cleanup() {
    char buff[255];

    sprintf(buff, "%s.%d", KEYBOARD_FD, getpid());
    remove(buff);

    sprintf(buff, "%s.%d", MOUSE_FD, getpid());
    remove(buff);
}

void finalizeFrameBuffer();

void __wrap_exit(int status) {
    cleanup();

    if (exitWrapper)
        (*exitWrapper)(status);

    // Exit process through Maemo instead!
    /// __real_exit(status);
}

void exithandler(int sig) {
    signal(sig, SIG_IGN);
    /// finalizeFrameBuffer();
    exit(0);
}

void initExit(exit_func *e) {
    exitWrapper = e;
}

int getScreenWidth() {
    return surface_width;
}

int getScreenHeight() {
    return surface_height;
}

void initPixmap(int w, int h, repaint_func *f) {
    surface_width = w;
    surface_height = h;
    repaintPixmap = f;
}

void repaint() {
    if (stop_repainting)
        return;

    (*repaintPixmap)(gxj_system_screen_buffer.pixelData);
}

/** Inits frame buffer device */
void initFrameBuffer() {
    fb.depth = 16;
    fb.lstep = gxj_system_screen_buffer.width * 4;
    fb.xoff  = 0;
    fb.yoff  = 0;
    fb.width = gxj_system_screen_buffer.width;
    fb.height= gxj_system_screen_buffer.height;
    fb.data  = gxj_system_screen_buffer.pixelData;
}

/**
 * Change screen orientation to landscape or portrait,
 * depending on the current screen mode
 */
void reverseScreenOrientation() {
    // Whether current Displayable won't repaint the entire screen on
    // resize event, the artefacts from the old screen content can appear.
    // That's why the buffer content is not preserved.
    gxj_rotate_screen_buffer(KNI_FALSE);
}

/** Initialize frame buffer video device */
void connectFrameBuffer() {
    initFrameBuffer();
    initKeyboard();
    initMouse();
}

/** Clear screen content */
void clearScreen() {
    int n;

    gxj_pixel_type *p = (gxj_pixel_type *)gxj_system_screen_buffer.pixelData;
    gxj_pixel_type color = (gxj_pixel_type)GXJ_RGB2PIXEL(0xa0, 0xa0, 0x80);
    for (n = fb.width * fb.height; n > 0; n--) {
        *p ++ = color;
    }
    repaint();
}

/**
 * Resizes system screen buffer to fit new screen geometry
 * and set system screen dimensions accordingly.
 * Call after frame buffer is initialized.
 */
void resizeScreenBuffer(int width, int height) {
    gxj_system_screen_buffer.width = width;
    gxj_system_screen_buffer.height = height;
}

/** Check if screen buffer is not bigger than frame buffer device */
static void checkScreenBufferSize(int width, int height) {
    // Check if frame buffer is big enough
    if (fb.width < width || fb.height < height) {
        fprintf(stderr, "Device screen too small. Need %dx%d\n", width, height);
        exit(1);
    }
}

/** Get x-coordinate of screen origin */
int getScreenX(int screenRotated) {
    // System screen buffer geometry
    int bufWidth = gxj_system_screen_buffer.width;
    int x = 0;
    int LCDwidth = screenRotated ? fb.height : fb.width;
    if (LCDwidth > bufWidth) {
        x = (LCDwidth - bufWidth) / 2;
    }
    return x;
}

/** Get y-coordinate of screen origin */
int getScreenY(int screenRotated) {
    int bufHeight = gxj_system_screen_buffer.height;
    int y = 0;
    int LCDheight = screenRotated ? fb.width : fb.height;
    if (LCDheight > bufHeight) {
        y = (LCDheight - bufHeight) / 2;
    }
    return y;
}

/** Refresh screen from offscreen buffer */
void refreshScreenNormal(int x1, int y1, int x2, int y2) {
    repaint();
}

void refreshScreenRotated(int x1, int y1, int x2, int y2) {
    repaint();
}

void resizeFrameBuffer(int width, int height) {
    surface_width = width;
    surface_height = height;

    resizeScreenBuffer(width, height);

    fb.width = gxj_system_screen_buffer.width;
    fb.height= gxj_system_screen_buffer.height;
}

/** Frees allocated resources and restore system state */
void finalizeFrameBuffer() {
    stop_repainting = 1;

    gxj_free_screen_buffer();

    if (mouseFd > 0) {
        close(mouseFd);
        mouseFd = -1;
    }
    if (keyboardFd > 0) {
        close(keyboardFd);
        keyboardFd = -1;
    }

    cleanup();
}

void initPlatform(invokeplatform_func *f) {
    invoke_platform = f;
}

JNIEXPORT jobjectArray JNICALL invokePlatform(JNIEnv *env, jclass clazz, jobjectArray params) {
    char* invocation[16];
    char* result[16];
    int i;
    int count;
    jobjectArray ret;

    for (i=0; i<16; i++) {
        invocation[i] = malloc(256);
        strcpy(invocation[i], "");
    }
    for (i=0; i<16; i++) {
        result[i] = malloc(256);
        strcpy(result[i], "");
    }

    count = (*env)->GetArrayLength(env, params);
    for (i=0; i<count; i++) {
        jstring jstr = (*env)->GetObjectArrayElement(env, params, i);
        const char *str = (*env)->GetStringUTFChars(env, jstr, 0);
        strcpy(invocation[i], str);
        (*env)->ReleaseStringUTFChars(env, jstr, str);
    }

    if (invoke_platform) {
        count = (*invoke_platform)(invocation, count, result);
    } else {
        count = 0;
    }

    ret = (jobjectArray)(*env)->NewObjectArray(env, count, (*env)->FindClass(env, "java/lang/String"), (*env)->NewStringUTF(env, ""));
    for (i=0; i<count; i++) {
        (*env)->SetObjectArrayElement(env, ret, i, (*env)->NewStringUTF(env, result[i]));
    }

    for (i=0; i<16; i++) {
        free(invocation[i]);
    }
    for (i=0; i<16; i++) {
        free(result[i]);
    }

    return ret;
}

int cvm_main(int argc, char **argv) {
    return ansiJavaMain(argc, (const char **)argv, JNI_CreateJavaVM);
}
