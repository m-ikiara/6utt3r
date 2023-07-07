/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _TILECOMPONENT_H_
#define _TILECOMPONENT_H_

#pragma once

#include <string>
#include "ECS.h"
#include "../Vector2D.h"
#include "../Butt3r.h"
#include "../TextureManager.h"

class TileComponent : public Component {
 public:
  SDL_Texture * texture;
  SDL_Rect srcRect, destRect;
  Vector2D position;

  TileComponent() = default;

  ~TileComponent() {
    SDL_DestroyTexture(texture);
  }

  explicit TileComponent(
    int srcX, int srcY,
    int xpos, int ypos,
    int tsize, int tscale, std::string id) {
    texture = Butt3r::assets->GetTexture(id);

    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = srcRect.h = tsize;
    position.x = static_cast<float>(xpos);
    position.y = static_cast<float>(ypos);
    destRect.w = destRect.h = tsize * tscale;
  }

  void update() override {
    destRect.x = static_cast<int>(position.x - Butt3r::camera.x);
    destRect.y = static_cast<int>(position.y - Butt3r::camera.y);
  }
  void draw() override {
    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
  }
};

#endif /* _TILECOMPONENT_H_ */

