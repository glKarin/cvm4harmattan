package com.nokia.mid.ui;

public abstract class CanvasItem
{
  public static final int SCALE_NOT_ALLOWED = 0;
  public static final int SCALE_NEAREST = 1;
  public static final int SCALE_AVERAGE = 2;
  
  public void setParent(Object paramObject) {}
  
  public void setSize(int paramInt1, int paramInt2) {}
  
  public void setSize(int paramInt1, int paramInt2, int paramInt3, int paramInt4) {}
  
  public void scale(int paramInt1, int paramInt2) {}
  
  public void scale(int paramInt1, int paramInt2, int paramInt3, int paramInt4) {}
  
  public void setScalingMode(int paramInt1, boolean paramBoolean, int paramInt2) {}
  
  public int getHeight()
  {
    int i = 1;
    return i;
  }
  
  public int getWidth()
  {
    int i = 1;
    return i;
  }
  
  public void setPosition(int paramInt1, int paramInt2) {}
  
  public int getPositionX()
  {
    int i = 1;
    return i;
  }
  
  public int getPositionY()
  {
    int i = 1;
    return i;
  }
  
  public void setVisible(boolean paramBoolean) {}
  
  public boolean isVisible()
  {
    boolean bool = true;
    return bool;
  }
  
  public void setZPosition(int paramInt) {}
  
  public int getZPosition()
  {
    int i = 1;
    return i;
  }
  
  public Object getParent()
  {
    Object localObject = null;
    return localObject;
  }
}
