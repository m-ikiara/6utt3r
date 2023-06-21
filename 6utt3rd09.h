#pragma once
#ifndef _6UTT3RD09_H_
#define _6UTT3RD09_H_

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/* Global variables */
const int WIDTH = 800;
const int HEIGHT = 600;
SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

/* Main Prototypes */
bool init();
bool loadMedia();
void close();

#endif /* !_6UTT3RD09_H_ */
