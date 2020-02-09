package com.nokia.mid.media;

import javax.microedition.media.Control;

public abstract interface AudioOutputControl
  extends Control
{
  public static final int DEFAULT = 0;
  public static final int ALL = 1;
  public static final int NONE = 2;
  public static final int PRIVATE = 3;
  public static final int PUBLIC = 4;
  
  public abstract int[] getAvailableOutputModes();
  
  public abstract int getOutputMode();
  
  public abstract AudioOutput getCurrent();
  
  public abstract int setOutputMode(int paramInt);
}
