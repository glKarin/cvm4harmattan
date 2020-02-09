#include "cvm.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <execinfo.h>

#include <QtGui>
#include <QtCore>

#ifdef Q_WS_MAEMO_5_OLD
#include <location/location-gps-device.h>
#include <location/location-gpsd-control.h>
#endif
#ifdef _HARMATTAN
#include "mediaplayer.h"
#else
#include <QMediaPlayer>
#endif

#include "locationwidget.h"
#include "framebuffer.h"

#define MOUSE_FD "/tmp/mouse_fd"
#define KEYBOARD_FD "/tmp/keyboard_fd"

extern void repaintPixmap(void *src);

static FILE* keyboard_fd = NULL;
static FILE* mouse_fd = NULL;

static jboolean *valid = NULL;
static jdouble *latitude = NULL;
static jdouble *longitude = NULL;
static jfloat *altitude = NULL;
static jfloat *speed = NULL;
static jfloat *bearing = NULL;
static jfloat *accuracy = NULL;

#ifdef Q_WS_MAEMO_5_OLD
static LocationGPSDevice *device = NULL;
static LocationGPSDControl *control = NULL;
#endif

static LocationWidget *location = NULL;
#ifdef _HARMATTAN
static karin::MediaPlayer *player = NULL;
#else
static QMediaPlayer *player = NULL;
#endif

typedef struct _gxj_screen_buffer {
    int width;
    int height;
    gxj_pixel_type *pixelData;
    gxj_alpha_type *alphaData;
} gxj_screen_buffer;

#ifdef _HARMATTAN
void keyEvent(unsigned int ch, int mask)
#else
void keyEvent(unsigned int ch)
#endif
{
    if (!input_ready)
        return;

    if (!keyboard_fd) {
        char buff[255];
        sprintf(buff, "/tmp/keyboard_fd.%d", getpid());
        keyboard_fd = fopen(buff, "w");
    }

    if (!keyboard_fd)
        return;

    if (!ch)
        return;

#ifdef _HARMATTAN
	// key pressed
	if(mask == 1)
	{
#endif
    fputc(ch, keyboard_fd);
#ifdef _HARMATTAN
    fputc(ch >> 8, keyboard_fd);
#else
    fputc(ch/256, keyboard_fd);
#endif
#ifdef _HARMATTAN
	}
#endif

#ifdef _HARMATTAN
	// key released
	if(mask == 0 || mask == 2)
	{
#endif
    fputc(0x80, keyboard_fd);
    fputc(0x00, keyboard_fd);

    fputc(ch, keyboard_fd);
#ifdef _HARMATTAN
    fputc(ch >> 8, keyboard_fd);
#else
    fputc(ch/256, keyboard_fd);
#endif
#ifdef _HARMATTAN
	}
#endif
    fflush(keyboard_fd);
}

void mouseEvent(int x, int y, int pressed) {
    if (!input_ready)
        return;

    if (!mouse_fd) {
        char buff[255];
        sprintf(buff, "/tmp/mouse_fd.%d", getpid());
        mouse_fd = fopen(buff, "w");
    }

    if (!mouse_fd)
        return;

#ifndef _HARMATTAN
    if (rotate)
	{
        int tmp = x;
        x = height - y;
        y = tmp;
    }
#endif

    fputc(x & 0xff, mouse_fd);
    x >>= 8;
    fputc(x & 0xff, mouse_fd);
    x >>= 8;
    fputc(x & 0xff, mouse_fd);
    x >>= 8;
    fputc(x & 0xff, mouse_fd);

    fputc(y & 0xff, mouse_fd);
    y >>= 8;
    fputc(y & 0xff, mouse_fd);
    y >>= 8;
    fputc(y & 0xff, mouse_fd);
    y >>= 8;
    fputc(y & 0xff, mouse_fd);

    fputc(pressed, mouse_fd);
    fputc(0, mouse_fd);
    fputc(0, mouse_fd);
    fputc(0, mouse_fd);

    fflush(mouse_fd);
}

static void cleanup() {
    char buff[255];

    sprintf(buff, "%s.%d", KEYBOARD_FD, getpid());
    remove(buff);

    sprintf(buff, "%s.%d", MOUSE_FD, getpid());
    remove(buff);
}

static void init_gps_provider(jboolean *v, jdouble *lat, jdouble *lon, jfloat *alt, jfloat *s, jfloat *b, jfloat *a) {
    valid = v;
    latitude = lat;
    longitude = lon;
    altitude = alt;
    speed = s;
    bearing = b;
    accuracy = a;

#ifdef Q_WS_MAEMO_5_OLD
    control = location_gpsd_control_get_default();
    if (control)
        location_gpsd_control_start(control);

    device = (LocationGPSDevice*)g_object_new(LOCATION_TYPE_GPS_DEVICE, NULL);
    if (device) {
        g_signal_connect(device, "changed", G_CALLBACK(location_changed), NULL);
        g_signal_connect(device, "connected", G_CALLBACK(location_connected), NULL);
        g_signal_connect(device, "disconnected", G_CALLBACK(location_disconnected), NULL);
    }
#endif

    if (location) {
        location->startUpdates();
    }
}

