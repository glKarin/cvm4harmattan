package com.nokia.mid.ui;

public class VirtualKeyboard
{
  public static final int CUSTOM_KEYBOARD = 1;
  public static final int SYSTEM_KEYBOARD = 2;
  public static final int VKB_TYPE_ITUT = 1;
  public static final int VKB_TYPE_GAME = 3;
  public static final int VKB_MODE_DEFAULT = 0;
  public static final int VKB_MODE_NUMERIC = 1;
  public static final int VKB_MODE_ALPHA_LOWER_CASE = 2;
  public static final int VKB_MODE_ALPHA_UPPER_CASE = 3;
  public static final int VKB_MODE_ALPHA_UPPER_CASE_LOCKED = 4;
  
  public static void hideOpenKeypadCommand(boolean paramBoolean) {}
  
  public static int getXPosition()
  {
    int i = 1;
    return i;
  }
  
  public static int getYPosition()
  {
    int i = 1;
    return i;
  }
  
  public static int getWidth()
  {
    int i = 1;
    return i;
  }
  
  public static int getHeight()
  {
    int i = 1;
    return i;
  }
  
  public static void setVisibilityListener(KeyboardVisibilityListener paramKeyboardVisibilityListener) {}
  
  public static CustomKeyboardControl getCustomKeyboardControl()
  {
    CustomKeyboardControl localCustomKeyboardControl = null;
    return localCustomKeyboardControl;
  }
  
  public static boolean isVisible()
  {
    boolean bool = true;
    return bool;
  }
  
  public static void suppressSizeChanged(boolean paramBoolean) {}
}
