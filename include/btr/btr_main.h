#ifndef _MAIN_H_
#define _MAIN_H_

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "../SDL2/SDL.h"
#include "./btr_graphics.h"
#include "./btr_controller.h"
#include "./btr_vectors.h"

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}

/**
 * @brief Main Prototypes
 */
SDL_Window *init_butter(char *title, int x, int y, int w, int h);
void quit_butter(SDL_Window *window);

#endif // !_MAIN_H_
