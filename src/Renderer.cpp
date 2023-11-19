#include "../include/Renderer.hpp"

#include "../include/rectangle/AllRectangles.hpp"

#include <iostream>

Renderer::Renderer(Array *array, Uint16 wWidth, Uint16 wHeight, Uint8 delay) :
		delay(delay) {
	this->array = array;

	SDL_Init(SDL_INIT_EVERYTHING);

	this->window = SDL_CreateWindow("SDL2 Window",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, wWidth, wHeight, SDL_WINDOW_SHOWN);

	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

Renderer::~Renderer() {

}

Uint8 Renderer::renderSwap(const Uint16 indexA, const Uint16 indexB,
		Uint8 currentSteps, int maxSteps) {

	this->array->swap(indexA, indexB);
	if (maxSteps > 0 && currentSteps >= maxSteps - 1) {
		this->renderArray();
		return 0;
	}
	return currentSteps + 1;
}

void Renderer::renderArray() {
	SDL_RenderClear(this->renderer);
	for (Uint16 i = 0; i < this->array->SIZE; i++) {
		BaseRectangle *rect = this->array->get(i);
		SDL_SetRenderDrawColor(this->renderer, rect->getRed(), rect->getGreen(),
				rect->getBlue(), rect->getAlpha());
		rect->resetState();
		SDL_RenderFillRect(this->renderer, rect->getRectPointer());
	}
	SDL_SetRenderDrawColor(this->renderer, 69, 69, 69, 255);

	SDL_RenderPresent(this->renderer);
	SDL_Delay(this->delay);
}

void Renderer::finish() {
	if (this->array->TYPE != RectangleType::INTERACTIVE) {
		SDL_Delay(1000);
		return;
	}
	this->renderArray();
	const Uint16 finishDelay = 2048 / this->array->SIZE;
	for (Uint16 i = 0; i < this->array->SIZE; i++) {
		if (i > 0) {
			InteractiveRectangle *prevRect =
					dynamic_cast<InteractiveRectangle*>(this->array->get(i - 1));
			prevRect->resetState();
			prevRect->setCompared();

			SDL_SetRenderDrawColor(this->renderer, prevRect->getRed(),
					prevRect->getGreen(), prevRect->getBlue(),
					prevRect->getAlpha());
			SDL_RenderFillRect(this->renderer, prevRect->getRectPointer());
		}

		InteractiveRectangle *rect =
				dynamic_cast<InteractiveRectangle*>(this->array->get(i));

		rect->setSwapped();

		SDL_SetRenderDrawColor(this->renderer, rect->getRed(), rect->getGreen(),
				rect->getBlue(), rect->getAlpha());
		SDL_RenderFillRect(this->renderer, rect->getRectPointer());

		SDL_RenderPresent(this->renderer);

		SDL_Delay(finishDelay);
	}
}

void Renderer::quit() {
	SDL_Delay(1000);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

