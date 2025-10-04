#ifndef SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP
#define SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP

#include <array>

template <typename T, int N>
struct StackMemory {
    std::array<StackMemory*, N> children{nullptr};
    bool visited{false};
    T data;

    StackMemory(T value): data{value} {}

    ~StackMemory() {
        for (int i = 0; i < N; ++i) {
            delete children[i];
        }
    }
};

template <int N>
struct StackMemory<void, N> {
    std::array<StackMemory*, N> children{nullptr};
    bool visited{false};

    ~StackMemory() {
        for (int i = 0; i < N; ++i) {
            delete children[i];
        }
    }
};


#endif //SORTINGVISUALIZER_INCLUDE_SORTING_STACKMEMORY_HPP