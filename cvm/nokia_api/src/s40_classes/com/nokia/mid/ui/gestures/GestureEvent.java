package com.nokia.mid.ui.gestures;

public abstract interface GestureEvent
{
  public abstract int getType();
  
  public abstract int getDragDistanceX();
  
  public abstract int getDragDistanceY();
  
  public abstract int getStartX();
  
  public abstract int getStartY();
  
  public abstract float getFlickDirection();
  
  public abstract int getFlickSpeed();
  
  public abstract int getFlickSpeedX();
  
  public abstract int getFlickSpeedY();
  
  public abstract int getPinchDistanceStarting();
  
  public abstract int getPinchDistanceCurrent();
  
  public abstract int getPinchDistanceChange();
  
  public abstract int getPinchCenterX();
  
  public abstract int getPinchCenterY();
  
  public abstract int getPinchCenterChangeX();
  
  public abstract int getPinchCenterChangeY();
}
