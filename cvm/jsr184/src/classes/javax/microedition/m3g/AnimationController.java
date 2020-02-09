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

public class AnimationController extends Object3D {
	//------------------------------------------------------------------
	// Constructor
	//------------------------------------------------------------------

	public AnimationController() {
		super(_ctor(Interface.getHandle()));
		Object3D.KarinDebugCall(this, "public AnimationController() {");
	}

	/**
	 */
	AnimationController(long handle) {
		super(handle);
		Object3D.KarinDebugCall(this, "AnimationController(long handle) {");
	}

	//------------------------------------------------------------------
	// Public methods
	//------------------------------------------------------------------

	public void setActiveInterval(int worldTimeMin, int worldTimeMax) {
		Object3D.KarinDebugCall(this, "public void setActiveInterval(int worldTimeMin, int worldTimeMax) {");
		_setActiveInterval(handle, worldTimeMin, worldTimeMax);
	}

	public int getActiveIntervalStart() {
		Object3D.KarinDebugCall(this, "public int getActiveIntervalStart() {");
		return _getActiveIntervalStart(handle);
	}

	public int getActiveIntervalEnd() {
		Object3D.KarinDebugCall(this, "public int getActiveIntervalEnd() {");
		return _getActiveIntervalEnd(handle);
	}

	public void setSpeed(float factor, int worldTime) {
		Object3D.KarinDebugCall(this, "public void setSpeed(float factor, int worldTime) {");
		_setSpeed(handle, factor, worldTime);
	}

	public float getSpeed() {
		Object3D.KarinDebugCall(this, "public float getSpeed() {");
		return _getSpeed(handle);
	}

	public void setPosition(float time, int worldTime) {
		Object3D.KarinDebugCall(this, "public void setPosition(float time, int worldTime) {");
		_setPosition(handle, time, worldTime);
	}

	public float getPosition(int worldTime) {
		Object3D.KarinDebugCall(this, "public float getPosition(int worldTime) {");
		return _getPosition(handle, worldTime);
	}

	public void setWeight(float weight) {
		Object3D.KarinDebugCall(this, "public void setWeight(float weight) {");
		_setWeight(handle, weight);
	}

	public float getWeight() {
		Object3D.KarinDebugCall(this, "public float getWeight() {");
		return _getWeight(handle);
	}

	// M3G maintenance version 1.1
	public int getRefWorldTime() {
		Object3D.KarinDebugCall(this, "public int getRefWorldTime() {");
		return _getRefWorldTime(handle);
	}


	// Native methods
	private native static long _ctor(long hInterface);

	private native static void _setActiveInterval(long handle, int worldTimeMin, int worldTimeMax);

	private native static int _getActiveIntervalStart(long handle);

	private native static int _getActiveIntervalEnd(long handle);

	private native static void _setSpeed(long handle, float factor, int worldTime);

	private native static float _getSpeed(long handle);

	private native static void _setPosition(long handle, float time, int worldTime);

	private native static float _getPosition(long handle, int worldTime);

	private native static void _setWeight(long handle, float weight);

	private native static float _getWeight(long handle);

	// M3G maintenance version 1.1
	private native static int _getRefWorldTime(long handle);

}
