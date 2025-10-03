#ifndef INCLUDE_SORTING_QUICKSORT_HPP_
#define INCLUDE_SORTING_QUICKSORT_HPP_

#include "Sort.hpp"
#include "../Array.hpp"
#include "StackMemory.hpp"

class Quicksort: public Sort {

	StackValueMemory<2,5> nodes;

	int pivot_index(int, int);
	void quicksort(int, int, int, StackValueMemory<2,5>*);

public:

	Quicksort(Array *array);

	void sort(int) override;
	void reset() override;
};

#endif /* INCLUDE_SORTING_QUICKSORT_HPP_ */
