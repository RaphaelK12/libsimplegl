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
#ifndef _SIMPLEGL_MATH_H_
#define _SIMPLEGL_MATH_H_
#include <limits.h>
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
#ifdef __cplusplus
extern "C" {
#endif

#if defined(SIMPLEGL_MATH_USE_LONG_DOUBLE)
	#define VEC2_USE_LONG_DOUBLE
	#define VEC3_USE_LONG_DOUBLE
	#define VEC4_USE_LONG_DOUBLE
	#define MAT3_USE_LONG_DOUBLE
#elif defined(SIMPLEGL_MATH_USE_DOUBLE)
	#define VEC2_USE_DOUBLE
	#define VEC3_USE_DOUBLE
	#define VEC4_USE_DOUBLE
	#define MAT3_USE_DOUBLE
#else /* default: use float */
	#define VEC2_USE_FLOAT
	#define VEC3_USE_FLOAT
	#define VEC4_USE_FLOAT
	#define MAT3_USE_DOUBLE
#endif


#include <vec2.h>
#include <vec3.h>
#include <vec4.h>
#include <mat2.h>
#include <mat3.h>
//#include <mat4.h>


/*
 * Four Dimensional Matrices
typedef struct mat4 {
    union { // allowed in C11
        struct {
            vec4_t x;
            vec4_t y;
            vec4_t z;
            vec4_t w;
        };
        scaler_t m[ 16 ];
    };
} mat4_t;
*/

#ifdef __cplusplus
} /* C linkage */
#endif
#endif /* _SIMPLEGL_MATH_H_ */
