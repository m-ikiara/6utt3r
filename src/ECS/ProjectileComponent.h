/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _PROJECTILECOMPONENT_H_
#define _PROJECTILECOMPONENT_H_

#pragma once

#include "ECS.h"
#include "Components.h"
#include "../Vector2D.h"

class ProjectileComponent : public Component {
 public:
  ProjectileComponent(int rng, int sp, Vector2D vel)
    : range(rng), speed(sp), velocity(vel)
  {}
  ~ProjectileComponent()
  {}

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
    transform->velocity = velocity;
  }

  void update() override {
    distance += speed;

    if (distance > range) {
      std::cout << "Out of Range" << std::endl;
      entity->destroy();
    } else if (
      transform->position.x > Butt3r::camera.x + Butt3r::camera.w ||
      transform->position.x < Butt3r::camera.x ||
      transform->position.y > Butt3r::camera.y + Butt3r::camera.h ||
      transform->position.y < Butt3r::camera.y) {
      std::cout << "Out of bounds!" << std::endl;
      entity->destroy();
    }
  }

 private:
  TransformComponent* transform;

  int range = 0;
  int speed = 0;
  int distance = 0;
  Vector2D velocity;
};

#endif /* _PROJECTILECOMPONENT_H_ */

