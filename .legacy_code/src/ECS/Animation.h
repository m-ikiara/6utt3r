/* Copyright [2023] <Brian M'Ikiara> */
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#pragma once

struct Animation {
  int index;
  int frames;
  int speed;

  Animation() {}
  Animation(int i, int f, int s) {
    index = i;
    frames = f;
    speed = s;
  }
};

#endif /* _ANIMATION_H_ */

