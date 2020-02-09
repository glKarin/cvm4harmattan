#ifndef _KARIN_QGLES1_H
#define _KARIN_QGLES1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <GLES/gl.h>
//#include <GL/glext.h>

#ifndef APIENTRY
#  define APIENTRY
#endif

extern void ( APIENTRY * qglAlphaFunc )(GLenum func, GLclampf ref);
extern void ( APIENTRY * qglClearColor )(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void ( APIENTRY * qglClearDepthf )(GLclampf depth);
extern void ( APIENTRY * qglClipPlanef )(GLenum plane, const GLfloat * equation);
extern void ( APIENTRY * qglColor4f )(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void ( APIENTRY * qglDepthRangef )(GLclampf zNear, GLclampf zFar);
extern void ( APIENTRY * qglFogf )(GLenum pname, GLfloat param);
extern void ( APIENTRY * qglFogfv )(GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglFrustumf )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
extern void ( APIENTRY * qglGetClipPlanef )(GLenum pname, GLfloat eqn[4]);
extern void ( APIENTRY * qglGetFloatv )(GLenum pname, GLfloat * params);
extern void ( APIENTRY * qglGetLightfv )(GLenum light, GLenum pname, GLfloat * params);
extern void ( APIENTRY * qglGetMaterialfv )(GLenum face, GLenum pname, GLfloat * params);
extern void ( APIENTRY * qglGetTexEnvfv )(GLenum env, GLenum pname, GLfloat * params);
extern void ( APIENTRY * qglGetTexParameterfv )(GLenum target, GLenum pname, GLfloat * params);
extern void ( APIENTRY * qglLightModelf )(GLenum pname, GLfloat param);
extern void ( APIENTRY * qglLightModelfv )(GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglLightf )(GLenum light, GLenum pname, GLfloat param);
extern void ( APIENTRY * qglLightfv )(GLenum light, GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglLineWidth )(GLfloat width);
extern void ( APIENTRY * qglLoadMatrixf )(const GLfloat * m);
extern void ( APIENTRY * qglMaterialf )(GLenum face, GLenum pname, GLfloat param);
extern void ( APIENTRY * qglMaterialfv )(GLenum face, GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglMultMatrixf )(const GLfloat * m);
extern void ( APIENTRY * qglMultiTexCoord4f )(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void ( APIENTRY * qglNormal3f )(GLfloat nx, GLfloat ny, GLfloat nz);
extern void ( APIENTRY * qglOrthof )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
extern void ( APIENTRY * qglPointParameterf )(GLenum pname, GLfloat param);
extern void ( APIENTRY * qglPointParameterfv )(GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglPointSize )(GLfloat size);
extern void ( APIENTRY * qglPolygonOffset )(GLfloat factor, GLfloat units);
extern void ( APIENTRY * qglRotatef )(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void ( APIENTRY * qglScalef )(GLfloat x, GLfloat y, GLfloat z);
extern void ( APIENTRY * qglTexEnvf )(GLenum target, GLenum pname, GLfloat param);
extern void ( APIENTRY * qglTexEnvfv )(GLenum target, GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglTexParameterf )(GLenum target, GLenum pname, GLfloat param);
extern void ( APIENTRY * qglTexParameterfv )(GLenum target, GLenum pname, const GLfloat * params);
extern void ( APIENTRY * qglTranslatef )(GLfloat x, GLfloat y, GLfloat z);
extern void ( APIENTRY * qglActiveTexture )(GLenum texture);
extern void ( APIENTRY * qglAlphaFuncx )(GLenum func, GLclampx ref);
extern void ( APIENTRY * qglBindBuffer )(GLenum target, GLuint buffer);
extern void ( APIENTRY * qglBindTexture )(GLenum target, GLuint texture);
extern void ( APIENTRY * qglBlendFunc )(GLenum sfactor, GLenum dfactor);
extern void ( APIENTRY * qglBufferData )(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
extern void ( APIENTRY * qglBufferSubData )(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
extern void ( APIENTRY * qglClear )(GLbitfield mask);
extern void ( APIENTRY * qglClearColorx )(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
extern void ( APIENTRY * qglClearDepthx )(GLclampx depth);
extern void ( APIENTRY * qglClearStencil )(GLint s);
extern void ( APIENTRY * qglClientActiveTexture )(GLenum texture);
extern void ( APIENTRY * qglClipPlanex )(GLenum plane, const GLfixed * equation);
extern void ( APIENTRY * qglColor4ub )(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern void ( APIENTRY * qglColor4x )(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
extern void ( APIENTRY * qglColorMask )(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void ( APIENTRY * qglColorPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
extern void ( APIENTRY * qglCompressedTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
extern void ( APIENTRY * qglCompressedTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
extern void ( APIENTRY * qglCopyTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void ( APIENTRY * qglCopyTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void ( APIENTRY * qglCullFace )(GLenum mode);
extern void ( APIENTRY * qglDeleteBuffers )(GLsizei n, const GLuint * buffers);
extern void ( APIENTRY * qglDeleteTextures )(GLsizei n, const GLuint * textures);
extern void ( APIENTRY * qglDepthFunc )(GLenum func);
extern void ( APIENTRY * qglDepthMask )(GLboolean flag);
extern void ( APIENTRY * qglDepthRangex )(GLclampx zNear, GLclampx zFar);
extern void ( APIENTRY * qglDisable )(GLenum cap);
extern void ( APIENTRY * qglDisableClientState )(GLenum array);
extern void ( APIENTRY * qglDrawArrays )(GLenum mode, GLint first, GLsizei count);
extern void ( APIENTRY * qglDrawElements )(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
extern void ( APIENTRY * qglEnable )(GLenum cap);
extern void ( APIENTRY * qglEnableClientState )(GLenum array);
extern void ( APIENTRY * qglFinish )( void);
extern void ( APIENTRY * qglFlush )( void);
extern void ( APIENTRY * qglFogx )(GLenum pname, GLfixed param);
extern void ( APIENTRY * qglFogxv )(GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglFrontFace )(GLenum mode);
extern void ( APIENTRY * qglFrustumx )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void ( APIENTRY * qglGetBooleanv )(GLenum pname, GLboolean * params);
extern void ( APIENTRY * qglGetBufferParameteriv )(GLenum target, GLenum pname, GLint * params);
extern void ( APIENTRY * qglGetClipPlanex )(GLenum pname, GLfixed eqn[4]);
extern void ( APIENTRY * qglGenBuffers )(GLsizei n, GLuint * buffers);
extern void ( APIENTRY * qglGenTextures )(GLsizei n, GLuint * textures);
extern GLenum ( APIENTRY * qglGetError )( void);
extern void ( APIENTRY * qglGetFixedv )(GLenum pname, GLfixed * params);
extern void ( APIENTRY * qglGetIntegerv )(GLenum pname, GLint * params);
extern void ( APIENTRY * qglGetLightxv )(GLenum light, GLenum pname, GLfixed * params);
extern void ( APIENTRY * qglGetMaterialxv )(GLenum face, GLenum pname, GLfixed * params);
extern void ( APIENTRY * qglGetPointerv )(GLenum pname, void * *params);
extern const GLubyte * ( * APIENTRY qglGetString )(GLenum name);
extern void ( APIENTRY * qglGetTexEnviv )(GLenum env, GLenum pname, GLint * params);
extern void ( APIENTRY * qglGetTexEnvxv )(GLenum env, GLenum pname, GLfixed * params);
extern void ( APIENTRY * qglGetTexParameteriv )(GLenum target, GLenum pname, GLint * params);
extern void ( APIENTRY * qglGetTexParameterxv )(GLenum target, GLenum pname, GLfixed * params);
extern void ( APIENTRY * qglHint )(GLenum target, GLenum mode);
extern GLboolean ( APIENTRY * qglIsBuffer )(GLuint buffer);
extern GLboolean ( APIENTRY * qglIsEnabled )(GLenum cap);
extern GLboolean ( APIENTRY * qglIsTexture )(GLuint texture);
extern void ( APIENTRY * qglLightModelx )(GLenum pname, GLfixed param);
extern void ( APIENTRY * qglLightModelxv )(GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglLightx )(GLenum light, GLenum pname, GLfixed param);
extern void ( APIENTRY * qglLightxv )(GLenum light, GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglLineWidthx )(GLfixed width);
extern void ( APIENTRY * qglLoadIdentity )( void);
extern void ( APIENTRY * qglLoadMatrixx )(const GLfixed * m);
extern void ( APIENTRY * qglLogicOp )(GLenum opcode);
extern void ( APIENTRY * qglMaterialx )(GLenum face, GLenum pname, GLfixed param);
extern void ( APIENTRY * qglMaterialxv )(GLenum face, GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglMatrixMode )(GLenum mode);
extern void ( APIENTRY * qglMultMatrixx )(const GLfixed * m);
extern void ( APIENTRY * qglMultiTexCoord4x )(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
extern void ( APIENTRY * qglNormal3x )(GLfixed nx, GLfixed ny, GLfixed nz);
extern void ( APIENTRY * qglNormalPointer )(GLenum type, GLsizei stride, const GLvoid * pointer);
extern void ( APIENTRY * qglOrthox )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void ( APIENTRY * qglPixelStorei )(GLenum pname, GLint param);
extern void ( APIENTRY * qglPointParameterx )(GLenum pname, GLfixed param);
extern void ( APIENTRY * qglPointParameterxv )(GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglPointSizex )(GLfixed size);
extern void ( APIENTRY * qglPolygonOffsetx )(GLfixed factor, GLfixed units);
extern void ( APIENTRY * qglPopMatrix )( void);
extern void ( APIENTRY * qglPushMatrix )( void);
extern void ( APIENTRY * qglReadPixels )(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
extern void ( APIENTRY * qglRotatex )(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
extern void ( APIENTRY * qglSampleCoverage )(GLclampf value, GLboolean invert);
extern void ( APIENTRY * qglSampleCoveragex )(GLclampx value, GLboolean invert);
extern void ( APIENTRY * qglScalex )(GLfixed x, GLfixed y, GLfixed z);
extern void ( APIENTRY * qglScissor )(GLint x, GLint y, GLsizei width, GLsizei height);
extern void ( APIENTRY * qglShadeModel )(GLenum mode);
extern void ( APIENTRY * qglStencilFunc )(GLenum func, GLint ref, GLuint mask);
extern void ( APIENTRY * qglStencilMask )(GLuint mask);
extern void ( APIENTRY * qglStencilOp )(GLenum fail, GLenum zfail, GLenum zpass);
extern void ( APIENTRY * qglTexCoordPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
extern void ( APIENTRY * qglTexEnvi )(GLenum target, GLenum pname, GLint param);
extern void ( APIENTRY * qglTexEnvx )(GLenum target, GLenum pname, GLfixed param);
extern void ( APIENTRY * qglTexEnviv )(GLenum target, GLenum pname, const GLint * params);
extern void ( APIENTRY * qglTexEnvxv )(GLenum target, GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglTexImage2D )(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
extern void ( APIENTRY * qglTexParameteri )(GLenum target, GLenum pname, GLint param);
extern void ( APIENTRY * qglTexParameterx )(GLenum target, GLenum pname, GLfixed param);
extern void ( APIENTRY * qglTexParameteriv )(GLenum target, GLenum pname, const GLint * params);
extern void ( APIENTRY * qglTexParameterxv )(GLenum target, GLenum pname, const GLfixed * params);
extern void ( APIENTRY * qglTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
extern void ( APIENTRY * qglTranslatex )(GLfixed x, GLfixed y, GLfixed z);
extern void ( APIENTRY * qglVertexPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
extern void ( APIENTRY * qglViewport )(GLint x, GLint y, GLsizei width, GLsizei height);
extern void ( APIENTRY * qglPointSizePointerOES )(GLenum type, GLsizei stride, const GLvoid * pointer);

extern void ( APIENTRY * qglLockArraysEXT)( int, int);
extern void ( APIENTRY * qglUnlockArraysEXT) ( void );

extern void ( APIENTRY * qglPointParameterfEXT)( GLenum param, GLfloat value );
extern void ( APIENTRY * qglPointParameterfvEXT)( GLenum param, const GLfloat *value );
extern void ( APIENTRY * qglColorTableEXT)( GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid * );

extern void ( APIENTRY * qgl3DfxSetPaletteEXT)( GLuint * );
extern void ( APIENTRY * qglSelectTextureSGIS)( GLenum );
extern void ( APIENTRY * qglMTexCoord2fSGIS)( GLenum, GLfloat, GLfloat );
extern void ( APIENTRY * qglActiveTextureARB) ( GLenum );
extern void ( APIENTRY * qglClientActiveTextureARB) ( GLenum );

// local function in dll
extern void *karinqglGetProcAddress(const char *symbol);

extern int karinPrintGL(void);

#ifdef __cplusplus
}
#endif

#endif
