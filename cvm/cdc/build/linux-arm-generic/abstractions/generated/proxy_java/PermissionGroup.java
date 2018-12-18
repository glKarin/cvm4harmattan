/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.security;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.security.PermissionGroup
public final class PermissionGroup extends com_sun_j2me_proxy_security__ProxyBase {
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
                        __method1 = __clazz.getDeclaredMethod("getRuntimeDialogTitle", new Class[] {});
                        __method2 = __clazz.getDeclaredMethod("getRuntimeQuestion", new Class[] {});
                        __method3 = __clazz.getDeclaredMethod("getRuntimeOneshotQuestion", new Class[] {});
                        __method4 = __clazz.getDeclaredMethod("getSettingsQuestion", new Class[] {});
                        __method5 = __clazz.getDeclaredMethod("getDisableSettingChoice", new Class[] {});
                        __method6 = __clazz.getDeclaredMethod("getName", new Class[] {});
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
        return new PermissionGroup(com.sun.j2me.proxy.security.PermissionGroup.class, null, internal);
    }
    // Internal constructor
    public PermissionGroup(final Class cls, final String fieldName, final Object obj) {
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
    protected PermissionGroup() {
        __init();
    }
    public java.lang.String getRuntimeDialogTitle() {
        try {
            java.lang.String result = (java.lang.String)__method1.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getRuntimeQuestion() {
        try {
            java.lang.String result = (java.lang.String)__method2.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getRuntimeOneshotQuestion() {
        try {
            java.lang.String result = (java.lang.String)__method3.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getSettingsQuestion() {
        try {
            java.lang.String result = (java.lang.String)__method4.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getDisableSettingChoice() {
        try {
            java.lang.String result = (java.lang.String)__method5.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public java.lang.String getName() {
        try {
            java.lang.String result = (java.lang.String)__method6.invoke(__getInternal(), new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    private static Class __clazz;
    private static Class __clazz5;
    private static void __init_classes() {
        try {
            __clazz5 = Class.forName("com.sun.midp.security.PermissionGroup", true, __cloader);
            __clazz = __clazz5;
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
