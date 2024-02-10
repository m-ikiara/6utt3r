/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Use the Vectors and Color structs that we had already defined
 *   2. Actually draw an object to the Screen
 *   3. Refactor the code and make it more pleasant
 *
 ***************************************************************************/
#include <butter/main.h>

/**
 * @brief Draws a pixel to the Screen
 *
 * @param (SDL_Surface *) surface: Pointer to Screen
 * @param (int) x
 * @param (int) y
 * @param (uint8_t) r
 * @param (uint8_t) g
 * @param (uint8_t) b
 *
 * @description: This function will set the value of a given pixel in order to
 * display it on our window. The pixelArray depends on a given processor's
 * architecture among other nitty-gritties. Feel free to modify the value
 * of the offsets to your liking.
 * @returns: Nothing
 */
void
SetPixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
  SDL_LockSurface(surface);
  uint8_t *pixelArray = (uint8_t *)surface->pixels;

  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 0] = b;
  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 1] = g;
  pixelArray[y*surface->pitch + x*surface->format->BytesPerPixel + 2] = r;

  SDL_UnlockSurface(surface);
}

int
main(int argc, char *argv[])
{
  if (argc == 0 && !argv)
    return EXIT_FAILURE;

  // WindowSettings *w1 = NULL;
  SDL_Window *window = NULL;
  SDL_Surface *screen = NULL; // "Grab" the Screen

  SDL_Init(SDL_INIT_VIDEO) < 0 ? fprintf(stderr, "[ERROR] %s", SDL_GetError())
                               : fprintf(stderr, "[INFO] Hi, I'm Butter! \\o/");

  // *w1->x = (int) 800 / 2, *w1->y = (int) 400 / 2;
  // *w1->w = 800, *w1->h = 600;
  window = SDL_CreateWindow("6utt3r: The Ray-casting Engine",
                            (int) 800 / 2, (int) 400 / 2,
                            800, 600,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  !window ? fprintf(stderr, "[ERROR] %s", SDL_GetError())
          : fprintf(stderr, "[INFO] Window Created! =-D");

  /**
   * // Initialize the Surface buffer
   *
   * // Load the Image
   * SDL_Surface *image;
   * image = IMG_Load("./assets/images/favicon.png");
   * SDL_BlitSurface(image, NULL, screen, NULL);
   * SDL_FreeSurface(image);
   * // Update to Screen
   */
  screen = SDL_GetWindowSurface(window);


  bool isRunning = true;
  while (isRunning) {
    SDL_Event event;

    /**
     * // Capture Mouse state and Position
     * pColor *pc1 = NULL, *pc2 = NULL;
     * Vector1 *v1 = NULL;
     * *pc1->pr = 0,   *pc1->pg = 0, *pc1->pb = 255;
     * *pc2->pr = 255, *pc2->pg = 0, *pc2->pb = 0;
     * *v1->x0 = 0, *v1->y0 = 0;
     */
    int x, y;

    // SDL_GetMouseState((*v1).x0, (*v1).y0);
    SDL_GetMouseState(&x, &y);

    while (SDL_PollEvent(&event)) {
      event.type == SDL_QUIT ? isRunning = false : isRunning;
      
      // Query Mouse Position per Mouse Button click
      if (event.button.button == SDL_BUTTON_LEFT) {
        /**
        fprintf(stderr,
                "[MOUSE] Right MSB clicked at x: %d y: %d", *v1->x0, *v1->y0);
        SetPixel(screen, *v1->x0, *v1->y0, *pc1->pr, *pc1->pg, *pc1->pb);
        */
        fprintf(stderr, "MOUSE] Left MSB clicked at x: %d y: %d\n", x, y);
        SetPixel(screen, x, y, 255, 0, 0);
      }

      if (event.button.button == SDL_BUTTON_RIGHT) {
        /**
        fprintf(stderr,
                "[MOUSE] Right MSB clicked at x: %d y: %d", *v1->x0, *v1->y0);
        SetPixel(screen, *v1->x0, *v1->y0, *pc2->pr, *pc2->pg, *pc2->pb);
         */
        fprintf(stderr, "MOUSE] Right MSB clicked at x: %d y: %d\n", x, y);
        SetPixel(screen, x, y, 0, 0, 255);
      }
    }

    // Refresh the Screen per Update
    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);

  for (int i = 3; i > 0; i--) {
    fprintf(stderr, "[INFO] Closing in %d\n", i);
    SDL_Delay(3000);
  }
  fprintf(stderr, "\n");

  fprintf(stderr, "[INFO] Bye Bye! =-D\n");
  SDL_Quit();

  return EXIT_SUCCESS;
}

/*******************************6utt3r***************************************
 *
 * @name 6utt3r
 * @version 0.3.0
 * @author Brian M'Ikiara
 *
 ***************************************************************************/
