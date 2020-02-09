package com.nokia.mid.ui.locale;

public abstract interface Locale
{
  public abstract String getCountry();
  
  public abstract String getLanguage();
  
  public abstract boolean equals(Object paramObject);
}
