/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.security;
import java.lang.reflect.*;
// Proxy class for com.sun.j2me.security.AccessController
public final class AccessController extends com_sun_j2me_proxy_security__ProxyBase {
    public static final java.lang.String TRUSTED_APP_PERMISSION_NAME = "com.sun.j2me.trustedApp";
    private static Method __method1;
    private static Method __method2;
    private static Method __method3;
    private static Method __method4;
    private static Method __method5;
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
                        __method1 = __clazz.getDeclaredMethod("setAccessControlContext", new Class[] {__clazz7});
                        __method2 = __clazz.getDeclaredMethod("getAccessControlContext", new Class[] {});
                        __method3 = __clazz.getDeclaredMethod("checkPermission", new Class[] {java.lang.String.class, java.lang.String.class, java.lang.String.class});
                        __method4 = __clazz.getDeclaredMethod("checkPermission", new Class[] {java.lang.String.class, java.lang.String.class});
                        __method5 = __clazz.getDeclaredMethod("checkPermission", new Class[] {java.lang.String.class});
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
        return new AccessController(com.sun.j2me.proxy.security.AccessController.class, null, internal);
    }
    // Internal constructor
    public AccessController(final Class cls, final String fieldName, final Object obj) {
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
    protected AccessController() {
        __init();
    }
    public static void setAccessControlContext(com.sun.j2me.proxy.security.AccessControlContext arg1) {
        __init();
        try {
            __method1.invoke(null, new Object[] {arg1});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static com.sun.j2me.proxy.security.AccessControlContext getAccessControlContext() {
        __init();
        try {
            Object result = __method2.invoke(null, new Object[] {});
            return (com.sun.j2me.proxy.security.AccessControlContext)result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static void checkPermission(java.lang.String arg1, java.lang.String arg2, java.lang.String arg3) throws java.lang.SecurityException {
        __init();
        try {
            __method3.invoke(null, new Object[] {arg1, arg2, arg3});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            if (target instanceof java.lang.SecurityException) {
                throw (java.lang.SecurityException)target;
            }
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static void checkPermission(java.lang.String arg1, java.lang.String arg2) throws java.lang.SecurityException {
        __init();
        try {
            __method4.invoke(null, new Object[] {arg1, arg2});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            if (target instanceof java.lang.SecurityException) {
                throw (java.lang.SecurityException)target;
            }
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static void checkPermission(java.lang.String arg1) throws java.lang.SecurityException {
        __init();
        try {
            __method5.invoke(null, new Object[] {arg1});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            if (target instanceof java.lang.SecurityException) {
                throw (java.lang.SecurityException)target;
            }
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    private static Class __clazz;
    private static Class __clazz6;
    private static Class __clazz7;
    private static void __init_classes() {
        try {
            __clazz6 = Class.forName("com.sun.j2me.security.AccessController", true, __cloader);
            __clazz = __clazz6;
            __clazz7 = Class.forName("com.sun.j2me.security.AccessControlContext", true, __cloader);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
