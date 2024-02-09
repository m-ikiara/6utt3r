#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <glad/glad.h>

int
main(int argc, char *argv[]) {
  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = NULL;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("SDL failed to initialize: %s", SDL_GetError());
  else
    printf("[SUCCESS] Hello, World!");

  // Setting up OpenGL version
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            (int) 800 / 2,
                            (int) 400 / 2,
                            800,
                            600,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  !window ? printf("[ERROR] Failed to Initialize Window!: %s", SDL_GetError())
          : printf("[SUCCESS] Window created!: %p", (void *) &window);

  // Pre-load the Graphics:
  // Context
  SDL_GLContext context;
  context = SDL_GL_CreateContext(window);

  // Function pointers
  gladLoadGLLoader(SDL_GL_GetProcAddress);
  
  bool isRunning = true;
  while (isRunning) {
    // Refreshing the Viewport
    glViewport((GLint) 800 / 2,
               (GLint) 400 / 2,
               800, 600);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      event.type == SDL_QUIT ? isRunning = false : isRunning;
      if (event.type == SDL_MOUSEMOTION)
        printf("[INFO] Mouse's moved!");
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_0)
          printf("[INFO] You pressed 0!");
        else
          printf("[INFO] You didn't press 0!");
      }
      if (event.type == SDL_KEYUP) {
        if (event.key.keysym.sym == SDLK_0)
          printf("[INFO] You stopped pressing 0!");
      }
      
      const Uint8 *state = SDL_GetKeyboardState(NULL);
      if (state[SDL_SCANCODE_RIGHT])
        printf("[INFO] Turning right...\n");
      if (state[SDL_SCANCODE_LEFT])
        printf("[INFO] Turning left...\n");
    }

    // Rendering color to the Viewport
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Updating changes to Viewport
    SDL_GL_SwapWindow(window);
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
