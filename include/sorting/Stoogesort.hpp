
#ifndef INCLUDE_SORTING_STOOGESORT_HPP_
#define INCLUDE_SORTING_STOOGESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Stoogesort: public Sort {

private:
	int split(Uint16 begin, Uint16 end, Uint8 currentSteps, const int stepMax);

protected:
	void sort(int stepCount) override;

public:

	Stoogesort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_STOOGESORT_HPP_ */
