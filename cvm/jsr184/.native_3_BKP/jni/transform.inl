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
#include "javax_microedition_m3g_Transform.h"

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1transformArray
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jlong aHArray, jfloatArray aOutArray, jboolean aW)
{
    // null pointers are never passed
    Matrix* matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    jfloat* outArray = (*aEnv)->GetFloatArrayElements(aEnv, aOutArray, NULL);
    if (outArray == NULL)
    {
        (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);

        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    int outArrayLen = (*aEnv)->GetArrayLength(aEnv, aOutArray);

    M3G_DO_LOCK
    m3gTransformArray((M3GVertexArray)aHArray, matrix, (M3Gfloat *)outArray, outArrayLen, (M3Gbool)aW);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);
    (*aEnv)->ReleaseFloatArrayElements(aEnv, aOutArray, outArray, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1rotateQuat
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloat aQx, jfloat aQy, jfloat aQz, jfloat aQw)
{
    M3GQuat quat;
    Matrix* matrix = NULL;

    if (aQx == 0 && aQy == 0 && aQz == 0 && aQw == 0)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/IllegalArgumentException");
        return;
    }

    matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    quat.x = aQx;
    quat.y = aQy;
    quat.z = aQz;
    quat.w = aQw;

    M3G_DO_LOCK
    m3gNormalizeQuat(&quat);
    m3gPostRotateMatrixQuat(matrix, (const Quat *)&quat);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1setIdentity
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix)
{
    Matrix* matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }
    M3G_DO_LOCK
    m3gIdentityMatrix(matrix);
    M3G_DO_UNLOCK(aEnv)
    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1translate
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloat aTx, jfloat aTy, jfloat aTz)
{
    Matrix* matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }
    M3G_DO_LOCK
    m3gPostTranslateMatrix(matrix, aTx, aTy, aTz);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1getMatrix
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloatArray aDstArray)
{
    Matrix *matrix = NULL;

    if (aDstArray == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/NullPointerException");
        return;
    }

    if ((*aEnv)->GetArrayLength(aEnv, aDstArray) < 16)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/IllegalArgumentException");
        return;
    }

    matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    float* dstArray = (float*)((*aEnv)->GetFloatArrayElements(aEnv, aDstArray, NULL));
    if (dstArray == NULL)
    {
        (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);

        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    M3G_DO_LOCK
    m3gGetMatrixRows(matrix, dstArray);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);
    (*aEnv)->ReleaseFloatArrayElements(aEnv, aDstArray, dstArray, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1transformTable
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloatArray aTableArray)
{
    // null pointers are never passed
    M3Gfloat *v = (M3Gfloat *)((*aEnv)->GetFloatArrayElements(aEnv, aTableArray, NULL));
    if (v == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }
    int tabelArrayLen = (*aEnv)->GetArrayLength(aEnv, aTableArray);
    Matrix* matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        (*aEnv)->ReleaseFloatArrayElements(aEnv, aTableArray, v, JNI_ABORT);

        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    {
        M3Gint i;
        M3GVec4 vec;

        M3G_DO_LOCK
        for (i = 0; i < tabelArrayLen; i += 4)
        {
            m3gSetVec4(&vec, v[i + 0], v[i + 1], v[i + 2], v[i + 3]);
            m3gTransformVec4(matrix, &vec);
            v[i + 0] = vec.x;
            v[i + 1] = vec.y;
            v[i + 2] = vec.z;
            v[i + 3] = vec.w;
        }
        M3G_DO_UNLOCK(aEnv)
    }

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);
    (*aEnv)->ReleaseFloatArrayElements(aEnv, aTableArray, v, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1scale
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloat aSx, jfloat aSy, jfloat aSz)
{
    Matrix* matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    M3G_DO_LOCK
    m3gPostScaleMatrix(matrix, aSx, aSy, aSz);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1mul
(JNIEnv* aEnv, jclass _unused, jbyteArray aProdArray, jbyteArray aLeftArray, jbyteArray aRightArray)
{

    if (aRightArray == NULL || aLeftArray == NULL || aProdArray == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/NullPointerException");
        return;
    }

    {
        const Matrix *right = (const Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aRightArray, NULL));
        if (right == NULL)
        {
            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return;
        }

        const Matrix *left = (const Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aLeftArray, NULL));
        if (left == NULL)
        {
            (*aEnv)->ReleaseByteArrayElements(aEnv, aRightArray, (jbyte*)right, JNI_ABORT);

            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return;
        }

        Matrix *prod = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aProdArray, NULL));
        if (prod == NULL)
        {
            (*aEnv)->ReleaseByteArrayElements(aEnv, aRightArray, (jbyte*)right, JNI_ABORT);
            (*aEnv)->ReleaseByteArrayElements(aEnv, aLeftArray, (jbyte*)left, JNI_ABORT);

            M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
            return;
        }

        Matrix temp;
        M3G_DO_LOCK
        m3gMatrixProduct(&temp, left, right);
        M3G_DO_UNLOCK(aEnv)

        *prod = temp;

        (*aEnv)->ReleaseByteArrayElements(aEnv, aRightArray, (jbyte*)right, JNI_ABORT);
        (*aEnv)->ReleaseByteArrayElements(aEnv, aLeftArray, (jbyte*)left, JNI_ABORT);
        (*aEnv)->ReleaseByteArrayElements(aEnv, aProdArray, (jbyte*)prod, 0);
    }
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1setMatrix
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloatArray aSrcArray)
{
    Matrix *matrix = NULL;

    if (aSrcArray == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/NullPointerException");
        return;
    }
    if ((*aEnv)->GetArrayLength(aEnv, aSrcArray) < 16)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/IllegalArgumentException");
        return;
    }

    matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    float* srcArray = (*aEnv)->GetFloatArrayElements(aEnv, aSrcArray, NULL);
    if (srcArray == NULL)
    {
        (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);

        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    M3G_DO_LOCK
    m3gSetMatrixRows(matrix, (const float *)srcArray);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseFloatArrayElements(aEnv, aSrcArray, srcArray, JNI_ABORT);
    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1transpose
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix)
{
    Matrix tpos;
    Matrix *matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }
    M3G_DO_LOCK
    m3gMatrixTranspose(&tpos, matrix);
    m3gCopyMatrix(matrix, &tpos);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1invert
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix)
{
    Matrix *matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    M3G_BEGIN_PROFILE(M3G_PROFILE_TRANSFORM_INVERT);
    M3G_DO_LOCK
    if (!m3gInvertMatrix(matrix))
    {
        (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, JNI_ABORT);
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/ArithmeticException");
        M3G_DO_UNLOCK(aEnv)
        return;
    }
    M3G_DO_UNLOCK(aEnv)
    M3G_END_PROFILE(M3G_PROFILE_TRANSFORM_INVERT);

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}

JNIEXPORT void JNICALL Java_javax_microedition_m3g_Transform__1rotate
(JNIEnv* aEnv, jclass _unused, jbyteArray aMatrix, jfloat aAngle, jfloat aAx, jfloat aAy, jfloat aAz)
{
    Matrix *matrix = NULL;

    if (aAx == 0 && aAy == 0 && aAz == 0 && aAngle != 0)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/IllegalArgumentException");
        return;
    }

    matrix = (Matrix *)((*aEnv)->GetByteArrayElements(aEnv, aMatrix, NULL));
    if (matrix == NULL)
    {
        M3G_RAISE_EXCEPTION(aEnv, "java/lang/OutOfMemoryError");
        return;
    }

    M3G_DO_LOCK
    m3gPostRotateMatrix(matrix, aAngle, aAx, aAy, aAz);
    M3G_DO_UNLOCK(aEnv)

    (*aEnv)->ReleaseByteArrayElements(aEnv, aMatrix, (jbyte*)matrix, 0);
}
