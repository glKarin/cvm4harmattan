/*
 * Copyright  1990-2008 Sun Microsystems, Inc. All Rights Reserved.
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

/*
 * NOTICE: Portions Copyright (c) 2007-2009 Davy Preuveneers.
 * This file has been modified by Davy Preuveneers on 2009/01/11. The
 * changes are licensed under the terms of the GNU General Public
 * License version 2. This notice was added to meet the conditions of
 * Section 3.a of the GNU General Public License version 2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <jni.h>

static jboolean valid = 0;
static jdouble latitude = 0;
static jdouble longitude = 0;
static jfloat altitude = 0;
static jfloat speed = 0;
static jfloat bearing = 0;
static jfloat accuracy = 0;

typedef void initgps_func(jboolean *, jdouble *, jdouble *, jfloat *, jfloat *, jfloat *, jfloat *);
static initgps_func *initgps = NULL;

typedef void finishgps_func();
static finishgps_func *finishgps = NULL;

void initGPS(initgps_func *init, finishgps_func *finish) {
    initgps = init;
    finishgps = finish;
}

JNIEXPORT void JNICALL Java_com_openlapi_LocationProviderMaemo_initGpsProvider(JNIEnv *env, jclass clazz) {
    if (initgps)
        (*initgps)(&valid, &latitude, &longitude, &altitude, &speed, &bearing, &accuracy);
}

JNIEXPORT void JNICALL Java_com_openlapi_LocationProviderMaemo_finishGpsProvider(JNIEnv *env, jclass clazz) {
    if (finishgps)
        (*finishgps)();
}

JNIEXPORT jboolean JNICALL Java_com_openlapi_LocationProviderMaemo_isValid(JNIEnv *env, jclass clazz) {
    return valid;
}

JNIEXPORT jdouble JNICALL Java_com_openlapi_LocationProviderMaemo_getLatitude(JNIEnv *env, jclass clazz) {
    return latitude;
}

JNIEXPORT jdouble JNICALL Java_com_openlapi_LocationProviderMaemo_getLongitude(JNIEnv *env, jclass clazz) {
    return longitude;
}

JNIEXPORT jfloat JNICALL Java_com_openlapi_LocationProviderMaemo_getAltitude(JNIEnv *env, jclass clazz) {
    return altitude;
}

JNIEXPORT jfloat JNICALL Java_com_openlapi_LocationProviderMaemo_getSpeed(JNIEnv *env, jclass clazz) {
    return speed;
}

JNIEXPORT jfloat JNICALL Java_com_openlapi_LocationProviderMaemo_getBearing(JNIEnv *env, jclass clazz) {
    return bearing;
}

JNIEXPORT jfloat JNICALL Java_com_openlapi_LocationProviderMaemo_getAccuracy(JNIEnv *env, jclass clazz) {
    return accuracy;
}
