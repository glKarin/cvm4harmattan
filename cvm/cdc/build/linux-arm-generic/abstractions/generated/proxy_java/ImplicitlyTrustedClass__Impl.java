/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.security;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.security.ImplicitlyTrustedClass
public /* abstract */  class ImplicitlyTrustedClass__Impl extends com_sun_j2me_proxy_security__ProxyBase implements com.sun.j2me.proxy.security.ImplicitlyTrustedClass {
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
        return new ImplicitlyTrustedClass__Impl(com.sun.j2me.proxy.security.ImplicitlyTrustedClass.class, null, internal);
    }
    // Internal constructor
    public ImplicitlyTrustedClass__Impl(final Class cls, final String fieldName, final Object obj) {
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
    protected ImplicitlyTrustedClass__Impl() {
        __init();
    }
    public static Object __getProxyClass(com.sun.j2me.proxy.security.ImplicitlyTrustedClass instance) {
        __init();
        final com.sun.j2me.proxy.security.ImplicitlyTrustedClass fInstance = instance;
        Object proxy = 
            Proxy.newProxyInstance(__cloader, 
                new Class[] {__clazz3}, 
                new InvocationHandler() {
                    private com.sun.j2me.proxy.security.ImplicitlyTrustedClass myInstance = fInstance;
                    private int hc = fInstance.hashCode() + 1;
                    public Object invoke(Object p, Method m, Object[] a) throws Throwable {
                        Class[] args = m.getParameterTypes();
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
    private static Class __clazz3;
    private static void __init_classes() {
        try {
            __clazz3 = Class.forName("com.sun.midp.security.ImplicitlyTrustedClass", true, __cloader);
            __clazz = __clazz3;
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
}
