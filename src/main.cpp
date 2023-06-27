#include "./6utt3rd09.hpp"

Butt3r *d0g = nullptr; /* Create new Butt3r instance globally */

/**
 * main - Function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Description: Runs our glorious game.
 * Return: EXIT_SUCCESS; EXIT_FAILURE, otherwise.
 * On error, stderr & SDL_GetError();
 */
int main(int ac, char **av)
{
	d0g = new Butt3r;

	if (ac >= 2) { return EXIT_FAILURE; }
	if (!av) { return EXIT_FAILURE; }
	if (!d0g)
	{
		std::cout << "No butter? (TT)\n\tError: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	d0g->initButt3r(
		"6uττεrδ09 by iMjN",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600, false
	);
	/* Our game loop */
	while (d0g->runDog())
	{
		d0g->handleDog(); /* Handle events */
		d0g->updatDog(); /* Update window */
		d0g->renderDog(); /* Render graphics */
	}
	d0g->cleanDog(); /* Clean up */

	return EXIT_SUCCESS;
}
