package com.nokia.mid.ui;

import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.Image;

public class IconCommand
  extends Command
{
  public static final int ICON_ADD_CONTACT = 0;
  public static final int ICON_BACK = 1;
  public static final int ICON_OPTIONS = 2;
  public static final int ICON_SEND_SMS = 3;
  public static final int ICON_OK = 4;
  
  public IconCommand(String paramString1, String paramString2, int paramInt1, int paramInt2, int paramInt3)
  {
    super(paramString1, paramString2, paramInt2, paramInt3);
  }
  
  public IconCommand(String paramString, int paramInt1, int paramInt2, int paramInt3)
  {
    super(paramString, paramInt1, paramInt2);
  }
  
  public IconCommand(String paramString1, String paramString2, Image paramImage1, Image paramImage2, int paramInt1, int paramInt2)
  {
    super(paramString1, paramString2, paramInt1, paramInt2);
  }
  
  public IconCommand(String paramString, Image paramImage1, Image paramImage2, int paramInt1, int paramInt2)
  {
    super(paramString, paramInt1, paramInt2);
  }
  
  public int getIconId()
  {
    int i = 1;
    return i;
  }
  
  public Image getUnselectedIcon()
  {
    Image localImage = null;
    return localImage;
  }
  
  public Image getSelectedIcon()
  {
    Image localImage = null;
    return localImage;
  }
}
