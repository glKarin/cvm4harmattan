package com.nokia.mid.ui;

public abstract interface ElementListener
{
  public static final int BACK = -1;
  
  public abstract void notifyElementSelected(CategoryBar paramCategoryBar, int paramInt);
}
