cmake_minimum_required(VERSION 3.26.4)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 QUIET)

# Must set the path to the main.cpp
add_executable(${PROJECT_NAME} main.cpp
        src/Array.cpp
        src/rectangle/InteractRect.cpp
        src/rectangle/RainbowRect.cpp
        src/rectangle/Rect.cpp
        src/sorting/Sort.cpp
        src/sorting/Bogosort.cpp
        src/sorting/Bubblesort.cpp
        src/sorting/Heapsort.cpp
        src/sorting/Insertionsort.cpp
        src/sorting/Mergesort.cpp
        src/sorting/Quicksort.cpp
        src/sorting/Radixsort.cpp
        src/sorting/Selectionsort.cpp
        src/sorting/Shellsort.cpp
        src/sorting/Stoogesort.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL3_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
