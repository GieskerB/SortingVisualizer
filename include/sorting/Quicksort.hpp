#ifndef INCLUDE_SORTING_QUICKSORT_HPP_
#define INCLUDE_SORTING_QUICKSORT_HPP_

#include <tuple>

#include "Sort.hpp"
#include "../Array.hpp"
#include "../StackMemory.hpp"

class Quicksort: public Sort {

	StackMemory<std::tuple<bool,float,int,int,bool>,2> nodes;

	void quicksort(int, int, int, StackMemory<std::tuple<bool,float,int,int,bool>, 2>*);

public:

	Quicksort(Array *array);

	void sort(int) override;
	void reset() override;
};

#endif /* INCLUDE_SORTING_QUICKSORT_HPP_ */
