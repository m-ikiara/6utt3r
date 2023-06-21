#include "6utt3rd09.h"

/**
 * init - Boolean
 *
 * Description: It initializes the window and
 * prepares for other utilities to be loaded.
 * Return: success, if it works properly.
 * On error, SDL_Error.
 */
bool init()
{
        bool success = true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
                printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
                success = false;
        }
        else
        {
                gWindow = SDL_CreateWindow(
                        "6utt3rd09 by iMjN",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        WIDTH,
                        HEIGHT,
                        SDL_WINDOW_SHOWN
                );
                if (gWindow == NULL)
                {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                        success = false;
                }
                else
                {
                        gScreenSurface = SDL_GetWindowSurface(gWindow);
                }
        }
        return (success);
}

/**
 * loadMedia - Boolean
 *
 * Description: Displays the graphics we'd
 * like to load in our wiindow.
 * Return: success, if it works.
 * On error, SDL_Error.
 */
bool loadMedia()
{
        bool success = true;

        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        gHelloWorld = IMG_Load(".\\images\\iReadme\\Mario.jpg");
        if(gHelloWorld == NULL)
        {
                printf("Unable to load image %s! SDL Error: %s\n", ".\\images.\\iReadme\\Mario.jpg", SDL_GetError());
                success = false;
        }

        return (success);
}

/**
 * close - Function
 *
 * Description: Perform clean-up and exit function.
 * Return: void.
 * On error, SDL_Error.
 */
void close()
{
        SDL_FreeSurface(gHelloWorld);
        gHelloWorld = NULL;
        SDL_DestroyWindow(gWindow);
        SDL_Quit();
}

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: Runs our window to display our graphics.
 * Return: EXIT_SUCCESS; EXIT_FAILURE, otherwise.
 * On error, stderr.
 */
int main(int ac, char *av[])
{
        if (!init()) { printf("Failed to launch!\n"); }
        else
        {
                if (!loadMedia) { printf("Failed to load media!\n"); }
                else
                {
                        SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
                        SDL_UpdateWindowSurface(gWindow);
                        SDL_Event e; bool quit = false; while(quit == false) { while(SDL_PollEvent(&e)) { if(e.type == SDL_QUIT) quit = true; }}
                }
        }
        close();
        return (EXIT_SUCCESS);
}
