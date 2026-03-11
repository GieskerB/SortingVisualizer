#ifndef INCLUDE_SORTING_SELECTIONSORT_HPP_
#define INCLUDE_SORTING_SELECTIONSORT_HPP_

#include "Sort.hpp"

class Selectionsort: public Sort {

	int glob_i, glob_j;

public:

	Selectionsort(Array *array);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_SELECTIONSORT_HPP_ */
