/* include/config.h.  Generated from config.h.in by configure.  */
/* include/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define this if using Alsa 1.0.1 or higher */
#define ALSA_NEW 1

/* Define this to enable all experimental code */
/* #undef EXPERIMENT_626 */

/* Define this if your system uses alsa */
#define HAVE_ALSA 1

/* Define to 1 if you have the <alsa/asoundlib.h> header file. */
#define HAVE_ALSA_ASOUNDLIB_H 1

/* Define to 1 if you have the <ctype.h> header file. */
#define HAVE_CTYPE_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <linux/soundcard.h> header file. */
#define HAVE_LINUX_SOUNDCARD_H 1

/* Define to 1 if you have the <machine/soundcard.h> header file. */
/* #undef HAVE_MACHINE_SOUNDCARD_H */

/* Define to 1 if you have the <math.h> header file. */
#define HAVE_MATH_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <mmsystem.h> header file. */
/* #undef HAVE_MMSYSTEM_H */

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H 1

/* Define to 1 if you have the <stdarg.h> header file. */
#define HAVE_STDARG_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdio.h> header file. */
#define HAVE_STDIO_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#define HAVE_SYS_IOCTL_H 1

/* Define to 1 if you have the <sys/mman.h> header file. */
#define HAVE_SYS_MMAN_H 1

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#define HAVE_SYS_SOUNDCARD_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the <windows.h> header file. */
/* #undef HAVE_WINDOWS_H */

/* Define this if the GCC __builtin_expect keyword is available */
#define HAVE___BUILTIN_EXPECT 1
#ifndef HAVE___BUILTIN_EXPECT
# define __builtin_expect(x,c) x
#endif

/* Name of package */
#define PACKAGE "wildmidi"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* "Proper" program name */
#define PROGRAM "WildMidi"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define this to the location of the timidity config file */
#define TIMIDITY_CFG "/etc/wildmidi/wildmidi.cfg"

/* Version number of package */
#define VERSION "0.2.2"

/* current lib version */
#define WILDMIDILIB_VERSION "0.2.2"

/* current program version */
#define WILDMIDI_VERSION "0.2.2"

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */