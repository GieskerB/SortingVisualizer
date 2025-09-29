#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "include/Array.hpp"
#include "include/rectangle/AllRectangles.hpp"

struct AppState {
	const unsigned int MAX_DELAY = 20;

	int window_width, window_height;

	SDL_Window *window{nullptr};
	SDL_Renderer *renderer{nullptr};
	Array array;

	AppState(const int width, const int height, const int array_size) : window_width(width), window_height(height),
	                                                                    array(
		                                                                    RAINBOW, array_size,
		                                                                    static_cast<float>(width),
		                                                                    static_cast<float>(height)
	                                                                    ) {
	}
};


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) return SDL_APP_FAILURE;

	auto *state = new AppState(1000, 700, 200);

	SDL_CreateWindowAndRenderer("Sorting Visualizer", state->window_width, state->window_height,SDL_WINDOW_RESIZABLE,
	                            &state->window,
	                            &state->renderer);
	if (!state->window || !state->renderer) {
		SDL_Log("Window or Renderer creation failed: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	std::srand((unsigned) std::time(nullptr)); // setup Random Seed

	*appstate = state;

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
	auto *state = static_cast<AppState *>(appstate);

	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}
	if (event->type == SDL_EVENT_WINDOW_RESIZED) {
		const int new_width = event->window.data1;
		const int new_height = event->window.data2;
		state->array.window_resize(state->window_width, state->window_height, new_width, new_height);
		state->window_width = new_width;
		state->window_height = new_height;
	}

	if (event->type == SDL_EVENT_KEY_DOWN) {
		if (event->key.key == 115) {
			// Key: s
			state->array.shuffle();
		}
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
	auto *state = static_cast<AppState *>(appstate);
	SDL_RenderClear(state->renderer);
	SDL_SetRenderDrawColor(state->renderer, 69, 69, 69, 255);
	SDL_RenderFillRect(state->renderer, NULL);
	for (int i = 0; i < state->array.size(); ++i) {
		state->array[i]->draw(state->renderer);
	}
	SDL_RenderPresent(state->renderer);

	SDL_Delay(state->MAX_DELAY);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
	const auto *state = static_cast<AppState *>(appstate);
	delete state;
	SDL_Quit();
}

