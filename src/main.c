/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Refactor! Optimize! Sleep! Repeat!
 *
 ***************************************************************************/

#include "../include/btr/btr_main.h"

int
main(int argc, char *argv[])
{
  bool is_running = true;
  const char title[] = "6utt3r: The Ray-casting Engine";
  int x0 = (int) 800 / 2, y0 = (int) 400 / 2, w = 800, h = 600;
  SDL_Surface *screen = NULL;

  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Window *window = init_butter(title, x, y, w, h);
  screen = SDL_GetWindowSurface(window);

  // Create renderer and the Rectangle
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                              SDL_RENDERER_ACCELERATED);
  SDL_Rect rect = { x, y, w, h };

  while (is_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      handle_butter(event, screen, &is_running);
    }

    // Clear the screen and prepare for Drawing
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    // Now draw the Rectangle
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, x, y,
                       x - w, h);
    SDL_RenderDrawRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    update_butter(window, is_running);
  }

  quit_butter(window);

  return EXIT_SUCCESS;
}

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Provides 6utt3r's Primary entry point.
 ***************************************************************************/
