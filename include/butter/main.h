#ifndef _MAIN_H_
#define _MAIN_H_

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * @brief The Vectors we'll be using in the Development of Butter
 */
typedef struct Vector1D {
  int *x0;
  int *y0;
} vec1;

typedef struct Vector2D {
  int *x0;
  int *y0;
  int *x1;
  int *y1;
} vec2;

typedef struct Vector3D {
  int *x0;
  int *y0;
  int *z0;
  int *x1;
  int *y1;
  int *z1;
} vec3;

/**
 * @brief Color Settings
 */
typedef struct {
  uint8_t *pr;
  uint8_t *pg;
  uint8_t *pb;
} pColor;

/**
 * @brief Window Settings
 */
typedef struct {
  int *x;
  int *y;
  int *w;
  int *h;
} setWindow;

/**
 * @brief Custom functions to interface with SDL2
 */
void SetPixel(SDL_Surface *,              // Surface or Screen
              int, int,                   // Pixel position (x, y)
              uint8_t, uint8_t, uint8_t); // Pixel color (r, g, b)

/**
 * @brief: To be set if using OpenGL
 *
 * #define gl_x (GLint) 20
 * #define gl_y (GLint) 20
 * #define gl_w (GLsizei) 800
 * #define gl_h (GLsizei) 600
 *
 * #define r (float) 1.0 
 * #define b (float) 0.0 
 * #define g (float) 0.0 
 * #define a (float) 1.0 
 */

#endif // !_MAIN_H_
