#ifndef _KARIN_QEGL_H
#define _KARIN_QEGL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>

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

// local function in dll
extern void *karinqeglGetProcAddress(const char *symbol);

#ifdef __cplusplus
}
#endif

#endif
