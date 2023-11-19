#ifndef INCLUDE_SORTING_BUBBLESORT_HPP_
#define INCLUDE_SORTING_BUBBLESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Bubblesort: public Sort {

protected:
	void sort(int stepCount) override;

public:

	Bubblesort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_BUBBLESORT_HPP_ */
