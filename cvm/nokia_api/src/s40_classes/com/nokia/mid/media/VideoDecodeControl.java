package com.nokia.mid.media;

import javax.microedition.media.Control;

public abstract interface VideoDecodeControl
  extends Control
{
  public static final int DECODE_OFF = 1;
  public static final int DECODE_FULL = 0;
  
  public abstract int getDecodeStatus();
  
  public abstract int setDecodeStatus(int paramInt);
}
