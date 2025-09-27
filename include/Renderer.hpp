#ifndef INCLUDE_RENDERER_HPP_
#define INCLUDE_RENDERER_HPP_

#include <sys/types.h>
#include <SDL3/SDL.h>

#include "Array.hpp"

class Renderer {

	const Uint16 delay;

	SDL_Window *window;
	SDL_Renderer *renderer;

	Array *array;

public:

	Renderer(Array *array, uint16_t wWidth, uint16_t wHeight, Uint8 delay);
	~Renderer();

	Uint8 renderSwap(uint16_t indexA, uint16_t indexB,
			Uint8 currentSteps, int maxSteps);

	void renderArray();

	void finish();

	void quit();

};

#endif /* INCLUDE_RENDERER_HPP_ */
