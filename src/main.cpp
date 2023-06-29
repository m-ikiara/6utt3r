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

#include "./6utt3rd09.h"

Butt3r *d0g = nullptr; /* Create new Butt3r instance globally */

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
  if (argc < 1) return EXIT_FAILURE;
  if (!argv) return EXIT_FAILURE;

  d0g = new Butt3r;
  d0g->init("6uττεrδ09 by iMjN", d0g->WIDTH, d0g->HEIGHT, false);
  while (d0g->runDog()) {
    d0g->renderDog();
    d0g->updatDog();
    d0g->handleDog();
  }
  d0g->cleanDog();
  delete d0g;

  return 0;
}
