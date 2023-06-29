/**
 * 6uττεrδ09 - The Game
 * Author: Brian M'Ikiara and Mr. Nobody
 * Created: 2023-06-09
 *
 * Description: MY GAME, MY RULES!
 *
 * Copyright (c) 2023 Brian M'Ikiara
 * All Rights Reserved.
 */

#include "6utt3rd09.h"

/**
 * Butt3r - Class constructor
 *
 * Description: It's all in the name.
 * On error, stderr.
 */
Butt3r::Butt3r()
{}

/**
 * ~Butt3r - Class deconstructor
 *
 * Description: The real McGyver.
 * On error, stderr.
 */
Butt3r::~Butt3r()
{}

/**
 * initButt3r - Class method
 * @title: Game name
 * @width: Window width
 * @height: Window height
 * @fullscreen: Fullscreen
 *
 * Description: Initializes our game window and
 * prepares for rendering and other events.
 * Return: success, if it works or otherwise.
 * On error, stderr + SDL_Error.
 */
void Butt3r::init(const char *title, int width, int height, bool fullscreen) {
  int flags = 0;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    gWindow = SDL_CreateWindow(
      title,
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      width, height, flags);
    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    if (gRenderer) {
      SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    }

    isRunning = true;
  }
}

/**
 * handleDog - Class method
 *
 * Description: Handle global events passed onto our
 * game that include, but're not limited to: key
 * inputs, interaction control e.t.c
 * Return: void.
 * On error, stderr + SDL_GetError();
 */
void Butt3r::handleDog() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}

/**
 * updatDog - Class method
 *
 * Description: Perform real-time updates to objects,
 * positions...the whole nine yards.
 * Return: void.
 * On error, stderr + SDL_GetError.
 */
void Butt3r::updatDog()
{
  std::cout << cnt++ << std::endl;
}

/**
 * renderDog - Class method
 *
 * Description: Render graphics et al.
 * Return: void.
 * On error, stderr + SDL_GetError();
 */
void Butt3r::renderDog() {
  SDL_RenderClear(gRenderer);
  SDL_RenderPresent(gRenderer);
}

/**
 * cleanDog - Class method
 *
 * Description: Perform Clean-upOps i.e. destroy window,
 * destroy subsystems and quit SDL.
 * Return: void.
 * On error, stderr + SDL_GetError();
 */
void Butt3r::cleanDog() {
  SDL_DestroyWindow(gWindow);
  SDL_DestroyRenderer(gRenderer);
  SDL_Quit();
}
