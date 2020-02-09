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

#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QDebug>

#include "framebuffer.h"
#include "cvmthread.h"
#include "main.h"

#define SURFACE_WIDTH       854
#define SURFACE_HEIGHT      480 // 424

#ifdef _HARMATTAN
int width = 800;            // N900: 800, N9: 854
int height = 480;           // N900: 424, N9: 376
int input_ready = 0;
int enable_state_change = 0;
#else
static int width = 800;            // N900: 800, N9: 854
static int height = 480;           // N900: 424, N9: 376
static int input_ready = 0;
static int enable_state_change = 0;
#endif
static int midlet_argc;
static char **midlet_argv;

static FrameBuffer *fb = NULL;

static CVMThread thread;

#ifdef _HARMATTAN
bool fullscreen = true;
bool rotate = false;
bool antialias = true;
bool bitmapfont = false;
bool errorlog = false;
bool sip = false;
#else
static bool fullscreen = true;
static bool rotate = false;
static bool antialias = true;
static bool bitmapfont = false;
static bool errorlog = false;
static bool sip = false;
#endif

#ifdef _HARMATTAN
#include "defs.h"
#include "cvm.h"
#include "common/midlet_util.h"

QString global_midlet_name;
QString global_midlet_icon;
int global_midlet_index = 1;

QString global_jar_file;
QString global_jad_file;
QString global_midlet_class;
int global_orientation = karin::OrientationType_Auto;
bool global_full_framebuffer = false;
int global_vkb_type = karin::VKBType_Disable;
bool global_vkb_translucent = true;
unsigned int global_debug = 0;
int global_buffer_width = DEFAULT_DEVICE_SCREEN_WIDTH;
int global_buffer_height = DEFAULT_DEVICE_SCREEN_HEIGHT;
int global_keyboard_scheme = karin::KeyboardScheme_T9_Inverse;
int global_paint_scheme = karin::FillType_Fill;
qreal global_keyboard_opacity = 1.0;
QString global_framebuffer_background_color("#000000");
QString global_render_system("native");

void validate_global_variant()
{
	if(global_vkb_type < 0 || global_vkb_type >= karin::VKBType_total)
		global_vkb_type = karin::VKBType_Disable;
	if(global_orientation < 0 || global_orientation >= karin::OrientationType_total)
		global_orientation = karin::OrientationType_Auto;
	if(global_keyboard_scheme < 0 || global_keyboard_scheme >= karin::KeyboardScheme_total)
		global_keyboard_scheme = karin::KeyboardScheme_T9;
	if(global_buffer_width <= 0)
		global_buffer_width = DEFAULT_DEVICE_SCREEN_WIDTH;
	if(global_buffer_height <= 0)
		global_buffer_height = DEFAULT_DEVICE_SCREEN_HEIGHT;
	if(global_paint_scheme < 0 || global_paint_scheme >= karin::FillType_total)
		global_paint_scheme = karin::FillType_Fill;
	if(global_keyboard_opacity <= 0.0 || global_keyboard_opacity > 1.0)
		global_keyboard_opacity = 1.0;
}

static bool read_opt(const QStringList &args, const QString &name, QVariant *flag = 0)
{
	bool suc;
	int len;
	QString shortName;
	QString longName;

	if(name.startsWith("--"))
	{
		longName = name;
		shortName = name.mid(1);
	}
	else if(name.startsWith("-"))
	{
		shortName = name;
		longName = '-' + name;
	}
	else
	{
		shortName = '-' + name;
		longName = "--" + name;
	}

	suc = false;
	len = args.size();
	for(int i = 0; i < len; i++)
	{
		if(args[i] == shortName)
		{
			if(i + 1 < len)
			{
				QString value = args[i + 1];
				if(value.startsWith('-') || value.startsWith("--")) // no value
				{
					if(flag)
						*flag = QVariant();
				}
				else
				{
					if(flag)
						*flag = value;
				}
			}
			else
			{
				if(flag)
					*flag = QVariant();
			}
			suc = true;
			break;
		}
		else if(args[i].startsWith(longName + '='))
		{
			if(longName.length() + 1 < args[i].length()) // has value
			{
				QString value = args[i].right(args[i].length() - longName.length() - 1);
				if(flag)
					*flag = value;
			}
			else
			{
				if(flag)
					*flag = QVariant();
			}
			suc = true;
			break;
		}
		else
			continue;
	}
	
	return suc;
}

