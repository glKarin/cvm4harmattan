/*
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

/* This file is auto-generated. Do not edit*/

#ifndef _ROM_STRUCTS_H_
#define _ROM_STRUCTS_H_

#define int32_t int

#define CVM_OBJ_HEADER void* dummy1; void* dummy2

typedef struct {
    CVM_OBJ_HEADER;
    int length;
    jbyte elements[1];
} jbyte_array;

typedef struct {
    CVM_OBJ_HEADER;
    int length;
    jchar elements[1];
} jchar_array;

typedef struct {
    CVM_OBJ_HEADER;
    int length;
    jint elements[1];
} jint_array;

typedef struct {
    CVM_OBJ_HEADER;
    int length;
    jint elements[1];
} jobject_array;

struct Java_javax_microedition_lcdui_Graphics {
    CVM_OBJ_HEADER;
    int32_t clipX1;
    int32_t clipY1;
    int32_t clipX2;
    int32_t clipY2;
    int32_t transX;
    int32_t transY;
    int32_t systemClipX1;
    int32_t systemClipY1;
    int32_t systemClipX2;
    int32_t systemClipY2;
    int32_t ax;
    int32_t ay;
    /*boolean*/ int32_t clipped;
    int32_t rgbColor;
    int32_t gray;
    int32_t pixel;
    int32_t style;
    struct Java_javax_microedition_lcdui_Font *currentFont;
    int32_t maxWidth;
    int32_t maxHeight;
    /*boolean*/ int32_t runtimeClipEnforce;
    int32_t displayId;
    struct Java_javax_microedition_lcdui_Image *img;
    struct Hjava_lang_Object *creator;
};

struct Java_javax_microedition_lcdui_Image {
    CVM_OBJ_HEADER;
    int32_t width;
    int32_t height;
    struct Java_javax_microedition_lcdui_ImageData *imageData;
};

struct Java_javax_microedition_lcdui_ImageData {
    CVM_OBJ_HEADER;
    int32_t width;
    int32_t height;
    /*boolean*/ int32_t isMutable;
    jbyte_array *pixelData;
    jbyte_array *alphaData;
    int32_t nativePixelData;
    int32_t nativeAlphaData;
};

struct Java_javax_microedition_lcdui_Font {
    CVM_OBJ_HEADER;
    int32_t face;
    int32_t style;
    int32_t sizeRounded;
    int32_t size;
    int32_t baseline;
    int32_t height;
/* Inaccessible static: DEFAULT_FONT */
/* Inaccessible static: table */
};

struct Java_java_lang_String {
    CVM_OBJ_HEADER;
    jchar_array *value;
    int32_t offset;
    int32_t count;
/* Inaccessible static: serialPersistentFields */
/* Inaccessible static: CASE_INSENSITIVE_ORDER */
};

struct Java_com_sun_midp_rms_RecordStoreFile {
    CVM_OBJ_HEADER;
    int32_t handle;
};

struct Java_com_sun_midp_chameleon_input_NativeInputMode {
    CVM_OBJ_HEADER;
    int32_t STATE_CALLBACK_RES;
    int32_t STATE_FUNC_TOKEN;
    int32_t STATE_NEXT_STATE;
    int32_t STATE_INT_ARG;
    int32_t STATE_FINAL_RES;
    int32_t STATE_INTERNAL;
    int32_t STATE_INTERNAL_EXT;
    int32_t STATE_DATA_ARRAY_SIZE;
    int32_t MEDIATOR_NOOP;
    int32_t MEDIATOR_COMMIT;
    int32_t MEDIATOR_CLEAR;
    int32_t MEDIATOR_SUBINPUTMODECHANGED;
    int32_t MEDIATOR_INPUTMODECOMPLETED;
    int32_t MEDIATOR_ISCLEARKEY;
    int32_t MEDIATOR_GETAVAILABLESIZE;
    int32_t id;
    int32_t instanceData;
    struct Hcom_sun_midp_chameleon_input_InputModeMediator *mediator;
    struct HArrayOfArray *isMap;
};

struct Java_com_sun_midp_io_j2me_storage_RandomAccessStream {
    CVM_OBJ_HEADER;
    /*boolean*/ int32_t connectionOpen;
    int32_t iStreams;
    int32_t maxIStreams;
    int32_t oStreams;
    int32_t maxOStreams;
    int32_t handle;
};

struct Java_javax_microedition_lcdui_game_GameCanvas {
    CVM_OBJ_HEADER;
    struct HArrayOfObject *commands;
    int32_t numCommands;
    struct Java_javax_microedition_lcdui_CommandListener *listener;
    /*boolean*/ int32_t isInFullScreenMode;
    int32_t lastSetMode;
    /*boolean*/ int32_t isRotated;
    struct Hjava_lang_String *title;
    struct Java_javax_microedition_lcdui_Ticker *ticker;
    struct Java_javax_microedition_lcdui_DisplayableLF *displayableLF;
    /*boolean*/ int32_t suppressKeyEvents;
    struct Java_javax_microedition_lcdui_CanvasLF *canvasLF;
    struct Hcom_sun_midp_lcdui_GameCanvasLFImpl *gameCanvasLF;
/* Inaccessible static: gameAccess */
};

#endif /* _ROM_STRUCTS_H_ */
