/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#pragma once

#include "Butt3r.h"
#include "../SDL2/include/SDL_image.h"

class TextureManager {
 public:
  static SDL_Texture* LoadTexture(const char* fileName);
  static void Draw(
    SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
};

#endif /* _TEXTUREMANAGER_H_ */
