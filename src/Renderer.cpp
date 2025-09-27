#include "../include/Renderer.hpp"

#include "../include/rectangle/AllRectangles.hpp"

#include <iostream>

Renderer::Renderer(Array *array, int wWidth, int wHeight, Uint8 delay) :
		delay(delay) {
	this->array = array;

}

Renderer::~Renderer() {

}

Uint8 Renderer::renderSwap(const int indexA, const int indexB,
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
	for (int i = 0; i < this->array->SIZE; i++) {
		Rect *rect = this->array->get(i);
		SDL_SetRenderDrawColor(this->renderer, rect->getRed(), rect->getGreen(),
				rect->getBlue(), rect->getAlpha());
		rect->resetState();
		// SDL_RenderFillRect(this->renderer, rect->getRectPointer());
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
	const int finishDelay = 2048 / this->array->SIZE;
	for (int i = 0; i < this->array->SIZE; i++) {
		if (i > 0) {
			InteractiveRectangle *prevRect =
					dynamic_cast<InteractiveRectangle*>(this->array->get(i - 1));
			prevRect->resetState();
			prevRect->setCompared();

			SDL_SetRenderDrawColor(this->renderer, prevRect->getRed(),
					prevRect->getGreen(), prevRect->getBlue(),
					prevRect->getAlpha());
			// SDL_RenderFillRect(this->renderer, prevRect->getRectPointer());
		}

		InteractiveRectangle *rect =
				dynamic_cast<InteractiveRectangle*>(this->array->get(i));

		rect->setSwapped();

		SDL_SetRenderDrawColor(this->renderer, rect->getRed(), rect->getGreen(),
				rect->getBlue(), rect->getAlpha());
		// SDL_RenderFillRect(this->renderer, rect->getRectPointer());

		SDL_RenderPresent(this->renderer);

		SDL_Delay(finishDelay);
	}
}

void Renderer::quit() {
	SDL_Delay(1000);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