template <class T>
static bool read_opt(const QStringList &args, const QString &name, T *flag = 0)
{
	QVariant tmp;
	bool suc;

	suc = read_opt(args, name, flag ? &tmp : 0);
	if(suc && flag)
	{
		*flag = tmp.value<T>();
	}
	return suc;
}

static bool get_opt(QStringList &args, const QString &name, int has_arg = 0, QVariant *flag = 0, const QVariant &val = QVariant())
{
	bool suc;
	int i;
	int start, used;
	int len;
	QString shortName;
	QString longName;

	if(name.startsWith("--"))
	{
		longName = name;
		shortName = name.mid(1);
	}
	else if(name.startsWith("-"))
	{
		shortName = name;
		longName = '-' + name;
	}
	else
	{
		shortName = '-' + name;
		longName = "--" + name;
	}
	start = 0;
	used = 0;
	suc = false;
	len = args.size();
	for(i = 0; i < len; i++)
	{
		if(has_arg == 0)
		{
			if(args[i] != shortName)
				continue;
			start = i;
			used = 1;
			suc = true;
			break;
		}
		else if(has_arg == 2)
		{
			if(args[i] == shortName)
			{
				if(i + 1 < len)
				{
					QString value = args[i + 1];
					if(value.startsWith('-') || value.startsWith("--")) // no value
					{
						if(flag)
							*flag = val;
						start = i;
						used = 1;
					}
					else
					{
						if(flag)
							*flag = value;
						start = i;
						used = 2;
					}
				}
				else
				{
					if(flag)
						*flag = val;
					start = i;
					used = 1;
				}
				suc = true;
				break;
			}
			else if(args[i].startsWith(longName + '='))
			{
				if(longName.length() + 1 < args[i].length()) // no value
				{
					QString value = args[i].right(args[i].length() - longName.length() - 1);
					if(flag)
						*flag = value;
					start = i;
					used = 1;
				}
				else
				{
					if(flag)
						*flag = val;
					start = i;
					used = 1;
				}
				suc = true;
				break;
			}
			else
				continue;
		}
		else
		{
			if(args[i] == shortName)
			{
				if(i + 1 < len)
				{
					QString value = args[i + 1];
					if(value.startsWith('-') || value.startsWith("--")) // no value
					{
						start = i; // remove it
						used = 1;
					}
					else
					{
						if(flag)
							*flag = value;
						start = i;
						used = 2;
						suc = true;
					}
				}
				else
				{
					start = i; // remove it
					used = 1;
				}
				break;
			}
			else if(args[i].startsWith(longName + '='))
			{
				if(longName.length() + 1 < args[i].length()) // no value
				{
					QString value = args[i].right(args[i].length() - longName.length() - 1);
					if(flag)
						*flag = value;
					start = i;
					used = 1;
					suc = true;
				}
				else
				{
					start = i; // remove it
					used = 1;
				}
				break;
			}
			else
				continue;
		}
	}

	if(1 || suc)
	{
		for(int m = 0; m < used; m++)
		{
			args.removeAt(start);
		}
	}
	
	return suc;
}

template <class T>
static bool get_opt(QStringList &args, const QString &name, int has_arg = 0, T *flag = 0, const T &val = T())
{
	QVariant tmp;
	bool suc;

	suc = get_opt(args, name, has_arg, flag ? &tmp : 0, val);
	if(suc && flag)
	{
		*flag = tmp.value<T>();
	}
	return suc;
}

