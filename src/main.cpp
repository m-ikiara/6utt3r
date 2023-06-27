/**
 * 6uττεrδ09 - The Game
 * Author: Brian M'Ikiara and Mr. Nobody
 * Created: 2023-06-09
 *
 * Description: MY GAME, MY RULES!
 *
 * Copyright (c) 2023 Brian M'Ikiara
 * All Rights Reserved.
 */

#include "./6utt3rd09.hpp"

Butt3r *d0g = nullptr; /* Create new Butt3r instance globally */

#ifdef _WIN32

#include <windows.h>

/**
 * WinMain - Entry Point
 * @hInstance: Current instance handle
 * @hPrevInstance: Previous instance handle
 * @lpCmdLine: Argument variables
 * @nCmdShow: Window size
 *
 * Description: This enables compilation in a Windows environment.
 * Return: 0, success; <int:n>, otherwise.
 * On error, stderr.
 */
int WINAPI WinMain(
        [[maybe_unused]] HINSTANCE hInstance,
        [[maybe_unused]] HINSTANCE hPrevInstance,
        [[maybe_unused]] LPSTR lpCmdLine,
        [[maybe_unused]] int nCmdShow) {
  d0g = new Butt3r;
  d0g->initButt3r(
    "6uττεrδ09 by iMjN",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800, 600, false);
  if (!d0g) {
    std::cout << "No butter? (TT)\n\tError: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }
  while (d0g->runDog()) {
    d0g->handleDog();
    d0g->updatDog();
    d0g->renderDog();
  }

  d0g->cleanDog();
  delete d0g;

  return 0;
}

#else

/**
 * main - Function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: Runs our glorious game.
 * Return: EXIT_SUCCESS; EXIT_FAILURE, otherwise.
 * On error, stderr & SDL_GetError();
 */
int main(int ac, char **av) {
  d0g = new Butt3r;

  if (ac >= 2) { return EXIT_FAILURE; }
  if (!av) { return EXIT_FAILURE; }
  if (!d0g) {
    std::cout << "No butter? (TT)\n\tError: " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  }
  d0g->initButt3r(
    "6uττεrδ09 by iMjN",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    800, 600, false);
  /* Our game loop */
  while (d0g->runDog()) {
    d0g->handleDog(); /* Handle events */
    d0g->updatDog(); /* Update window */
    d0g->renderDog(); /* Render graphics */
  }
  d0g->cleanDog(); /* Clean up */
  delete dog;

  return EXIT_SUCCESS;
}

#endif
