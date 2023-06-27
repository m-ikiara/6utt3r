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

#ifndef _6UTT3RD09_HPP_
#define _6UTT3RD09_HPP_

#pragma once
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
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
    bool fullscreen);
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
