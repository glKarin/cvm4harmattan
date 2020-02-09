package com.nokia.mid.ui;

public abstract class SoftNotification
{
  public static SoftNotification newInstance(int paramInt)
  {
    SoftNotification localSoftNotification = null;
    return localSoftNotification;
  }
  
  public static SoftNotification newInstance()
  {
    SoftNotification localSoftNotification = null;
    return localSoftNotification;
  }
  
  public abstract int getId();
  
  public abstract void post()
    throws SoftNotificationException;
  
  public abstract void remove()
    throws SoftNotificationException;
  
  public abstract void setListener(SoftNotificationListener paramSoftNotificationListener);
  
  public abstract void setText(String paramString1, String paramString2)
    throws SoftNotificationException;
  
  public abstract void setSoftkeyLabels(String paramString1, String paramString2)
    throws SoftNotificationException;
  
  public abstract void setImage(byte[] paramArrayOfByte)
    throws SoftNotificationException;
}
