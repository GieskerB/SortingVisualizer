#include "../../include/sorting/Mergesort.hpp"

#define ARR_FILLED 0
#define ARR1 1
#define ARR2 2
#define LEFT 3
#define RIGHT 4
#define TOTAL 5


Mergesort::Mergesort(Array *array):Sort(array), nodes{{false,{},{},0,0,0}} {}

void Mergesort::divide(const int start, const int end, const int limit, StackMemMS* node) {
	if (end-start < 2) return;

	if (node->children[0] == nullptr) {
		node->children[0] = new StackMemMS{{false,{},{},0,0,0}};
		node->children[1] = new StackMemMS{{false,{},{},0,0,0}};
		node->children[2] = new StackMemMS{{false,{},{},0,0,0}};
	}

	const int middle = (start + end) / 2;

	if (!node->children[0]->visited) divide(start, middle, limit, node->children[0]);
	if (!node->children[1]->visited) divide(middle, end, limit, node->children[1]);
	if (!node->children[2]->visited) conquer(start, middle, end,  limit, node->children[2]);
	
	node->visited = true;
}

void Mergesort::conquer(const int start, const int middle, const int end, int limit, StackMemMS* node) {

	std::cout << "\n\nCONQUER "<< start<< " " << middle<< " " << end <<"\n";

	if (node->children[0] == nullptr) {
		node->children[0] = new StackMemMS{{false,{},{},0,0,0}};
		node->children[1] = new StackMemMS{{false,{},{},0,0,0}};
		node->children[2] = new StackMemMS{{false,{},{},0,0,0}};
	}

	auto& arr1 = std::get<ARR1>(node->data);
	auto& arr2 = std::get<ARR2>(node->data);

	if (!std::get<ARR_FILLED>(node->data)) {
		for (int i = start; i < middle; i++) {
			arr1.push_back(std::make_shared<Rect*>(array->operator[](i)->copy()));
			std::cout << "arr1[" << i - start << "]"<<*arr1.back()<<"\n";
		}
		for (int i = middle; i < end; i++) {
			arr2.push_back(std::make_shared<Rect*>(array->operator[](i)->copy()));
			std::cout << "arr2[" << i - middle << "]"<<*arr2.back()<<"\n";
		}

		std::cout << "SIZE: " << arr1.size() << " " <<arr2.size() <<std::endl;

		for (const auto& rect: arr1) {
			std::cout <<"ARR1: "<< *rect<< '\n';
		}

		std::get<LEFT>(node->data) = 0;
		std::get<RIGHT>(node->data) = 0;
		std::get<TOTAL>(node->data) = start;
		std::get<ARR_FILLED>(node->data) = true;
	}

	int& left_ptr = std::get<LEFT>(node->data);
	int& right_ptr = std::get<RIGHT>(node->data);
	int& total_ptr = std::get<TOTAL>(node->data);

	std::cout << "LRT: " << left_ptr << " " << right_ptr << " " << total_ptr << '\n';

	std::cout << "D\n";
	while (left_ptr < middle && right_ptr < end) {

		std::cout << "D1\n";
		std::cout << left_ptr << " " << arr1[left_ptr] << "\n";
		std::cout << right_ptr << " " << arr2[right_ptr] << "\n";
		if ((*arr1[left_ptr])->value() > (*arr2[right_ptr])->value()) {
		std::cout << "D2\n";
			array->swap(total_ptr++,*arr2[right_ptr++]);
			++swaps;
			if (swaps >= limit) {
				throw swaps;
			}
		} else {
		std::cout << "D3\n";
			array->swap(total_ptr++,*arr1[left_ptr++]);
			++swaps;
			if (swaps >= limit) {
				throw swaps;
			}
		}
	}
	std::cout << "E\n";

	while (left_ptr < middle) {
		array->swap(total_ptr++,*arr1[left_ptr++]);
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}
	std::cout << "F\n";

	while (right_ptr < end) {
		array->swap(total_ptr++,*arr2[right_ptr++]);
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}
	std::cout << "G\n";
	node->visited = true;
}


void Mergesort::sort(int limit) {
	if (array->is_sorted()) return;

	try {
		divide(0, array->size(), limit, & nodes);
	} catch (int swaps) {
		return;
	}
}

void Mergesort::reset() {
	for (int i = 0; i < 2; ++i) {
		delete nodes.children[i];
		nodes.children[i] = nullptr;
		nodes.data = {false,{},{},0,0,0};
	}
}

