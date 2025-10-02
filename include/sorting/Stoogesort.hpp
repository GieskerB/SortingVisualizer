
#ifndef INCLUDE_SORTING_STOOGESORT_HPP_
#define INCLUDE_SORTING_STOOGESORT_HPP_

#include "Sort.hpp"
#include "../Array.hpp"
#include "StackMemory.hpp"

class Stoogesort: public Sort {

	StackMemory<3> nodes;

	void split(int, int, int,StackMemory<3>*);

public:

	Stoogesort(Array *array);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_STOOGESORT_HPP_ */
