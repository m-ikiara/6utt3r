#ifndef _BTR_GRAPHICS_H_
#define _BTR_GRAPHICS_H_

#pragma once

#include "../SDL2/SDL_image.h"

/***************************************************************************
 * @brief COLOR MANAGEMENT
 ***************************************************************************/
typedef enum {
  btr_pr = (uint8_t) 0,
  btr_pg = (uint8_t) 0,
  btr_pb = (uint8_t) 0
} btr_Pixel_Color;

typedef enum {
  btr_gl_x = (int) 800 / 2,
  btr_gl_y = (int) 400 / 2,
  btr_gl_w = 800,
  btr_gl_h = 600,
} btr_GLR_Position;

/**
 * typedef enum {
 *   btr_gl_r = 1.0, 
 *   btr_gl_b = 0.0,
 *   btr_gl_g = 0.0,
 *   btr_gl_a = 1.0
 * } btr_GLR_Color;
*/

/***************************************************************************
 * @brief PIXEL MANAGEMENT
 ***************************************************************************/
void set_pixel(SDL_Surface *surface,
               int x, int y, uint8_t r, uint8_t g, uint8_t b);

/****************************************************************************
 * @brief SURFACE MANAGEMENT
 ***************************************************************************/

/****************************************************************************
 * @brief TEXTURE MANAGEMENT
 ***************************************************************************/
SDL_Texture *load_texture(SDL_Renderer *renderer, const char path[]);

/***************************************************************************
 * @brief OpenGL MANAGEMENT
 ***************************************************************************/

#endif // !_BTR_GRAPHICS_H_

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Graphics configuration.
 ***************************************************************************/
