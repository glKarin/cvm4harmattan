/*
 * Copyright  1990-2008 Sun Microsystems, Inc. All Rights Reserved.
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

#ifndef _JSR120_SIGNALS_H_
#define _JSR120_SIGNALS_H_

/**
 * Makes the thread sleeping
 */
void jsr120_wait_for_signal(int handle, int signal);

/**
 * Throws signal to wake up waiting threads
 */
void jsr120_throw_signal(int handle, int signal);

/**
 * Initializes signal system.
 */
void jsr120_init_signal();

/**
 * Finalizes signal system.
 */
void jsr120_finalize_signal();

#endif /* _JSR120_SIGNALS_H_ */
