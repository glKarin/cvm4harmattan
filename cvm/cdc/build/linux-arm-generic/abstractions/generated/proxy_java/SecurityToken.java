/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.security;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.security.SecurityToken
public final class SecurityToken extends com_sun_j2me_proxy_security__ProxyBase {
    public static final java.lang.String STD_EX_MSG = "Application not authorized to access the restricted API";
    private static Method __method1;
    private static Method __method2;
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
                        __method1 = __clazz.getDeclaredMethod("checkIfPermissionAllowed", new Class[] {java.lang.String.class});
                        __method2 = __clazz.getDeclaredMethod("checkIfPermissionAllowed", new Class[] {int.class});
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
        return new SecurityToken(com.sun.j2me.proxy.security.SecurityToken.class, null, internal);
    }
    // Internal constructor
    public SecurityToken(final Class cls, final String fieldName, final Object obj) {
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
    protected SecurityToken() {
        __init();
    }
    public void checkIfPermissionAllowed(java.lang.String arg1) {
        try {
            __method1.invoke(__getInternal(), new Object[] {arg1});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public void checkIfPermissionAllowed(int arg1) {
        try {
            __method2.invoke(__getInternal(), new Object[] {new java.lang.Integer(arg1)});
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    private static Class __clazz;
    private static Class __clazz1;
    private static void __init_classes() {
        try {
            __clazz1 = Class.forName("com.sun.midp.security.SecurityToken", true, __cloader);
            __clazz = __clazz1;
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
