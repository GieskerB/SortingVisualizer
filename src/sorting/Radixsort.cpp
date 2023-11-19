#include "../../include/sorting/Radixsort.hpp"

#include "../../include/rectangle/InteractiveRectangle.hpp"

const char Radixsort::DIGITS[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F' };

const Uint8 Radixsort::BUFFER_SIZE = 12;

Radixsort::Radixsort(Array *array, Renderer *renderer, Base base) :
		Sort(array, renderer), BASE(
				(2 <= base && base <= 16) ? base : Base::DECIMAL), largestNumberLength(
				this->numberLengthBaseX(array->SIZE)), buckets(
				new std::queue<BaseRectangle*>[this->BASE]) {

}

Radixsort::~Radixsort() {
	delete[] buckets;
}

Uint8 Radixsort::digitToNumber(char digit) {

	switch (digit) {
	case '0' ... '9':
		return digit - 48;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	default:
		return 0;
	}
}

Uint8 Radixsort::numberLengthBaseX(Uint16 numberDec) {
	char *tmpArr = &this->toBaseXConverter(numberDec);
	Sint8 counter = Radixsort::BUFFER_SIZE - 1;
	while (counter >= 0 && tmpArr[counter] != '\0') {
		counter--;
	}
	delete tmpArr;
	return Radixsort::BUFFER_SIZE - (counter + 1);
}

char& Radixsort::toBaseXConverter(Uint16 numberDec) {
	char *buffer = new char[Radixsort::BUFFER_SIZE];
	for (Uint8 i = 0; i < Radixsort::BUFFER_SIZE; i++) {
		buffer[i] = '\0';
	}
	Uint8 counter = 1;
	while (numberDec != 0) {
		int tmp = numberDec % this->BASE;
		buffer[Radixsort::BUFFER_SIZE - counter] = Radixsort::DIGITS[tmp];
		numberDec /= this->BASE;
		counter++;
	}

	return *buffer;
}

void Radixsort::sort(int stepCount) {

	for (Sint8 i = Radixsort::BUFFER_SIZE - 1;
			i >= Radixsort::BUFFER_SIZE - this->largestNumberLength; i--) {
		for (Uint16 j = 0; j < this->array->SIZE; j++) {
			char *numberInBaseX = &this->toBaseXConverter(
					this->array->getValue(j));

			if (this->array->TYPE == RectangleType::INTERACTIVE) {
				((InteractiveRectangle*) this->array->get(j))->setCompared();
			}
			this->buckets[this->digitToNumber(numberInBaseX[i])].push(
					this->array->get(j));

			this->renderer->renderArray();

			delete numberInBaseX;
		}
		Uint16 counter = 0;
		for (Uint8 j = 0; j < this->BASE; j++) {
			while (!this->buckets[j].empty()) {
				if (this->array->TYPE == RectangleType::INTERACTIVE) {
					((InteractiveRectangle*) this->buckets[j].front())->setSwapped();
				}
				this->array->set(this->buckets[j].front(), counter++);
				this->buckets[j].pop();

				this->renderer->renderArray();
			}
		}
		this->renderer->renderArray();
	}

}

