/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _BUTT3R_H_
#define _BUTT3R_H_

#pragma once

#include "./include/SDL.h"
#include "./include/SDL_main.h"
#include "./include/SDL_image.h"
#include <iostream>
#include <vector>

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

#endif /* _BUTT3R_H_ */

