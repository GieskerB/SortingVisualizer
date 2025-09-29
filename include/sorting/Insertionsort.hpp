#ifndef INCLUDE_SORTING_INSERTIONSORT_HPP_
#define INCLUDE_SORTING_INSERTIONSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Insertionsort: public Sort {

	bool done_reverse;
	int glob_i, glob_j;

protected:
	void sort(int) override;

public:

	Insertionsort(Array *array);

};

#endif /* INCLUDE_SORTING_INSERTIONSORT_HPP_ */
