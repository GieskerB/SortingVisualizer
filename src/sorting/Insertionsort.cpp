#include "../../include/sorting/Insertionsort.hpp"

Insertionsort::Insertionsort(Array *array, Renderer *renderer,
		bool binarySearch) :
		Sort(array, renderer), binarySearch(binarySearch) {

}

void Insertionsort::sort(int stepCount) {
	Uint16 currentSteps = 0;

	for (int i = 1; i < this->array->SIZE; i++) {
//		if (this->binarySearch) {
//			const int comapreTo = this->array->get(i)->getValue();
//			int leftIndex = 0, rightIndex = i - 1;
//			while (leftIndex <= rightIndex) {
//
//			}
//		} else {
			for (int j = i; j > 0; j--) {
				if (this->array->compareSmaller(j, j - 1)) {
					currentSteps = this->renderer->renderSwap(j, j - 1,
							currentSteps, stepCount);

				} else {
					break;
				}
			}
//		}
	}
}

