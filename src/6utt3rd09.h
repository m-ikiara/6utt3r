#ifndef _6UTT3RD09_H_
#define _6UTT3RD09_H_

#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * struct SDL_InstanceDeclarer - Instance declaration struct
 * SDL_Instance - typedef for SDL_InstanceDeclarer
 * @WIDTH: Window width
 * @HEIGHT: Window height
 * @gWindow: Window
 * @gRenderer: Renderer
 * @gSurface: Surfaces
 *
 * Description: Declares the instance of window CRUD.
 */
typedef struct SDL_InstanceDeclarer
{
	size_t WIDTH;
	size_t HEIGHT;
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;
	SDL_Surface *gSurface;
} SDL_Instance;


/* Main Prototypes */
bool initButt3r(SDL_Instance *);
bool loadMedia(void);
void close(void);

#endif /* !_6UTT3RD09_H_ */
