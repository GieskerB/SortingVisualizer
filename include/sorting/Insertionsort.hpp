#ifndef INCLUDE_SORTING_INSERTIONSORT_HPP_
#define INCLUDE_SORTING_INSERTIONSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Insertionsort: public Sort {

	bool done_reverse;
	int glob_i, glob_j;

public:

	Insertionsort(Array *array);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_INSERTIONSORT_HPP_ */
