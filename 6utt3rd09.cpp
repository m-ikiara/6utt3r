#include "6utt3rd09.h"

/**
 * main - Function
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: Tests whether SDL2 is installed correctly
 * in the system.
 * Return: A window
 * On error, stderr.
 */


int main(int argc, char *argv[]) {
        const int WIDTH = 800, HEIGHT = 600;
        SDL_Window *window;
        SDL_Renderer *renderer;

        if (argc < 1) return EXIT_FAILURE;
        if (!argv) return EXIT_FAILURE;

        if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return 1;

        window = SDL_CreateWindow(
                        "6uττεrδ09 by iMjN",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        WIDTH,
                        HEIGHT,
                        SDL_WINDOW_ALLOW_HIGHDPI
                        );
        if(window == NULL) return 1;
  
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
  
        SDL_Event event;
        while(1) {
                if(SDL_PollEvent(&event))
                {
                        if(event.type == SDL_QUIT)
                                break;
                }
        }

        SDL_DestroyWindow(window);

        SDL_Quit();
        return 0;
}
