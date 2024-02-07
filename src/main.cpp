#include <iostream>
#include <cstdlib>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
  if (argc < 1 && !argv)
    return EXIT_FAILURE;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cout << "SDL failed to Initialize: " << SDL_GetError();
  else
    std::cout << "Hello, World!\n";

  return EXIT_SUCCESS;
}
