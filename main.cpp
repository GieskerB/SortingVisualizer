#define SDL_MAIN_USE_CALLBACKS 1

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <unordered_map>

#include "include/Array.hpp"
#include "include/rectangle/AllRectangles.hpp"
#include "include/sorting/AllSorts.hpp"


// =====================================================================================================================

/*
 * Arg Parser for Sorting visualizer
 */

struct Args {

	static const std::array<std::string,10> algorithms;
	static const std::unordered_map<std::string, int> algo_ids;

	int width = 1000, height = 600, array_size = 100;
	std::string sorting_algorithm = "Bubblesort";
	int algo_id = 2;
};

const std::array<std::string,10> Args::algorithms {"Bogosort", "Bubblesort", "Cyclesort", "Heapsort", "Insertionsort", "Mergesort", "Quicksort", "Radixsort", "Selectionsort", "Stoogesort"};
const std::unordered_map<std::string, int> Args::algo_ids {{"Bogosort",1}, {"Bubblesort",2}, {"Cyclesort",3},{"Heapsort",4}, {"Insertionsort",5}, {"Mergesort",6}, {"Quicksort",7}, {"Radixsort",8}, {"Selectionsort",9}, {"Stoogesort",10}};

void parse_args(int argc, char *argv[], Args *args) {
	for (int i = 1; i < argc; ++i) {
		std::string arg{argv[i]};
		if (arg.length() == 2 and arg[0] == '-') {
			switch (arg[1]) {
			case 'w':
				args->width = atoi(argv[++i]);
				continue;
			case 'h':
				args->height = atoi(argv[++i]);
				continue;
			case 'n':
				args->array_size = atoi(argv[++i]);
				continue;
			case 'a':
				const std::string& algo {argv[++i]};
				if (std::find(Args::algorithms.begin(), Args::algorithms.end(),algo) != Args::algorithms.end()) {
					args->algo_id = Args::algo_ids.at(algo);
					args->sorting_algorithm = algo;
				}

				continue;
			}
		} else {
			std::cerr << arg << " -> currently only support single char arguments.\n";
		}
	}
}

// =====================================================================================================================

struct AppState {
	const unsigned int MAX_DELAY = 5;

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

Sort* sorter;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
	if (!SDL_Init(SDL_INIT_VIDEO)) return SDL_APP_FAILURE;

	Args args{};

	parse_args(argc, argv, &args);

	auto *state = new AppState(args.width, args.height, args.array_size);

	SDL_CreateWindowAndRenderer("Sorting Visualizer", state->window_width, state->window_height,SDL_WINDOW_RESIZABLE,
	                            &state->window,
	                            &state->renderer);
	if (!state->window || !state->renderer) {
		SDL_Log("Window or Renderer creation failed: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	std::srand((unsigned) std::time(nullptr)); // setup Random Seed

	switch (args.algo_id) {
		case 1:
			sorter = new Bogosort(&state->array);
			break;
		case 2:
			sorter = new Bubblesort(&state->array);
			break;
		case 3:
			sorter = new Cyclesort(&state->array);
			break;
		case 4:
			sorter = new Heapsort(&state->array);
			break;
		case 5:
			sorter = new Insertionsort(&state->array);
			break;
		case 6:
			sorter = new Mergesort(&state->array);
			break;
		case 7:
			sorter = new Quicksort(&state->array);
			break;
		case 8:
			sorter = new Radixsort(&state->array);
			break;
		case 9:
			sorter = new Selectionsort(&state->array);
			break;
		case 10:
			sorter = new Stoogesort(&state->array);
			break;
	}


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
			sorter->reset();
		}
		// std::cout << event->key.key<< std::endl;
		if (event->key.key == 98) {
			// Key: b
			sorter->sort(1000);
		}
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
	auto *state = static_cast<AppState *>(appstate);
	SDL_RenderClear(state->renderer);
	SDL_SetRenderDrawColor(state->renderer, 69, 69, 69, 255);
	SDL_RenderFillRect(state->renderer, nullptr);
	for (int i = 0; i < state->array.size(); ++i) {
		state->array[i]->draw(state->renderer);
	}
	SDL_RenderPresent(state->renderer);
	sorter->sort(1);

	SDL_Delay(state->MAX_DELAY);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
	const auto *state = static_cast<AppState *>(appstate);
	delete state;
	delete sorter;
	SDL_Quit();
}