static void finish_gps_provider() {
#ifdef Q_WS_MAEMO_5_OLD
    if (device) {
        g_object_unref(device);
        device = NULL;
    }

    if (control) {
        location_gpsd_control_stop(control);
        control = NULL;
    }
#endif

    if (location) {
        location->stopUpdates();
    }
}

static void inthandler(int sig) {
    signal(sig, SIG_IGN);
    /// finalizeFrameBuffer();

    finish_gps_provider();
    exit(0);
}

static void playFile(QString filename) {
#ifdef _HARMATTAN
    player->setMedia(filename);
#else
    player->setMedia(QUrl::fromLocalFile(filename + " " + filename));
#endif
    player->play(filename);
}

static void playAlert(int i) {
#ifdef Q_WS_MAEMO_5
    if (i == 3) // Error
        playFile(QString("/usr/share/sounds/ui-default_beep.wav"));
    else if (i == 2) // Warning
        playFile(QString("/usr/share/sounds/ui-general_warning.wav"));
    else if (i == 1) // Info - Command
        playFile(QString("/usr/share/sounds/ui-information_note.wav"));
    else if (i == 5) // Confirmation
        playFile(QString("/usr/share/sounds/ui-confirmation_note.wav"));
    else if (i == 4) // Alarm
        playFile(QString("/usr/share/sounds/ui-battery_low.wav"));
    else
        playFile(QString("/usr/share/sounds/ui-default_beep.wav"));
#else
    if (i == 3)
        playFile(QString("/usr/share/sounds/ui-tones/snd_default_beep.wav"));
    else if (i == 2)
        playFile(QString("/usr/share/sounds/ui-tones/snd_warning.wav"));
    else if (i == 1)
        playFile(QString("/usr/share/sounds/ui-tones/snd_information.wav"));
    else if (i == 5)
        playFile(QString("/usr/share/sounds/ui-tones/snd_query.wav"));
    else if (i == 4)
        playFile(QString("/usr/share/sounds/ui-tones/snd_warning_strong.wav"));
    else
        playFile(QString("/usr/share/sounds/ui-tones/snd_default_beep.wav"));
#endif
}

int call_platform(char *invocation[16], int count, char *result[16]) {
    int i, ret;

#ifndef _HARMATTAN
    fprintf(stderr, "INFO:");
    for (i=0; i<count; i++) {
        fprintf(stderr, " %s", invocation[i]);
    }
    fprintf(stderr, "\n");
#endif

    strcpy(result[0], "");
    ret = 1;

    if (count >= 3) {
        if (strcmp(invocation[0], "maemo.media.MediaPlayer") == 0) {
            if (strcmp(invocation[1], "playAlert") == 0) {
                playAlert(atoi(invocation[2]));
                ret = 0;
            }
            if (strcmp(invocation[1], "create") == 0) {
#ifdef _HARMATTAN
                player->setMedia(invocation[2]);
#else
                player->setMedia(QUrl::fromLocalFile(invocation[2]));
#endif
                ret = 0;
            }
            if (strcmp(invocation[1], "start") == 0) {
                player->play(invocation[2]);
                ret = 0;
            }
            if (strcmp(invocation[1], "stop") == 0) {
                player->stop(invocation[2]);
                ret = 0;
            }
        }
    }

    return ret;
}

static void segvhandler(int signum) {
    fprintf(stderr, "ERROR: Catched signal %d\n", signum);

    void *array[16];
    size_t size;

    size = backtrace(array, 16);
    backtrace_symbols_fd(array, size, 2);

    finish_gps_provider();
    exit(1);
}

#ifdef Q_WS_MAEMO_5_OLD
void location_changed(LocationGPSDevice *device, gpointer userdata) {
    (void)userdata;

    if (device->status == LOCATION_GPS_DEVICE_STATUS_NO_FIX) {
        // fprintf(stderr, "No Fix\n");
        *valid = false;
    } else {
        // fprintf(stderr, "Fixed\n");
        *valid = true;
    }

    // fprintf(stderr, "Satellites in use: %d\n", device->satellites_in_use);
    LocationGPSDeviceFix *fix = device->fix;

    if ((fix->mode == LOCATION_GPS_DEVICE_MODE_3D) && (fix->fields & LOCATION_GPS_DEVICE_ALTITUDE_SET)) {
        // fprintf(stderr, "Altitude: %f m\n", fix->altitude);
        *altitude = (jfloat)(fix->altitude);
    }

    if ((fix->mode == LOCATION_GPS_DEVICE_MODE_3D || fix->mode == LOCATION_GPS_DEVICE_MODE_2D) && (fix->fields & LOCATION_GPS_DEVICE_LATLONG_SET)) {
        // fprintf(stderr, "Latitude: %f - Longitude: %f\n", fix->latitude, fix->longitude);

        *latitude = fix->latitude;
        *longitude = fix->longitude;
    }

    if (fix->fields & LOCATION_GPS_DEVICE_SPEED_SET) {
        // fprintf(stderr, "Speed: %f km/h\n", fix->speed);
        *speed = (jfloat)(fix->speed);
    }

    // fprintf(stderr, "Timestamp: %f s\n", fix->time);

    // fprintf(stderr, "Horizontal accuracy: %f m\n", fix->eph/100);
    *accuracy = (jfloat)(fix->eph/100);

    // fprintf(stderr, "Bearing: %f degrees\n", fix->track);
    *bearing = (jfloat)(fix->track);
}

