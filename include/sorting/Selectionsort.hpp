#ifndef INCLUDE_SORTING_SELECTIONSORT_HPP_
#define INCLUDE_SORTING_SELECTIONSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Selectionsort: public Sort {

protected:
	void sort(int stepCount) override;

public:

	Selectionsort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_SELECTIONSORT_HPP_ */
