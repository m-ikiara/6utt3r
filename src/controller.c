/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Use the Vectors and Color structs that we had already defined
 *   2. Actually draw an object to the Screen
 *   3. Refactor the code and make it more pleasant
 *
 ***************************************************************************/

#include "../include/btr/btr_main.h"
#include <stdio.h>

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
init_butter(char *title, int x, int y, int w, int h)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("[ERROR] %s\n", SDL_GetError());
    fflush(NULL);
  }

  SDL_Window *window = SDL_CreateWindow(title, x, y, w, h,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  SDL_Delay(3000);

  if (!window) {
    printf("[ERROR] %s\n", SDL_GetError());
    fflush(NULL);
    return NULL;
  }
  printf("[INFO] Window Created! =-D\n");
  fflush(NULL);

  return window;
}

/**
 * @brief Handles all of 6utt3r's events
 *
 * @param (SDL_Event) event
 * @param (bool) isRunning
 * @param (char *) status
 * @param (void (*) (void)) action
 *
 * @returns Nothing
 */
void
handle_butter(SDL_Event event, bool isRunning,
             char *status, void (*action)(void))
{ 
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        isRunning = false;
        break;

      case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
          printf("[INFO] %s\n", status);
          fflush(NULL);
          (*action)();
        }
        if (event.button.button == SDL_BUTTON_RIGHT) {
          printf("[INFO] %s\n", status);
          fflush(NULL);
          (*action)();
        }
        break;

      case SDL_KEYDOWN:
        printf("[TODO] %s\n", status);
        fflush(NULL);
        (*action)();
        break;

      default:
        printf("[ERROR] %s\n", SDL_GetError());
        fflush(NULL);
        break;
    }
  }
}

/**
 * @brief Update 6utt3r's state
 *
 * @param (SDL_Window *) window
 *
 * @returns Nothing
 */
void
update_butter(SDL_Window *window)
{
  // Refresh the Screen per Update
  SDL_UpdateWindowSurface(window);
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
    printf(stderr, "Closing in %d\n", i);
    fflush(NULL);
  }

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

