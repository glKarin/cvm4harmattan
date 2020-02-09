/*
 * Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies).
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

package javax.microedition.m3g;

public class Fog extends Object3D {
	public static final int EXPONENTIAL = 80;
	public static final int LINEAR = 81;

	public Fog() {
		super(_ctor(Interface.getHandle()));
		Object3D.KarinDebugCall(this, "public Fog() {");
	}

	/**
	 */
	Fog(long handle) {
		super(handle);
		Object3D.KarinDebugCall(this, "Fog(long handle) {");
	}

	public void setMode(int mode) {
		Object3D.KarinDebugCall(this, "public void setMode(int mode) {");
		_setMode(handle, mode);
	}

	public int getMode() {
		Object3D.KarinDebugCall(this, "public int getMode() {");
		return _getMode(handle);
	}

	public void setLinear(float near, float far) {
		Object3D.KarinDebugCall(this, "public void setLinear(float near, float far) {");
		_setLinear(handle, near, far);
	}

	public float getNearDistance() {
		Object3D.KarinDebugCall(this, "public float getNearDistance() {");
		return _getDistance(handle, Defs.GET_NEAR);
	}

	public float getFarDistance() {
		Object3D.KarinDebugCall(this, "public float getFarDistance() {");
		return _getDistance(handle, Defs.GET_FAR);
	}

	public void setDensity(float density) {
		Object3D.KarinDebugCall(this, "public void setDensity(float density) {");
		_setDensity(handle, density);
	}

	public float getDensity() {
		Object3D.KarinDebugCall(this, "public float getDensity() {");
		return _getDensity(handle);
	}

	public void setColor(int RGB) {
		Object3D.KarinDebugCall(this, "public void setColor(int RGB) {");
		_setColor(handle, RGB);
	}

	public int getColor() {
		Object3D.KarinDebugCall(this, "public int getColor() {");
		return _getColor(handle);
	}

	// Native methods
	private static native long _ctor(long hInterface);

	private static native void _setMode(long handle, int mode);

	private static native int _getMode(long handle);

	private static native void _setLinear(long handle, float near, float far);

	private static native float _getDistance(long handle, int which);

	private static native void _setDensity(long handle, float density);

	private static native float _getDensity(long handle);

	private static native void _setColor(long handle, int RGB);

	private static native int _getColor(long handle);
}
