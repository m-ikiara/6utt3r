#ifndef _BTR_GRAPHICS_H_
#define _BTR_GRAPHICS_H_

#pragma once

#include "../SDL2/SDL_image.h"

/**
 * @brief Color Settings
 */
typedef struct {
  uint8_t *pr;
  uint8_t *pg;
  uint8_t *pb;
} pColor;

/**
 * @brief Pixel management
 */
void set_pixel(SDL_Surface *surface,              // Surface or Screen
               int x, int y,                      // Pixel position (x, y)
               uint8_t r, uint8_t g, uint8_t b);  // Pixel color (r, g, b)

void load_surface(char *path,              // Surface URL
                  SDL_Surface *surface);   // Screen or Surface
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

#endif // !_BTR_GRAPHICS_H_
