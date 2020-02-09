static FILE *gles1_log_fp = NULL;
static DLFcn_t gles1;

// extern func ptr
void ( APIENTRY * qglAlphaFunc )(GLenum func, GLclampf ref);
void ( APIENTRY * qglClearColor )(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void ( APIENTRY * qglClearDepthf )(GLclampf depth);
void ( APIENTRY * qglClipPlanef )(GLenum plane, const GLfloat *equation);
void ( APIENTRY * qglColor4f )(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void ( APIENTRY * qglDepthRangef )(GLclampf zNear, GLclampf zFar);
void ( APIENTRY * qglFogf )(GLenum pname, GLfloat param);
void ( APIENTRY * qglFogfv )(GLenum pname, const GLfloat *params);
void ( APIENTRY * qglFrustumf )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
void ( APIENTRY * qglGetClipPlanef )(GLenum pname, GLfloat eqn[4]);
void ( APIENTRY * qglGetFloatv )(GLenum pname, GLfloat *params);
void ( APIENTRY * qglGetLightfv )(GLenum light, GLenum pname, GLfloat *params);
void ( APIENTRY * qglGetMaterialfv )(GLenum face, GLenum pname, GLfloat *params);
void ( APIENTRY * qglGetTexEnvfv )(GLenum env, GLenum pname, GLfloat *params);
void ( APIENTRY * qglGetTexParameterfv )(GLenum target, GLenum pname, GLfloat *params);
void ( APIENTRY * qglLightModelf )(GLenum pname, GLfloat param);
void ( APIENTRY * qglLightModelfv )(GLenum pname, const GLfloat *params);
void ( APIENTRY * qglLightf )(GLenum light, GLenum pname, GLfloat param);
void ( APIENTRY * qglLightfv )(GLenum light, GLenum pname, const GLfloat *params);
void ( APIENTRY * qglLineWidth )(GLfloat width);
void ( APIENTRY * qglLoadMatrixf )(const GLfloat *m);
void ( APIENTRY * qglMaterialf )(GLenum face, GLenum pname, GLfloat param);
void ( APIENTRY * qglMaterialfv )(GLenum face, GLenum pname, const GLfloat *params);
void ( APIENTRY * qglMultMatrixf )(const GLfloat *m);
void ( APIENTRY * qglMultiTexCoord4f )(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void ( APIENTRY * qglNormal3f )(GLfloat nx, GLfloat ny, GLfloat nz);
void ( APIENTRY * qglOrthof )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
void ( APIENTRY * qglPointParameterf )(GLenum pname, GLfloat param);
void ( APIENTRY * qglPointParameterfv )(GLenum pname, const GLfloat *params);
void ( APIENTRY * qglPointSize )(GLfloat size);
void ( APIENTRY * qglPolygonOffset )(GLfloat factor, GLfloat units);
void ( APIENTRY * qglRotatef )(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void ( APIENTRY * qglScalef )(GLfloat x, GLfloat y, GLfloat z);
void ( APIENTRY * qglTexEnvf )(GLenum target, GLenum pname, GLfloat param);
void ( APIENTRY * qglTexEnvfv )(GLenum target, GLenum pname, const GLfloat *params);
void ( APIENTRY * qglTexParameterf )(GLenum target, GLenum pname, GLfloat param);
void ( APIENTRY * qglTexParameterfv )(GLenum target, GLenum pname, const GLfloat *params);
void ( APIENTRY * qglTranslatef )(GLfloat x, GLfloat y, GLfloat z);
void ( APIENTRY * qglActiveTexture )(GLenum texture);
void ( APIENTRY * qglAlphaFuncx )(GLenum func, GLclampx ref);
void ( APIENTRY * qglBindBuffer )(GLenum target, GLuint buffer);
void ( APIENTRY * qglBindTexture )(GLenum target, GLuint texture);
void ( APIENTRY * qglBlendFunc )(GLenum sfactor, GLenum dfactor);
void ( APIENTRY * qglBufferData )(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
void ( APIENTRY * qglBufferSubData )(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
void ( APIENTRY * qglClear )(GLbitfield mask);
void ( APIENTRY * qglClearColorx )(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
void ( APIENTRY * qglClearDepthx )(GLclampx depth);
void ( APIENTRY * qglClearStencil )(GLint s);
void ( APIENTRY * qglClientActiveTexture )(GLenum texture);
void ( APIENTRY * qglClipPlanex )(GLenum plane, const GLfixed *equation);
void ( APIENTRY * qglColor4ub )(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void ( APIENTRY * qglColor4x )(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void ( APIENTRY * qglColorMask )(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void ( APIENTRY * qglColorPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void ( APIENTRY * qglCompressedTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
void ( APIENTRY * qglCompressedTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void ( APIENTRY * qglCopyTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void ( APIENTRY * qglCopyTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void ( APIENTRY * qglCullFace )(GLenum mode);
void ( APIENTRY * qglDeleteBuffers )(GLsizei n, const GLuint *buffers);
void ( APIENTRY * qglDeleteTextures )(GLsizei n, const GLuint *textures);
void ( APIENTRY * qglDepthFunc )(GLenum func);
void ( APIENTRY * qglDepthMask )(GLboolean flag);
void ( APIENTRY * qglDepthRangex )(GLclampx zNear, GLclampx zFar);
void ( APIENTRY * qglDisable )(GLenum cap);
void ( APIENTRY * qglDisableClientState )(GLenum array);
void ( APIENTRY * qglDrawArrays )(GLenum mode, GLint first, GLsizei count);
void ( APIENTRY * qglDrawElements )(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void ( APIENTRY * qglEnable )(GLenum cap);
void ( APIENTRY * qglEnableClientState )(GLenum array);
void ( APIENTRY * qglFinish )( void);
void ( APIENTRY * qglFlush )( void);
void ( APIENTRY * qglFogx )(GLenum pname, GLfixed param);
void ( APIENTRY * qglFogxv )(GLenum pname, const GLfixed *params);
void ( APIENTRY * qglFrontFace )(GLenum mode);
void ( APIENTRY * qglFrustumx )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
void ( APIENTRY * qglGetBooleanv )(GLenum pname, GLboolean *params);
void ( APIENTRY * qglGetBufferParameteriv )(GLenum target, GLenum pname, GLint *params);
void ( APIENTRY * qglGetClipPlanex )(GLenum pname, GLfixed eqn[4]);
void ( APIENTRY * qglGenBuffers )(GLsizei n, GLuint *buffers);
void ( APIENTRY * qglGenTextures )(GLsizei n, GLuint *textures);
GLenum ( APIENTRY * qglGetError )( void);
void ( APIENTRY * qglGetFixedv )(GLenum pname, GLfixed *params);
void ( APIENTRY * qglGetIntegerv )(GLenum pname, GLint *params);
void ( APIENTRY * qglGetLightxv )(GLenum light, GLenum pname, GLfixed *params);
void ( APIENTRY * qglGetMaterialxv )(GLenum face, GLenum pname, GLfixed *params);
void ( APIENTRY * qglGetPointerv )(GLenum pname, void **params);
const GLubyte * ( APIENTRY * qglGetString )(GLenum name);
void ( APIENTRY * qglGetTexEnviv )(GLenum env, GLenum pname, GLint *params);
void ( APIENTRY * qglGetTexEnvxv )(GLenum env, GLenum pname, GLfixed *params);
void ( APIENTRY * qglGetTexParameteriv )(GLenum target, GLenum pname, GLint *params);
void ( APIENTRY * qglGetTexParameterxv )(GLenum target, GLenum pname, GLfixed *params);
void ( APIENTRY * qglHint )(GLenum target, GLenum mode);
GLboolean ( APIENTRY * qglIsBuffer )(GLuint buffer);
GLboolean ( APIENTRY * qglIsEnabled )(GLenum cap);
GLboolean ( APIENTRY * qglIsTexture )(GLuint texture);
void ( APIENTRY * qglLightModelx )(GLenum pname, GLfixed param);
void ( APIENTRY * qglLightModelxv )(GLenum pname, const GLfixed *params);
void ( APIENTRY * qglLightx )(GLenum light, GLenum pname, GLfixed param);
void ( APIENTRY * qglLightxv )(GLenum light, GLenum pname, const GLfixed *params);
void ( APIENTRY * qglLineWidthx )(GLfixed width);
void ( APIENTRY * qglLoadIdentity )( void);
void ( APIENTRY * qglLoadMatrixx )(const GLfixed *m);
void ( APIENTRY * qglLogicOp )(GLenum opcode);
void ( APIENTRY * qglMaterialx )(GLenum face, GLenum pname, GLfixed param);
void ( APIENTRY * qglMaterialxv )(GLenum face, GLenum pname, const GLfixed *params);
void ( APIENTRY * qglMatrixMode )(GLenum mode);
void ( APIENTRY * qglMultMatrixx )(const GLfixed *m);
void ( APIENTRY * qglMultiTexCoord4x )(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void ( APIENTRY * qglNormal3x )(GLfixed nx, GLfixed ny, GLfixed nz);
void ( APIENTRY * qglNormalPointer )(GLenum type, GLsizei stride, const GLvoid *pointer);
void ( APIENTRY * qglOrthox )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
void ( APIENTRY * qglPixelStorei )(GLenum pname, GLint param);
void ( APIENTRY * qglPointParameterx )(GLenum pname, GLfixed param);
void ( APIENTRY * qglPointParameterxv )(GLenum pname, const GLfixed *params);
void ( APIENTRY * qglPointSizex )(GLfixed size);
void ( APIENTRY * qglPolygonOffsetx )(GLfixed factor, GLfixed units);
void ( APIENTRY * qglPopMatrix )( void);
void ( APIENTRY * qglPushMatrix )( void);
void ( APIENTRY * qglReadPixels )(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void ( APIENTRY * qglRotatex )(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void ( APIENTRY * qglSampleCoverage )(GLclampf value, GLboolean invert);
void ( APIENTRY * qglSampleCoveragex )(GLclampx value, GLboolean invert);
void ( APIENTRY * qglScalex )(GLfixed x, GLfixed y, GLfixed z);
void ( APIENTRY * qglScissor )(GLint x, GLint y, GLsizei width, GLsizei height);
void ( APIENTRY * qglShadeModel )(GLenum mode);
void ( APIENTRY * qglStencilFunc )(GLenum func, GLint ref, GLuint mask);
void ( APIENTRY * qglStencilMask )(GLuint mask);
void ( APIENTRY * qglStencilOp )(GLenum fail, GLenum zfail, GLenum zpass);
void ( APIENTRY * qglTexCoordPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void ( APIENTRY * qglTexEnvi )(GLenum target, GLenum pname, GLint param);
void ( APIENTRY * qglTexEnvx )(GLenum target, GLenum pname, GLfixed param);
void ( APIENTRY * qglTexEnviv )(GLenum target, GLenum pname, const GLint *params);
void ( APIENTRY * qglTexEnvxv )(GLenum target, GLenum pname, const GLfixed *params);
void ( APIENTRY * qglTexImage2D )(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void ( APIENTRY * qglTexParameteri )(GLenum target, GLenum pname, GLint param);
void ( APIENTRY * qglTexParameterx )(GLenum target, GLenum pname, GLfixed param);
void ( APIENTRY * qglTexParameteriv )(GLenum target, GLenum pname, const GLint *params);
void ( APIENTRY * qglTexParameterxv )(GLenum target, GLenum pname, const GLfixed *params);
void ( APIENTRY * qglTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void ( APIENTRY * qglTranslatex )(GLfixed x, GLfixed y, GLfixed z);
void ( APIENTRY * qglVertexPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void ( APIENTRY * qglViewport )(GLint x, GLint y, GLsizei width, GLsizei height);
void ( APIENTRY * qglPointSizePointerOES )(GLenum type, GLsizei stride, const GLvoid *pointer);

// ori func ptr
static void ( APIENTRY * dllAlphaFunc )(GLenum func, GLclampf ref);
static void ( APIENTRY * dllClearColor )(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
static void ( APIENTRY * dllClearDepthf )(GLclampf depth);
static void ( APIENTRY * dllClipPlanef )(GLenum plane, const GLfloat *equation);
static void ( APIENTRY * dllColor4f )(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
static void ( APIENTRY * dllDepthRangef )(GLclampf zNear, GLclampf zFar);
static void ( APIENTRY * dllFogf )(GLenum pname, GLfloat param);
static void ( APIENTRY * dllFogfv )(GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllFrustumf )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
static void ( APIENTRY * dllGetClipPlanef )(GLenum pname, GLfloat eqn[4]);
static void ( APIENTRY * dllGetFloatv )(GLenum pname, GLfloat *params);
static void ( APIENTRY * dllGetLightfv )(GLenum light, GLenum pname, GLfloat *params);
static void ( APIENTRY * dllGetMaterialfv )(GLenum face, GLenum pname, GLfloat *params);
static void ( APIENTRY * dllGetTexEnvfv )(GLenum env, GLenum pname, GLfloat *params);
static void ( APIENTRY * dllGetTexParameterfv )(GLenum target, GLenum pname, GLfloat *params);
static void ( APIENTRY * dllLightModelf )(GLenum pname, GLfloat param);
static void ( APIENTRY * dllLightModelfv )(GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllLightf )(GLenum light, GLenum pname, GLfloat param);
static void ( APIENTRY * dllLightfv )(GLenum light, GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllLineWidth )(GLfloat width);
static void ( APIENTRY * dllLoadMatrixf )(const GLfloat *m);
static void ( APIENTRY * dllMaterialf )(GLenum face, GLenum pname, GLfloat param);
static void ( APIENTRY * dllMaterialfv )(GLenum face, GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllMultMatrixf )(const GLfloat *m);
static void ( APIENTRY * dllMultiTexCoord4f )(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
static void ( APIENTRY * dllNormal3f )(GLfloat nx, GLfloat ny, GLfloat nz);
static void ( APIENTRY * dllOrthof )(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
static void ( APIENTRY * dllPointParameterf )(GLenum pname, GLfloat param);
static void ( APIENTRY * dllPointParameterfv )(GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllPointSize )(GLfloat size);
static void ( APIENTRY * dllPolygonOffset )(GLfloat factor, GLfloat units);
static void ( APIENTRY * dllRotatef )(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
static void ( APIENTRY * dllScalef )(GLfloat x, GLfloat y, GLfloat z);
static void ( APIENTRY * dllTexEnvf )(GLenum target, GLenum pname, GLfloat param);
static void ( APIENTRY * dllTexEnvfv )(GLenum target, GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllTexParameterf )(GLenum target, GLenum pname, GLfloat param);
static void ( APIENTRY * dllTexParameterfv )(GLenum target, GLenum pname, const GLfloat *params);
static void ( APIENTRY * dllTranslatef )(GLfloat x, GLfloat y, GLfloat z);
static void ( APIENTRY * dllActiveTexture )(GLenum texture);
static void ( APIENTRY * dllAlphaFuncx )(GLenum func, GLclampx ref);
static void ( APIENTRY * dllBindBuffer )(GLenum target, GLuint buffer);
static void ( APIENTRY * dllBindTexture )(GLenum target, GLuint texture);
static void ( APIENTRY * dllBlendFunc )(GLenum sfactor, GLenum dfactor);
static void ( APIENTRY * dllBufferData )(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
static void ( APIENTRY * dllBufferSubData )(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
static void ( APIENTRY * dllClear )(GLbitfield mask);
static void ( APIENTRY * dllClearColorx )(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
static void ( APIENTRY * dllClearDepthx )(GLclampx depth);
static void ( APIENTRY * dllClearStencil )(GLint s);
static void ( APIENTRY * dllClientActiveTexture )(GLenum texture);
static void ( APIENTRY * dllClipPlanex )(GLenum plane, const GLfixed *equation);
static void ( APIENTRY * dllColor4ub )(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
static void ( APIENTRY * dllColor4x )(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
static void ( APIENTRY * dllColorMask )(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
static void ( APIENTRY * dllColorPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void ( APIENTRY * dllCompressedTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
static void ( APIENTRY * dllCompressedTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
static void ( APIENTRY * dllCopyTexImage2D )(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
static void ( APIENTRY * dllCopyTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
static void ( APIENTRY * dllCullFace )(GLenum mode);
static void ( APIENTRY * dllDeleteBuffers )(GLsizei n, const GLuint *buffers);
static void ( APIENTRY * dllDeleteTextures )(GLsizei n, const GLuint *textures);
static void ( APIENTRY * dllDepthFunc )(GLenum func);
static void ( APIENTRY * dllDepthMask )(GLboolean flag);
static void ( APIENTRY * dllDepthRangex )(GLclampx zNear, GLclampx zFar);
static void ( APIENTRY * dllDisable )(GLenum cap);
static void ( APIENTRY * dllDisableClientState )(GLenum array);
static void ( APIENTRY * dllDrawArrays )(GLenum mode, GLint first, GLsizei count);
static void ( APIENTRY * dllDrawElements )(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
static void ( APIENTRY * dllEnable )(GLenum cap);
static void ( APIENTRY * dllEnableClientState )(GLenum array);
static void ( APIENTRY * dllFinish )( void);
static void ( APIENTRY * dllFlush )( void);
static void ( APIENTRY * dllFogx )(GLenum pname, GLfixed param);
static void ( APIENTRY * dllFogxv )(GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllFrontFace )(GLenum mode);
static void ( APIENTRY * dllFrustumx )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
static void ( APIENTRY * dllGetBooleanv )(GLenum pname, GLboolean *params);
static void ( APIENTRY * dllGetBufferParameteriv )(GLenum target, GLenum pname, GLint *params);
static void ( APIENTRY * dllGetClipPlanex )(GLenum pname, GLfixed eqn[4]);
static void ( APIENTRY * dllGenBuffers )(GLsizei n, GLuint *buffers);
static void ( APIENTRY * dllGenTextures )(GLsizei n, GLuint *textures);
static GLenum ( APIENTRY * dllGetError )( void);
static void ( APIENTRY * dllGetFixedv )(GLenum pname, GLfixed *params);
static void ( APIENTRY * dllGetIntegerv )(GLenum pname, GLint *params);
static void ( APIENTRY * dllGetLightxv )(GLenum light, GLenum pname, GLfixed *params);
static void ( APIENTRY * dllGetMaterialxv )(GLenum face, GLenum pname, GLfixed *params);
static void ( APIENTRY * dllGetPointerv )(GLenum pname, void **params);
static const GLubyte * ( APIENTRY * dllGetString )(GLenum name);
static void ( APIENTRY * dllGetTexEnviv )(GLenum env, GLenum pname, GLint *params);
static void ( APIENTRY * dllGetTexEnvxv )(GLenum env, GLenum pname, GLfixed *params);
static void ( APIENTRY * dllGetTexParameteriv )(GLenum target, GLenum pname, GLint *params);
static void ( APIENTRY * dllGetTexParameterxv )(GLenum target, GLenum pname, GLfixed *params);
static void ( APIENTRY * dllHint )(GLenum target, GLenum mode);
static GLboolean ( APIENTRY * dllIsBuffer )(GLuint buffer);
static GLboolean ( APIENTRY * dllIsEnabled )(GLenum cap);
static GLboolean ( APIENTRY * dllIsTexture )(GLuint texture);
static void ( APIENTRY * dllLightModelx )(GLenum pname, GLfixed param);
static void ( APIENTRY * dllLightModelxv )(GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllLightx )(GLenum light, GLenum pname, GLfixed param);
static void ( APIENTRY * dllLightxv )(GLenum light, GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllLineWidthx )(GLfixed width);
static void ( APIENTRY * dllLoadIdentity )( void);
static void ( APIENTRY * dllLoadMatrixx )(const GLfixed *m);
static void ( APIENTRY * dllLogicOp )(GLenum opcode);
static void ( APIENTRY * dllMaterialx )(GLenum face, GLenum pname, GLfixed param);
static void ( APIENTRY * dllMaterialxv )(GLenum face, GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllMatrixMode )(GLenum mode);
static void ( APIENTRY * dllMultMatrixx )(const GLfixed *m);
static void ( APIENTRY * dllMultiTexCoord4x )(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
static void ( APIENTRY * dllNormal3x )(GLfixed nx, GLfixed ny, GLfixed nz);
static void ( APIENTRY * dllNormalPointer )(GLenum type, GLsizei stride, const GLvoid *pointer);
static void ( APIENTRY * dllOrthox )(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
static void ( APIENTRY * dllPixelStorei )(GLenum pname, GLint param);
static void ( APIENTRY * dllPointParameterx )(GLenum pname, GLfixed param);
static void ( APIENTRY * dllPointParameterxv )(GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllPointSizex )(GLfixed size);
static void ( APIENTRY * dllPolygonOffsetx )(GLfixed factor, GLfixed units);
static void ( APIENTRY * dllPopMatrix )( void);
static void ( APIENTRY * dllPushMatrix )( void);
static void ( APIENTRY * dllReadPixels )(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
static void ( APIENTRY * dllRotatex )(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
static void ( APIENTRY * dllSampleCoverage )(GLclampf value, GLboolean invert);
static void ( APIENTRY * dllSampleCoveragex )(GLclampx value, GLboolean invert);
static void ( APIENTRY * dllScalex )(GLfixed x, GLfixed y, GLfixed z);
static void ( APIENTRY * dllScissor )(GLint x, GLint y, GLsizei width, GLsizei height);
static void ( APIENTRY * dllShadeModel )(GLenum mode);
static void ( APIENTRY * dllStencilFunc )(GLenum func, GLint ref, GLuint mask);
static void ( APIENTRY * dllStencilMask )(GLuint mask);
static void ( APIENTRY * dllStencilOp )(GLenum fail, GLenum zfail, GLenum zpass);
static void ( APIENTRY * dllTexCoordPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void ( APIENTRY * dllTexEnvi )(GLenum target, GLenum pname, GLint param);
static void ( APIENTRY * dllTexEnvx )(GLenum target, GLenum pname, GLfixed param);
static void ( APIENTRY * dllTexEnviv )(GLenum target, GLenum pname, const GLint *params);
static void ( APIENTRY * dllTexEnvxv )(GLenum target, GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllTexImage2D )(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
static void ( APIENTRY * dllTexParameteri )(GLenum target, GLenum pname, GLint param);
static void ( APIENTRY * dllTexParameterx )(GLenum target, GLenum pname, GLfixed param);
static void ( APIENTRY * dllTexParameteriv )(GLenum target, GLenum pname, const GLint *params);
static void ( APIENTRY * dllTexParameterxv )(GLenum target, GLenum pname, const GLfixed *params);
static void ( APIENTRY * dllTexSubImage2D )(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
static void ( APIENTRY * dllTranslatex )(GLfixed x, GLfixed y, GLfixed z);
static void ( APIENTRY * dllVertexPointer )(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
static void ( APIENTRY * dllViewport )(GLint x, GLint y, GLsizei width, GLsizei height);
static void ( APIENTRY * dllPointSizePointerOES )(GLenum type, GLsizei stride, const GLvoid *pointer);

// log func ptr
#define PRINT_GL_ERROR_DEVICE stdout
#define PRINT_GL_CALL_DEVICE stdout

static void APIENTRY logAlphaFunc(GLenum func, GLclampf ref)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glAlphaFunc( 0x%X, %f )\n", func, ref );
	dllAlphaFunc(func, ref);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClearColor( %f, %f, %f, %f )\n", red, green, blue, alpha );
	dllClearColor(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClearDepthf(GLclampf depth)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClearDepthf( %f )\n", depth );
	dllClearDepthf(depth);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClipPlanef(GLenum plane, const GLfloat * equation)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClipPlanef( 0x%X, %p )\n", plane, equation );
	dllClipPlanef(plane, equation);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glColor4f( %f, %f, %f, %f )\n", red, green, blue, alpha );
	dllColor4f(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDepthRangef(GLclampf zNear, GLclampf zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDepthRangef( %f, %f )\n", zNear, zFar );
	dllDepthRangef(zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFogf(GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFogf( 0x%X, %f )\n", pname, param );
	dllFogf(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFogfv(GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFogfv( 0x%X, %p )\n", pname, params );
	dllFogfv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFrustumf( %f, %f, %f, %f, %f, %f )\n", left, right, bottom, top, zNear, zFar );
	dllFrustumf(left, right, bottom, top, zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetClipPlanef(GLenum pname, GLfloat eqn[4])
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetClipPlanef( 0x%X, %p )\n", pname, eqn );
	dllGetClipPlanef(pname, eqn);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetFloatv(GLenum pname, GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetFloatv( 0x%X, %p )\n", pname, params );
	dllGetFloatv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetLightfv(GLenum light, GLenum pname, GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetLightfv( 0x%X, 0x%X, %p )\n", light, pname, params );
	dllGetLightfv(light, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetMaterialfv(GLenum face, GLenum pname, GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetMaterialfv( 0x%X, 0x%X, %p )\n", face, pname, params );
	dllGetMaterialfv(face, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetTexEnvfv(GLenum env, GLenum pname, GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexEnvfv( 0x%X, 0x%X, %p )\n", env, pname, params );
	dllGetTexEnvfv(env, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexParameterfv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllGetTexParameterfv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightModelf(GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightModelf( 0x%X, %f )\n", pname, param );
	dllLightModelf(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightModelfv(GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightModelfv( 0x%X, %p )\n", pname, params );
	dllLightModelfv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightf(GLenum light, GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightf( 0x%X, 0x%X, %f )\n", light, pname, param );
	dllLightf(light, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightfv(GLenum light, GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightfv( 0x%X, 0x%X, %p )\n", light, pname, params );
	dllLightfv(light, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLineWidth(GLfloat width)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLineWidth( %f )\n", width );
	dllLineWidth(width);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLoadMatrixf(const GLfloat * m)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLoadMatrixf( %p )\n", m );
	dllLoadMatrixf(m);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMaterialf(GLenum face, GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMaterialf( 0x%X, 0x%X, %f )\n", face, pname, param );
	dllMaterialf(face, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMaterialfv(GLenum face, GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMaterialfv( 0x%X, 0x%X, %p )\n", face, pname, params );
	dllMaterialfv(face, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMultMatrixf(const GLfloat * m)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMultMatrixf( %p )\n", m );
	dllMultMatrixf(m);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMultiTexCoord4f( 0x%X, %f, %f, %f, %f )\n", target, s, t, r, q );
	dllMultiTexCoord4f(target, s, t, r, q);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logNormal3f(GLfloat nx, GLfloat ny, GLfloat nz)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glNormal3f( %f, %f, %f )\n", nx, ny, nz );
	dllNormal3f(nx, ny, nz);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glOrthof( %f, %f, %f, %f, %f, %f )\n", left, right, bottom, top, zNear, zFar );
	dllOrthof(left, right, bottom, top, zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointParameterf(GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointParameterf( 0x%X, %f )\n", pname, param );
	dllPointParameterf(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointParameterfv(GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointParameterfv( 0x%X, %p )\n", pname, params );
	dllPointParameterfv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointSize(GLfloat size)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointSize( %f )\n", size );
	dllPointSize(size);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPolygonOffset(GLfloat factor, GLfloat units)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPolygonOffset( %f, %f )\n", factor, units );
	dllPolygonOffset(factor, units);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glRotatef( %f, %f, %f, %f )\n", angle, x, y, z );
	dllRotatef(angle, x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logScalef(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glScalef( %f, %f, %f )\n", x, y, z );
	dllScalef(x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnvf( 0x%X, 0x%X, %f )\n", target, pname, param );
	dllTexEnvf(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnvfv(GLenum target, GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnvfv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexEnvfv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameterf( 0x%X, 0x%X, %f )\n", target, pname, param );
	dllTexParameterf(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameterfv(GLenum target, GLenum pname, const GLfloat * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameterfv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexParameterfv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTranslatef( %f, %f, %f )\n", x, y, z );
	dllTranslatef(x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logActiveTexture(GLenum texture)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glActiveTexture( 0x%X )\n", texture );
	dllActiveTexture(texture);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logAlphaFuncx(GLenum func, GLclampx ref)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glAlphaFuncx( 0x%X, %+d )\n", func, ref );
	dllAlphaFuncx(func, ref);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logBindBuffer(GLenum target, GLuint buffer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glBindBuffer( 0x%X, %d )\n", target, buffer );
	dllBindBuffer(target, buffer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logBindTexture(GLenum target, GLuint texture)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glBindTexture( 0x%X, %d )\n", target, texture );
	dllBindTexture(target, texture);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logBlendFunc(GLenum sfactor, GLenum dfactor)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glBlendFunc( 0x%X, 0x%X )\n", sfactor, dfactor );
	dllBlendFunc(sfactor, dfactor);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glBufferData( 0x%X, %d, %p, 0x%X )\n", target, size, data, usage );
	dllBufferData(target, size, data, usage);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glBufferSubData( 0x%X, %d, %d, %p )\n", target, offset, size, data );
	dllBufferSubData(target, offset, size, data);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClear(GLbitfield mask)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClear( 0x%X )\n", mask );
	dllClear(mask);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClearColorx( %+d, %+d, %+d, %+d )\n", red, green, blue, alpha );
	dllClearColorx(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClearDepthx(GLclampx depth)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClearDepthx( %+d )\n", depth );
	dllClearDepthx(depth);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClearStencil(GLint s)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClearStencil( %+d )\n", s );
	dllClearStencil(s);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClientActiveTexture(GLenum texture)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClientActiveTexture( 0x%X )\n", texture );
	dllClientActiveTexture(texture);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logClipPlanex(GLenum plane, const GLfixed * equation)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glClipPlanex( 0x%X, %p )\n", plane, equation );
	dllClipPlanex(plane, equation);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glColor4ub( %d, %d, %d, %d )\n", red, green, blue, alpha );
	dllColor4ub(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glColor4x( %+d, %+d, %+d, %+d )\n", red, green, blue, alpha );
	dllColor4x(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glColorMask( %+d, %+d, %+d, %+d )\n", red, green, blue, alpha );
	dllColorMask(red, green, blue, alpha);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glColorPointer( %+d, 0x%X, %+d, %p )\n", size, type, stride, pointer );
	dllColorPointer(size, type, stride, pointer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glCompressedTexImage2D( 0x%X, %+d, 0x%X, %+d, %+d, %+d, %+d, %p )\n", target, level, internalformat, width, height, border, imageSize, data );
	dllCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glCompressedTexSubImage2D( 0x%X, %+d, %+d, %+d, %+d, %+d, 0x%X, %+d, %p )\n", target, level, xoffset, yoffset, width, height, format, imageSize, data );
	dllCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glCopyTexImage2D( 0x%X, %+d, 0x%X, %+d, %+d, %+d, %+d, %+d )\n", target, level, internalformat, x, y, width, height, border );
	dllCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glCopyTexSubImage2D( 0x%X, %+d, %+d, %+d, %+d, %+d, %+d, %+d )\n", target, level, xoffset, yoffset, x, y, width, height );
	dllCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logCullFace(GLenum mode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glCullFace( 0x%X )\n", mode );
	dllCullFace(mode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDeleteBuffers(GLsizei n, const GLuint * buffers)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDeleteBuffers( %+d, %p )\n", n, buffers );
	dllDeleteBuffers(n, buffers);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDeleteTextures(GLsizei n, const GLuint * textures)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDeleteTextures( %+d, %p )\n", n, textures );
	dllDeleteTextures(n, textures);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDepthFunc(GLenum func)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDepthFunc( 0x%X )\n", func );
	dllDepthFunc(func);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDepthMask(GLboolean flag)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDepthMask( %+d )\n", flag );
	dllDepthMask(flag);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDepthRangex(GLclampx zNear, GLclampx zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDepthRangex( %+d, %+d )\n", zNear, zFar );
	dllDepthRangex(zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDisable(GLenum cap)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDisable( 0x%X )\n", cap );
	dllDisable(cap);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDisableClientState(GLenum array)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDisableClientState( 0x%X )\n", array );
	dllDisableClientState(array);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDrawArrays( 0x%X, %+d, %+d )\n", mode, first, count );
	dllDrawArrays(mode, first, count);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glDrawElements( 0x%X, %+d, 0x%X, %p )\n", mode, count, type, indices );
	dllDrawElements(mode, count, type, indices);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logEnable(GLenum cap)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glEnable( 0x%X )\n", cap );
	dllEnable(cap);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logEnableClientState(GLenum array)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glEnableClientState( 0x%X )\n", array );
	dllEnableClientState(array);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFinish(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFinish()\n" );
	dllFinish();
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFlush(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFlush()\n" );
	dllFlush();
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFogx(GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFogx( 0x%X, %+d )\n", pname, param );
	dllFogx(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFogxv(GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFogxv( 0x%X, %p )\n", pname, params );
	dllFogxv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFrontFace(GLenum mode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFrontFace( 0x%X )\n", mode );
	dllFrontFace(mode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glFrustumx( %+d, %+d, %+d, %+d, %+d, %+d )\n", left, right, bottom, top, zNear, zFar );
	dllFrustumx(left, right, bottom, top, zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetBooleanv(GLenum pname, GLboolean * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetBooleanv( 0x%X, %p )\n", pname, params );
	dllGetBooleanv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetBufferParameteriv(GLenum target, GLenum pname, GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetBufferParameteriv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllGetBufferParameteriv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetClipPlanex(GLenum pname, GLfixed eqn[4])
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetClipPlanex( 0x%X, %p )\n", pname, eqn );
	dllGetClipPlanex(pname, eqn);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGenBuffers(GLsizei n, GLuint * buffers)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGenBuffers( %+d, %p )\n", n, buffers );
	dllGenBuffers(n, buffers);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGenTextures(GLsizei n, GLuint * textures)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGenTextures( %+d, %p )\n", n, textures );
	dllGenTextures(n, textures);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static GLenum APIENTRY logGetError(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetError()" );
	GLenum ret = dllGetError();
	fprintf( PRINT_GL_CALL_DEVICE, " -> 0x%X\n", ret );
	/*
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
	*/
	return ret;
}

static void APIENTRY logGetFixedv(GLenum pname, GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetFixedv( 0x%X, %p )\n", pname, params );
	dllGetFixedv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetIntegerv(GLenum pname, GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetIntegerv( 0x%X, %p )\n", pname, params );
	dllGetIntegerv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetLightxv(GLenum light, GLenum pname, GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetLightxv( 0x%X, 0x%X, %p )\n", light, pname, params );
	dllGetLightxv(light, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetMaterialxv(GLenum face, GLenum pname, GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetMaterialxv( 0x%X, 0x%X, %p )\n", face, pname, params );
	dllGetMaterialxv(face, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetPointerv(GLenum pname, void * *params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetPointerv( 0x%X, %p )\n", pname, *params );
	dllGetPointerv(pname, *params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static const GLubyte * APIENTRY logGetString(GLenum name)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetString( 0x%X )", name );
	const GLubyte *ret = dllGetString(name);
	fprintf( PRINT_GL_CALL_DEVICE, " -> %s\n", ret );
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
	return ret;
}

static void APIENTRY logGetTexEnviv(GLenum env, GLenum pname, GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexEnviv( 0x%X, 0x%X, %p )\n", env, pname, params );
	dllGetTexEnviv(env, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetTexEnvxv(GLenum env, GLenum pname, GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexEnvxv( 0x%X, 0x%X, %p )\n", env, pname, params );
	dllGetTexEnvxv(env, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetTexParameteriv(GLenum target, GLenum pname, GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexParameteriv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllGetTexParameteriv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glGetTexParameterxv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllGetTexParameterxv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logHint(GLenum target, GLenum mode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glHint( 0x%X, 0x%X )\n", target, mode );
	dllHint(target, mode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static GLboolean APIENTRY logIsBuffer(GLuint buffer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glIsBuffer( %d )", buffer );
	GLboolean ret = dllIsBuffer(buffer);
	fprintf( PRINT_GL_CALL_DEVICE, " -> %d\n", ret );
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
	return ret;
}

static GLboolean APIENTRY logIsEnabled(GLenum cap)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glIsEnabled( 0x%X )", cap );
	GLboolean ret = dllIsEnabled(cap);
	fprintf( PRINT_GL_CALL_DEVICE, " -> %d\n", ret );
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
	return ret;
}

static GLboolean APIENTRY logIsTexture(GLuint texture)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glIsTexture( %d )", texture );
	GLboolean ret = dllIsTexture(texture);
	fprintf( PRINT_GL_CALL_DEVICE, " -> %d\n", ret );
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
	return ret;
}

static void APIENTRY logLightModelx(GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightModelx( 0x%X, %+d )\n", pname, param );
	dllLightModelx(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightModelxv(GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightModelxv( 0x%X, %p )\n", pname, params );
	dllLightModelxv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightx(GLenum light, GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightx( 0x%X, 0x%X, %+d )\n", light, pname, param );
	dllLightx(light, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLightxv(GLenum light, GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLightxv( 0x%X, 0x%X, %p )\n", light, pname, params );
	dllLightxv(light, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLineWidthx(GLfixed width)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLineWidthx( %+d )\n", width );
	dllLineWidthx(width);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLoadIdentity(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLoadIdentity()\n" );
	dllLoadIdentity();
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLoadMatrixx(const GLfixed * m)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLoadMatrixx( %p )\n", m );
	dllLoadMatrixx(m);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logLogicOp(GLenum opcode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glLogicOp( 0x%X )\n", opcode );
	dllLogicOp(opcode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMaterialx(GLenum face, GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMaterialx( 0x%X, 0x%X, %+d )\n", face, pname, param );
	dllMaterialx(face, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMaterialxv(GLenum face, GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMaterialxv( 0x%X, 0x%X, %p )\n", face, pname, params );
	dllMaterialxv(face, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMatrixMode(GLenum mode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMatrixMode( 0x%X )\n", mode );
	dllMatrixMode(mode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMultMatrixx(const GLfixed * m)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMultMatrixx( %p )\n", m );
	dllMultMatrixx(m);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glMultiTexCoord4x( 0x%X, %+d, %+d, %+d, %+d )\n", target, s, t, r, q );
	dllMultiTexCoord4x(target, s, t, r, q);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logNormal3x(GLfixed nx, GLfixed ny, GLfixed nz)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glNormal3x( %+d, %+d, %+d )\n", nx, ny, nz );
	dllNormal3x(nx, ny, nz);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glNormalPointer( 0x%X, %+d, %p )\n", type, stride, pointer );
	dllNormalPointer(type, stride, pointer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glOrthox( %+d, %+d, %+d, %+d, %+d, %+d )\n", left, right, bottom, top, zNear, zFar );
	dllOrthox(left, right, bottom, top, zNear, zFar);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPixelStorei(GLenum pname, GLint param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPixelStorei( 0x%X, %+d )\n", pname, param );
	dllPixelStorei(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointParameterx(GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointParameterx( 0x%X, %+d )\n", pname, param );
	dllPointParameterx(pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointParameterxv(GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointParameterxv( 0x%X, %p )\n", pname, params );
	dllPointParameterxv(pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointSizex(GLfixed size)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointSizex( %+d )\n", size );
	dllPointSizex(size);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPolygonOffsetx(GLfixed factor, GLfixed units)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPolygonOffsetx( %+d, %+d )\n", factor, units );
	dllPolygonOffsetx(factor, units);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPopMatrix(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPopMatrix()\n" );
	dllPopMatrix();
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPushMatrix(void)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPushMatrix()\n" );
	dllPushMatrix();
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glReadPixels( %+d, %+d, %+d, %+d, 0x%X, 0x%X, %p )\n", x, y, width, height, format, type, pixels );
	dllReadPixels(x, y, width, height, format, type, pixels);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glRotatex( %+d, %+d, %+d, %+d )\n", angle, x, y, z );
	dllRotatex(angle, x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logSampleCoverage(GLclampf value, GLboolean invert)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glSampleCoverage( %f, %+d )\n", value, invert );
	dllSampleCoverage(value, invert);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logSampleCoveragex(GLclampx value, GLboolean invert)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glSampleCoveragex( %+d, %+d )\n", value, invert );
	dllSampleCoveragex(value, invert);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logScalex(GLfixed x, GLfixed y, GLfixed z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glScalex( %+d, %+d, %+d )\n", x, y, z );
	dllScalex(x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glScissor( %+d, %+d, %+d, %+d )\n", x, y, width, height );
	dllScissor(x, y, width, height);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logShadeModel(GLenum mode)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glShadeModel( 0x%X )\n", mode );
	dllShadeModel(mode);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logStencilFunc(GLenum func, GLint ref, GLuint mask)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glStencilFunc( 0x%X, %+d, %d )\n", func, ref, mask );
	dllStencilFunc(func, ref, mask);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logStencilMask(GLuint mask)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glStencilMask( %d )\n", mask );
	dllStencilMask(mask);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glStencilOp( 0x%X, 0x%X, 0x%X )\n", fail, zfail, zpass );
	dllStencilOp(fail, zfail, zpass);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexCoordPointer( %+d, 0x%X, %+d, %p )\n", size, type, stride, pointer );
	dllTexCoordPointer(size, type, stride, pointer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnvi(GLenum target, GLenum pname, GLint param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnvi( 0x%X, 0x%X, %+d )\n", target, pname, param );
	dllTexEnvi(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnvx(GLenum target, GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnvx( 0x%X, 0x%X, %+d )\n", target, pname, param );
	dllTexEnvx(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnviv(GLenum target, GLenum pname, const GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnviv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexEnviv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexEnvxv(GLenum target, GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexEnvxv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexEnvxv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexImage2D( 0x%X, %+d, %+d, %+d, %+d, %+d, 0x%X, 0x%X, %p )\n", target, level, internalformat, width, height, border, format, type, pixels );
	dllTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameteri(GLenum target, GLenum pname, GLint param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameteri( 0x%X, 0x%X, %+d )\n", target, pname, param );
	dllTexParameteri(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameterx(GLenum target, GLenum pname, GLfixed param)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameterx( 0x%X, 0x%X, %+d )\n", target, pname, param );
	dllTexParameterx(target, pname, param);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameteriv(GLenum target, GLenum pname, const GLint * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameteriv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexParameteriv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexParameterxv(GLenum target, GLenum pname, const GLfixed * params)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexParameterxv( 0x%X, 0x%X, %p )\n", target, pname, params );
	dllTexParameterxv(target, pname, params);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTexSubImage2D( 0x%X, %+d, %+d, %+d, %+d, %+d, 0x%X, 0x%X, %p )\n", target, level, xoffset, yoffset, width, height, format, type, pixels );
	dllTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logTranslatex(GLfixed x, GLfixed y, GLfixed z)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glTranslatex( %+d, %+d, %+d )\n", x, y, z );
	dllTranslatex(x, y, z);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glVertexPointer( %+d, 0x%X, %+d, %p )\n", size, type, stride, pointer );
	dllVertexPointer(size, type, stride, pointer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glViewport( %+d, %+d, %+d, %+d )\n", x, y, width, height );
	dllViewport(x, y, width, height);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

static void APIENTRY logPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer)
{
	fprintf( PRINT_GL_CALL_DEVICE, "glPointSizePointerOES( 0x%X, %+d, %p )\n", type, stride, pointer );
	dllPointSizePointerOES(type, stride, pointer);
	GLenum err = dllGetError();
	if(err != GL_NO_ERROR)
	{
		fprintf(PRINT_GL_ERROR_DEVICE, "GL_Error -> %X\n", err);
	}
}

#undef PRINT_GL_ERROR_DEVICE
#undef PRINT_GL_CALL_DEVICE


static void unload_opengl( void )
{
	if ( gles1.dl_ptr )
	{
		dlclose ( gles1.dl_ptr );
		gles1.dl_ptr = NULL;
	}

	gles1.dl_ptr = NULL;
	gles1.loaded = 0;

	qglAlphaFunc = NULL;
	qglClearColor = NULL;
	qglClearDepthf = NULL;
	qglClipPlanef = NULL;
	qglColor4f = NULL;
	qglDepthRangef = NULL;
	qglFogf = NULL;
	qglFogfv = NULL;
	qglFrustumf = NULL;
	qglGetClipPlanef = NULL;
	qglGetFloatv = NULL;
	qglGetLightfv = NULL;
	qglGetMaterialfv = NULL;
	qglGetTexEnvfv = NULL;
	qglGetTexParameterfv = NULL;
	qglLightModelf = NULL;
	qglLightModelfv = NULL;
	qglLightf = NULL;
	qglLightfv = NULL;
	qglLineWidth = NULL;
	qglLoadMatrixf = NULL;
	qglMaterialf = NULL;
	qglMaterialfv = NULL;
	qglMultMatrixf = NULL;
	qglMultiTexCoord4f = NULL;
	qglNormal3f = NULL;
	qglOrthof = NULL;
	qglPointParameterf = NULL;
	qglPointParameterfv = NULL;
	qglPointSize = NULL;
	qglPolygonOffset = NULL;
	qglRotatef = NULL;
	qglScalef = NULL;
	qglTexEnvf = NULL;
	qglTexEnvfv = NULL;
	qglTexParameterf = NULL;
	qglTexParameterfv = NULL;
	qglTranslatef = NULL;
	qglActiveTexture = NULL;
	qglAlphaFuncx = NULL;
	qglBindBuffer = NULL;
	qglBindTexture = NULL;
	qglBlendFunc = NULL;
	qglBufferData = NULL;
	qglBufferSubData = NULL;
	qglClear = NULL;
	qglClearColorx = NULL;
	qglClearDepthx = NULL;
	qglClearStencil = NULL;
	qglClientActiveTexture = NULL;
	qglClipPlanex = NULL;
	qglColor4ub = NULL;
	qglColor4x = NULL;
	qglColorMask = NULL;
	qglColorPointer = NULL;
	qglCompressedTexImage2D = NULL;
	qglCompressedTexSubImage2D = NULL;
	qglCopyTexImage2D = NULL;
	qglCopyTexSubImage2D = NULL;
	qglCullFace = NULL;
	qglDeleteBuffers = NULL;
	qglDeleteTextures = NULL;
	qglDepthFunc = NULL;
	qglDepthMask = NULL;
	qglDepthRangex = NULL;
	qglDisable = NULL;
	qglDisableClientState = NULL;
	qglDrawArrays = NULL;
	qglDrawElements = NULL;
	qglEnable = NULL;
	qglEnableClientState = NULL;
	qglFinish = NULL;
	qglFlush = NULL;
	qglFogx = NULL;
	qglFogxv = NULL;
	qglFrontFace = NULL;
	qglFrustumx = NULL;
	qglGetBooleanv = NULL;
	qglGetBufferParameteriv = NULL;
	qglGetClipPlanex = NULL;
	qglGenBuffers = NULL;
	qglGenTextures = NULL;
	qglGetError = NULL;
	qglGetFixedv = NULL;
	qglGetIntegerv = NULL;
	qglGetLightxv = NULL;
	qglGetMaterialxv = NULL;
	qglGetPointerv = NULL;
	qglGetString = NULL;
	qglGetTexEnviv = NULL;
	qglGetTexEnvxv = NULL;
	qglGetTexParameteriv = NULL;
	qglGetTexParameterxv = NULL;
	qglHint = NULL;
	qglIsBuffer = NULL;
	qglIsEnabled = NULL;
	qglIsTexture = NULL;
	qglLightModelx = NULL;
	qglLightModelxv = NULL;
	qglLightx = NULL;
	qglLightxv = NULL;
	qglLineWidthx = NULL;
	qglLoadIdentity = NULL;
	qglLoadMatrixx = NULL;
	qglLogicOp = NULL;
	qglMaterialx = NULL;
	qglMaterialxv = NULL;
	qglMatrixMode = NULL;
	qglMultMatrixx = NULL;
	qglMultiTexCoord4x = NULL;
	qglNormal3x = NULL;
	qglNormalPointer = NULL;
	qglOrthox = NULL;
	qglPixelStorei = NULL;
	qglPointParameterx = NULL;
	qglPointParameterxv = NULL;
	qglPointSizex = NULL;
	qglPolygonOffsetx = NULL;
	qglPopMatrix = NULL;
	qglPushMatrix = NULL;
	qglReadPixels = NULL;
	qglRotatex = NULL;
	qglSampleCoverage = NULL;
	qglSampleCoveragex = NULL;
	qglScalex = NULL;
	qglScissor = NULL;
	qglShadeModel = NULL;
	qglStencilFunc = NULL;
	qglStencilMask = NULL;
	qglStencilOp = NULL;
	qglTexCoordPointer = NULL;
	qglTexEnvi = NULL;
	qglTexEnvx = NULL;
	qglTexEnviv = NULL;
	qglTexEnvxv = NULL;
	qglTexImage2D = NULL;
	qglTexParameteri = NULL;
	qglTexParameterx = NULL;
	qglTexParameteriv = NULL;
	qglTexParameterxv = NULL;
	qglTexSubImage2D = NULL;
	qglTranslatex = NULL;
	qglVertexPointer = NULL;
	qglViewport = NULL;
	qglPointSizePointerOES = NULL;
}

#define GPA( a ) dlsym( gles1.dl_ptr, a )

void * karinGLGetProcAddress(const char *symbol)
{
	if (gles1.loaded)
		return GPA ( symbol );
	return NULL;
}

static int load_opengl()
{
	if ( gles1.loaded )
		return 1;
	
	qglAlphaFunc = dllAlphaFunc = GPA( "glAlphaFunc" );
	qglClearColor = dllClearColor = GPA( "glClearColor" );
	qglClearDepthf = dllClearDepthf = GPA( "glClearDepthf" );
	qglClipPlanef = dllClipPlanef = GPA( "glClipPlanef" );
	qglColor4f = dllColor4f = GPA( "glColor4f" );
	qglDepthRangef = dllDepthRangef = GPA( "glDepthRangef" );
	qglFogf = dllFogf = GPA( "glFogf" );
	qglFogfv = dllFogfv = GPA( "glFogfv" );
	qglFrustumf = dllFrustumf = GPA( "glFrustumf" );
	qglGetClipPlanef = dllGetClipPlanef = GPA( "glGetClipPlanef" );
	qglGetFloatv = dllGetFloatv = GPA( "glGetFloatv" );
	qglGetLightfv = dllGetLightfv = GPA( "glGetLightfv" );
	qglGetMaterialfv = dllGetMaterialfv = GPA( "glGetMaterialfv" );
	qglGetTexEnvfv = dllGetTexEnvfv = GPA( "glGetTexEnvfv" );
	qglGetTexParameterfv = dllGetTexParameterfv = GPA( "glGetTexParameterfv" );
	qglLightModelf = dllLightModelf = GPA( "glLightModelf" );
	qglLightModelfv = dllLightModelfv = GPA( "glLightModelfv" );
	qglLightf = dllLightf = GPA( "glLightf" );
	qglLightfv = dllLightfv = GPA( "glLightfv" );
	qglLineWidth = dllLineWidth = GPA( "glLineWidth" );
	qglLoadMatrixf = dllLoadMatrixf = GPA( "glLoadMatrixf" );
	qglMaterialf = dllMaterialf = GPA( "glMaterialf" );
	qglMaterialfv = dllMaterialfv = GPA( "glMaterialfv" );
	qglMultMatrixf = dllMultMatrixf = GPA( "glMultMatrixf" );
	qglMultiTexCoord4f = dllMultiTexCoord4f = GPA( "glMultiTexCoord4f" );
	qglNormal3f = dllNormal3f = GPA( "glNormal3f" );
	qglOrthof = dllOrthof = GPA( "glOrthof" );
	qglPointParameterf = dllPointParameterf = GPA( "glPointParameterf" );
	qglPointParameterfv = dllPointParameterfv = GPA( "glPointParameterfv" );
	qglPointSize = dllPointSize = GPA( "glPointSize" );
	qglPolygonOffset = dllPolygonOffset = GPA( "glPolygonOffset" );
	qglRotatef = dllRotatef = GPA( "glRotatef" );
	qglScalef = dllScalef = GPA( "glScalef" );
	qglTexEnvf = dllTexEnvf = GPA( "glTexEnvf" );
	qglTexEnvfv = dllTexEnvfv = GPA( "glTexEnvfv" );
	qglTexParameterf = dllTexParameterf = GPA( "glTexParameterf" );
	qglTexParameterfv = dllTexParameterfv = GPA( "glTexParameterfv" );
	qglTranslatef = dllTranslatef = GPA( "glTranslatef" );
	qglActiveTexture = dllActiveTexture = GPA( "glActiveTexture" );
	qglAlphaFuncx = dllAlphaFuncx = GPA( "glAlphaFuncx" );
	qglBindBuffer = dllBindBuffer = GPA( "glBindBuffer" );
	qglBindTexture = dllBindTexture = GPA( "glBindTexture" );
	qglBlendFunc = dllBlendFunc = GPA( "glBlendFunc" );
	qglBufferData = dllBufferData = GPA( "glBufferData" );
	qglBufferSubData = dllBufferSubData = GPA( "glBufferSubData" );
	qglClear = dllClear = GPA( "glClear" );
	qglClearColorx = dllClearColorx = GPA( "glClearColorx" );
	qglClearDepthx = dllClearDepthx = GPA( "glClearDepthx" );
	qglClearStencil = dllClearStencil = GPA( "glClearStencil" );
	qglClientActiveTexture = dllClientActiveTexture = GPA( "glClientActiveTexture" );
	qglClipPlanex = dllClipPlanex = GPA( "glClipPlanex" );
	qglColor4ub = dllColor4ub = GPA( "glColor4ub" );
	qglColor4x = dllColor4x = GPA( "glColor4x" );
	qglColorMask = dllColorMask = GPA( "glColorMask" );
	qglColorPointer = dllColorPointer = GPA( "glColorPointer" );
	qglCompressedTexImage2D = dllCompressedTexImage2D = GPA( "glCompressedTexImage2D" );
	qglCompressedTexSubImage2D = dllCompressedTexSubImage2D = GPA( "glCompressedTexSubImage2D" );
	qglCopyTexImage2D = dllCopyTexImage2D = GPA( "glCopyTexImage2D" );
	qglCopyTexSubImage2D = dllCopyTexSubImage2D = GPA( "glCopyTexSubImage2D" );
	qglCullFace = dllCullFace = GPA( "glCullFace" );
	qglDeleteBuffers = dllDeleteBuffers = GPA( "glDeleteBuffers" );
	qglDeleteTextures = dllDeleteTextures = GPA( "glDeleteTextures" );
	qglDepthFunc = dllDepthFunc = GPA( "glDepthFunc" );
	qglDepthMask = dllDepthMask = GPA( "glDepthMask" );
	qglDepthRangex = dllDepthRangex = GPA( "glDepthRangex" );
	qglDisable = dllDisable = GPA( "glDisable" );
	qglDisableClientState = dllDisableClientState = GPA( "glDisableClientState" );
	qglDrawArrays = dllDrawArrays = GPA( "glDrawArrays" );
	qglDrawElements = dllDrawElements = GPA( "glDrawElements" );
	qglEnable = dllEnable = GPA( "glEnable" );
	qglEnableClientState = dllEnableClientState = GPA( "glEnableClientState" );
	qglFinish = dllFinish = GPA( "glFinish" );
	qglFlush = dllFlush = GPA( "glFlush" );
	qglFogx = dllFogx = GPA( "glFogx" );
	qglFogxv = dllFogxv = GPA( "glFogxv" );
	qglFrontFace = dllFrontFace = GPA( "glFrontFace" );
	qglFrustumx = dllFrustumx = GPA( "glFrustumx" );
	qglGetBooleanv = dllGetBooleanv = GPA( "glGetBooleanv" );
	qglGetBufferParameteriv = dllGetBufferParameteriv = GPA( "glGetBufferParameteriv" );
	qglGetClipPlanex = dllGetClipPlanex = GPA( "glGetClipPlanex" );
	qglGenBuffers = dllGenBuffers = GPA( "glGenBuffers" );
	qglGenTextures = dllGenTextures = GPA( "glGenTextures" );
	qglGetError = dllGetError = GPA( "glGetError" );
	qglGetFixedv = dllGetFixedv = GPA( "glGetFixedv" );
	qglGetIntegerv = dllGetIntegerv = GPA( "glGetIntegerv" );
	qglGetLightxv = dllGetLightxv = GPA( "glGetLightxv" );
	qglGetMaterialxv = dllGetMaterialxv = GPA( "glGetMaterialxv" );
	qglGetPointerv = dllGetPointerv = GPA( "glGetPointerv" );
	qglGetString = dllGetString = GPA( "glGetString" );
	qglGetTexEnviv = dllGetTexEnviv = GPA( "glGetTexEnviv" );
	qglGetTexEnvxv = dllGetTexEnvxv = GPA( "glGetTexEnvxv" );
	qglGetTexParameteriv = dllGetTexParameteriv = GPA( "glGetTexParameteriv" );
	qglGetTexParameterxv = dllGetTexParameterxv = GPA( "glGetTexParameterxv" );
	qglHint = dllHint = GPA( "glHint" );
	qglIsBuffer = dllIsBuffer = GPA( "glIsBuffer" );
	qglIsEnabled = dllIsEnabled = GPA( "glIsEnabled" );
	qglIsTexture = dllIsTexture = GPA( "glIsTexture" );
	qglLightModelx = dllLightModelx = GPA( "glLightModelx" );
	qglLightModelxv = dllLightModelxv = GPA( "glLightModelxv" );
	qglLightx = dllLightx = GPA( "glLightx" );
	qglLightxv = dllLightxv = GPA( "glLightxv" );
	qglLineWidthx = dllLineWidthx = GPA( "glLineWidthx" );
	qglLoadIdentity = dllLoadIdentity = GPA( "glLoadIdentity" );
	qglLoadMatrixx = dllLoadMatrixx = GPA( "glLoadMatrixx" );
	qglLogicOp = dllLogicOp = GPA( "glLogicOp" );
	qglMaterialx = dllMaterialx = GPA( "glMaterialx" );
	qglMaterialxv = dllMaterialxv = GPA( "glMaterialxv" );
	qglMatrixMode = dllMatrixMode = GPA( "glMatrixMode" );
	qglMultMatrixx = dllMultMatrixx = GPA( "glMultMatrixx" );
	qglMultiTexCoord4x = dllMultiTexCoord4x = GPA( "glMultiTexCoord4x" );
	qglNormal3x = dllNormal3x = GPA( "glNormal3x" );
	qglNormalPointer = dllNormalPointer = GPA( "glNormalPointer" );
	qglOrthox = dllOrthox = GPA( "glOrthox" );
	qglPixelStorei = dllPixelStorei = GPA( "glPixelStorei" );
	qglPointParameterx = dllPointParameterx = GPA( "glPointParameterx" );

	qglPointParameterxv = dllPointParameterxv = GPA( "glPointParameterxv" );
	qglPointSizex = dllPointSizex = GPA( "glPointSizex" );
	qglPolygonOffsetx = dllPolygonOffsetx = GPA( "glPolygonOffsetx" );
	qglPopMatrix = dllPopMatrix = GPA( "glPopMatrix" );
	qglPushMatrix = dllPushMatrix = GPA( "glPushMatrix" );
	qglReadPixels = dllReadPixels = GPA( "glReadPixels" );
	qglRotatex = dllRotatex = GPA( "glRotatex" );
	qglSampleCoverage = dllSampleCoverage = GPA( "glSampleCoverage" );
	qglSampleCoveragex = dllSampleCoveragex = GPA( "glSampleCoveragex" );
	qglScalex = dllScalex = GPA( "glScalex" );
	qglScissor = dllScissor = GPA( "glScissor" );
	qglShadeModel = dllShadeModel = GPA( "glShadeModel" );
	qglStencilFunc = dllStencilFunc = GPA( "glStencilFunc" );
	qglStencilMask = dllStencilMask = GPA( "glStencilMask" );
	qglStencilOp = dllStencilOp = GPA( "glStencilOp" );
	qglTexCoordPointer = dllTexCoordPointer = GPA( "glTexCoordPointer" );
	qglTexEnvi = dllTexEnvi = GPA( "glTexEnvi" );
	qglTexEnvx = dllTexEnvx = GPA( "glTexEnvx" );
	qglTexEnviv = dllTexEnviv = GPA( "glTexEnviv" );
	qglTexEnvxv = dllTexEnvxv = GPA( "glTexEnvxv" );
	qglTexImage2D = dllTexImage2D = GPA( "glTexImage2D" );
	qglTexParameteri = dllTexParameteri = GPA( "glTexParameteri" );
	qglTexParameterx = dllTexParameterx = GPA( "glTexParameterx" );
	qglTexParameteriv = dllTexParameteriv = GPA( "glTexParameteriv" );
	qglTexParameterxv = dllTexParameterxv = GPA( "glTexParameterxv" );
	qglTexSubImage2D = dllTexSubImage2D = GPA( "glTexSubImage2D" );
	qglTranslatex = dllTranslatex = GPA( "glTranslatex" );
	qglVertexPointer = dllVertexPointer = GPA( "glVertexPointer" );
	qglViewport = dllViewport = GPA( "glViewport" );
	qglPointSizePointerOES = dllPointSizePointerOES = GPA( "glPointSizePointerOES" );

	return 1;
}

#undef GPA

static void enable_gles1_logging( int enable )
{
	if ( enable )
	{
		qglAlphaFunc = logAlphaFunc;
		qglClearColor = logClearColor;
		qglClearDepthf = logClearDepthf;
		qglClipPlanef = logClipPlanef;
		qglColor4f = logColor4f;
		qglDepthRangef = logDepthRangef;
		qglFogf = logFogf;
		qglFogfv = logFogfv;
		qglFrustumf = logFrustumf;
		qglGetClipPlanef = logGetClipPlanef;
		qglGetFloatv = logGetFloatv;
		qglGetLightfv = logGetLightfv;
		qglGetMaterialfv = logGetMaterialfv;
		qglGetTexEnvfv = logGetTexEnvfv;
		qglGetTexParameterfv = logGetTexParameterfv;
		qglLightModelf = logLightModelf;
		qglLightModelfv = logLightModelfv;
		qglLightf = logLightf;
		qglLightfv = logLightfv;
		qglLineWidth = logLineWidth;
		qglLoadMatrixf = logLoadMatrixf;
		qglMaterialf = logMaterialf;
		qglMaterialfv = logMaterialfv;
		qglMultMatrixf = logMultMatrixf;
		qglMultiTexCoord4f = logMultiTexCoord4f;
		qglNormal3f = logNormal3f;
		qglOrthof = logOrthof;
		qglPointParameterf = logPointParameterf;
		qglPointParameterfv = logPointParameterfv;
		qglPointSize = logPointSize;
		qglPolygonOffset = logPolygonOffset;
		qglRotatef = logRotatef;
		qglScalef = logScalef;
		qglTexEnvf = logTexEnvf;
		qglTexEnvfv = logTexEnvfv;
		qglTexParameterf = logTexParameterf;
		qglTexParameterfv = logTexParameterfv;
		qglTranslatef = logTranslatef;
		qglActiveTexture = logActiveTexture;
		qglAlphaFuncx = logAlphaFuncx;
		qglBindBuffer = logBindBuffer;
		qglBindTexture = logBindTexture;
		qglBlendFunc = logBlendFunc;
		qglBufferData = logBufferData;
		qglBufferSubData = logBufferSubData;
		qglClear = logClear;
		qglClearColorx = logClearColorx;
		qglClearDepthx = logClearDepthx;
		qglClearStencil = logClearStencil;
		qglClientActiveTexture = logClientActiveTexture;
		qglClipPlanex = logClipPlanex;
		qglColor4ub = logColor4ub;
		qglColor4x = logColor4x;
		qglColorMask = logColorMask;
		qglColorPointer = logColorPointer;
		qglCompressedTexImage2D = logCompressedTexImage2D;
		qglCompressedTexSubImage2D = logCompressedTexSubImage2D;
		qglCopyTexImage2D = logCopyTexImage2D;
		qglCopyTexSubImage2D = logCopyTexSubImage2D;
		qglCullFace = logCullFace;
		qglDeleteBuffers = logDeleteBuffers;
		qglDeleteTextures = logDeleteTextures;
		qglDepthFunc = logDepthFunc;
		qglDepthMask = logDepthMask;
		qglDepthRangex = logDepthRangex;
		qglDisable = logDisable;
		qglDisableClientState = logDisableClientState;
		qglDrawArrays = logDrawArrays;
		qglDrawElements = logDrawElements;
		qglEnable = logEnable;
		qglEnableClientState = logEnableClientState;
		qglFinish = logFinish;
		qglFlush = logFlush;
		qglFogx = logFogx;
		qglFogxv = logFogxv;
		qglFrontFace = logFrontFace;
		qglFrustumx = logFrustumx;
		qglGetBooleanv = logGetBooleanv;
		qglGetBufferParameteriv = logGetBufferParameteriv;
		qglGetClipPlanex = logGetClipPlanex;
		qglGenBuffers = logGenBuffers;
		qglGenTextures = logGenTextures;
		qglGetError = logGetError;
		qglGetFixedv = logGetFixedv;
		qglGetIntegerv = logGetIntegerv;
		qglGetLightxv = logGetLightxv;
		qglGetMaterialxv = logGetMaterialxv;
		qglGetPointerv = logGetPointerv;
		qglGetString = logGetString;
		qglGetTexEnviv = logGetTexEnviv;
		qglGetTexEnvxv = logGetTexEnvxv;
		qglGetTexParameteriv = logGetTexParameteriv;
		qglGetTexParameterxv = logGetTexParameterxv;
		qglHint = logHint;
		qglIsBuffer = logIsBuffer;
		qglIsEnabled = logIsEnabled;
		qglIsTexture = logIsTexture;
		qglLightModelx = logLightModelx;
		qglLightModelxv = logLightModelxv;
		qglLightx = logLightx;
		qglLightxv = logLightxv;
		qglLineWidthx = logLineWidthx;
		qglLoadIdentity = logLoadIdentity;
		qglLoadMatrixx = logLoadMatrixx;
		qglLogicOp = logLogicOp;
		qglMaterialx = logMaterialx;
		qglMaterialxv = logMaterialxv;
		qglMatrixMode = logMatrixMode;
		qglMultMatrixx = logMultMatrixx;
		qglMultiTexCoord4x = logMultiTexCoord4x;
		qglNormal3x = logNormal3x;
		qglNormalPointer = logNormalPointer;
		qglOrthox = logOrthox;
		qglPixelStorei = logPixelStorei;
		qglPointParameterx = logPointParameterx;
		qglPointParameterxv = logPointParameterxv;
		qglPointSizex = logPointSizex;
		qglPolygonOffsetx = logPolygonOffsetx;
		qglPopMatrix = logPopMatrix;
		qglPushMatrix = logPushMatrix;
		qglReadPixels = logReadPixels;
		qglRotatex = logRotatex;
		qglSampleCoverage = logSampleCoverage;
		qglSampleCoveragex = logSampleCoveragex;
		qglScalex = logScalex;
		qglScissor = logScissor;
		qglShadeModel = logShadeModel;
		qglStencilFunc = logStencilFunc;
		qglStencilMask = logStencilMask;
		qglStencilOp = logStencilOp;
		qglTexCoordPointer = logTexCoordPointer;
		qglTexEnvi = logTexEnvi;
		qglTexEnvx = logTexEnvx;
		qglTexEnviv = logTexEnviv;
		qglTexEnvxv = logTexEnvxv;
		qglTexImage2D = logTexImage2D;
		qglTexParameteri = logTexParameteri;
		qglTexParameterx = logTexParameterx;
		qglTexParameteriv = logTexParameteriv;
		qglTexParameterxv = logTexParameterxv;
		qglTexSubImage2D = logTexSubImage2D;
		qglTranslatex = logTranslatex;
		qglVertexPointer = logVertexPointer;
		qglViewport = logViewport;
		qglPointSizePointerOES = logPointSizePointerOES;

	}
	else
	{
		qglAlphaFunc = dllAlphaFunc;
		qglClearColor = dllClearColor;
		qglClearDepthf = dllClearDepthf;
		qglClipPlanef = dllClipPlanef;
		qglColor4f = dllColor4f;
		qglDepthRangef = dllDepthRangef;
		qglFogf = dllFogf;
		qglFogfv = dllFogfv;
		qglFrustumf = dllFrustumf;
		qglGetClipPlanef = dllGetClipPlanef;
		qglGetFloatv = dllGetFloatv;
		qglGetLightfv = dllGetLightfv;
		qglGetMaterialfv = dllGetMaterialfv;
		qglGetTexEnvfv = dllGetTexEnvfv;
		qglGetTexParameterfv = dllGetTexParameterfv;
		qglLightModelf = dllLightModelf;
		qglLightModelfv = dllLightModelfv;
		qglLightf = dllLightf;
		qglLightfv = dllLightfv;
		qglLineWidth = dllLineWidth;
		qglLoadMatrixf = dllLoadMatrixf;
		qglMaterialf = dllMaterialf;
		qglMaterialfv = dllMaterialfv;
		qglMultMatrixf = dllMultMatrixf;
		qglMultiTexCoord4f = dllMultiTexCoord4f;
		qglNormal3f = dllNormal3f;
		qglOrthof = dllOrthof;
		qglPointParameterf = dllPointParameterf;
		qglPointParameterfv = dllPointParameterfv;
		qglPointSize = dllPointSize;
		qglPolygonOffset = dllPolygonOffset;
		qglRotatef = dllRotatef;
		qglScalef = dllScalef;
		qglTexEnvf = dllTexEnvf;
		qglTexEnvfv = dllTexEnvfv;
		qglTexParameterf = dllTexParameterf;
		qglTexParameterfv = dllTexParameterfv;
		qglTranslatef = dllTranslatef;
		qglActiveTexture = dllActiveTexture;
		qglAlphaFuncx = dllAlphaFuncx;
		qglBindBuffer = dllBindBuffer;
		qglBindTexture = dllBindTexture;
		qglBlendFunc = dllBlendFunc;
		qglBufferData = dllBufferData;
		qglBufferSubData = dllBufferSubData;
		qglClear = dllClear;
		qglClearColorx = dllClearColorx;
		qglClearDepthx = dllClearDepthx;
		qglClearStencil = dllClearStencil;
		qglClientActiveTexture = dllClientActiveTexture;
		qglClipPlanex = dllClipPlanex;
		qglColor4ub = dllColor4ub;
		qglColor4x = dllColor4x;
		qglColorMask = dllColorMask;
		qglColorPointer = dllColorPointer;
		qglCompressedTexImage2D = dllCompressedTexImage2D;
		qglCompressedTexSubImage2D = dllCompressedTexSubImage2D;
		qglCopyTexImage2D = dllCopyTexImage2D;
		qglCopyTexSubImage2D = dllCopyTexSubImage2D;
		qglCullFace = dllCullFace;
		qglDeleteBuffers = dllDeleteBuffers;
		qglDeleteTextures = dllDeleteTextures;
		qglDepthFunc = dllDepthFunc;
		qglDepthMask = dllDepthMask;
		qglDepthRangex = dllDepthRangex;
		qglDisable = dllDisable;
		qglDisableClientState = dllDisableClientState;
		qglDrawArrays = dllDrawArrays;
		qglDrawElements = dllDrawElements;
		qglEnable = dllEnable;
		qglEnableClientState = dllEnableClientState;
		qglFinish = dllFinish;
		qglFlush = dllFlush;
		qglFogx = dllFogx;
		qglFogxv = dllFogxv;
		qglFrontFace = dllFrontFace;
		qglFrustumx = dllFrustumx;
		qglGetBooleanv = dllGetBooleanv;
		qglGetBufferParameteriv = dllGetBufferParameteriv;
		qglGetClipPlanex = dllGetClipPlanex;
		qglGenBuffers = dllGenBuffers;
		qglGenTextures = dllGenTextures;
		qglGetError = dllGetError;
		qglGetFixedv = dllGetFixedv;
		qglGetIntegerv = dllGetIntegerv;
		qglGetLightxv = dllGetLightxv;
		qglGetMaterialxv = dllGetMaterialxv;
		qglGetPointerv = dllGetPointerv;
		qglGetString = dllGetString;
		qglGetTexEnviv = dllGetTexEnviv;
		qglGetTexEnvxv = dllGetTexEnvxv;
		qglGetTexParameteriv = dllGetTexParameteriv;
		qglGetTexParameterxv = dllGetTexParameterxv;
		qglHint = dllHint;
		qglIsBuffer = dllIsBuffer;
		qglIsEnabled = dllIsEnabled;
		qglIsTexture = dllIsTexture;
		qglLightModelx = dllLightModelx;
		qglLightModelxv = dllLightModelxv;
		qglLightx = dllLightx;
		qglLightxv = dllLightxv;
		qglLineWidthx = dllLineWidthx;
		qglLoadIdentity = dllLoadIdentity;
		qglLoadMatrixx = dllLoadMatrixx;
		qglLogicOp = dllLogicOp;
		qglMaterialx = dllMaterialx;
		qglMaterialxv = dllMaterialxv;
		qglMatrixMode = dllMatrixMode;
		qglMultMatrixx = dllMultMatrixx;
		qglMultiTexCoord4x = dllMultiTexCoord4x;
		qglNormal3x = dllNormal3x;
		qglNormalPointer = dllNormalPointer;
		qglOrthox = dllOrthox;
		qglPixelStorei = dllPixelStorei;
		qglPointParameterx = dllPointParameterx;
		qglPointParameterxv = dllPointParameterxv;
		qglPointSizex = dllPointSizex;
		qglPolygonOffsetx = dllPolygonOffsetx;
		qglPopMatrix = dllPopMatrix;
		qglPushMatrix = dllPushMatrix;
		qglReadPixels = dllReadPixels;
		qglRotatex = dllRotatex;
		qglSampleCoverage = dllSampleCoverage;
		qglSampleCoveragex = dllSampleCoveragex;
		qglScalex = dllScalex;
		qglScissor = dllScissor;
		qglShadeModel = dllShadeModel;
		qglStencilFunc = dllStencilFunc;
		qglStencilMask = dllStencilMask;
		qglStencilOp = dllStencilOp;
		qglTexCoordPointer = dllTexCoordPointer;
		qglTexEnvi = dllTexEnvi;
		qglTexEnvx = dllTexEnvx;
		qglTexEnviv = dllTexEnviv;
		qglTexEnvxv = dllTexEnvxv;
		qglTexImage2D = dllTexImage2D;
		qglTexParameteri = dllTexParameteri;
		qglTexParameterx = dllTexParameterx;
		qglTexParameteriv = dllTexParameteriv;
		qglTexParameterxv = dllTexParameterxv;
		qglTexSubImage2D = dllTexSubImage2D;
		qglTranslatex = dllTranslatex;
		qglVertexPointer = dllVertexPointer;
		qglViewport = dllViewport;
		qglPointSizePointerOES = dllPointSizePointerOES;
	}
}

static int set_gles1_log(int open)
{
	if(open)
	{
		if ( !gles1_log_fp )
		{
			struct tm *newtime;
			time_t aclock;
			char buffer[1024];

			time( &aclock );
			newtime = localtime( &aclock );

			asctime( newtime );

			snprintf( buffer, sizeof(buffer), "%s/jsr184_m3g_gl.log", "." ); 
			gles1_log_fp = fopen( buffer, "wt" );
			if(!gles1_log_fp)
				return 0;

			fprintf( gles1_log_fp, "%s\n", asctime( newtime ) );
		}
		return 1;
	}
	else
	{
		if(gles1_log_fp)
		{
			fflush(gles1_log_fp);
			fclose(gles1_log_fp);
			gles1_log_fp = NULL;
		}
		return 0;
	}
}

static int karinGLES1Init(void)
{
#define OPENGL_SO "libGLES_CM.so"
	void *handle;
	int res;

	if(gles1.loaded)
		return 1;
	handle = open_dl(OPENGL_SO);
	if(!handle)
		return 0;
	gles1.dl_ptr = handle;
	res = load_opengl();
	if(!res)
		return 0;
	gles1.loaded = 1;
	enable_gles1_logging(1);
	return 1;
#undef OPENGL_SO
}

static int karinGLES1Deinit(void)
{
	if(!gles1.loaded)
		return 1;
	dlclose(gles1.dl_ptr);
	unload_opengl();
	return 1;
}

int karinPrintGL(void)
{
	const char *ret;
	EGLDisplay dpy;

	if(!gles1.loaded)
	{
		fprintf(stderr, "[Harmattan]: OpenGLES v1 library not load.\n");
		return 0;
	}

    ret = qglGetString(GL_VENDOR);
	if(!ret)
	{
		fprintf(stderr, "[Harmattan]: OpenGLES v1 not initilize.\n");
		return 0;
	}

	printf("[Harmattan]: OpenGL vendor -> %s\n", ret);
    ret = qglGetString(GL_VERSION);
	printf("[Harmattan]: OpenGL version -> %s\n", ret);
    ret = qglGetString(GL_RENDERER);
	printf("[Harmattan]: OpenGL renderer -> %s\n", ret);
    ret = qglGetString(GL_EXTENSIONS);
	printf("[Harmattan]: OpenGL extensions -> %s\n", ret);

	return 1;
}
