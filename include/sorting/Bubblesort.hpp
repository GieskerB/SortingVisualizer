#ifndef INCLUDE_SORTING_BUBBLESORT_HPP_
#define INCLUDE_SORTING_BUBBLESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Bubblesort: public Sort {

	int glob_i, glob_j;
	int swaps;

public:

	Bubblesort(Array *array);
	void sort(int) override;

};

#endif /* INCLUDE_SORTING_BUBBLESORT_HPP_ */
