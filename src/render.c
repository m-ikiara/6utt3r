/***************************************************************************
 * 
 * TODO: You'll need to:
 *   1. Implement a Sprite and Object renderer
 *   2. Refactor! Optimize! Sleep! Repeat!
 *
 ***************************************************************************/

#include "../include/btr/btr_render.h"

/**
 * @brief Initializes the Renderer
 *
 * @param (void)
 */
SDL_Renderer *
init_render(SDL_Window *window, int i)
{
  SDL_Renderer *renderer = SDL_CreateRenderer(window, i,
                                              SDL_RENDERER_ACCELERATED);
  return renderer;
}

/**
 * @brief Draw a Rectangle
 *
 * @param (SDL_Renderer *) renderer
 * @param (Uint8) r
 * @param (Uint8) g
 * @param (Uint8) b
 * @param (Uint8) a
 *
 * @returns Nothing
 */
void
draw_rect(SDL_Renderer *renderer)
{
  const SDL_Rect rect = { rect_x0, rect_y0, rect_w0, rect_h0 };

  SDL_SetRenderDrawColor(renderer, rect_r, rect_g, rect_b, rect_a);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_SetRenderDrawColor(renderer, rect_r, rect_g, rect_b, rect_a);
  SDL_RenderFillRect(renderer, &rect);

  SDL_RenderPresent(renderer);
}

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 1.3.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Provides 6utt3r's Renderer modules and implementations.
 ***************************************************************************/
