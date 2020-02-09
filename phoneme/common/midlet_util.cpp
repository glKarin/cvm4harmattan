#include "midlet_util.h"

#include <QTextStream>
#include <QFile>
#include <QStringList>

#include <stdlib.h>

#include "zip_util.h"

namespace karin
{
	bool parse_jad(MIDletJad_t &ret, const QString &jadFile)
	{
		bool suc;
		int pos;
		QFile file(jadFile);

		suc = file.open(QIODevice::ReadOnly);
		if(!suc)
			return false;
		QStringList lines;
		QTextStream stream(&file);
		while(!stream.atEnd())
		{
			QString line = stream.readLine();
			if(line.isEmpty())
				continue;
			if(line.startsWith(" "))
			{
				if(!lines.isEmpty())
				{
					lines[lines.size() - 1] += line.trimmed();
					continue;
				}
			}
			lines.push_back(line);
		}
		Q_FOREACH(const QString &line, lines)
		{
			pos = line.indexOf(':');
			if(pos == -1)
				continue;
			QString name = line.left(pos);
			QString value = line.right(line.length() - pos - 1).trimmed();
			//qDebug() << name << value;
			if(name == "MIDlet-Version")
				ret.version = value;
			else if(name == "MIDlet-Jar-Size")
				ret.jar_size = value.toLong();
			else if(name == "MIDlet-Vendor")
				ret.vendor = value;
			else if(name == "MIDlet-Name")
				ret.name = value;
			else if(name == "MIDlet-Jar-URL")
				ret.jar_url = value;
			else if(name == "MIDlet-Icon")
				ret.icon = value;
			else if(name.indexOf(QRegExp("MIDlet-\\d+")) == 0)
			{
				QString numStr = name.mid(7);
				QStringList valueList = value.split(',');
				if(valueList.isEmpty())
					continue;
				MIDlet_t m;
				QString str = valueList.takeFirst();
				if(!str.isEmpty())
					m.name = str.trimmed();
				str = valueList.isEmpty() ? QString::null : valueList.takeFirst();
				if(!str.isEmpty())
					m.icon = str.trimmed();
				str = valueList.isEmpty() ? QString::null : valueList.takeFirst();
				if(!str.isEmpty())
					m.midlet_class = str.trimmed();

				ret.midlets.insert(numStr.toInt(), m);
			}
		}
		file.close();
		return true;
	}

	bool parse_MANIFEST(MIDletManifest_t &ret, const QString &jar)
	{
#define _MAINFEST "META-INF/MANIFEST.MF"
		int size;
		char *data;
		int pos;

		size = 0;
		data = unzip_file(jar.toStdString().c_str(), _MAINFEST, &size);
		if(!data)
			return false;

		QString text(QByteArray(data).trimmed());
		QTextStream stream(&text);
		QStringList lines;
		pos = 0;
		//qDebug() << bytes << size << text << text.length();
		while(!stream.atEnd())
		{
			QString line = stream.readLine();
			if(line.isEmpty())
				continue;
			if(line.startsWith(" "))
			{
				if(!lines.isEmpty())
				{
					lines[lines.size() - 1] += line.trimmed();
					continue;
				}
			}
			lines.push_back(line);
		}
		Q_FOREACH(const QString &line, lines)
		{
			pos = line.indexOf(':');
			if(pos == -1)
				continue;
			QString name = line.left(pos);
			QString value = line.right(line.length() - pos - 1).trimmed();
			//qDebug() << name << value;
			if(name == "MIDlet-Version")
				ret.version = value;
			else if(name == "MIDlet-Vendor")
				ret.vendor = value;
			else if(name == "MIDlet-Name")
				ret.name = value;
			else if(name == "MIDlet-Icon")
				ret.icon = value;
			else if(name.indexOf(QRegExp("MIDlet-\\d+")) == 0)
			{
				QString numStr = name.mid(7);
				QStringList valueList = value.split(',');
				if(valueList.isEmpty())
					continue;
				MIDlet_t m;
				QString str = valueList.takeFirst();
				if(!str.isEmpty())
					m.name = str.trimmed();
				str = valueList.isEmpty() ? QString::null : valueList.takeFirst();
				if(!str.isEmpty())
					m.icon = str.trimmed();
				str = valueList.isEmpty() ? QString::null : valueList.takeFirst();
				if(!str.isEmpty())
					m.midlet_class = str.trimmed();

				ret.midlets.insert(numStr.toInt(), m);
			}
		}

		free(data);
		return true;
#undef _MAINFEST
	}

}
