#include <butter/main.h>

int
main(int argc, char *argv[]) {
  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = NULL;
  SDL_Surface *screen = NULL; // "Grab" the Screen

  SDL_Init(SDL_INIT_VIDEO) < 0 ? fprintf(stderr, "[ERROR] %s", SDL_GetError())
                               : fprintf(stdout, "[INFO] Hi, I'm Butter! \\o/");

  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            x, y, w, h,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  !window ? fprintf(stderr, "[ERROR] %s", SDL_GetError())
          : fprintf(stdout, "[INFO] Window Created! =-D");

  // Initialize the Surface buffer
  screen = SDL_GetWindowSurface(window);

  // Load the Image
  SDL_Surface *image;
  image = IMG_Load("./assets/images/favicon.png");
  SDL_BlitSurface(image, NULL, screen, NULL);
  SDL_FreeSurface(image);

  // Update to Screen
  SDL_UpdateWindowSurface(window);

  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      event.type == SDL_QUIT ? isRunning = false : isRunning;
      if (event.type == SDL_MOUSEMOTION)
        fprintf(stdout, "[INFO] Mouse's moved!");
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_0)
          fprintf(stdout, "[INFO] You pressed 0!");
        else
          fprintf(stdout, "[INFO] You didn't press 0!");
      }
      if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_0)
          fprintf(stdout, "[INFO] You stopped pressing 0!");
      }
      
      const Uint8 *state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_RIGHT])
        fprintf(stdout, "[INFO] Turning right...\n");
      if (state[SDL_SCANCODE_LEFT])
        fprintf(stdout, "[INFO] Turning left...\n");
    }
  }

  SDL_DestroyWindow(window);

  for (int i = 3; i > 0; i--) {
    fprintf(stdout, "[INFO] Closing in %d", i);
    SDL_Delay(3000);
  }

  fprintf(stdout, "[INFO] Bye Bye! =-D");
  SDL_Quit();

  return EXIT_SUCCESS;
}
