/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Use the Vectors and Color structs that we had already defined
 *   2. Actually draw an object to the Screen
 *   3. Refactor the code and make it more pleasant
 *
 ***************************************************************************/

#include "../include/butter/main.h"

int
main(int argc, char *argv[])
{
  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  SDL_Surface *screen = NULL; // "Grab" the Screen

  SDL_Window *window = init_butter("6utt3r: The Ray-casting Engine",
                       (int) 800 / 2, (int) 400 / 2, 800, 600);
  screen = SDL_GetWindowSurface(window);


  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;

    int x, y;
    SDL_GetMouseState(&x, &y);

    handle_butter(event);

    update_butter(window);
  }

  quit_butter(window);

  return EXIT_SUCCESS;
}

/*******************************6utt3r***************************************
 *
 * @name 6utt3r
 * @version 0.3.0
 * @author Brian M'Ikiara
 *
 ***************************************************************************/
