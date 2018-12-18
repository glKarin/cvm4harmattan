/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.i18n;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.i18n.Resource
public /* abstract */ class Resource extends com_sun_j2me_proxy_i18n__ProxyBase {
    private static Method __method1;
    private static Method __method2;
    private static Method __method3;
    private static Method __method4;
    private static Method __method5;
    private static Method __method6;
    private static Method __method7;
    private static Method __method8;
    private static Constructor __cons9;
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
                        __method1 = __clazz.getDeclaredMethod("getDateString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method2 = __clazz.getDeclaredMethod("getTimeString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method3 = __clazz.getDeclaredMethod("getDateTimeString", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method4 = __clazz.getDeclaredMethod("getFirstDayOfWeek", new Class[] {});
                        __method5 = __clazz.getDeclaredMethod("isAMPMafterTime", new Class[] {});
                        __method6 = __clazz.getDeclaredMethod("getString", new Class[] {java.lang.String.class, java.lang.String[].class});
                        __method7 = __clazz.getDeclaredMethod("getString", new Class[] {int.class});
                        __method8 = __clazz.getDeclaredMethod("getString", new Class[] {int.class, java.lang.String[].class});
                        __cons9 = __clazz.getDeclaredConstructor(new Class[] {});
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
        return new Resource(com.sun.j2me.proxy.i18n.Resource.class, null, internal);
    }
    // Internal constructor
    public Resource(final Class cls, final String fieldName, final Object obj) {
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
    public static java.lang.String getDateString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method1.invoke(null, new Object[] {arg1, arg2, arg3, arg4});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getTimeString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method2.invoke(null, new Object[] {arg1, arg2, arg3, arg4});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getDateTimeString(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3, java.lang.String arg4, java.lang.String arg5, java.lang.String arg6, java.lang.String arg7, java.lang.String arg8) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method3.invoke(null, new Object[] {arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static int getFirstDayOfWeek() {
        __init();
        try {
            java.lang.Integer result = (java.lang.Integer)__method4.invoke(null, new Object[] {});
            return result.intValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static boolean isAMPMafterTime() {
        __init();
        try {
            java.lang.Boolean result = (java.lang.Boolean)__method5.invoke(null, new Object[] {});
            return result.booleanValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getString(java.lang.String arg1, java.lang.String[] arg2) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method6.invoke(null, new Object[] {arg1, arg2});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getString(int arg1) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method7.invoke(null, new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getString(int arg1, java.lang.String[] arg2) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method8.invoke(null, new Object[] {new java.lang.Integer(arg1), arg2});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public Resource() {
        __init();
        try {
            __setInternal(__cons9.newInstance(new Object[] {}));
            if (__getInternal() != null) {
                __objList.put(__getInternal(), new java.lang.ref.WeakReference(this));
            }
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        } catch (InstantiationException ie) {
            throw new RuntimeException(ie);
        }
    }
    private static Class __clazz;
    private static Class __clazz9;
    private static void __init_classes() {
        try {
            __clazz9 = Class.forName("com.sun.midp.i18n.Resource", true, __cloader);
            __clazz = __clazz9;
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
