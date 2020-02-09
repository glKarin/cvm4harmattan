package com.nokia.mid.ui;

import javax.microedition.lcdui.Graphics;

public abstract class CanvasGraphicsItem
  extends CanvasItem
{
  public CanvasGraphicsItem(int paramInt1, int paramInt2) {}
  
  protected abstract void paint(Graphics paramGraphics);
  
  public void repaint() {}
  
  public void repaint(int paramInt1, int paramInt2, int paramInt3, int paramInt4) {}
  
  public void setParent(Object paramObject) {}
  
  public void setVisible(boolean paramBoolean) {}
  
  public void setSize(int paramInt1, int paramInt2, int paramInt3, int paramInt4) {}
  
  public void setSize(int paramInt1, int paramInt2) {}
  
  public void setPosition(int paramInt1, int paramInt2) {}
  
  public int getContentWidth()
  {
    int i = 1;
    return i;
  }
  
  public int getContentHeight()
  {
    int i = 1;
    return i;
  }
  
  public void setZPosition(int paramInt) {}
}
