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

  if (argc == 0 && !argv) return EXIT_FAILURE;

  SDL_Window *window = init_butter(title, win_x, win_y, win_w, win_h);
  SDL_Renderer *renderer = init_render(window, -1);

  while (is_running) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      handle_butter(event, NULL, renderer, &is_running);
    }
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
