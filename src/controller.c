/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Implement a Keyboard handler
 *   2. Refactor! Optimize! Sleep! Repeat!
 *
 ***************************************************************************/

#include "../include/btr/btr_main.h"

/**
 * @brief Initializes SDL and 6utt3r as a whole
 *
 * @param (char *) title
 * @param (int) x
 * @param (int) y
 * @param (int) w
 * @param (int) h
 *
 * @returns A pointer to the window or NULL
 */
SDL_Window *
init_butter(const char title[], int x, int y, int w, int h)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("[ERROR] %s", SDL_GetError());
    fflush(stdout);
  }

  SDL_Window *window = SDL_CreateWindow(title, x, y, w, h,
                                        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  if (!window) {
    printf("[ERROR] %s", SDL_GetError());
    fflush(stdout);
    return NULL;
  }
  printf("[INFO] Window Created! =-D");
  fflush(stdout);

  return window;
}

/**
 * @brief Handles all of 6utt3r's events
 *
 * @param (SDL_Event) event
 * @param (SDL_Surface *) surface
 * @param (SDL_Renderer *) renderer
 * @param (bool) status
 *
 * @returns Nothing
 */
bool *
handle_butter(SDL_Event event,
              SDL_Surface *surface, SDL_Renderer *renderer,
              bool *status)
{ 
  switch (event.type) {
    case SDL_QUIT:
      printf("[QUIT] Exiting...");
      fflush(stdout);
      *status = false;
      break;

    case SDL_MOUSEBUTTONDOWN:
      SDL_GetMouseState((int *) mouse_x, (int *) mouse_y);

      if (event.button.button == SDL_BUTTON_LEFT) {
        printf("[INFO] Left Button pressed! o-0");
        fflush(stdout);
        set_pixel(surface, mouse_x, mouse_y, 255, 0, 0);
        *status = true;
      }
      if (event.button.button == SDL_BUTTON_RIGHT) {
        printf("[INFO] Right Button pressed! 0-o");
        fflush(stdout);
        set_pixel(surface, mouse_x, mouse_y, 0, 0, 255);
        *status = true;
      }
      break;

    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_r) {
        draw_rect(renderer);
      }
      *status = true;
      break;

    default:
      printf("[ERROR] %s", SDL_GetError());
      fflush(stdout);
      *status = true;
      break;
  }
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);

  return status;
}

/**
 * @brief Update 6utt3r's state
 *
 * @param (SDL_Window *) window
 *
 * @returns Nothing
 */
void
update_butter(SDL_Window *window, bool status)
{
  if (status == true) { SDL_UpdateWindowSurface(window); }
}

/**
 * @brief Quits 6utt3r and closes SDL2's subsystems
 *
 * @param (SDL_Window *) window
 *
 * @returns Nothing
 */
void
quit_butter(SDL_Window *window)
{
  SDL_DestroyWindow(window);

  for (int i = 3; i > 0; i--) {
    printf("[QUIT] Closing in %d", i);
    fflush(stdout);
  }

  printf("[QUIT] Bye Bye! ^-^");
  fflush(stdout);
  SDL_Quit();
}

/**************************************6utt3r********************************
 * @name 6utt3r
 * @version 0.1.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Contains all the functions that controll 6utt3r..
 ***************************************************************************/

