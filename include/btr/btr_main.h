#ifndef _BTR_MAIN_H_
#define _BTR_MAIN_H_

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * #define try bool __HadError=false;
 * #define catch(x) ExitJmp:if(__HadError)
 * #define throw(x) {__HadError=true;goto ExitJmp;}
 */

#include <stdbool.h>
#include "../SDL2/SDL.h"

/***************************************************************************
 * @brief PERIPHERAL MANAGEMENT
 ***************************************************************************/
typedef enum {
  mouse_x,
  mouse_y
} btr_Mouse;

/***************************************************************************
 * @brief WINDOW MANAGEMENT
 ***************************************************************************/
typedef enum {
  win_x = (int) 800 / 2,
  win_y = (int) 400 / 2, 
  win_w = (int) 800, 
  win_h = (int) 600
} btr_Window;

/***************************************************************************
 * @brief CONTROLLER PROTOTYPES
 ***************************************************************************/
SDL_Window *init_butter(const char title[], int x, int y, int w, int h);
bool *handle_butter(SDL_Event event,
                    SDL_Surface *surface, SDL_Renderer *renderer,
                    bool *status);
void update_butter(SDL_Window *window, bool status);
void quit_butter(SDL_Window *window);

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

#include "../SDL2/SDL_render.h"

/***************************************************************************
 * @brief RENDERER MANAGEMENT
 ***************************************************************************/
SDL_Renderer *init_render(SDL_Window *window, int i);

/***************************************************************************
 * @brief OBJECT MANAGEMENT
 ***************************************************************************/
typedef enum {
  rect_r = (Uint8) 0,
  rect_g = (Uint8) 0,
  rect_b = (Uint8) 255,
  rect_a = (Uint8) SDL_ALPHA_OPAQUE,
  rect_x = (int) 800 / 2,
  rect_y = (int) 400 / 2,
  rect_x0 = (int) (800 - 125) / 2,
  rect_y0 = (int) (600 - 125) / 2,
  rect_w0 = 125,
  rect_h0 = 125
} btr_Rect;

void draw_rect(SDL_Renderer *renderer);

/***************************************************************************
 * @brief VECTOR MANAGEMENT
 ***************************************************************************/
typedef struct {
  int *x0;
  int *y0;
} Vector1D;

typedef struct {
  int *x0;
  int *y0;
  int *x1;
  int *y1;
} Vector2D;

typedef struct Vector3D {
  int *x0;
  int *y0;
  int *z0;
  int *x1;
  int *y1;
  int *z1;
} Vector3D;

#endif // !_BTR_MAIN_H_

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Primary entry point configuration.
 ***************************************************************************/
