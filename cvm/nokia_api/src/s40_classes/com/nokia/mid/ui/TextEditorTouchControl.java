package com.nokia.mid.ui;

public abstract interface TextEditorTouchControl
{
  public static final int PANEL_OFF = 1;
  public static final int PANEL_FIXED_POSITION = 2;
  public static final int PANEL_FLOATING = 3;
  public static final int ACTION_PANEL_MOVED = 268435456;
  
  public abstract void setPanelMode(int paramInt);
  
  public abstract int getPanelMode();
  
  public abstract void setPanelPosition(int paramInt1, int paramInt2);
  
  public abstract int getPanelWidth();
  
  public abstract int getPanelHeight();
  
  public abstract int getPanelX();
  
  public abstract int getPanelY();
  
  public abstract void setTouchEnabled(boolean paramBoolean);
  
  public abstract boolean isTouchEnabled();
  
  public abstract void setCaret(int paramInt1, int paramInt2);
}
