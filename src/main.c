/*******************************6uttt3r**************************************
 *
 * TODO: Read through each of these and work accordingly:
 *   1. Refactor! Optimize! Sleep! Repeat!
 *
 ***************************************************************************/

#include <btr/btr_main.h>

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

	SDL_Window *window = SDL_CreateWindow(
			title, x, y, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
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
	int mse_x, mse_y;
	switch (event.type) {
		case SDL_QUIT:
			printf("[QUIT] Exiting...");
			fflush(stdout);
			*status = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&mse_x, &mse_y);

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
			if (event.key.keysym.sym == SDLK_r) draw_rect(renderer);
			if (event.key.keysym.sym == SDLK_x) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);
			}
			*status = true;
			break;

		default:
			printf("[ERROR] %s", SDL_GetError());
			fflush(stdout);
			*status = true;
			break;
	}

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
