#ifndef _KARIN_MACROS_H
#define _KARIN_MACROS_H

#define ID_FOREACH(C, c) \
	for(C::iterator itor = c.begin(); itor != c.end(); ++itor)
#define ID_CONST_FOREACH(C, c) \
	for(C::const_iterator itor = c.constBegin(); itor != c.constEnd(); ++itor)

#ifdef _DEBUG
#define ID_QOBJECT_DESTROY_DEBUG qDebug() << objectName();
#define ID_DESTROY_DEBUG(x) qDebug() << #x;
#else
#define ID_QOBJECT_DESTROY_DEBUG
#define ID_DESTROY_DEBUG(x)
#endif

#endif
