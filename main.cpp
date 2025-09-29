#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "include/Array.hpp"
#include "include/rectangle/AllRectangles.hpp"

static const int WINDOW_WIDTH = 1000;
static const int WINDOW_HEIGHT = 700;
static const int ARRAY_SIZE = 500;
static const int DELAY = 20;

static SDL_Window *window;
SDL_Renderer *renderer;
Array *array;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) return SDL_APP_FAILURE;

	window = SDL_CreateWindow("Sorting Visualizer", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE);
	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize Window");
		return SDL_APP_FAILURE;
	}
	renderer = SDL_CreateRenderer(window, nullptr);
	if (!renderer) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialize Renderer");
		return SDL_APP_FAILURE;
	}
	// setup Random Seed
	std::srand((unsigned) std::time(nullptr));

	array = new Array{RAINBOW, ARRAY_SIZE, WINDOW_WIDTH, WINDOW_HEIGHT};
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 69, 69, 69, 255);
	SDL_RenderFillRect(renderer, NULL);
	for (int i = 0; i < array->size(); ++i) {
		(*array)[i]->draw(renderer);
	}
	SDL_RenderPresent(renderer);

	SDL_Delay(DELAY);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
	if (array) delete array;
	SDL_Quit();
}

