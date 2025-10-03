#ifndef SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP
#define SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP

#include <array>

template <int N>
struct StackMemory {
    std::array<StackMemory*, N> children{nullptr};
    bool visited{false};
    ~StackMemory() {
        for (int i = 0; i < N; ++i) delete children[i];
    }

};

template <int N,int M>
struct StackValueMemory {
    std::array<StackValueMemory*, N> children{nullptr};
    std::array<int,M> values{0};
    bool visited{false};
    ~StackValueMemory() {
        for (int i = 0; i < N; ++i) delete children[i];
    }

};


#endif //SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP