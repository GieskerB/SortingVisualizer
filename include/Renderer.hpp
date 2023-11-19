#ifndef INCLUDE_RENDERER_HPP_
#define INCLUDE_RENDERER_HPP_

#include <SDL.h>

#include "Array.hpp"

class Renderer {

private:

	const Uint16 delay;

	SDL_Window *window;
	SDL_Renderer *renderer;

	Array *array;

public:

	Renderer(Array *array, Uint16 wWidth, Uint16 wHeight, Uint8 delay);
	~Renderer();

	Uint8 renderSwap(const Uint16 indexA, const Uint16 indexB,
			Uint8 currentSteps, int maxSteps);

	void renderArray();

	void finish();

	void quit();

};

#endif /* INCLUDE_RENDERER_HPP_ */
