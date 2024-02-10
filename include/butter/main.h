#ifndef _MAIN_H_
#define _MAIN_H_

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define r (float) 1.0 
#define b (float) 0.0 
#define g (float) 0.0 
#define a (float) 1.0 

#define w 800
#define h 600
#define x (int) (w / 2)
#define y (int) ((h * 1) / 3)

/**
 * @brief: To be set if using OpenGL
 *
 * #define gl_x (GLint) 20
 * #define gl_y (GLint) 20
 * #define gl_w (GLsizei) 800
 * #define gl_h (GLsizei) 600
 */

#endif // !_MAIN_H_
