package com.nokia.mid.ui;

import javax.microedition.lcdui.Image;

public class CategoryBar
{
  public static final int IMAGE_TYPE_BACKGROUND = 1;
  public static final int IMAGE_TYPE_ICON = 2;
  public static final int DEFAULT_HIGHLIGHT_COLOUR = -1;
  public static final int DEFAULT_BACKGROUND = -1;
  
  public CategoryBar(Image[] paramArrayOfImage1, Image[] paramArrayOfImage2, String[] paramArrayOfString) {}
  
  public CategoryBar(IconCommand[] paramArrayOfIconCommand, boolean paramBoolean) {}
  
  public static int getBestImageWidth(int paramInt)
  {
    int i = 1;
    return i;
  }
  
  public static int getBestImageHeight(int paramInt)
  {
    int i = 1;
    return i;
  }
  
  public static int getMaxElements()
  {
    int i = 1;
    return i;
  }
  
  public static int[] getDefaultBoundingBox()
  {
    int[] arrayOfInt = null;
    return arrayOfInt;
  }
  
  public int getSelectedIndex()
  {
    int i = 1;
    return i;
  }
  
  public boolean getVisibility()
  {
    boolean bool = true;
    return bool;
  }
  
  public void setBackgroundImage(Image paramImage) {}
  
  public void setElementListener(ElementListener paramElementListener) {}
  
  public void setElementProperties(int paramInt, Image paramImage1, Image paramImage2, String paramString) {}
  
  public void setElementProperties(int paramInt, IconCommand paramIconCommand, boolean paramBoolean) {}
  
  public void setSelectedIndex(int paramInt) {}
  
  public void setTransitionSupport(boolean paramBoolean) {}
  
  public void setVisibility(boolean paramBoolean) {}
  
  public void setHighlightColour(int paramInt) {}
  
  public void setBackgroundColour(int paramInt) {}
  
  public static void suppressSizeChanged(boolean paramBoolean) {}
}
