/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/

#include "javax_microedition_m3g_VertexBuffer.h"

JNIEXPORT void JNICALL Java_javax_microedition_m3g_VertexBuffer__1setTexCoords
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jint aTexUnit, jlong aHArray, jfloat aScale, jfloatArray aSrcArray)
{
    int biasLength = 0;
    float *bias = NULL;
	printf("C99 setTextCoords -> %ld - %ld\n", aHBuffer, aHArray);
    if (aSrcArray && 0)
    {
        bias = (float *)(*aEnv)->GetFloatArrayElements(aEnv, aSrcArray, NULL);
        if (bias == NULL)
        {
            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return;
        }
    }

    biasLength = 0; //aSrcArray ? (*aEnv)->GetArrayLength(aEnv, aSrcArray) : 0;

    M3G_DO_LOCK
    m3gSetTexCoordArray((M3GVertexBuffer)aHBuffer, aTexUnit, (M3GVertexArray)aHArray, aScale, bias, biasLength);
    M3G_DO_UNLOCK(aEnv)

    if (aSrcArray)
    {
        (*aEnv)->ReleaseFloatArrayElements(aEnv, aSrcArray, bias, JNI_ABORT);
    }
}

JNIEXPORT jlong JNICALL Java_javax_microedition_m3g_VertexBuffer__1getArray
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jint aWhich, jfloatArray aDstArray)
{
    int dstLength = 0;
    float *dstData = NULL;
    if (aDstArray)
    {
        dstData = (float *)(*aEnv)->GetFloatArrayElements(aEnv, aDstArray, NULL);
        if (dstData == NULL)
        {
            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return 0;
        }
    }

    dstLength = aDstArray ? (*aEnv)->GetArrayLength(aEnv, aDstArray) : 0;

    M3G_DO_LOCK
    jlong ret = (jlong)m3gGetVertexArray((M3GVertexBuffer)aHBuffer, aWhich, dstData, dstLength);
    M3G_DO_UNLOCK(aEnv)

    if (aDstArray)
    {
        (*aEnv)->ReleaseFloatArrayElements(aEnv, aDstArray, dstData, 0);
    }

    return ret;
}

JNIEXPORT jint JNICALL Java_javax_microedition_m3g_VertexBuffer__1getDefaultColor
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer)
{
    M3G_DO_LOCK
    jint color = (M3Guint)m3gGetVertexDefaultColor((M3GVertexBuffer)aHBuffer);
    M3G_DO_UNLOCK(aEnv)
    return color;
}

JNIEXPORT jlong JNICALL Java_javax_microedition_m3g_VertexBuffer__1ctor
(JNIEnv* aEnv, jclass _unused, jlong aM3g)
{
    M3G_DO_LOCK
    M3GVertexBuffer vb = m3gCreateVertexBuffer((M3GInterface)aM3g);
	printf("=========contruct VertexBuffer: -> %ld\n", vb);
    M3G_DO_UNLOCK(aEnv)
    return (jlong) vb;
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_VertexBuffer__1setNormals
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jlong aHArray)
{
    M3G_DO_LOCK
    m3gSetNormalArray((M3GVertexBuffer) aHBuffer, (M3GVertexArray) aHArray);
    M3G_DO_UNLOCK(aEnv)
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_VertexBuffer__1setDefaultColor
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jint aARGB)
{
    M3G_DO_LOCK
    m3gSetVertexDefaultColor((M3GVertexBuffer)aHBuffer, aARGB);
    M3G_DO_UNLOCK(aEnv)
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_VertexBuffer__1setColors
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jlong aHArray)
{
    M3G_DO_LOCK
    m3gSetColorArray((M3GVertexBuffer) aHBuffer, (M3GVertexArray) aHArray);
    M3G_DO_UNLOCK(aEnv)
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_VertexBuffer__1setVertices
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer, jlong aHArray, jfloat aScale, jfloatArray aSrcArray)
{
    int biasLength = 0;
    float *bias = NULL;
	printf("C99 setVertex -> %ld - %ld\n", aHBuffer, aHArray);
    if (aSrcArray && 0)
    {
        bias = (float *)(*aEnv)->GetFloatArrayElements(aEnv, aSrcArray, NULL);
        if (bias == NULL)
        {
            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return;
        }
    }

    biasLength = 0;//k aSrcArray ? (*aEnv)->GetArrayLength(aEnv, aSrcArray) : 0;

    M3G_DO_LOCK
    m3gSetVertexArray((M3GVertexBuffer)aHBuffer, (M3GVertexArray)aHArray, aScale, bias, biasLength);
    M3G_DO_UNLOCK(aEnv)

    if (aSrcArray)
    {
        (*aEnv)->ReleaseFloatArrayElements(aEnv, aSrcArray, bias, JNI_ABORT);
    }
}

JNIEXPORT jint JNICALL Java_javax_microedition_m3g_VertexBuffer__1getVertexCount
(JNIEnv* aEnv, jclass _unused, jlong aHBuffer)
{
    M3G_DO_LOCK
    jint count = (M3Guint)m3gGetVertexCount((M3GVertexBuffer)aHBuffer);
    M3G_DO_UNLOCK(aEnv)
    return count;
}