static bool set_opt(QStringList &args, const QString &name, int has_arg = 0, const QVariant &val = QVariant(), QVariant *flag = 0)
{
	bool suc;
	int i;
	int len;
	bool has;
	bool mixed;

	mixed = name.startsWith("--");
	has = false;
	suc = false;
	len = args.size();
	for(i = 0; i < len; i++)
	{
		if(has_arg == 0)
		{
			if(args[i] != name)
				continue;
			has = true;
			break;
		}
		else if(has_arg == 2)
		{
			if(args[i] == name)
			{
				if(i + 1 < len)
				{
					QString value = args[i + 1];
					if(value.startsWith('-') || value.startsWith("--")) // no value
					{
						if(flag)
							*flag = QVariant();
						if(val.isValid())
						{
							args.insert(i, val.toString());
							suc = true;
						}
					}
					else
					{
						if(flag)
							*flag = value;
						if(val.isValid())
						{
							QString newValue(val.toString());
							if(newValue != value)
							{
								args.replace(i + 1, newValue);
								suc = true;
							}
						}
						else
						{
							args.removeAt(i + 1);
							suc = true;
						}
					}
				}
				else
				{
					if(flag)
						*flag = QVariant();
					if(val.isValid())
					{
						args.insert(i, val.toString());
						suc = true;
					}
				}
				has = true;
				break;
			}
			else if(args[i].startsWith(name + '='))
			{
				if(name.length() + 1 < args[i].length()) // has value
				{
					QString value = args[i].right(args[i].length() - name.length() - 1);
					if(flag)
						*flag = value;
					if(val.isValid())
					{
						QString newValue(val.toString());
						if(newValue != value)
						{
							args.replace(i, name + '=' + newValue);
							suc = true;
						}
					}
					else
					{
						args.replace(i, name + '=');
						suc = true;
					}
				}
				else
				{
					if(flag)
						*flag = QVariant();
					if(val.isValid())
					{
						args.replace(i, name + '=' + val.toString());
						suc = true;
					}
				}
				has = true;
				break;
			}
			else
				continue;
		}
		else
		{
			if(args[i] == name)
			{
				if(i + 1 < len)
				{
					QString value = args[i + 1];
					if(value.startsWith('-') || value.startsWith("--")) // no value
					{
						if(flag)
							*flag = QVariant();
						args.insert(i, val.toString());
						suc = true;
					}
					else
					{
						if(flag)
							*flag = value;
						QString newValue(val.toString());
						if(value != newValue)
						{
							args.replace(i + 1, newValue);
							suc = true;
						}
					}
				}
				else
				{
					if(flag)
						*flag = QVariant();
					args.insert(i, val.toString());
					suc = true;
				}
				has = true;
				break;
			}
			else if(args[i].startsWith(name + '='))
			{
				if(name.length() + 1 < args[i].length()) // has value
				{
					QString value = args[i].right(args[i].length() - name.length() - 1);
					if(flag)
						*flag = value;
					QString newValue(val.toString());
					if(newValue != value)
					{
						args.replace(i, name + '=' + newValue);
						suc = true;
					}
				}
				else
				{
					if(flag)
						*flag = QVariant();
					args.replace(i, name + '=' + val.toString());
					suc = true;
				}
				has = true;
				break;
			}
			else
				continue;
		}
	}

	if(!has)
	{
		if(has_arg == 0)
			args.push_back(name);
		else if(has_arg == 2)
		{
			if(mixed)
				args.push_back(name + '=' + (val.isValid() ? val.toString() : ""));
			else
			{
				if(val.isValid())
					args << name << val.toString();
			}
		}
		else
		{
			if(mixed)
				args.push_back(name + '=' + val.toString());
			else
				args << name << val.toString();
		}
	}
	
	return suc;
}

