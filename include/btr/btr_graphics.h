#ifndef _BTR_GRAPHICS_H_
#define _BTR_GRAPHICS_H_

#pragma once

#include "../SDL2/SDL_image.h"

/***************************************************************************
 * @brief COLOR MANAGEMENT
 ***************************************************************************/
typedef struct {
  uint8_t *pr;
  uint8_t *pg;
  uint8_t *pb;
} pColor;

/***************************************************************************
 * @brief PIXEL MANAGEMENT
 ***************************************************************************/
void set_pixel(SDL_Surface *surface,
               int x, int y, uint8_t r, uint8_t g, uint8_t b);

/****************************************************************************
 * @brief SURFACE MANAGEMENT
 ***************************************************************************/
void load_surface(char *path, SDL_Surface *surface);

/****************************************************************************
 * @brief TEXTURE MANAGEMENT
 * TODO: Create the Texture prototypes.
 ***************************************************************************/

/***************************************************************************
 * @brief OpenGL MANAGEMENT
 ***************************************************************************/
/**
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

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Graphics configuration.
 ***************************************************************************/
