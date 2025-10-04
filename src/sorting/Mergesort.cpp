#include "../../include/sorting/Mergesort.hpp"

Mergesort::Mergesort(Array *array):Sort(array) {}

void Mergesort::divide(int start, int end, int limit) {
	if (start >= end) {
		return;
	}

	const int middle = (start + end) / 2 + start;

	divide(start, middle, limit);
	divide(middle, end, limit);

	conquer(start, middle, end,  limit);
}

void Mergesort::conquer(const int start, const int middle, const int end, int limit) {

	const int ARR1SIZE = middle - start;
	const int ARR2SIZE = end - middle;

	// BaseRectangle *arr1[ARR1SIZE], *arr2[ARR2SIZE];

	for (int i = start; i < middle; i++) {
		// arr1[i - start] = array->get(i);
	}

	for (int i = middle; i < end; i++) {
		// arr2[i - middle] = array->get(i);
	}

	int leftPointer = start, rightPointer = middle, totalPointer = start;

	// while (leftPointer < middle && rightPointer < end) {
	// 	if (array->TYPE == RectangleType::INTERACTIVE) {
	// 		((InteractiveRectangle*) arr1[leftPointer])->setCompared();
	// 		((InteractiveRectangle*) arr2[rightPointer])->setCompared();
	// 	}
	// 	if (arr1[leftPointer]->getValue() > arr2[rightPointer]->getValue()) {
	// 		if (array->TYPE == RectangleType::INTERACTIVE) {
	// 			((InteractiveRectangle*) arr2[rightPointer])->setSwapped();
	// 		}
	// 		array->set(arr2[rightPointer++], totalPointer++);
	//
	// 	} else {
	// 		if (array->TYPE == RectangleType::INTERACTIVE) {
	// 			((InteractiveRectangle*) arr1[leftPointer])->setSwapped();
	// 		}
	// 		array->set(arr1[leftPointer++], totalPointer++);
	// 	}
	//
	// }

	// while (leftPointer < middle) {
	// 	if (array->TYPE == RectangleType::INTERACTIVE) {
	// 		((InteractiveRectangle*) arr1[leftPointer])->setSwapped();
	// 	}
	// 	array->set(arr1[leftPointer++], totalPointer++);
	// }
	//
	// while (rightPointer < end) {
	// 	if (array->TYPE == RectangleType::INTERACTIVE) {
	// 		((InteractiveRectangle*) arr2[rightPointer])->setSwapped();
	// 	}
	// 	array->set(arr2[rightPointer++], totalPointer++);
	// }
}


void Mergesort::sort(int limit) {
	divide(0, array->size(), limit);
}

void Mergesort::reset() {

}

