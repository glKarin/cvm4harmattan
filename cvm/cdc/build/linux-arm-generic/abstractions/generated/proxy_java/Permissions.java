/*
 * Copyright  1990-2009 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
*/
/*
 * This is a generated file. Do not edit it!
 */
package com.sun.j2me.proxy.security;
import java.lang.reflect.*;
// Proxy class for com.sun.midp.security.Permissions
public final class Permissions extends com_sun_j2me_proxy_security__ProxyBase {
    public static final java.lang.String MIDP_PERMISSION_NAME = (String)__getValue("MIDP_PERMISSION_NAME");
    public static final java.lang.String AMS_PERMISSION_NAME = (String)__getValue("AMS_PERMISSION_NAME");
    public static final java.lang.String MANUFACTURER_DOMAIN_BINDING = (String)__getValue("MANUFACTURER_DOMAIN_BINDING");
    public static final java.lang.String OPERATOR_DOMAIN_BINDING = (String)__getValue("OPERATOR_DOMAIN_BINDING");
    public static final java.lang.String IDENTIFIED_DOMAIN_BINDING = (String)__getValue("IDENTIFIED_DOMAIN_BINDING");
    public static final java.lang.String UNIDENTIFIED_DOMAIN_BINDING = (String)__getValue("UNIDENTIFIED_DOMAIN_BINDING");
    public static final java.lang.String MINIMUM_DOMAIN_BINDING = (String)__getValue("MINIMUM_DOMAIN_BINDING");
    public static final java.lang.String MAXIMUM_DOMAIN_BINDING = (String)__getValue("MAXIMUM_DOMAIN_BINDING");
    public static final int MAX_LEVELS = __getIntValue("MAX_LEVELS");
    public static final int CUR_LEVELS = __getIntValue("CUR_LEVELS");
    public static final int MIDP = __getIntValue("MIDP");
    public static final int AMS = __getIntValue("AMS");
    public static final int HTTP = __getIntValue("HTTP");
    public static final int TCP = __getIntValue("TCP");
    public static final int HTTPS = __getIntValue("HTTPS");
    public static final int SSL = __getIntValue("SSL");
    public static final int TCP_SERVER = __getIntValue("TCP_SERVER");
    public static final int UDP = __getIntValue("UDP");
    public static final int UDP_SERVER = __getIntValue("UDP_SERVER");
    public static final int COMM = __getIntValue("COMM");
    public static final int PUSH = __getIntValue("PUSH");
    public static final int SMS_SERVER = __getIntValue("SMS_SERVER");
    public static final int CBS_SERVER = __getIntValue("CBS_SERVER");
    public static final int SMS_SEND = __getIntValue("SMS_SEND");
    public static final int SMS_RECEIVE = __getIntValue("SMS_RECEIVE");
    public static final int CBS_RECEIVE = __getIntValue("CBS_RECEIVE");
    public static final int MM_RECORD = __getIntValue("MM_RECORD");
    public static final int MM_IMAGE_CAPTURING = __getIntValue("MM_IMAGE_CAPTURING");
    public static final int MMS_SERVER = __getIntValue("MMS_SERVER");
    public static final int MMS_SEND = __getIntValue("MMS_SEND");
    public static final int MMS_RECEIVE = __getIntValue("MMS_RECEIVE");
    public static final int APDU_CONNECTION = __getIntValue("APDU_CONNECTION");
    public static final int JCRMI_CONNECTION = __getIntValue("JCRMI_CONNECTION");
    public static final int SIGN_SERVICE = __getIntValue("SIGN_SERVICE");
    public static final int APDU_CHANNEL0 = __getIntValue("APDU_CHANNEL0");
    public static final int CHAPI_REGISTER = __getIntValue("CHAPI_REGISTER");
    public static final int PIM_CONTACT_READ = __getIntValue("PIM_CONTACT_READ");
    public static final int PIM_CONTACT_WRITE = __getIntValue("PIM_CONTACT_WRITE");
    public static final int PIM_EVENT_READ = __getIntValue("PIM_EVENT_READ");
    public static final int PIM_EVENT_WRITE = __getIntValue("PIM_EVENT_WRITE");
    public static final int PIM_TODO_READ = __getIntValue("PIM_TODO_READ");
    public static final int PIM_TODO_WRITE = __getIntValue("PIM_TODO_WRITE");
    public static final int FILE_CONNECTION_READ = __getIntValue("FILE_CONNECTION_READ");
    public static final int FILE_CONNECTION_WRITE = __getIntValue("FILE_CONNECTION_WRITE");
    public static final int OBEX_CLIENT = __getIntValue("OBEX_CLIENT");
    public static final int OBEX_SERVER = __getIntValue("OBEX_SERVER");
    public static final int TCP_OBEX_CLIENT = __getIntValue("TCP_OBEX_CLIENT");
    public static final int TCP_OBEX_SERVER = __getIntValue("TCP_OBEX_SERVER");
    public static final int BLUETOOTH_CLIENT = __getIntValue("BLUETOOTH_CLIENT");
    public static final int BLUETOOTH_SERVER = __getIntValue("BLUETOOTH_SERVER");
    public static final int LOCATION = __getIntValue("LOCATION");
    public static final int ORIENTATION = __getIntValue("ORIENTATION");
    public static final int LOCATION_PROXIMITY = __getIntValue("LOCATION_PROXIMITY");
    public static final int LANDMARK_READ = __getIntValue("LANDMARK_READ");
    public static final int LANDMARK_WRITE = __getIntValue("LANDMARK_WRITE");
    public static final int LANDMARK_CATEGORY = __getIntValue("LANDMARK_CATEGORY");
    public static final int LANDMARK_MANAGE = __getIntValue("LANDMARK_MANAGE");
    public static final int SIP = __getIntValue("SIP");
    public static final int SIPS = __getIntValue("SIPS");
    public static final int PAYMENT = __getIntValue("PAYMENT");
    public static final int AMMS_CAMERA_SHUTTERFEEDBACK = __getIntValue("AMMS_CAMERA_SHUTTERFEEDBACK");
    public static final int AMMS_TUNER_SETPRESET = __getIntValue("AMMS_TUNER_SETPRESET");
    public static final int SENSOR = __getIntValue("SENSOR");
    public static final int PRIVATE_SENSOR = __getIntValue("PRIVATE_SENSOR");
    public static final int PROTECTED_SENSOR = __getIntValue("PROTECTED_SENSOR");
    public static final byte NEVER = __getByteValue("NEVER");
    public static final byte ALLOW = __getByteValue("ALLOW");
    public static final byte BLANKET_GRANTED = __getByteValue("BLANKET_GRANTED");
    public static final byte BLANKET = __getByteValue("BLANKET");
    public static final byte SESSION = __getByteValue("SESSION");
    public static final byte ONESHOT = __getByteValue("ONESHOT");
    public static final byte SESSION_GRANTED = __getByteValue("SESSION_GRANTED");
    public static final byte SESSION_DENIED = __getByteValue("SESSION_DENIED");
    public static final byte SESSION_UNKNOWN = __getByteValue("SESSION_UNKNOWN");
    public static final byte BLANKET_DENIED = __getByteValue("BLANKET_DENIED");
    public static final int NUMBER_OF_PERMISSIONS = __getIntValue("NUMBER_OF_PERMISSIONS");
    private static Method __method1;
    private static Method __method2;
    private static Method __method3;
    private static Method __method4;
    private static Method __method5;
    private static Method __method6;
    private static Method __method7;
    private static Method __method8;
    private static Method __method9;
    private static Method __method10;
    private static Method __method11;
    private static Method __method12;
    private static Method __method13;
    private static Method __method14;
    private static Constructor __cons15;
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
                        __method1 = __clazz.getDeclaredMethod("getTitle", new Class[] {int.class});
                        __method2 = __clazz.getDeclaredMethod("getQuestion", new Class[] {int.class});
                        __method3 = __clazz.getDeclaredMethod("getOneshotQuestion", new Class[] {int.class});
                        __method4 = __clazz.getDeclaredMethod("getUnsignedDomain", new Class[] {});
                        __method5 = __clazz.getDeclaredMethod("getEmptySet", new Class[] {});
                        __method6 = __clazz.getDeclaredMethod("getSettingGroups", new Class[] {byte[].class});
                        __method7 = __clazz.getDeclaredMethod("getPermissionGroupLevel", new Class[] {byte[].class, __clazz5});
                        __method8 = __clazz.getDeclaredMethod("setPermissionGroup", new Class[] {byte[].class, int.class, byte.class});
                        __method9 = __clazz.getDeclaredMethod("setPermissionGroup", new Class[] {byte[].class, byte.class, __clazz5, byte.class});
                        __method10 = __clazz.getDeclaredMethod("checkPushInterruptLevel", new Class[] {byte[].class, byte.class});
                        __method11 = __clazz.getDeclaredMethod("forDomain", new Class[] {java.lang.String.class});
                        __method12 = __clazz.getDeclaredMethod("getName", new Class[] {int.class});
                        __method13 = __clazz.getDeclaredMethod("getId", new Class[] {java.lang.String.class});
                        __method14 = __clazz.getDeclaredMethod("isTrusted", new Class[] {java.lang.String.class});
                        __cons15 = __clazz.getDeclaredConstructor(new Class[] {});
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
        return new Permissions(com.sun.j2me.proxy.security.Permissions.class, null, internal);
    }
    // Internal constructor
    public Permissions(final Class cls, final String fieldName, final Object obj) {
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
    public static java.lang.String getTitle(int arg1) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method1.invoke(null, new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getQuestion(int arg1) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method2.invoke(null, new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getOneshotQuestion(int arg1) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method3.invoke(null, new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getUnsignedDomain() {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method4.invoke(null, new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static byte[] getEmptySet() {
        __init();
        try {
            byte[] result = (byte[])__method5.invoke(null, new Object[] {});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static com.sun.j2me.proxy.security.PermissionGroup[] getSettingGroups(byte[] arg1) {
        __init();
        try {
            Object result = __method6.invoke(null, new Object[] {arg1});
            if (result == null) {
                return (com.sun.j2me.proxy.security.PermissionGroup[])null;
            }
            com.sun.j2me.proxy.security.PermissionGroup[] retArray = new com.sun.j2me.proxy.security.PermissionGroup[((Object[])result).length];
            for (int i0 = 0; i0 < ((Object[])result).length; i0++) {
                if (((Object[])result)[i0] == null) {
                    retArray[i0] = null;
                } else {
                    retArray[i0] = (com.sun.j2me.proxy.security.PermissionGroup)com.sun.j2me.proxy.security.PermissionGroup.__getInstance(((Object[])result)[i0]);
                }
            } // for i0
            return (com.sun.j2me.proxy.security.PermissionGroup[])retArray;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static byte getPermissionGroupLevel(byte[] arg1, com.sun.j2me.proxy.security.PermissionGroup arg2) {
        __init();
        try {
            java.lang.Byte result = (java.lang.Byte)__method7.invoke(null, new Object[] {arg1, (arg2 == null ? null : (((com.sun.j2me.proxy.security.PermissionGroup)arg2).__getInternal()))});
            return result.byteValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static void setPermissionGroup(byte[] arg1, int arg2, byte arg3) throws java.lang.SecurityException {
        __init();
        try {
            __method8.invoke(null, new Object[] {arg1, new java.lang.Integer(arg2), new java.lang.Byte(arg3)});
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
    public static void setPermissionGroup(byte[] arg1, byte arg2, com.sun.j2me.proxy.security.PermissionGroup arg3, byte arg4) throws java.lang.SecurityException {
        __init();
        try {
            __method9.invoke(null, new Object[] {arg1, new java.lang.Byte(arg2), (arg3 == null ? null : (((com.sun.j2me.proxy.security.PermissionGroup)arg3).__getInternal())), new java.lang.Byte(arg4)});
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
    public static void checkPushInterruptLevel(byte[] arg1, byte arg2) throws java.lang.SecurityException {
        __init();
        try {
            __method10.invoke(null, new Object[] {arg1, new java.lang.Byte(arg2)});
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
    public static byte[][] forDomain(java.lang.String arg1) {
        __init();
        try {
            byte[][] result = (byte[][])__method11.invoke(null, new Object[] {arg1});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static java.lang.String getName(int arg1) {
        __init();
        try {
            java.lang.String result = (java.lang.String)__method12.invoke(null, new Object[] {new java.lang.Integer(arg1)});
            return result;
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static int getId(java.lang.String arg1) {
        __init();
        try {
            java.lang.Integer result = (java.lang.Integer)__method13.invoke(null, new Object[] {arg1});
            return result.intValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public static boolean isTrusted(java.lang.String arg1) {
        __init();
        try {
            java.lang.Boolean result = (java.lang.Boolean)__method14.invoke(null, new Object[] {arg1});
            return result.booleanValue();
        } catch (IllegalAccessException iae) {
            throw new RuntimeException(iae);
        } catch (InvocationTargetException ite) {
            Throwable target = ite.getTargetException();
            throw new RuntimeException("Unreported exception:" + target.toString());
        }
    }
    public Permissions() {
        __init();
        try {
            __setInternal(__cons15.newInstance(new Object[] {}));
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
    private static Class __clazz4;
    private static Class __clazz5;
    private static void __init_classes() {
        try {
            __clazz4 = Class.forName("com.sun.midp.security.Permissions", true, __cloader);
            __clazz = __clazz4;
            __clazz5 = Class.forName("com.sun.midp.security.PermissionGroup", true, __cloader);
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e.toString() + " ClassLoader="+(__cloader==null?"null":__cloader.getClass().getName()),e);
        }
    }
    public static Class __getMyClass() {
        __init();
        return __clazz;
    }
    static int __getIntValue(final String fieldName) {
        __init();
            Integer ret_val = (Integer)
java.security.AccessController.doPrivileged(new java.security.PrivilegedAction() {                public Object run() {
                    try {
                        return (Object) new Integer(__clazz.getField(fieldName).getInt(null));
                    } catch (IllegalAccessException iae) {
                        throw new RuntimeException(iae);
                    } catch (NoSuchFieldException nsfe) {
                        throw new RuntimeException(nsfe);
                    }
                } // run()
            }); // doPrivileged()
            return ret_val.intValue();
    }
    static java.lang.String __getValue(final String fieldName) {
        __init();
            java.lang.String ret_val = (java.lang.String)
java.security.AccessController.doPrivileged(new java.security.PrivilegedAction() {                public Object run() {
                    try {
                        return (Object)__clazz.getField(fieldName).get(null);
                    } catch (IllegalAccessException iae) {
                        throw new RuntimeException(iae);
                    } catch (NoSuchFieldException nsfe) {
                        throw new RuntimeException(nsfe);
                    }
                } // run()
            }); // doPrivileged()
            return ret_val;
    }
    static byte __getByteValue(final String fieldName) {
        __init();
            Byte ret_val = (Byte)
java.security.AccessController.doPrivileged(new java.security.PrivilegedAction() {                public Object run() {
                    try {
                        return (Object) new Byte(__clazz.getField(fieldName).getByte(null));
                    } catch (IllegalAccessException iae) {
                        throw new RuntimeException(iae);
                    } catch (NoSuchFieldException nsfe) {
                        throw new RuntimeException(nsfe);
                    }
                } // run()
            }); // doPrivileged()
            return ret_val.byteValue();
    }
}
