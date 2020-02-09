package com.nokia.mid.ui.multipointtouch;

public class MultipointTouch
{
  public static final int POINTER_PRESSED = 1;
  public static final int POINTER_RELEASED = 2;
  public static final int POINTER_DRAGGED = 3;
  
  public void addMultipointTouchListener(MultipointTouchListener paramMultipointTouchListener) {}
  
  public static MultipointTouch getInstance()
  {
    MultipointTouch localMultipointTouch = null;
    return localMultipointTouch;
  }
  
  public void removeMultipointTouchListener(MultipointTouchListener paramMultipointTouchListener) {}
  
  public static int getMaxPointers()
  {
    int i = 1;
    return i;
  }
  
  public static int getState(int paramInt)
  {
    int i = 1;
    return i;
  }
  
  public static int getX(int paramInt)
  {
    int i = 1;
    return i;
  }
  
  public static int getY(int paramInt)
  {
    int i = 1;
    return i;
  }
}
