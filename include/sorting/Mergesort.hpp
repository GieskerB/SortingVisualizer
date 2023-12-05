#ifndef INCLUDE_SORTING_MERGESORT_HPP_
#define INCLUDE_SORTING_MERGESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Mergesort: public Sort {
private:

	Uint8 divide(Uint16 start, Uint16 end, Uint8 currentSteps, int maxSteps);
	Uint8 conquer(Uint16 start, Uint16 middle, Uint16 end, Uint8 currentSteps,
                  int maxSteps);

protected:
	void sort(int stepCount) override;

public:

	Mergesort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_MERGESORT_HPP_ */
