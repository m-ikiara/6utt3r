#include <butter/main.h>

int
main(int argc, char *argv[]) {
  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    fprintf(stderr, "SDL failed to initialize: %s", SDL_GetError());
  else
    fprintf(stderr, "[SUCCESS] Hello, World!");

  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            x, y, w, h,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  !window ? fprintf(stderr,
                    "[ERROR] Failed to Initialize Window!: %s",SDL_GetError())
          : fprintf(stderr, "[SUCCESS] Window created!");

  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      event.type == SDL_QUIT ? isRunning = false : isRunning;
      if (event.type == SDL_MOUSEMOTION)
        fprintf(stderr, "[INFO] Mouse's moved!");
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_0)
          fprintf(stderr, "[INFO] You pressed 0!");
        else
          fprintf(stderr, "[INFO] You didn't press 0!");
      }
      if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_0)
          fprintf(stderr, "[INFO] You stopped pressing 0!");
      }
      
      const Uint8 *state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_RIGHT])
        fprintf(stderr, "[INFO] Turning right...\n");
      if (state[SDL_SCANCODE_LEFT])
        fprintf(stderr, "[INFO] Turning left...\n");
    }
  }

  SDL_DestroyWindow(window);

  for (int i = 5; i > 0; i--) {
    fprintf(stderr, "[INFO] Closing in: %d", i);
    SDL_Delay(3000);
  }

  fprintf(stderr, "Bye Bye! =-D");
  SDL_Quit();

  return EXIT_SUCCESS;
}
