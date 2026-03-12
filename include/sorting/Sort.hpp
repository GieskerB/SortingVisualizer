#ifndef INCLUDE_SORTER_HPP_
#define INCLUDE_SORTER_HPP_

#include <iostream>

#include "../Array.hpp"

class Sort {
protected:

    int swaps;
    Array *array;

public:
    Sort(Array *);

    virtual ~Sort();
    virtual void sort(int stepCount) = 0;
    virtual void reset() = 0;
};

#endif /* INCLUDE_SORTER_HPP_ */
