/* Copyright [2023] <Brian M'Ikiara> */
#include "Butt3r.h"

Butt3r *d09 = nullptr;

int main(int argc, char *argv[]) {
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  d09 = new Butt3r();
  d09->init("6utt3rd09 by iMjN", 800, 640, false);

  while (d09->running()) {
    frameStart = SDL_GetTicks();

    d09->handleEvents();
    d09->update();
    d09->render();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  d09->clean();
  return 0;
}

