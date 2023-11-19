cmake_minimum_required(VERSION 3.26.4)
project(SortingVisualizer)

set(CMAKE_CXX_STANDARD 20)

# Must set the path to the main.cpp
add_executable(${PROJECT_NAME} main.cpp
        src/Array.cpp
        src/Renderer.cpp
        src/rectangle/BaseRectangle.cpp
        src/rectangle/InteractiveRectangle.cpp
        src/rectangle/RainbowRectangle.cpp
        src/sorting/Bogosort.cpp
        src/sorting/Bubblesort.cpp
        src/sorting/Heapsort.cpp
        src/sorting/Insertionsort.cpp
        src/sorting/Mergesort.cpp
        src/sorting/Quicksort.cpp
        src/sorting/Radixsort.cpp
        src/sorting/Selectionsort.cpp
        src/sorting/Sort.cpp
        src/sorting/Stoogesort.cpp)


# --- SDL2 SETUP ---
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
set(SDL2_PATH "D:/WindowsPrograms/Libraries/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
