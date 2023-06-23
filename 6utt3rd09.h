#pragma once
#ifndef _6UTT3RD09_H_
#define _6UTT3RD09_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * SDL_InstanceDeclarer - Instance declaration struct
 * SDL_Instance - typedef for SDL_InstanceDeclarer
 * @gWindow: Window
 * @gRenderer: Renderer
 *
 * Description: Declares the instance of window CRUD.
 */
typedef struct SDL_InstanceDeclarer
{
        SDL_Window *gWindow;
        SDL_Renderer *gRenderer;
        SDL_Surface *gHelloWorld;
} SDL_Instance;

/* Global variables */
const int WIDTH = 800;
const int HEIGHT = 600;

/* Main Prototypes */
bool init();
bool loadMedia();
void close();

#endif /* !_6UTT3RD09_H_ */
