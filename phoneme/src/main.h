/*
 * Copyright  2012 Davy Preuveneers. All Rights Reserved.
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
 */

#ifndef ANSI_MAIN_H
#define ANSI_MAIN_H

extern "C" {

    typedef unsigned char   jboolean;
    typedef unsigned short  jchar;
    typedef short           jshort;
    typedef float           jfloat;
    typedef double          jdouble;
    typedef int             jint;
    typedef jint            jsize;
    typedef long long       jlong;

    typedef void repaint_func(void *);

    typedef int drawchars_func(int, const jshort *, void *, int, int, int, int, int, int, int, const jchar *, int);
    typedef int getfontinfo_func(int, int, int, int *, int *, int *);
    typedef int getcharswidth_func(int, int, int, const jchar *, int);

    typedef int invokeplatform_func(char **, int, char **);

    void initPixmap(int w, int h, repaint_func *f);
    void resizeFrameBuffer(int width, int height);
    void finalizeFrameBuffer();

    typedef void initgps_func(jboolean *, jdouble *, jdouble *, jfloat *, jfloat *, jfloat *, jfloat *);
    typedef void finishgps_func();
    void initGPS(initgps_func *init, finishgps_func *finish);

    void initPlatform(invokeplatform_func *f);
    void initDrawChars(drawchars_func *draw, getfontinfo_func *info, getcharswidth_func *width);

    int cvm_main(int argc, char *argv[]);

}

#endif
