#ifndef KARIN_CVM_BACKEND_H
#define KARIN_CVM_BACKEND_H

#include "main.h"

#include <QWidget>

#define STYLE_PLAIN         0
#define STYLE_BOLD          1
#define STYLE_ITALIC        2
#define STYLE_UNDERLINED    4

#define SIZE_SMALL          8
#define SIZE_MEDIUM         0
#define SIZE_LARGE         16

#define FACE_SYSTEM         0
#define FACE_MONOSPACE     32
#define FACE_PROPORTIONAL  64

typedef unsigned short gxj_pixel_type;
typedef unsigned char  gxj_alpha_type;

extern int width;
extern int height;
extern int enable_state_change;
extern int input_ready;

extern bool fullscreen;
extern bool rotate;
extern bool antialias;
extern bool bitmapfont;
extern bool errorlog;
extern bool sip;

extern QString global_jar_file;
extern QString global_midlet_class;
extern int global_orientation;
extern bool global_full_framebuffer;
extern int global_vkb_type;
extern bool global_vkb_translucent;
extern unsigned int global_debug;
extern int global_buffer_width;
extern int global_buffer_height;
extern int global_keyboard_scheme;
extern qreal global_keyboard_opacity;
extern int global_paint_scheme;
extern QString global_framebuffer_background_color;

#ifdef _HARMATTAN
void keyEvent(unsigned int ch, int mask = 2);
#else
void keyEvent(unsigned int ch);
#endif
void mouseEvent(int x, int y, int pressed);
void resetFrameBufferSize(int w, int h);
extern void enableStateChange();
extern bool isRotated();

void init_cvm_backend();
void init_qcvm_backend(QWidget *window = 0);
void shutdown_cvm_backend();

#endif
