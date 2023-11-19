#ifndef INCLUDE_SORTING_INSERTIONSORT_HPP_
#define INCLUDE_SORTING_INSERTIONSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Insertionsort: public Sort {

private:
	bool binarySearch;

protected:
	void sort(int stepCount) override;

public:

	Insertionsort(Array *array, Renderer *renderer, bool binarySearch = false);

};

#endif /* INCLUDE_SORTING_INSERTIONSORT_HPP_ */
