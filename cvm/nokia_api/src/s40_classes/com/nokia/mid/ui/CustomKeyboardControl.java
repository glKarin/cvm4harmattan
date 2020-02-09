package com.nokia.mid.ui;

public abstract interface CustomKeyboardControl
{
  public static final int KEYBOARD_LANDSCAPE = 1;
  public static final int KEYBOARD_PORTRAIT = 2;
  public static final int KEYBOARD_LANDSCAPE_180 = 4;
  public static final int KEYBOARD_PORTRAIT_180 = 8;
  
  public abstract void launch(int paramInt1, int paramInt2);
  
  public abstract void launch(int paramInt);
  
  public abstract void launch();
  
  public abstract void dismiss();
  
  public abstract void setKeyboardType(int paramInt);
  
  public abstract void setKeyboardMode(int paramInt);
  
  public abstract int getKeyboardMode();
  
  public abstract int getKeyboardType();
  
  public abstract int getSupportedOrientations(int paramInt);
}
