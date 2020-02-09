#ifndef _KARIN_MIDLET_UTIL_H
#define _KARIN_MIDLET_UTIL_H

#include <QString>
#include <QList>
#include <QMap>

namespace karin
{
	typedef struct MIDlet_s
	{
		QString name;
		QString icon;
		QString midlet_class;
	} MIDlet_t;

	typedef QMap<int, MIDlet_t> MIDletMap_t;

	typedef struct MIDletManifest_s
	{
		QString version;
		QString vendor;
		QString name;
		QString icon;
		MIDletMap_t midlets;
	} MIDletManifest_t;

	typedef struct MIDletJad_s : MIDletManifest_s
	{
		QString jar_url;
		long jar_size;

		MIDletJad_s()
			: MIDletManifest_s(),
			jar_size(0)
		{
		}
	} MIDletJad_t;

	bool parse_jad(MIDletJad_t &ret, const QString &jadFile);
	bool parse_MANIFEST(MIDletManifest_t &ret, const QString &jar);
}

#endif
