/***************************************************************************
 *
 * TODO: HeRe'S yOuR lIsT. cHoP! cHoP!
 *   1. Implement a Texture manager
 *   2. Add more functionality to the Pixel manager
 *   3. REFACTOR! OPTIMIZE! SLEEP! REPEAT!
 *
 ***************************************************************************/

#include "../include/btr/btr_main.h"

/***************************************************************************
 * PIXEL MANAGEMENT >_<
 ***************************************************************************/

/**
 * @brief Draws a pixel to the Screen
 *
 * @param (SDL_Surface *) surface
 * @param (int) x
 * @param (int) y
 * @param (uint8_t) r
 * @param (uint8_t) g
 * @param (uint8_t) b
 *
 * @description This function will set the value of a given pixel in order to
 * display it on our window. The pixel array depends on a given processor's
 * architecture among other nitty-gritties. Feel free to modify the value
 * of the offsets to your liking.
 * @returns Nothing
 */
void
set_pixel(SDL_Surface *surface, int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
  SDL_LockSurface(surface);
  uint8_t *pixel_array = (uint8_t *)surface->pixels;

  pixel_array[y*surface->pitch + x*surface->format->BytesPerPixel + 0] = b;
  pixel_array[y*surface->pitch + x*surface->format->BytesPerPixel + 1] = g;
  pixel_array[y*surface->pitch + x*surface->format->BytesPerPixel + 2] = r;

  SDL_UnlockSurface(surface);
}

/***************************************************************************
 * SURFACE MANAGEMENT ^_^
 **************************************************************************/

/***************************************************************************
 * TEXTURE MANAGEMENT *-*
 ***************************************************************************/

/***********************************6utt3r**********************************
 * @name 6utt3r
 * @version 0.1.0
 * @author Brian M'Ikiara
 * @copyright 2024
 *
 * @description Contains all the functions that govern the rendering of
 * Graphics by 6utt3r.
 ***************************************************************************/
