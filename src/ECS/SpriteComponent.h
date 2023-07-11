/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _SPRITECOMPONENT_H_
#define _SPRITECOMPONENT_H_

#pragma once

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "Components.h"
#include "../TextureManager.h"
#include "Animation.h"
#include "../AssetManager.h"

class SpriteComponent : public Component {
 private:
  TransformComponent * transform;
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;

  bool animated = false;
  int frames = 0;
  int speed = 100;

 public:
  int animIndex = 0;
  std::map<const char*, Animation> animations;

  SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

  SpriteComponent() = default;
  explicit SpriteComponent(std::string id) {
    setTex(id);
  }

  SpriteComponent(std::string id, bool isAnimated) {
    animated = isAnimated;

    Animation idle = Animation(0, 3, 100);
    Animation walk = Animation(1, 8, 100);

    animations.emplace("Idle", idle);
    animations.emplace("Walk", walk);

    Play("Idle");

    setTex(id);
  }

  ~SpriteComponent()
  {}

  void setTex(std::string id) {
    texture = Butt3r::assets->GetTexture(id);
  }

  void init() override {
    transform = &entity->getComponent<TransformComponent>();

    srcRect.x = srcRect.y = 0;
    srcRect.w = transform->width;
    srcRect.h = transform->height;
  }

  void update() override {
    if (animated) {
      srcRect.x = srcRect.w * static_cast<int>(
        (SDL_GetTicks() / speed) % frames);
    }

    srcRect.y = animIndex * transform->height;

    destRect.x = static_cast<int>(transform->position.x - Butt3r::camera.x);
    destRect.y = static_cast<int>(transform->position.y - Butt3r::camera.y);
    destRect.w = transform->width * transform->scale;
    destRect.h = transform->height * transform->scale;
  }

  void draw() override {
    TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
  }

  void Play(const char* animName) {
    frames = animations[animName].frames;
    animIndex = animations[animName].index;
    speed = animations[animName].speed;
  }
};

#endif /* _SPRITECOMPONENT_H_ */

