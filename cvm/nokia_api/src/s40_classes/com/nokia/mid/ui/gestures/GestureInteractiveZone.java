package com.nokia.mid.ui.gestures;

public class GestureInteractiveZone
{
  public static final int GESTURE_TAP = 1;
  public static final int GESTURE_LONG_PRESS = 2;
  public static final int GESTURE_DRAG = 4;
  public static final int GESTURE_DROP = 8;
  public static final int GESTURE_FLICK = 16;
  public static final int GESTURE_LONG_PRESS_REPEATED = 32;
  public static final int GESTURE_PINCH = 64;
  public static final int GESTURE_RECOGNITION_START = 16384;
  public static final int GESTURE_RECOGNITION_END = 32768;
  public static final int GESTURE_ALL = 49279;
  
  public GestureInteractiveZone(int paramInt) {}
  
  public GestureInteractiveZone(int paramInt1, int paramInt2) {}
  
  public void setRectangle(int paramInt1, int paramInt2, int paramInt3, int paramInt4) {}
  
  public void setLongPressTimeInterval(int paramInt) {}
  
  public int getGestures()
  {
    int i = 1;
    return i;
  }
  
  public void setGestures(int paramInt) {}
  
  public int getX()
  {
    int i = 1;
    return i;
  }
  
  public int getY()
  {
    int i = 1;
    return i;
  }
  
  public int getWidth()
  {
    int i = 1;
    return i;
  }
  
  public int getHeight()
  {
    int i = 1;
    return i;
  }
  
  public int getLongPressTimeInterval()
  {
    int i = 1;
    return i;
  }
  
  public static boolean isSupported(int paramInt)
  {
    boolean bool = true;
    return bool;
  }
}
