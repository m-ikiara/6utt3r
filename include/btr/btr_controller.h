#ifndef _BTR_CONTROLLER_H_
#define _BTR_CONTROLLER_H_

#pragma once

#include "../SDL2/SDL.h"

/***************************************************************************
 * @brief WINDOW SETTINGS
 ***************************************************************************/
typedef struct {
  int *x;
  int *y;
  int *w;
  int *h;
} setWindow;

/***************************************************************************
 * @brief CONTROLLER PROTOTYPES
 ***************************************************************************/
SDL_Window *init_butter(const char title[], int x, int y, int w, int h);
bool *handle_butter(SDL_Event event, SDL_Surface *surface, bool *status);
void update_butter(SDL_Window *window, bool status);
void quit_butter(SDL_Window *window);

#endif // !_BTR_CONTROLLER_H_
