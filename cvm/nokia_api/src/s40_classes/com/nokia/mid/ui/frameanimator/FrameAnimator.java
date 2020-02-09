package com.nokia.mid.ui.frameanimator;

public class FrameAnimator
{
  public static final int FRAME_ANIMATOR_MAX_CONCURRENT = 5;
  public static final int FRAME_ANIMATOR_VERTICAL = 0;
  public static final int FRAME_ANIMATOR_HORIZONTAL = 1;
  public static final int FRAME_ANIMATOR_FREE_ANGLE = 2;
  public static final int FRAME_ANIMATOR_FRICTION_LOW = 0;
  public static final int FRAME_ANIMATOR_FRICTION_MEDIUM = 1;
  public static final int FRAME_ANIMATOR_FRICTION_HIGH = 2;
  
  public boolean register(int paramInt1, int paramInt2, short paramShort1, short paramShort2, FrameAnimatorListener paramFrameAnimatorListener)
  {
    boolean bool = true;
    return bool;
  }
  
  public void unregister() {}
  
  public void drag(int paramInt1, int paramInt2) {}
  
  public void kineticScroll(int paramInt1, int paramInt2, int paramInt3, float paramFloat) {}
  
  public void stop() {}
  
  public boolean isRegistered()
  {
    boolean bool = true;
    return bool;
  }
  
  public static int getNumRegisteredFrameAnimators()
  {
    int i = 1;
    return i;
  }
}
