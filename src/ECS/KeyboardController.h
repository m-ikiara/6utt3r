/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _KEYBOARDCONTROLLER_H_
#define _KEYBOARDCONTROLLER_H_

#pragma once

#include "../Butt3r.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
 public:
  TransformComponent *transform;
  SpriteComponent *sprite;

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
    sprite = &entity->getComponent<SpriteComponent>();
  }

  void update() override {
    if (Butt3r::event.type == SDL_KEYDOWN) {
      switch (Butt3r::event.key.keysym.sym) {
        case SDLK_w:
          transform->velocity.y = -1;
          sprite->Play("Walk");
          break;
        case SDLK_a:
          transform->velocity.x = -1;
          sprite->Play("Walk");
          sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
          break;
        case SDLK_d:
          transform->velocity.x = 1;
          sprite->Play("Walk");
          break;
        case SDLK_s:
          transform->velocity.y = 1;
          sprite->Play("Walk");
          break;
        default:
          break;
      }
    }

    if (Butt3r::event.type == SDL_KEYUP) {
      switch (Butt3r::event.key.keysym.sym) {
        case SDLK_w:
          transform->velocity.y = 0;
          sprite->Play("Idle");
          break;
        case SDLK_a:
          transform->velocity.x = 0;
          sprite->Play("Idle");
          sprite->spriteFlip = SDL_FLIP_NONE;
          break;
        case SDLK_d:
          transform->velocity.x = 0;
          sprite->Play("Idle");
          break;
        case SDLK_s:
          transform->velocity.y = 0;
          sprite->Play("Idle");
          break;
        case SDLK_ESCAPE:
          Butt3r::isRunning = false;
        default:
          break;
      }
    }
  }
};

#endif /* _KEYBOARDCONTROLLER_H_ */

