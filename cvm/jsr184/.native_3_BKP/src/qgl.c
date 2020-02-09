// dynamic load OpenGLES/EGL library.
#include "qgl.h"

#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct DLFcn_s
{
	int loaded;
	const char *dl_file;
	void *dl_ptr;
} DLFcn_t;

static void * open_dl(const char *dllname)
{
#define MAX_OSPATH 255
	void *ptr;

	ptr = 0;
	if ( ( ptr = dlopen( dllname, RTLD_LAZY ) ) == 0 )
	{
		char	fn[MAX_OSPATH];

		// try current directory
		snprintf (fn, MAX_OSPATH, "%s/%s", ".", dllname );

		if ( ( ptr = dlopen( fn, RTLD_LAZY ) ) == 0 ) {
			fprintf( stderr, "[Harmattan]: dlopen(%s, RTLD_LAZY) -> %s\n", fn, dlerror() );
		}
		else
			fprintf( stdout, "[Harmattan]: dlopen(%s, RTLD_LAZY) -> %p\n", fn, ptr );
	} else {
		fprintf( stdout, "[Harmattan]: dlopen(%s, RTLD_LAZY) -> %p\n", dllname, ptr );
	}
	return ptr;
#undef MAX_OSPATH
}

#include "qegl.c"
#include "qgles1.c"

int karinGLInit(void)
{
	int res;

	res = karinEGLInit();
	if(!res)
		return 0;
	
	res = karinGLES1Init();
	if(res)
		return 1;
	else
		karinGLES1Deinit();
	return 0;
}

int karinGLDeinit(void)
{
	karinGLES1Deinit();
	karinEGLDeinit();
	return 1;
}
