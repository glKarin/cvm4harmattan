package com.nokia.mid.ui;

public class TactileFeedback
{
  public static final int FEEDBACK_STYLE_BASIC = 1;
  public static final int FEEDBACK_STYLE_SENSITIVE = 2;
  
  public void directFeedback(int paramInt)
    throws IllegalArgumentException
  {}
  
  public boolean isTouchFeedbackSupported()
  {
    boolean bool = true;
    return bool;
  }
  
  public void registerFeedbackArea(Object paramObject, int paramInt1, int paramInt2, int paramInt3, int paramInt4, int paramInt5, int paramInt6)
    throws IllegalArgumentException
  {}
  
  public void unregisterFeedbackArea(Object paramObject, int paramInt)
    throws IllegalArgumentException
  {}
  
  public void removeFeedbackForComponent(Object paramObject) {}
  
  public void moveFeedbackAreaToFirstPriority(Object paramObject, int paramInt) {}
}
