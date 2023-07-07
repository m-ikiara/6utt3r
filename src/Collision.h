/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _COLLISION_H_
#define _COLLISION_H_

#pragma once
#include "../SDL2/include/SDL.h"

class ColliderComponent;

class Collision {
 public:
  static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
  static bool AABB(
    const ColliderComponent& colA, const ColliderComponent& colB);
};

#endif /* _COLLISION_H_ */

