static FILE *egl_log_fp = NULL;
static DLFcn_t egl;

// extern func ptr
EGLint ( * qeglGetError )(void );
EGLDisplay ( * qeglGetDisplay )(EGLNativeDisplayType display_id);
EGLBoolean ( * qeglInitialize )(EGLDisplay dpy, EGLint * major, EGLint * minor);
EGLBoolean ( * qeglTerminate )(EGLDisplay dpy);
const char * ( * qeglQueryString )(EGLDisplay dpy, EGLint name);
EGLBoolean ( * qeglGetConfigs )(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config);
EGLBoolean ( * qeglChooseConfig )(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config);
EGLBoolean ( * qeglGetConfigAttrib )(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value);
EGLSurface ( * qeglCreateWindowSurface )(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list);
EGLSurface ( * qeglCreatePbufferSurface )(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list);
EGLSurface ( * qeglCreatePixmapSurface )(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list);
EGLBoolean ( * qeglDestroySurface )(EGLDisplay dpy, EGLSurface surface);
EGLBoolean ( * qeglQuerySurface )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value);
EGLBoolean ( * qeglBindAPI )(EGLenum api);
EGLenum ( * qeglQueryAPI )(void );
EGLBoolean ( * qeglWaitClient )(void );
EGLBoolean ( * qeglReleaseThread )(void );
EGLSurface ( * qeglCreatePbufferFromClientBuffer )(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list);
EGLBoolean ( * qeglSurfaceAttrib )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
EGLBoolean ( * qeglBindTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLBoolean ( * qeglReleaseTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
EGLBoolean ( * qeglSwapInterval )(EGLDisplay dpy, EGLint interval);
EGLContext ( * qeglCreateContext )(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list);
EGLBoolean ( * qeglDestroyContext )(EGLDisplay dpy, EGLContext ctx);
EGLBoolean ( * qeglMakeCurrent )(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
EGLContext ( * qeglGetCurrentContext )(void );
EGLSurface ( * qeglGetCurrentSurface )(EGLint readdraw);
EGLDisplay ( * qeglGetCurrentDisplay )(void );
EGLBoolean ( * qeglQueryContext )(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value);
EGLBoolean ( * qeglWaitGL )(void );
EGLBoolean ( * qeglWaitNative )(EGLint engine);
EGLBoolean ( * qeglSwapBuffers )(EGLDisplay dpy, EGLSurface surface);
EGLBoolean ( * qeglCopyBuffers )(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
__eglMustCastToProperFunctionPointerType ( * qeglGetProcAddress )(const char * procname);

// ori func ptr
static EGLint ( * dlleGetError )(void );
static EGLDisplay ( * dlleGetDisplay )(EGLNativeDisplayType display_id);
static EGLBoolean ( * dlleInitialize )(EGLDisplay dpy, EGLint * major, EGLint * minor);
static EGLBoolean ( * dlleTerminate )(EGLDisplay dpy);
static const char * ( * dlleQueryString )(EGLDisplay dpy, EGLint name);
static EGLBoolean ( * dlleGetConfigs )(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config);
static EGLBoolean ( * dlleChooseConfig )(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config);
static EGLBoolean ( * dlleGetConfigAttrib )(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value);
static EGLSurface ( * dlleCreateWindowSurface )(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list);
static EGLSurface ( * dlleCreatePbufferSurface )(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list);
static EGLSurface ( * dlleCreatePixmapSurface )(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list);
static EGLBoolean ( * dlleDestroySurface )(EGLDisplay dpy, EGLSurface surface);
static EGLBoolean ( * dlleQuerySurface )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value);
static EGLBoolean ( * dlleBindAPI )(EGLenum api);
static EGLenum ( * dlleQueryAPI )(void );
static EGLBoolean ( * dlleWaitClient )(void );
static EGLBoolean ( * dlleReleaseThread )(void );
static EGLSurface ( * dlleCreatePbufferFromClientBuffer )(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list);
static EGLBoolean ( * dlleSurfaceAttrib )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
static EGLBoolean ( * dlleBindTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
static EGLBoolean ( * dlleReleaseTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
static EGLBoolean ( * dlleSwapInterval )(EGLDisplay dpy, EGLint interval);
static EGLContext ( * dlleCreateContext )(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list);
static EGLBoolean ( * dlleDestroyContext )(EGLDisplay dpy, EGLContext ctx);
static EGLBoolean ( * dlleMakeCurrent )(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
static EGLContext ( * dlleGetCurrentContext )(void );
static EGLSurface ( * dlleGetCurrentSurface )(EGLint readdraw);
static EGLDisplay ( * dlleGetCurrentDisplay )(void );
static EGLBoolean ( * dlleQueryContext )(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value);
static EGLBoolean ( * dlleWaitGL )(void );
static EGLBoolean ( * dlleWaitNative )(EGLint engine);
static EGLBoolean ( * dlleSwapBuffers )(EGLDisplay dpy, EGLSurface surface);
static EGLBoolean ( * dlleCopyBuffers )(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
static __eglMustCastToProperFunctionPointerType ( * dlleGetProcAddress )(const char * procname);

// log func ptr
#define PRINT_EGL_ERROR_DEVICE stdout
#define PRINT_EGL_CALL_DEVICE stdout

static EGLint logeGetError(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetError()");
	EGLint ret = dlleGetError();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> +%x\n", ret );
	/*
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	*/
	return ret;
}

static EGLDisplay logeGetDisplay(EGLNativeDisplayType display_id)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetDisplay(+%x)", display_id);
	EGLDisplay ret = dlleGetDisplay(display_id);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeInitialize(EGLDisplay dpy, EGLint * major, EGLint * minor)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglInitialize(0X%X, %p, %p)", dpy, major, minor);
	EGLBoolean ret = dlleInitialize(dpy, major, minor);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeTerminate(EGLDisplay dpy)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglTerminate(0X%X)", dpy);
	EGLBoolean ret = dlleTerminate(dpy);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static const char * logeQueryString(EGLDisplay dpy, EGLint name)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglQueryString(0X%X, +%x)", dpy, name);
	const char *ret = dlleQueryString(dpy, name);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> %s\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeGetConfigs(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetConfigs(0X%X, %p, %d, %p)", dpy, configs, config_size, num_config);
	EGLBoolean ret = dlleGetConfigs(dpy, configs, config_size, num_config);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeChooseConfig(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglChooseConfig(0X%X, %p, %p, %d, %p)", dpy, attrib_list, configs, config_size, num_config);
	EGLBoolean ret = dlleChooseConfig(dpy, attrib_list, configs, config_size, num_config);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetConfigAttrib(0X%X, 0X%X, +%x, %p)", dpy, config, attribute, value);
	EGLBoolean ret = dlleGetConfigAttrib(dpy, config, attribute, value);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLSurface logeCreateWindowSurface(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCreateWindowSurface(0X%X, 0X%X, %x, %p)", dpy, config, win, attrib_list);
	EGLSurface ret = dlleCreateWindowSurface(dpy, config, win, attrib_list);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLSurface logeCreatePbufferSurface(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCreatePbufferSurface(0X%X, 0X%X, %p)", dpy, config, attrib_list);
	EGLSurface ret = dlleCreatePbufferSurface(dpy, config, attrib_list);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0x%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLSurface logeCreatePixmapSurface(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCreatePixmapSurface(0X%X, 0X%X, 0X%X, %p)", dpy, config, pixmap, attrib_list);
	EGLSurface ret = dlleCreatePixmapSurface(dpy, config, pixmap, attrib_list);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglDestroySurface(0X%X, 0X%X)", dpy, surface);
	EGLBoolean ret = dlleDestroySurface(dpy, surface);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglQuerySurface(0X%X, 0X%X, +%x, %p)", dpy, surface, attribute, value);
	EGLBoolean ret = dlleQuerySurface(dpy, surface, attribute, value);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeBindAPI(EGLenum api)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglBindAPI(0X%X)", api);
	EGLBoolean ret = dlleBindAPI(api);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLenum logeQueryAPI(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglQueryAPI()");
	EGLenum ret = dlleQueryAPI();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> +%x\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeWaitClient(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglWaitClient()");
	EGLBoolean ret = dlleWaitClient();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeReleaseThread(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglReleaseThread()");
	EGLBoolean ret = dlleReleaseThread();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLSurface logeCreatePbufferFromClientBuffer(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCreatePbufferFromClientBuffer(0X%X, 0X%X, 0X%X, 0X%X, %p)", dpy, buftype, buffer, config, attrib_list);
	EGLSurface ret = dlleCreatePbufferFromClientBuffer(dpy, buftype, buffer, config, attrib_list);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglSurfaceAttrib(0X%X, 0X%X, +%x, %d)", dpy, surface, attribute, value);
	EGLBoolean ret = dlleSurfaceAttrib(dpy, surface, attribute, value);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglBindTexImage(0X%X, 0X%X, %d)", dpy, surface, buffer);
	EGLBoolean ret = dlleBindTexImage(dpy, surface, buffer);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglReleaseTexImage(0X%X, 0X%X, %d)", dpy, surface, buffer);
	EGLBoolean ret = dlleReleaseTexImage(dpy, surface, buffer);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeSwapInterval(EGLDisplay dpy, EGLint interval)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglSwapInterval(0X%X, %d)", dpy, interval);
	EGLBoolean ret = dlleSwapInterval(dpy, interval);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLContext logeCreateContext(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCreateContext(0X%X, 0X%X, 0X%X, %p)", dpy, config, share_context, attrib_list);
	EGLContext ret = dlleCreateContext(dpy, config, share_context, attrib_list);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglDestroyContext(0X%X, 0X%X)", dpy, ctx);
	EGLBoolean ret = dlleDestroyContext(dpy, ctx);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglMakeCurrent(0X%X, 0X%X, 0X%X, 0X%X)", dpy, draw, read, ctx);
	EGLBoolean ret = dlleMakeCurrent(dpy, draw, read, ctx);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLContext logeGetCurrentContext(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetCurrentContext()");
	EGLContext ret = dlleGetCurrentContext();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLSurface logeGetCurrentSurface(EGLint readdraw)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetCurrentSurface(%d)", readdraw);
	EGLSurface ret = dlleGetCurrentSurface(readdraw);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLDisplay logeGetCurrentDisplay(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetCurrentDisplay()");
	EGLDisplay ret = dlleGetCurrentDisplay();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> 0X%X\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglQueryContext(0X%X, 0X%X, +%x, %p)", dpy, ctx, attribute, value);
	EGLBoolean ret = dlleQueryContext(dpy, ctx, attribute, value);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeWaitGL(void )
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglWaitGL()");
	EGLBoolean ret = dlleWaitGL();
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeWaitNative(EGLint engine)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglWaitNative(%d)", engine);
	EGLBoolean ret = dlleWaitNative(engine);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglSwapBuffers(0X%X, 0X%X)", dpy, surface);
	EGLBoolean ret = dlleSwapBuffers(dpy, surface);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static EGLBoolean logeCopyBuffers(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglCopyBuffers(0X%X, 0X%X, 0X%X)", dpy, surface, target);
	EGLBoolean ret = dlleCopyBuffers(dpy, surface, target);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> ^%d\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

static __eglMustCastToProperFunctionPointerType logeGetProcAddress(const char * procname)
{
	fprintf(PRINT_EGL_CALL_DEVICE, "eglGetProcAddress(%s)", procname);
	__eglMustCastToProperFunctionPointerType ret = dlleGetProcAddress(procname);
	fprintf( PRINT_EGL_CALL_DEVICE, " -> %p\n", ret );
	EGLint err = dlleGetError();
	if(err != EGL_SUCCESS)
	{
		fprintf(PRINT_EGL_ERROR_DEVICE, "EGL_Error -> %X\n", err);
	}
	return ret;
}

#undef PRINT_GL_ERROR_DEVICE
#undef PRINT_GL_CALL_DEVICE


static void unload_egl( void )
{
	if ( egl.dl_ptr )
	{
		dlclose ( egl.dl_ptr );
		egl.dl_ptr = NULL;
	}

	egl.dl_ptr = NULL;
	egl.loaded = 0;

	qeglGetError = NULL;
	qeglGetDisplay = NULL;
	qeglInitialize = NULL;
	qeglTerminate = NULL;
	qeglQueryString = NULL;
	qeglGetConfigs = NULL;
	qeglChooseConfig = NULL;
	qeglGetConfigAttrib = NULL;
	qeglCreateWindowSurface = NULL;
	qeglCreatePbufferSurface = NULL;
	qeglCreatePixmapSurface = NULL;
	qeglDestroySurface = NULL;
	qeglQuerySurface = NULL;
	qeglBindAPI = NULL;
	qeglQueryAPI = NULL;
	qeglWaitClient = NULL;
	qeglReleaseThread = NULL;
	qeglCreatePbufferFromClientBuffer = NULL;
	qeglSurfaceAttrib = NULL;
	qeglBindTexImage = NULL;
	qeglReleaseTexImage = NULL;
	qeglSwapInterval = NULL;
	qeglCreateContext = NULL;
	qeglDestroyContext = NULL;
	qeglMakeCurrent = NULL;
	qeglGetCurrentContext = NULL;
	qeglGetCurrentSurface = NULL;
	qeglGetCurrentDisplay = NULL;
	qeglQueryContext = NULL;
	qeglWaitGL = NULL;
	qeglWaitNative = NULL;
	qeglSwapBuffers = NULL;
	qeglCopyBuffers = NULL;
	qeglGetProcAddress = NULL;
}

#define GPA( a ) dlsym( egl.dl_ptr, a )

void * karinEGLGetProcAddress(const char *symbol)
{
	if (egl.loaded)
		return GPA ( symbol );
	return NULL;
}

static int load_egl()
{
	if ( egl.loaded )
		return 1;
	
	qeglGetError = dlleGetError = GPA("eglGetError");
	qeglGetDisplay = dlleGetDisplay = GPA("eglGetDisplay");
	qeglInitialize = dlleInitialize = GPA("eglInitialize");
	qeglTerminate = dlleTerminate = GPA("eglTerminate");
	qeglQueryString = dlleQueryString = GPA("eglQueryString");
	qeglGetConfigs = dlleGetConfigs = GPA("eglGetConfigs");
	qeglChooseConfig = dlleChooseConfig = GPA("eglChooseConfig");
	qeglGetConfigAttrib = dlleGetConfigAttrib = GPA("eglGetConfigAttrib");
	qeglCreateWindowSurface = dlleCreateWindowSurface = GPA("eglCreateWindowSurface");
	qeglCreatePbufferSurface = dlleCreatePbufferSurface = GPA("eglCreatePbufferSurface");
	qeglCreatePixmapSurface = dlleCreatePixmapSurface = GPA("eglCreatePixmapSurface");
	qeglDestroySurface = dlleDestroySurface = GPA("eglDestroySurface");
	qeglQuerySurface = dlleQuerySurface = GPA("eglQuerySurface");
	qeglBindAPI = dlleBindAPI = GPA("eglBindAPI");
	qeglQueryAPI = dlleQueryAPI = GPA("eglQueryAPI");
	qeglWaitClient = dlleWaitClient = GPA("eglWaitClient");
	qeglReleaseThread = dlleReleaseThread = GPA("eglReleaseThread");
	qeglCreatePbufferFromClientBuffer = dlleCreatePbufferFromClientBuffer = GPA("eglCreatePbufferFromClientBuffer");
	qeglSurfaceAttrib = dlleSurfaceAttrib = GPA("eglSurfaceAttrib");
	qeglBindTexImage = dlleBindTexImage = GPA("eglBindTexImage");
	qeglReleaseTexImage = dlleReleaseTexImage = GPA("eglReleaseTexImage");
	qeglSwapInterval = dlleSwapInterval = GPA("eglSwapInterval");
	qeglCreateContext = dlleCreateContext = GPA("eglCreateContext");
	qeglDestroyContext = dlleDestroyContext = GPA("eglDestroyContext");
	qeglMakeCurrent = dlleMakeCurrent = GPA("eglMakeCurrent");
	qeglGetCurrentContext = dlleGetCurrentContext = GPA("eglGetCurrentContext");
	qeglGetCurrentSurface = dlleGetCurrentSurface = GPA("eglGetCurrentSurface");
	qeglGetCurrentDisplay = dlleGetCurrentDisplay = GPA("eglGetCurrentDisplay");
	qeglQueryContext = dlleQueryContext = GPA("eglQueryContext");
	qeglWaitGL = dlleWaitGL = GPA("eglWaitGL");
	qeglWaitNative = dlleWaitNative = GPA("eglWaitNative");
	qeglSwapBuffers = dlleSwapBuffers = GPA("eglSwapBuffers");
	qeglCopyBuffers = dlleCopyBuffers = GPA("eglCopyBuffers");
	qeglGetProcAddress = dlleGetProcAddress = GPA("eglGetProcAddress");

	return 1;
}

#undef GPA

static void enable_egl_logging( int enable )
{
	if ( enable )
	{
		qeglGetError = logeGetError;
		qeglGetDisplay = logeGetDisplay;
		qeglInitialize = logeInitialize;
		qeglTerminate = logeTerminate;
		qeglQueryString = logeQueryString;
		qeglGetConfigs = logeGetConfigs;
		qeglChooseConfig = logeChooseConfig;
		qeglGetConfigAttrib = logeGetConfigAttrib;
		qeglCreateWindowSurface = logeCreateWindowSurface;
		qeglCreatePbufferSurface = logeCreatePbufferSurface;
		qeglCreatePixmapSurface = logeCreatePixmapSurface;
		qeglDestroySurface = logeDestroySurface;
		qeglQuerySurface = logeQuerySurface;
		qeglBindAPI = logeBindAPI;
		qeglQueryAPI = logeQueryAPI;
		qeglWaitClient = logeWaitClient;
		qeglReleaseThread = logeReleaseThread;
		qeglCreatePbufferFromClientBuffer = logeCreatePbufferFromClientBuffer;
		qeglSurfaceAttrib = logeSurfaceAttrib;
		qeglBindTexImage = logeBindTexImage;
		qeglReleaseTexImage = logeReleaseTexImage;
		qeglSwapInterval = logeSwapInterval;
		qeglCreateContext = logeCreateContext;
		qeglDestroyContext = logeDestroyContext;
		qeglMakeCurrent = logeMakeCurrent;
		qeglGetCurrentContext = logeGetCurrentContext;
		qeglGetCurrentSurface = logeGetCurrentSurface;
		qeglGetCurrentDisplay = logeGetCurrentDisplay;
		qeglQueryContext = logeQueryContext;
		qeglWaitGL = logeWaitGL;
		qeglWaitNative = logeWaitNative;
		qeglSwapBuffers = logeSwapBuffers;
		qeglCopyBuffers = logeCopyBuffers;
		qeglGetProcAddress = logeGetProcAddress;
	}
	else
	{
		qeglGetError = dlleGetError;
		qeglGetDisplay = dlleGetDisplay;
		qeglInitialize = dlleInitialize;
		qeglTerminate = dlleTerminate;
		qeglQueryString = dlleQueryString;
		qeglGetConfigs = dlleGetConfigs;
		qeglChooseConfig = dlleChooseConfig;
		qeglGetConfigAttrib = dlleGetConfigAttrib;
		qeglCreateWindowSurface = dlleCreateWindowSurface;
		qeglCreatePbufferSurface = dlleCreatePbufferSurface;
		qeglCreatePixmapSurface = dlleCreatePixmapSurface;
		qeglDestroySurface = dlleDestroySurface;
		qeglQuerySurface = dlleQuerySurface;
		qeglBindAPI = dlleBindAPI;
		qeglQueryAPI = dlleQueryAPI;
		qeglWaitClient = dlleWaitClient;
		qeglReleaseThread = dlleReleaseThread;
		qeglCreatePbufferFromClientBuffer = dlleCreatePbufferFromClientBuffer;
		qeglSurfaceAttrib = dlleSurfaceAttrib;
		qeglBindTexImage = dlleBindTexImage;
		qeglReleaseTexImage = dlleReleaseTexImage;
		qeglSwapInterval = dlleSwapInterval;
		qeglCreateContext = dlleCreateContext;
		qeglDestroyContext = dlleDestroyContext;
		qeglMakeCurrent = dlleMakeCurrent;
		qeglGetCurrentContext = dlleGetCurrentContext;
		qeglGetCurrentSurface = dlleGetCurrentSurface;
		qeglGetCurrentDisplay = dlleGetCurrentDisplay;
		qeglQueryContext = dlleQueryContext;
		qeglWaitGL = dlleWaitGL;
		qeglWaitNative = dlleWaitNative;
		qeglSwapBuffers = dlleSwapBuffers;
		qeglCopyBuffers = dlleCopyBuffers;
		qeglGetProcAddress = dlleGetProcAddress;
	}
}

static int set_egl_log(int open)
{
	if(open)
	{
		if ( !egl_log_fp )
		{
			struct tm *newtime;
			time_t aclock;
			char buffer[1024];

			time( &aclock );
			newtime = localtime( &aclock );

			asctime( newtime );

			snprintf( buffer, sizeof(buffer), "%s/jsr184_m3g_egl.log", "." ); 
			egl_log_fp = fopen( buffer, "wt" );
			if(!egl_log_fp)
				return 0;

			fprintf( egl_log_fp, "%s\n", asctime( newtime ) );
		}
		return 1;
	}
	else
	{
		if(egl_log_fp)
		{
			fflush(egl_log_fp);
			fclose(egl_log_fp);
			egl_log_fp = NULL;
		}
		return 0;
	}
}

static int karinEGLInit(void)
{
#define EGL_SO "libEGL.so"
	void *handle;
	int res;

	if(egl.loaded)
		return 1;
	handle = open_dl(EGL_SO);
	if(!handle)
		return 0;
	egl.dl_ptr = handle;
	res = load_egl();
	if(!res)
		return 0;
	egl.loaded = 1;
	enable_egl_logging(1);
	return 1;
#undef EGL_SO
}

static int karinEGLDeinit(void)
{
	if(!egl.loaded)
		return 1;
	dlclose(egl.dl_ptr);
	unload_egl();
	return 1;
}

int karinPrintEGL(void)
{
	const char *ret;
	EGLDisplay dpy;

	if(!egl.loaded)
	{
		fprintf(stderr, "[Harmattan]: EGL library not load.\n");
		return 0;
	}
	dpy = qeglGetDisplay(EGL_DEFAULT_DISPLAY);

    ret = qeglQueryString(dpy, EGL_VENDOR);
	if(!ret)
	{
		fprintf(stderr, "[Harmattan]: EGL not initilize.\n");
		return 0;
	}

	printf("[Harmattan]: EGL vendor -> %s\n", ret);
    ret = qeglQueryString(dpy, EGL_VERSION);
	printf("[Harmattan]: EGL version -> %s\n", ret);
    ret = qeglQueryString(dpy, EGL_EXTENSIONS);
	printf("[Harmattan]: EGL extensions -> %s\n", ret);
    ret = qeglQueryString(dpy, EGL_CLIENT_APIS);
	printf("[Harmattan]: EGL client APIs -> %s\n", ret);

	return 1;
}
