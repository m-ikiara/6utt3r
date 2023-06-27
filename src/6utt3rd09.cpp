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

#include "./6utt3rd09.hpp"

/**
 * Butt3r - Class constructor
 *
 * Description: It's all in the name.
 * On error, stderr.
 */
Butt3r::Butt3r()
:isRunning(false),
 gWindow(nullptr),
 gRenderer(nullptr),
 gSurface(nullptr)
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
 * @xpos: X axis mapping
 * @ypos: Y axis mapping
 * @width: Window width
 * @height: Window height
 * @fullscreen: Fullscreen
 *
 * Description: Initializes our game window and
 * prepares for rendering and other events.
 * Return: success, if it works or otherwise.
 * On error, stderr + SDL_Error.
 */
void Butt3r::initButt3r(
  const char *title,
  int xpos, int ypos, int width, int height, bool fullscreen
) {
  int flags = 0;

  /* Check whether window is fullscreen */
  if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }
  /* Initialize an SDL instance and handle error */
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Let's go!" << std::endl;
    gWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!gWindow) {
      std::cout <<
        "No butter for dog? ;-(\n\tError: " <<
        SDL_GetError() << std::endl;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    if (!gRenderer) {
      std::cout <<
        "Unable to churn! ;-(\n\tError: " <<
        SDL_GetError() << std::endl;
    }
    isRunning = true;
  } else {
    std::cout << "Failure to launch!\n\tError: " << SDL_GetError() << std::endl;
    isRunning = false;
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
{}

/**
 * renderDog - Class method
 *
 * Description: Render graphics et al.
 * Return: void.
 * On error, stderr + SDL_GetError();
 */
void Butt3r::renderDog() {
  SDL_RenderClear(gRenderer);
  if (!gRenderer) {
    std::cout <<
      "Andere Wochenende! Auf Wiedersehen? Tchüss!\n\tError: " <<
      SDL_GetError() << std::endl;
  } else {
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 0);
  }
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

  std::cout << "So long! Que Passei! ;-)" << std::endl;
}

/**
 * runDog - Boolean
 *
 * Description: Returns true if the Game State is
 * "running".
 * Return: true, if it's running; false otherwise.
 * On error, stderr.
 */
bool Butt3r::runDog() {
  return (isRunning);
}