template <class T>
static bool set_opt(QStringList &args, const QString &name, int has_arg = 0, const T &val = T(), T *flag = 0)
{
	QVariant tmp;
	bool suc;

	suc = set_opt(args, name, has_arg, val, flag ? &tmp : 0);
	if(suc && flag)
	{
		*flag = tmp.value<T>();
	}
	return suc;
}


void parse_options(int argc, char *argv[])
{
#define _ARG_PREFIX "harm-"
#define MIDP_PATH "/home/user/cvm/cvm/cdc/build/linux-arm-generic/midp"
	int index;
	bool suc;
	QStringList args; // = QCoreApplication::arguments();
	bool jad_readed;

	suc = false;
	jad_readed = false;
	for(int i = 0; i < argc; i++)
		args.push_back(argv[i]);
	//qDebug() << args;

	args.removeAll("-graphicssystem");
	args.removeAll("-raster");
	if(args.size() == 2)
	{
		QString arg1 = args.takeLast();
		QFileInfo fi(arg1);
		if(fi.suffix().compare("jad", Qt::CaseInsensitive) == 0)
			global_jad_file = arg1;
		else
			global_jar_file = arg1;
		args << "-Xmx12m"
			<< "-Dmicroedition.profiles=MIDP-2.1"
			<< "-Dmicroedition.location.version=1.0"
			<< "-Dsun.midp.library.name=midp"
			<< "-Dsun.midp.home.path=" MIDP_PATH "/midp_linux_fb_gcc"
			<< "-Dcom.sun.midp.mainClass.name=com.sun.midp.main.CdcMIDletSuiteLoader"
			<< "sun.misc.MIDPLauncher"
			;
	}
	else
	{
		if(get_opt(args, _ARG_PREFIX "software-render"))
			global_render_system = "raster";
		get_opt<int>(args, _ARG_PREFIX "keyboard-scheme", 1, &global_keyboard_scheme, karin::KeyboardScheme_T9);
		global_vkb_translucent = get_opt(args, _ARG_PREFIX "vkb-translucent");
		get_opt<int>(args, _ARG_PREFIX "paint-scheme", 1, &global_paint_scheme, karin::FillType_Fill);
		get_opt<int>(args, _ARG_PREFIX "screen-orientation", 1, &global_orientation, karin::OrientationType_Auto);
		get_opt<int>(args, _ARG_PREFIX "vkb-type", 1, &global_vkb_type, karin::VKBType_Disable);
		get_opt<unsigned int>(args, _ARG_PREFIX "debug", 2, &global_debug, 0);
		fullscreen = !get_opt(args, _ARG_PREFIX "no-fullscreen");
		global_full_framebuffer = get_opt(args, _ARG_PREFIX "full-framebuffer");
		get_opt<int>(args, _ARG_PREFIX "buffer-width", 1, &global_buffer_width, DEFAULT_DEVICE_SCREEN_WIDTH);
		get_opt<int>(args, _ARG_PREFIX "buffer-height", 1, &global_buffer_height, DEFAULT_DEVICE_SCREEN_HEIGHT);
		get_opt<QString>(args, _ARG_PREFIX "background-color", 1, &global_framebuffer_background_color, "#000000");
		get_opt<qreal>(args, _ARG_PREFIX "keyboard-opacity", 1, &global_keyboard_opacity, 1.0);

		// for old version
		index = args.indexOf("-fullscreen");
		if(index != -1)
		{
			fullscreen = true;
			args.removeAt(index);
		}
		index = args.indexOf("-nofullscreen");
		if(index != -1)
		{
			fullscreen = false;
			args.removeAt(index);
		}
		index = args.indexOf("-rotate");
		if(index != -1)
		{
			rotate = true;
			args.removeAt(index);
		}
		index = args.indexOf("-portrait");
		if(index != -1)
		{
			rotate = true;
			args.removeAt(index);
		}
		index = args.indexOf("-norotate");
		if(index != -1)
		{
			rotate = false;
			args.removeAt(index);
		}
		index = args.indexOf("-noportrait");
		if(index != -1)
		{
			rotate = false;
			args.removeAt(index);
		}
		index = args.indexOf("-bitmapfont");
		if(index != -1)
		{
			bitmapfont = true;
			args.removeAt(index);
		}
		index = args.indexOf("-nobitmapfont");
		if(index != -1)
		{
			bitmapfont = false;
			args.removeAt(index);
		}
		index = args.indexOf("-antialias");
		if(index != -1)
		{
			antialias = true;
			args.removeAt(index);
		}
		index = args.indexOf("-noantialias");
		if(index != -1)
		{
			antialias = false;
			args.removeAt(index);
		}

		suc = read_opt<QString>(args, "suitepath", &global_jar_file);
		if(!suc)
			get_opt<QString>(args, _ARG_PREFIX "jar", 1, &global_jar_file);
		suc = read_opt<QString>(args, "jadpath", &global_jad_file);
		if(!suc)
			get_opt<QString>(args, _ARG_PREFIX "jad", 1, &global_jad_file);
		suc = read_opt<QString>(args, "1", &global_midlet_class); // only first main midlet class
		if(!suc)
			get_opt<QString>(args, _ARG_PREFIX "midlet", 1, &global_midlet_class);
	}
	get_opt<int>(args, _ARG_PREFIX "midlet-no", 1, &global_midlet_index, 1);

	//qDebug() << args;
	// if jad is set, if jar is empty, find jar in jad directory, if midlet class is empty, find midlet class in jar or jad.
	karin::MIDletJad_t jad;
	if(!global_jad_file.isEmpty())
	{
		if(global_jar_file.isEmpty())
		{
			QFileInfo fileinfo(global_jad_file);
			QString basename = fileinfo.baseName();
			QString path = fileinfo.absolutePath();
			global_jar_file = path + '/' + basename + ".jar"; // check exists?
			set_opt(args, "-suitepath", 1, global_jar_file);
		}
		if(global_midlet_class.isEmpty())
		{
			suc = karin::parse_MANIFEST(jad, global_jar_file) || karin::parse_jad(jad, global_jad_file);
			if(suc && !jad.midlets.isEmpty())
			{
				const karin::MIDlet_t &first = jad.midlets.contains(global_midlet_index) ? jad.midlets[global_midlet_index] : jad.midlets.constBegin().value();
				global_midlet_class = first.midlet_class;
				set_opt(args, "-1", 1, global_midlet_class);
			}
			jad_readed = true;
		}
		QString ori;
		suc = read_opt<QString>(args, "-jadpath", &ori);
		if(!suc || ori.isEmpty())
			set_opt(args, "-jadpath", 1, global_jad_file);
	}
	// if jar is set, if midlet class is empty, find midlet class in jar or jad.
	else if(!global_jar_file.isEmpty())
	{
		QString ori;
		suc = read_opt<QString>(args, "-suitepath", &ori);
		if(!suc || ori.isEmpty())
			set_opt(args, "-suitepath", 1, global_jar_file);
		if(global_midlet_class.isEmpty())
		{
			suc = karin::parse_MANIFEST(jad, global_jar_file);
			if(!suc && !global_jad_file.isEmpty())
				suc = karin::parse_jad(jad, global_jad_file);
			if(suc && !jad.midlets.isEmpty())
			{
				const karin::MIDlet_t &first = jad.midlets.contains(global_midlet_index) ? jad.midlets[global_midlet_index] : jad.midlets.constBegin().value();
				global_midlet_class = first.midlet_class;
				set_opt(args, "-1", 1, global_midlet_class);
			}
			jad_readed = true;
		}
	}
	if(!jad_readed)
	{
		if(!global_jar_file.isEmpty())
			jad_readed = parse_MANIFEST(jad, global_jar_file);
		if(!suc && !global_jad_file.isEmpty())
			jad_readed = parse_jad(jad, global_jad_file);
	}
	if(jad_readed)
	{
		global_midlet_name = jad.name;
		global_midlet_icon = jad.icon; //TODO get it
	}
	//qDebug() << args;
	args.removeAll("-graphicssystem");
	args.removeAll("raster");

	midlet_argc = args.size();
	midlet_argv = new char *[midlet_argc];
	for(int i = 0; i < midlet_argc; i++)
	{
		QByteArray bytes = args[i].toLocal8Bit();
		midlet_argv[i] = new char[bytes.size() + 1];
		memcpy(midlet_argv[i], bytes.data(), bytes.size());
		midlet_argv[i][bytes.size()] = '\0';
	}
}

