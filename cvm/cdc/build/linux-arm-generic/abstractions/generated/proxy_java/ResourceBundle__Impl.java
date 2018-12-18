/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.i18n;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.i18n.ResourceBundle
public /* abstract */  class ResourceBundle__Impl extends com_sun_j2me_proxy_i18n__ProxyBase implements com.sun.j2me.proxy.i18n.ResourceBundle {
    private static Method __method1;
    private static Method __method2;
    private static Method __method3;
    private static Method __method4;
    private static Method __method5;
    private static Method __method6;
    private static ClassLoader __cloader;
    private static boolean __initialized = false;
    private static Object __sync;
    // Initialize class
    private static void __init() {
        if (__sync == null) {
            __sync = new Object();
        }
        if (__initialized) {
            return;
        }
        synchronized (__sync) {
            if (__initialized) {
                return;
            }
            java.security.AccessController.doPrivileged(new java.security.PrivilegedAction() {
                public Object run() {
                    __cloader = sun.misc.MIDPConfig.getMIDPImplementationClassLoader();
                    if (__cloader == null) {
                        throw new RuntimeException("Cannot get ClassLoader");
                    }
                    __init_classes();
                    try {
                        __method1 = __clazz.getDeclaredMethod("getLocalizedDateString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method2 = __clazz.getDeclaredMethod("getLocalizedTimeString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method3 = __clazz.getDeclaredMethod("getLocalizedDateTimeString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method4 = __clazz.getDeclaredMethod("getLocalizedFirstDayOfWeek", new Class[] {});
                        __method5 = __clazz.getDeclaredMethod("isLocalizedAMPMafterTime", new Class[] {});
                        __method6 = __clazz.getDeclaredMethod("getString", new Class[] {int.class});
                    } catch (NoSuchMethodException e) {
                        throw new RuntimeException(e);
                    }
                return null;
                }
            });
            __initialized = true;
        }
    }
    // getInstance method
    public static Object __getInstance(Object internal) {
        __init();
        if (internal == null) {
            return null;
        }
        Object saved = __objList.get(internal);
        if (saved != null) {
            saved = ((java.lang.ref.WeakReference)saved).get();
            if (saved != null) {
                return saved;
            } else {
                __objList.remove(internal);
            }
        }
        return new ResourceBundle__Impl(com.sun.j2me.proxy.i18n.ResourceBundle.class, null, internal);
    }
    // Internal constructor
    public ResourceBundle__Impl(final Class cls, final String fieldName, final Object obj) {
        __init();
        if (fieldName == null) {
            __setInternal(obj);
        } else {
            java.security.AccessController.doPrivileged(new java.security.PrivilegedAction() {
                public Object run() {
                    try {
                        __setInternal(cls.getDeclaredField(fieldName).get(obj));
                    } catch (NoSuchFieldException nsfe) {
                        throw new RuntimeException(nsfe);
                    } catch (IllegalAccessException iae) {
                        throw new RuntimeException(iae);
                    }
                return null;
                } // run()
            }); // doPrivileged()
        }
        if (__getInternal() != null) {
            __objList.put(__getInternal(), new java.lang.ref.WeakReference(this));
        }
    }
    // Finalizer
    protected void finalize() {
        __objList.remove(__getInternal());
    }
    // Default constructor (for derived classes)
    protected ResourceBundle__Impl() {
        __init();
    }
    public java.lang.String getLocalizedDateString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4) {
        try {
            java.lang.String result = (java.lang.String)__method1.invoke(__getInternal(), new Object[] {arg1, arg2, arg3, arg4});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getLocalizedTimeString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4) {
        try {
            java.lang.String result = (java.lang.String)__method2.invoke(__getInternal(), new Object[] {arg1, arg2, arg3, arg4});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getLocalizedDateTimeString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4, java.lang.String arg5, java.lang.String arg6, java.lang.String arg7, java.lang.String arg8) {
        try {
            java.lang.String result = (java.lang.String)__method3.invoke(__getInternal(), new Object[] {arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public int getLocalizedFirstDayOfWeek() {
        try {
            java.lang.Integer result = (java.lang.Integer)__method4.invoke(__getInternal(), new Object[] {});
            return result.intValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public boolean isLocalizedAMPMafterTime() {
        try {
            java.lang.Boolean result = (java.lang.Boolean)__method5.invoke(__getInternal(), new Object[] {});
            return result.booleanValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getString(int arg1) {
        try {
            java.lang.String result = (java.lang.String)__method6.invoke(__getInternal(), new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static Object __getProxyClass(com.sun.j2me.proxy.i18n.ResourceBundle instance) {
        __init();
        final com.sun.j2me.proxy.i18n.ResourceBundle fInstance = instance;
        Object proxy = 
            Proxy.newProxyInstance(__cloader, 
                new Class[] {__clazz10}, 
                new InvocationHandler() {
                    private com.sun.j2me.proxy.i18n.ResourceBundle myInstance = fInstance;
                    private int hc = fInstance.hashCode() + 1;
                    public Object invoke(Object p, Method m, Object[] a) throws Throwable {
                        Class[] args = m.getParameterTypes();
                        if (m.getName().equals("getLocalizedDateString") && args.length == 4 && args[0].getName().equals("java.lang.String") && args[1].getName().equals("java.lang.String") && args[2].getName().equals("java.lang.String") && args[3].getName().equals("java.lang.String")) {
                                java.lang.String result = myInstance.getLocalizedDateString((java.lang.String)a[0], (java.lang.String)a[1], (java.lang.String)a[2], (java.lang.String)a[3]);
                                return result;
                        } else
                        if (m.getName().equals("getLocalizedTimeString") && args.length == 4 && args[0].getName().equals("java.lang.String") && args[1].getName().equals("java.lang.String") && args[2].getName().equals("java.lang.String") && args[3].getName().equals("java.lang.String")) {
                                java.lang.String result = myInstance.getLocalizedTimeString((java.lang.String)a[0], (java.lang.String)a[1], (java.lang.String)a[2], (java.lang.String)a[3]);
                                return result;
                        } else
                        if (m.getName().equals("getLocalizedDateTimeString") && args.length == 8 && args[0].getName().equals("java.lang.String") && args[1].getName().equals("java.lang.String") && args[2].getName().equals("java.lang.String") && args[3].getName().equals("java.lang.String") && args[4].getName().equals("java.lang.String") && args[5].getName().equals("java.lang.String") && args[6].getName().equals("java.lang.String") && args[7].getName().equals("java.lang.String")) {
                                java.lang.String result = myInstance.getLocalizedDateTimeString((java.lang.String)a[0], (java.lang.String)a[1], (java.lang.String)a[2], (java.lang.String)a[3], (java.lang.String)a[4], (java.lang.String)a[5], (java.lang.String)a[6], (java.lang.String)a[7]);
                                return result;
                        } else
                        if (m.getName().equals("getLocalizedFirstDayOfWeek") && (args == null || args.length == 0)) {
                                int result = myInstance.getLocalizedFirstDayOfWeek();
                                return new java.lang.Integer(result);
                        } else
                        if (m.getName().equals("isLocalizedAMPMafterTime") && (args == null || args.length == 0)) {
                                boolean result = myInstance.isLocalizedAMPMafterTime();
                                return new java.lang.Boolean(result);
                        } else
                        if (m.getName().equals("getString") && args.length == 1 && args[0].getName().equals("int")) {
                                java.lang.String result = myInstance.getString(((Integer)a[0]).intValue());
                                return result;
                        } else
                        if (m.getName().equals("hashCode") && (args == null || args.length == 0)) {
                            return new Integer(myInstance.hashCode());
                        } else
                        if (m.getName().equals("equals") && args.length == 1 && args[0].getName().equals("java.lang.Object")) {
                            boolean result = (a[0] == null ? false : a[0].equals(myInstance));
                            return new Boolean(result);
                        } else {
                            StringBuffer s = new StringBuffer();
                            s.append(m.getName());
                            s.append("(");
                            for (int i = 0; i < args.length; i++) {
                                if (i > 0) {
                                    s.append(", ");
                                }
                                s.append(args[i].getName());
                            }
                            s.append(")");
                            throw new RuntimeException("Cannot find method: " + s.toString());
                        }
                    }
                });
        __objList.put(proxy, new java.lang.ref.WeakReference(fInstance));
        return proxy;
    }
    private static Class __clazz;
    private static Class __clazz10;
    private static void __init_classes() {
        try {
            __clazz10 = Class.forName("com.sun.midp.i18n.ResourceBundle", true, __cloader);
            __clazz = __clazz10;
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
