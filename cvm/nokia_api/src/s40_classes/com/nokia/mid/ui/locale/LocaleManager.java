package com.nokia.mid.ui.locale;

public class LocaleManager
{
  public static LocaleManager getInstance()
  {
    LocaleManager localLocaleManager = null;
    return localLocaleManager;
  }
  
  public void addLocaleListener(LocaleListener paramLocaleListener) {}
  
  public void removeLocaleListener(LocaleListener paramLocaleListener) {}
  
  public Locale[] getAvailableLocales()
  {
    Locale[] arrayOfLocale = null;
    return arrayOfLocale;
  }
  
  public Locale getDefaultLocale()
  {
    Locale localLocale = null;
    return localLocale;
  }
}
