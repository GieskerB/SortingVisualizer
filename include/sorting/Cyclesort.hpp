#ifndef SORTINGVISUALIZER_CYCLESORT_HPP
#define  SORTINGVISUALIZER_CYCLESORT_HPP

#include "Sort.hpp"

class Cyclesort : public Sort {

    int glob_cycle;

public:
    Cyclesort(Array *);

    void sort(int) override;
    void reset() override;
};


#endif // SORTINGVISUALIZER_CYCLESORT_HPP