#ifndef _BTR_CONTROLLER_H_
#define _BTR_CONTROLLER_H_

#pragma once

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

#endif // !_BTR_CONTROLLER_H_

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Defines 6utt3r's Global configuration.
 ***************************************************************************/
