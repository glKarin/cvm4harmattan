/*
 * Copyright  1990-2006 Sun Microsystems, Inc. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation. 
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt). 
 * 
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA 
 * 
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa
 * Clara, CA 95054 or visit www.sun.com if you need additional
 * information or have any questions.
 */

/*
 * NOTICE: Portions Copyright (c) 2007-2010 Davy Preuveneers.
 * This file has last been modified by Davy Preuveneers on 2010-02-23. The
 * changes are licensed under the terms of the GNU General Public
 * License version 2. This notice was added to meet the conditions of
 * Section 3.a of the GNU General Public License version 2.
 */

package com.sun.j2me.app;

/**
 * Abstraction for application model
 */
public class AppModel{

    private AppModel() {
    }

    public final static int MIDLET = 0;
    public final static int XLET = 1;
    public final static int UNKNOWN_MODEL = 2;

    public static int getAppModel() {
        return MIDLET;
    }
}
