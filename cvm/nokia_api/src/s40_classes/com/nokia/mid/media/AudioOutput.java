package com.nokia.mid.media;

public abstract interface AudioOutput
{
  public abstract int getActiveOutputMode();
  
  public abstract int[] getOutputDevices();
}
