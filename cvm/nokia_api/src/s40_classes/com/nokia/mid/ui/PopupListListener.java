package com.nokia.mid.ui;

public abstract interface PopupListListener
{
  public abstract void itemSelected(PopupList paramPopupList, PopupListItem paramPopupListItem);
  
  public abstract void listDismissed(PopupList paramPopupList);
}
