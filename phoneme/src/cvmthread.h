/*
 * Copyright  2012 Davy Preuveneers. All Rights Reserved.
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
 */

#ifndef CVMTHREAD_H
#define CVMTHREAD_H

#include <QThread>
#include <QtCore>

void cvm_exec();

class CVMThread : public QThread
{
    Q_OBJECT

#ifdef _HARMATTAN
		public Q_SLOTS:
		void Finish(bool sync = false);
#endif
private:
    void run();
};
#endif // CVMTHREAD_H
