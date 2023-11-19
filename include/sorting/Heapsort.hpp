#ifndef INCLUDE_SORTING_HEAPSORT_HPP_
#define INCLUDE_SORTING_HEAPSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Heapsort: public Sort {

private:
	Uint16 heapSize;

	Uint16 leftChildIndex(Uint16 parenIndex);
	Uint16 rightChildIndex(Uint16 parentIndex);

	Uint16 heapify(const Uint16 index, Uint16 currentSteps, const int maxSteps);

	Uint16 siftDown(const Uint16 index, Uint16 currentSteps, const int maxSteps);

protected:
	void sort(int stepCount) override;

public:

	Heapsort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_HEAPSORT_HPP_ */
