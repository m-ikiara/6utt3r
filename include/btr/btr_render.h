#ifndef _BTR_RENDER_H_
#define _BTR_RENDER_H_

#pragma once

#include "./btr_vectors.h"
#include "../SDL2/SDL_render.h"


/***************************************************************************
 * @brief RENDERER MANAGEMENT
 ***************************************************************************/
SDL_Renderer *init_render(SDL_Window *window, int i);

/***************************************************************************
 * @brief OBJECT MANAGEMENT
 ***************************************************************************/
typedef enum {
  rect_x = (int) 800 / 2,
  rect_y = (int) 400 / 2,
  rect_w0 = 125,
  rect_h0 = 125
} btr_Rect;

void draw_rect(SDL_Renderer *renderer, Vector2D *vector,
               Uint8 r, Uint8 g, Uint8 b, Uint8 a);

#endif // !_BTR_RENDER_H_

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Renderer configuration.
 ***************************************************************************/
