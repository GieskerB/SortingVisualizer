#ifndef INCLUDE_SORTER_HPP_
#define INCLUDE_SORTER_HPP_

#include <iostream>

#include "../Array.hpp"
#include "../Renderer.hpp"

class Sort {
protected:

	Array *array;

public:

	Sort(Array *array);
	virtual ~Sort();
	virtual void sort(int stepCount) = 0;

};

#endif /* INCLUDE_SORTER_HPP_ */
