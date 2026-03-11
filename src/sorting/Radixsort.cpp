#include "../../include/sorting/Radixsort.hpp"

#include <cmath>

#define BASE 10

Radixsort::Radixsort(Array *array): Sort(array), number_index(-1), glob_bucket_index(0),glob_array_index(0),numbers_in_buckets(false){}

void Radixsort::sort_in_buckets() {
	for (int i = 0; i < BASE; i++) {
		buckets[i] = {};
	}
	for (int i = 0; i < array->size(); i++) {
		Rect* rect = (*array)[i];
		int bucket_index = static_cast<int>(round(rect->value() * BASE));
		bucket_index /= static_cast<int>(pow(BASE, number_index +1));
		bucket_index %= BASE;
		buckets[bucket_index].emplace(rect->copy());
	}
	numbers_in_buckets = true;
}

void Radixsort::sort(int limit) {
	swaps = 0;
	while (!array->is_sorted()) {

		if (!numbers_in_buckets) sort_in_buckets();

		int bucket_index = glob_bucket_index;
		std::queue<Rect*>* bucket = &buckets[bucket_index];
		for (int i = glob_array_index; i < array->size(); i++) {
			while (bucket->empty() and bucket_index < buckets.size()) {
				bucket = &buckets[++bucket_index];
			}
			Rect* rect = bucket->front();
			bucket->pop();
			array->swap(i, rect);
			swaps++;
			if (swaps >= limit) {
				glob_array_index = i + 1;
				glob_bucket_index = bucket_index;
				return;
			}
		}
		++number_index;
		glob_bucket_index = 0;
		glob_array_index = 0;
		numbers_in_buckets = false;
	}
}

void Radixsort::reset() {
	number_index = -1;
	glob_bucket_index = 0;
	glob_array_index = 0;
	numbers_in_buckets = false;
}