void location_connected(LocationGPSDevice *device, gpointer userdata) {
    (void)device;
    (void)userdata;
}

void location_disconnected(LocationGPSDevice *device, gpointer userdata) {
    (void)device;
    (void)userdata;
}
#endif

void update_location(bool val, double lat, double lon, float alt, float spd, float brg, float acc) {
    *valid = val;
    *latitude = lat;
    *longitude = lon;
    *altitude = alt;
    *speed = spd;
    *bearing = brg;
    *accuracy = acc;
}

static int gxjport_get_chars_width(int face, int style, int size,
                                   const jchar *charArray, int n) {

    QFont font = QApplication::font();
    font.setPixelSize(size);
    if (style & STYLE_BOLD) {
        font.setWeight(QFont::Bold);
    }
    if (style & STYLE_ITALIC) {
        font.setItalic(true);
    }
    if (style & STYLE_UNDERLINED) {
        font.setUnderline(true);
    }

    QFontMetrics fm(font);
    QString s((QChar *)charArray, n);

    return fm.width(s);
}

static int gxjport_draw_chars(int pixel, const jshort *clip, void *dst, int dotted,
                              int face, int style, int size,
                              int x, int y, int anchor,
                              const jchar *charArray, int n) {

    gxj_screen_buffer *dest = (gxj_screen_buffer *)dst;

    QFont font = QApplication::font();
    if (!antialias) {
        font.setStyleStrategy(QFont::NoAntialias);
    }
    font.setPixelSize(size);
    if (style & STYLE_BOLD) {
        font.setWeight(QFont::Bold);
    }
    if (style & STYLE_ITALIC) {
        font.setItalic(true);
    }
    if (style & STYLE_UNDERLINED) {
        font.setUnderline(true);
    }

    QFontMetrics fm(font);
    QString s((QChar *)charArray, n);

    int font_width = fm.width(s);
    int font_height = fm.height();

    QImage image((uchar *)dest->pixelData, dest->width, dest->height, QImage::Format_RGB16);
    QPainter painter(&image);
    painter.setClipping(true);
    painter.setFont(font);
    painter.setPen(QColor(pixel));

    QRect rect = QRect(clip[0], clip[1], clip[2]-clip[0], clip[3]-clip[1]);
    painter.setClipRect(rect);

    painter.drawText(x, y, font_width, font_height, Qt::AlignLeft|Qt::AlignTop, s);

    return 1;
}

static int gxjport_get_font_info(int face, int style, int size,
                                 int *ascent, int *descent, int *leading) {

    QFont font = QApplication::font();
    font.setPixelSize(size);
    if (style & STYLE_BOLD) {
        font.setWeight(QFont::Bold);
    }
    if (style & STYLE_ITALIC) {
        font.setItalic(true);
    }
    if (style & STYLE_UNDERLINED) {
        font.setUnderline(true);
    }

    QFontMetrics fm(font);
    *ascent = fm.ascent();
    *descent = fm.descent();
    *leading = fm.leading();

    return 1;
}

void init_cvm_backend()
{
	if (atexit(cleanup)) {
		fprintf(stderr, "ERROR: Failed to register callback.\n");
    }

    struct sigaction sigact;
    signal(SIGINT, inthandler);
    // set up new handler to specify new action
    sigact.sa_handler = segvhandler;
    // sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    // attach SIGSEV to segvhandler
    sigaction(SIGSEGV, &sigact, NULL);

#ifdef _HARMATTAN
    if (isRotated()) 
#else
    if (rotate) 
#endif
	{
        initPixmap(height, width, &repaintPixmap);
    } else {
        initPixmap(width, height, &repaintPixmap);
    }

    if (!bitmapfont)
        initDrawChars(&gxjport_draw_chars, &gxjport_get_font_info, &gxjport_get_chars_width);

    initPlatform(&call_platform);

    initGPS(&init_gps_provider, &finish_gps_provider);

#ifdef Q_WS_MAEMO_5_OLD
        g_type_init();
#endif
}

void init_qcvm_backend(QWidget *window)
{
	/*
    if (!bitmapfont)
        initDrawChars(&gxjport_draw_chars, &gxjport_get_font_info, &gxjport_get_chars_width);
*/

#ifdef _HARMATTAN
	player = new karin::SystemMediaPlayer;
#else
	//player = new QMediaPlayer(0, QMediaPlayer::LowLatency);
#endif
	player->setVolume(85);

	location = new LocationWidget(window);
}

void shutdown_cvm_backend()
{
	delete player;
	delete location;

	finish_gps_provider();
}
