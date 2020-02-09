package com.nokia.mid.ui;

public class PopupList
  extends PopupListItem
{
  public static final int CONTEXTUAL_MENU = 0;
  public static final int LIST_DIALOG = 1;
  public static final int TAIL_LEFT = 0;
  public static final int TAIL_RIGHT = 1;
  public static final int TAIL_NONE = 2;
  public static final int TAIL_PARENT = 3;
  
  public PopupList()
  {
    super("");
  }
  
  public PopupList(String paramString)
  {
    super(paramString);
  }
  
  public PopupList(String paramString, int paramInt)
    throws PopupListException
  {
    this(paramString);
  }
  
  public void setListener(PopupListListener paramPopupListListener) {}
  
  public void appendItem(PopupListItem paramPopupListItem)
    throws NullPointerException, PopupListException
  {}
  
  public void insertItem(PopupListItem paramPopupListItem, int paramInt)
    throws NullPointerException, PopupListException, IndexOutOfBoundsException
  {}
  
  public void removeItem(PopupListItem paramPopupListItem) {}
  
  public void removeItemAt(int paramInt)
    throws IndexOutOfBoundsException
  {}
  
  public int size()
  {
    int i = 1;
    return i;
  }
  
  public PopupListItem getItem(int paramInt)
    throws IndexOutOfBoundsException
  {
    PopupListItem localPopupListItem = null;
    return localPopupListItem;
  }
  
  public void setItemText(String paramString) {}
  
  public void setText(String paramString) {}
  
  public void setVisible(boolean paramBoolean)
    throws PopupListException, IllegalStateException
  {}
  
  public void setTailStyle(int paramInt)
    throws PopupListException
  {}
  
  public void setListYPos(int paramInt)
    throws PopupListException
  {}
}
