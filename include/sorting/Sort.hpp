#ifndef INCLUDE_SORTER_HPP_
#define INCLUDE_SORTER_HPP_

#include <iostream>

#include "../Array.hpp"
#include "../Renderer.hpp"

class Sort {
protected:

	Array *array;
	Renderer *renderer;

public:

	Sort(Array *array, Renderer *renderer);
	virtual ~Sort();

	virtual void sort(int stepCount) = 0;

	void sortFully();

	void sortStepByStep();

	void sortMultipleSteps(int numSteps);

};

#endif /* INCLUDE_SORTER_HPP_ */
