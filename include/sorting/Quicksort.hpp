#ifndef INCLUDE_SORTING_QUICKSORT_HPP_
#define INCLUDE_SORTING_QUICKSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

enum PivotType {
	FIRST, MIDDEL, LAST, RANDOM
};

class Quicksort: public Sort {
private:

	const PivotType PIVOT_TYPE;

	Uint16 getPivotIndex(Uint16 begin, Uint16 end);

	Uint16 quicksort(Uint16 begin, Uint16 end, Uint16 currentSteps,
			const int maxSteps);


protected:
	void sort(int stepCount) override;

public:

	Quicksort(Array *array, Renderer *renderer, PivotType pivotType =
			PivotType::FIRST);

};

#endif /* INCLUDE_SORTING_QUICKSORT_HPP_ */
