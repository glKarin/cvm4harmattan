package com.nokia.mid.ui.orientation;

public class Orientation
{
  public static final int ORIENTATION_PORTRAIT = 1;
  public static final int ORIENTATION_LANDSCAPE = 2;
  public static final int ORIENTATION_PORTRAIT_180 = 3;
  public static final int ORIENTATION_LANDSCAPE_180 = 4;
  
  public static void setAppOrientation(int paramInt) {}
  
  public static int getAppOrientation()
  {
    int i = 1;
    return i;
  }
  
  public static int getDisplayOrientation()
  {
    int i = 1;
    return i;
  }
  
  public static void addOrientationListener(OrientationListener paramOrientationListener) {}
  
  public static void removeOrientationListener(OrientationListener paramOrientationListener) {}
}