static void print_cvm_args()
{
	if(midlet_argc == 0)
	{
		printf("[CVM]: cvm argc = 0\n");
		return;
	}
	if(!midlet_argv)
	{
		printf("[CVM]: cvm argv = NULL\n");
		return;
	}
	printf("------ CVM start ------\n");
	printf("  * MIDlet jar: %s\n", global_jar_file.toStdString().c_str());
	printf("  * MIDlet jad: %s\n", global_jad_file.toStdString().c_str());
	printf("  * MIDlet name: %s\n", global_midlet_name.toStdString().c_str());
	printf("  * MIDlet icon: %s\n", global_midlet_icon.toStdString().c_str());
	printf("  * MIDlet class: %s\n", global_midlet_class.toStdString().c_str());
	for(int i = 0; i < midlet_argc; i++)
	{
		printf(midlet_argv[i]);
		if(i < midlet_argc - 1)
			printf(" ");
		else
			printf("\n");
	}
}

static void print_cvm_ret()
{
	printf("------ CVM end ------\n");
}

#endif

#ifndef _HARMATTAN
// cross thread call
#endif
void enableStateChange() {
    enable_state_change = 1;
}

// run cvm thread
void cvm_exec() {
#ifdef _HARMATTAN
	print_cvm_args();
#endif
    cvm_main(midlet_argc, midlet_argv);
#ifdef _HARMATTAN
	print_cvm_ret();
#endif
}

