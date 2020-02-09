#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <stdarg.h>

#define ANDROID_LOG_ERROR stderr
#define ANDROID_LOG_WARN stderr

#define __android_log_print(device, ...) fprintf(device, __VA_ARGS__)
#define __android_log_vprint(device, name, ...) fprintf(device, __VA_ARGS__)


#endif
