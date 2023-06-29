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

#ifndef _6UTT3RD09_H_
#define _6UTT3RD09_H_
#define SDL_MAIN_HANDLED

#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

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
  void init(
    const char *title,
    int width,
    int height,
    bool fullscreen);
  void updatDog();
  void handleDog();
  void renderDog();
  void cleanDog();
  const int WIDTH = 800, HEIGHT = 600;
  bool runDog() { return isRunning; }

 private:
  bool isRunning = false;
  int cnt = 0;
  SDL_Window *gWindow = nullptr;
  SDL_Renderer *gRenderer = nullptr;
  SDL_Surface *gSurface = nullptr;
};

#endif /* _6UTT3RD09_H_ */