#ifndef _HARMATTAN
// cross thread call
#endif
bool isRotated() {
    return rotate;
}

extern "C" {
extern void * gl_get_m3g_pixel_data(void);
}
void repaintPixmap(void *src) {
	//src = gl_get_m3g_pixel_data();
    if (fb && src)
    {
        static gxj_pixel_type * last_buffer = 0;

        if (last_buffer && fb->buffer.contains(last_buffer))
            while (fb->buffer[last_buffer])
                usleep(1000);

        last_buffer = (unsigned short *)src;

        fb->buffer[last_buffer] = true;

        fb->update(last_buffer);
    }

    enable_state_change = 1;
    input_ready = 1;
}

void resetFrameBufferSize(int w, int h) {

    width = w;
    height = h;

#ifdef _HARMATTAN
	resizeFrameBuffer(width, height);
	qDebug() << "[CVM]: resize frame buffer -> " << width << height;
#else
    if (rotate) {
        resizeFrameBuffer(height, width);
    } else {
        resizeFrameBuffer(width, height);
    }
#endif

    if (enable_state_change) {
        keyEvent(0x15);
        if (fb) {
            fb->update();
        }
    }

    enable_state_change = 1; // Force a size reset the next time this method is called
}

bool checkparam(int &argc, char *argv[], char *param) {
    for (int i=0; i<argc; i++) {
        if (!strcmp(argv[i], param)) {
            for (int j=i+1; j<argc; j++) {
                argv[j-1] = argv[j];
            }
            argc--;
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
#ifndef _HARMATTAN
    char *ptr;
    char path[256];
    void *handle;
#endif
    int gui = 0;

	//
#ifndef _HARMATTAN
    QSettings settings("phoneme", "user");
#endif

    if (errorlog) {
        freopen("/home/user/MyDocs/out.txt", "w", stdout);
        freopen("/home/user/MyDocs/err.txt", "w", stderr);
    }

#ifdef _HARMATTAN
	parse_options(argc, argv);
    for (int i=0; i<midlet_argc; i++) {
        if (!strcmp(midlet_argv[i], "sun.misc.MIDPLauncher")) {
            gui = 1;
            break;
        }
    }
#else
    for (int i=0; i<argc; i++) {
        if (!strcmp(argv[i], "sun.misc.MIDPLauncher")) {
            gui = 1;
            break;
        }
    }

    if (checkparam(argc, argv, (char *)"-fullscreen")) {
        fullscreen = true;
    }

    if (checkparam(argc, argv, (char *)"-nofullscreen")) {
        fullscreen = false;
    }

    if (checkparam(argc, argv, (char *)"-rotate")) {
        rotate = true;
    }

    if (checkparam(argc, argv, (char *)"-portrait")) {
        rotate = true;
    }

    if (checkparam(argc, argv, (char *)"-norotate")) {
        rotate = false;
    }

    if (checkparam(argc, argv, (char *)"-noportrait")) {
        rotate = false;
    }

    if (checkparam(argc, argv, (char *)"-bitmapfont")) {
        bitmapfont = true;
    }

    if (checkparam(argc, argv, (char *)"-nobitmapfont")) {
        bitmapfont = false;
    }

    if (checkparam(argc, argv, (char *)"-antialias")) {
        antialias = true;
    }

    if (checkparam(argc, argv, (char *)"-noantialias")) {
        antialias = false;
    }

    midlet_argc = argc;
    midlet_argv = argv;
#endif

#ifdef _HARMATTAN
		init_cvm_backend();
#endif

    if (gui) {
        char buf[255];
        sprintf(buf, "phoneME");

        if (argc > 1) {
            snprintf(buf, sizeof(buf)-1, "%s", argv[argc-1]);

            char *ptr = strrchr(argv[argc-1], '.');
            if (ptr)
                snprintf(buf, sizeof(buf)-1, "%s", ptr+1);
        }

        FILE *f = fopen("/etc/issue", "r");
        char issue[256];
        fgets(issue, 255, f);
        fclose(f);

        if (strncmp(issue, "Maemo 5", 7) == 0) {
            if (fullscreen) {
                width = 800;
                height = 480;
            } else {
                width = 800;
                height = 424;
            }
        } else if (strncmp(issue, "MeeGo", 5) == 0) {
            width = 854;
            height = 480;
        } else {
            width = 854;
            height = 480;
        }

        QApplication app(argc, argv);
#ifdef _HARMATTAN
		if(global_render_system != "native")
			QApplication::setGraphicsSystem(global_render_system);
#endif
        app.setApplicationName("phoneME");
        app.setProperty("NoMStyle", true);
        FrameBuffer window(0, width, height);
        window.setWindowTitle(buf);

        if (fullscreen) {
            window.showFullScreen();
        } else {
            window.show();
        }

#ifdef _HARMATTAN
        window.setWindowTitle(global_midlet_name);
        fb = &window;
		init_qcvm_backend(&window);
		QObject::connect(qApp, SIGNAL(aboutToQuit()), &thread, SLOT(Finish()));
#endif
        thread.start();

        app.exec();

        if (thread.isRunning()) {
            thread.quit();
        }

#ifdef _HARMATTAN
		shutdown_cvm_backend();
#endif
        /// (*fn_finalizeFrameBuffer)();
    } else {
        cvm_exec();
    }

#ifdef _HARMATTAN
	for(int i = 0; i < midlet_argc; i++)
	{
		delete[] midlet_argv[i];
	}
	delete[] midlet_argv;
#endif

    return 0;
}
