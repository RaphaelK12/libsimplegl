/* Copyright (C) 2013 by Joseph A. Marrero, http://www.manvscode.com/
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _SIMPLEGL_H_
#define _SIMPLEGL_H_
#ifdef __cplusplus
extern "C" {
#endif
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#include <stdbool.h>
#ifdef __restrict
#undef __restrict
#define __restrict restrict
#endif
#ifdef __inline
#undef __inline
#define __inline inline
#endif
#else
#define bool int
#define true 1
#define false 0
#ifdef __restrict
#undef __restrict
#define __restrict
#endif
#ifdef __inline
#undef __inline
#define __inline
#endif
#endif

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif

/*
 * Always include OpenGL and GLU headers
 */
#if __APPLE__
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif


/*
 * Mathematics
 */
#include "mathematics.h"

/*
 * Texturing
 */
GLuint tex2d_create      ( void );
void   tex2d_destroy     ( GLuint texture );
bool   tex2d_load        ( GLuint texture, const char* filename, GLint min_filter, GLint mag_filter, bool clamp );
bool   tex2d_load_for_2d ( GLuint texture, const char* filename );
bool   tex2d_load_for_3d ( GLuint texture, const char* filename, bool clamp );

/*
 * Projections
 */
mat4_t orthographic ( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far );
mat4_t frustum      ( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far );
mat4_t perspective  ( GLdouble fov, GLdouble aspect, GLdouble near, GLdouble far );
mat4_t look_at      ( const pt3_t* p, const pt3_t* t, const vec3_t* u );

/*
 * Transformations
 */
mat4_t translate     ( const vec3_t* t );
mat4_t scale         ( const vec3_t* s );
mat4_t uniform_scale ( GLdouble scale );
mat4_t rotate_x      ( GLdouble angle );
mat4_t rotate_y      ( GLdouble angle );
mat4_t rotate_z      ( GLdouble angle );
mat4_t orientation   ( vec3_t* forward, vec3_t* left, vec3_t* up );

/*
 * Shaders
 */
typedef struct shader_info {
	GLenum type;
	char*  filename;
} shader_info_t;

GLboolean     simplegl_program_from_shaders      ( GLuint* p_program, const shader_info_t* shaders, GLsizei count );
GLboolean     simplegl_shader_create_from_source ( GLuint* p_shader, GLenum type, const GLchar* source );
const GLchar* simplegl_shader_log                ( GLuint shader );
GLboolean     simplegl_program_create            ( GLuint* p_program, GLuint *p_shaders, GLsizei shader_count, GLboolean mark_shaders_for_deletion );
const GLchar* simplegl_program_log               ( GLuint program );

#ifdef __cplusplus
} /* C linkage */
#endif
#endif /* _SIMPLEGL_H_ */
