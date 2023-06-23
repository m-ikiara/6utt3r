#include "6utt3rd09.h"

/**
 * initButt3r - Boolean
 * @gInstance: Instance
 *
 * Description: Initializes our game window and
 * prepares for rendering and other events.
 * Return: success, if it works or otherwise.
 * On error, SDL_Error.
 */
bool initButt3r(SDL_Instance *gInstance)
{
	bool success = false;

	instance != NULL
	?
		success = true
	:
		fprintf("Failure to launch!\n\tError: %s\n", SDL_GetError()),
		success;
	SDL_Init(SDL_INIT_EVERYTHING) == 0
	?
		success = true
	:
		fprintf("Can't churn ze butter! ;-(\n\tError: %s\n", SDL_GetError()),
		success;
	gInstance->WIDTH = 800, gInstance->HEIGHT = 600, gInstance->gSurface = NULL;
	gInstance->gWindow = SDL_CreateWindow(
		"6uττεrδ09 by iMjN",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		gInstance->WIDTH, gInstance->HEIGHT, 0
	);
	gInstance->gWindow != NULL
	?
		success = true
	:
		fprintf("Can't open window! ;-(\n\tError: %s\n", SDL_GetError()),
		success;
	gInstance->gRenderer = SDL_CreateRenderer(
		gInstance->gWindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	gInstance->gRenderer != NULL
	?
		success = true
	: 
		SDL_DestroyWindow(),
		fprintf("No eyes! ;-(\n\tError: %s\n", SDL_GetError()),	SDL_Quit(),
		success;

	return (success);
}
