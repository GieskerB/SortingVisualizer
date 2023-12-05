#include <cstdlib>
#include <ctime>
#include <iostream>

#include <SDL.h>

#include "includes.inc"

int main(int argc, char *args[]) {

	const Uint16 WINDOW_WIDTH = 1920;
	const Uint16 WINDOW_HEIGHT = 1080;
	const Uint16 ARRAY_SIZE = 2000;
	const Uint8 DELAY = 0;

	// setup Random Seed
	std::srand((unsigned) std::time(nullptr));

	Array array = Array(RectangleType::INTERACTIVE,
			(ARRAY_SIZE > WINDOW_WIDTH ? WINDOW_WIDTH : ARRAY_SIZE),
			WINDOW_WIDTH, WINDOW_HEIGHT);

	Renderer renderer = Renderer(&array, WINDOW_WIDTH, WINDOW_HEIGHT, DELAY);

	Sort *sorter = new Heapsort(&array, &renderer);

	array.shuffle();

	renderer.renderArray();


//	sorter->sortMultipleSteps(8);
//	sorter->sortFully();
	sorter->sortStepByStep();

	renderer.finish();
	renderer.quit();

	delete sorter;

	return 0;
}

