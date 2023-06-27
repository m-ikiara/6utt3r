#ifndef _6UTT3RD09_HPP_
#define _6UTT3RD09_HPP_

#pragma once
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unistd.h>
#include <stddef.h>
#include <cctype>
#include <cstdlib>

/**
 * Butt3r - Class
 *
 * Description: This defines our game loop.
 */
class Butt3r {
public:
	/* Call to construct our classes */
	Butt3r();
	~Butt3r();

	/* Method prototypes */
	void initButt3r(
		const char *title,
		int xpos,
		int ypos,
		int width,
		int height,
		bool fullscreen
	);
	void updatDog();
	void handleDog();
	void renderDog();
	void cleanDog();
	bool runDog();

private:
	bool isRunning;
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;
	SDL_Surface *gSurface;
};

#endif /* _6UTT3RD09_HPP_ */
