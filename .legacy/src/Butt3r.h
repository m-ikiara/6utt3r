/**
 * Copyright Brian M'Ikiara @2023
 */
#ifndef _BUTT3R_H_
#define _BUTT3R_H_

#pragma once
#include <string>
#include "./SDL.h"
#include "./SDL_main.h"

class Butt3r {
 public:
    Butt3r::Butt3r();
    Butt3r::~Butt3r();

    void init(std::string, size_t, size_t, bool);
    void handleEvents();
    void update();

 private:
    void render();
};

#endif  // !_BUTT3R_H_
