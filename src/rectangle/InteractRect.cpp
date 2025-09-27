#include "../../include/rectangle/InteractRect.hpp"

void InteractRect::resetChecked() {
	m_compared = false;
}

void InteractRect::resetSwapped() {
	m_swapped = false;
}

void InteractRect::setCompared() {
	if (!m_swapped) {
		red((COMPARED_COLOR & 255 << 24) >> 24);
		green((COMPARED_COLOR & 255 << 16) >> 16);
		blue((COMPARED_COLOR & 255 << 8) >> 8);
	}
	m_compared = true;
}

void InteractRect::setSwapped() {
	red((SWAPPED_COLOR & 255 << 24) >> 24);
	green((SWAPPED_COLOR & 255 << 16) >> 16);
	blue((SWAPPED_COLOR & 255 << 8) >> 8);
	m_swapped = true;
}

void InteractRect::resetState() {
	if (m_swapped || m_compared) {
		red((DEFAULT_COLOR & 255 << 24) >> 24);
		green((DEFAULT_COLOR & 255 << 16) >> 16);
		blue((DEFAULT_COLOR & 255 << 8) >> 8);
	}
	resetChecked();
	resetSwapped();
}
