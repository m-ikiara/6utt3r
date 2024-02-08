#include <iostream>
#include <cstdlib>

#include <SDL2/SDL.h>


int main(int argc, char *argv[]) {
  std::setvbuf(stdout, NULL, _IONBF, 0);

  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("SDL failed to initialize: %s", SDL_GetError());
  else
    printf("[SUCCESS] Hello, World!");

  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            (int) 800 / 2,
                            (int) 400 / 2,
                            800,
                            600,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  !window ? printf("[ERROR] Failed to Initialize Window!: %s", SDL_GetError())
          : printf("[SUCCESS] Window created!: %p", (void *) &window);


  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      event.type == SDL_QUIT ? isRunning = false : isRunning;
      if (event.type == SDL_MOUSEMOTION)
        printf("[INFO] Mouse's moved!");
      if (event.type == SDL_KEYDOWN) {
        // TODO: Implement ESCAPE key and other features
        if (event.key.keysym.sym == SDLK_0)
          printf("[INFO] You pressed 0!");
        else
          printf("[INFO] You didn't press 0!");
      }
      if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_0)
          printf("[INFO] You stopped pressing 0!");
      }
    }
  }

  SDL_DestroyWindow(window);

  for (int i = 5; i > 0; i--) {
    printf("[INFO] Closing in: %d", i);
    SDL_Delay(3000);
  }

  printf("Bye Bye! =-D");
  SDL_Quit();

  return EXIT_SUCCESS;
}
