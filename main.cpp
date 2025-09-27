#include <cstdlib>
#include <ctime>
#include <iostream>

#include "include/Array.hpp"
#include "include/rectangle/AllRectangles.hpp"

#include <SDL3/SDL.h>

void render_array(SDL_Window * window, SDL_Renderer *renderer, const Array &array) {

}

int main(int argc, char *args[]) {

	const int WINDOW_WIDTH = 1000;
	const int WINDOW_HEIGHT = 700;
	const int ARRAY_SIZE = 500;
	const int DELAY = 5000;

	// setup Random Seed
	std::srand((unsigned) std::time(nullptr));

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * const window = SDL_CreateWindow("Sorting Visualizer", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE);

	if (!window) {
		SDL_Log("Could not create window: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer * const renderer = SDL_CreateRenderer(window, "Renderer");

	// Array array{RAINBOW, ARRAY_SIZE, WINDOW_WIDTH, WINDOW_HEIGHT};
	//
	// render_array(window,renderer, array);

	SDL_Delay(DELAY);

	SDL_Quit();

	return 0;
}

