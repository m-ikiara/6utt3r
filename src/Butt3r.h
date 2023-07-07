/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _GAME_H_
#define _GAME_H_

#pragma once

#include <iostream>
#include <vector>
#include "../SDL2/include/SDL.h"
#include "../SDL2/include/SDL_image.h"

class AssetManager;
class ColliderComponent;

class Butt3r {
 public:
  Butt3r();
  ~Butt3r();

  void init(const char* title, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  bool running() { return isRunning; }
  void render();
  void clean();

  static SDL_Renderer *renderer;
  static SDL_Event event;
  static bool isRunning;
  static SDL_Rect camera;
  static AssetManager* assets;
  enum groupLabels : std::size_t {
    groupMap,
    groupPlayers,
    groupColliders,
    groupProjectiles
  };

 private:
  int cnt = 0;
  SDL_Window *window;
};

#endif /* _GAME_H_ */

