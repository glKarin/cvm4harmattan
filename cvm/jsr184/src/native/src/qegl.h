#ifndef _KARIN_QEGL_H
#define _KARIN_QEGL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>

extern EGLint ( * qeglGetError )(void );
extern EGLDisplay ( * qeglGetDisplay )(EGLNativeDisplayType display_id);
extern EGLBoolean ( * qeglInitialize )(EGLDisplay dpy, EGLint * major, EGLint * minor);
extern EGLBoolean ( * qeglTerminate )(EGLDisplay dpy);
extern const char * ( * qeglQueryString )(EGLDisplay dpy, EGLint name);
extern EGLBoolean ( * qeglGetConfigs )(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config);
extern EGLBoolean ( * qeglChooseConfig )(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config);
extern EGLBoolean ( * qeglGetConfigAttrib )(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value);
extern EGLSurface ( * qeglCreateWindowSurface )(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list);
extern EGLSurface ( * qeglCreatePbufferSurface )(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list);
extern EGLSurface ( * qeglCreatePixmapSurface )(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list);
extern EGLBoolean ( * qeglDestroySurface )(EGLDisplay dpy, EGLSurface surface);
extern EGLBoolean ( * qeglQuerySurface )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value);
extern EGLBoolean ( * qeglBindAPI )(EGLenum api);
extern EGLenum ( * qeglQueryAPI )(void );
extern EGLBoolean ( * qeglWaitClient )(void );
extern EGLBoolean ( * qeglReleaseThread )(void );
extern EGLSurface ( * qeglCreatePbufferFromClientBuffer )(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list);
extern EGLBoolean ( * qeglSurfaceAttrib )(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
extern EGLBoolean ( * qeglBindTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
extern EGLBoolean ( * qeglReleaseTexImage )(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
extern EGLBoolean ( * qeglSwapInterval )(EGLDisplay dpy, EGLint interval);
extern EGLContext ( * qeglCreateContext )(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list);
extern EGLBoolean ( * qeglDestroyContext )(EGLDisplay dpy, EGLContext ctx);
extern EGLBoolean ( * qeglMakeCurrent )(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
extern EGLContext ( * qeglGetCurrentContext )(void );
extern EGLSurface ( * qeglGetCurrentSurface )(EGLint readdraw);
extern EGLDisplay ( * qeglGetCurrentDisplay )(void );
extern EGLBoolean ( * qeglQueryContext )(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value);
extern EGLBoolean ( * qeglWaitGL )(void );
extern EGLBoolean ( * qeglWaitNative )(EGLint engine);
extern EGLBoolean ( * qeglSwapBuffers )(EGLDisplay dpy, EGLSurface surface);
extern EGLBoolean ( * qeglCopyBuffers )(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
extern __eglMustCastToProperFunctionPointerType ( * qeglGetProcAddress )(const char * procname);

// local function in dll
extern void *karinqeglGetProcAddress(const char *symbol);

extern int karinPrintEGL(void);

#ifdef __cplusplus
}
#endif

#endif
