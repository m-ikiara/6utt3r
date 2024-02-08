#include <iostream>
#include <cstdlib>

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {

  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cout << "SDL failed to initialize: " << SDL_GetError();
  else
    std::cout << "Hello, World!\n";

  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            0,
                            0,
                            800,
                            600,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  if (!window)
    std::cout << "Failed to Initialize Window!: " << SDL_GetError();

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
