# SDL Sorting Visualizer

A lightweight, real-time sorting algorithm visualizer built with **C++** and **SDL3**.
This application provides a graphical representation of how different sorting mechanics manipulate data arrays.

---

## Features
* **Dynamic Visualization:** Watch bars swap and move in real-time.
* **Shuffle System:** Instantly randomize the dataset to test algorithms from scratch.
* **Boost Mode:** Toggle frame-skipping to speed up the sorting process for larger arrays.
* **Clean Console Output:** Real-time status updates printed directly to your terminal.

### Implemented Algorithms

The project currently supports the following sorting algorithms:

- **Bogosort**
- **Bubblesort**
- **Cyclesort**
- **Heapsort**
- **Insertionsort**
- **Mergesort**
- **Quicksort**
- **Radixsort**
- **Selectionsort**
- **Shellsort**
- **Stoogesort**

---

## Controls

| Key       | Action      | Description                                                    |
|:----------|:------------|:---------------------------------------------------------------|
| **`S`**   | **Shuffle** | Randomizes the current list of elements.                       |
| **`B`**   | **Boost**   | "Boost Mode" skips ~100 visualization steps and finish faster. |

---

## Getting Started

### Prerequisites

Make sure these things are installed on your system: 
- C++ compiler
- cmake
- SDL3

### Compilation
Use the following command to compile the project (standard for GCC/Clang):

```bash
mkdir build && cd build
cmake ..
cmake --build .
./SortingVisualizer
```

### Running the code

Sorting Visualizer has 4 different console parameters:
- **-w**: *followed by the* width of the opened window.
- **-h**: *followed by the* height of the opened window.
- **-n**: *followed by the* number of elements in the array to sort.
- **-a**: *followed by the* name of the sorting algorithm.

---

## Contributions

Contributions are what make the open-source community such an amazing place to learn, inspire, and create.
Any contributions you make are greatly appreciated.

1. Fork the Project.
2. Create your Feature Branch (`git checkout -b your_name/amazing_feature`).
3. Commit your Changes (`git commit -m 'compact but descriptive commit message'`).
4. Push to the Branch (`git push origin your_name/amazing_feature`).
5. Open a Pull Request.

Whether it is fixing a bug, adding a new sorting algorithm, or improving the UI—your help is welcome!

### Planed Features

- Implementation of InteractRect: implemented dynamic state-coloring where elements default to white/light gray,
  highlight red during comparison ("looked at"), and flash green during a swap operation.
- A smaller pause on just the compare operation to recognize the immense weight of algorithms like stoge sort
- More sorting algorithms
- Additional control (either via console parameters or keyboard)

### Project Structure

- src/sorting/: Contains the logic for all individual sorting algorithms.
- src/rectangle/: Handles the visual rendering of the array elements (Rainbow and Interactive modes).
- src/Array.cpp: Manages the data state and shuffling logic.