#include "../../include/rectangle/InteractRect.hpp"

void InteractRect::resetChecked() {
	m_compared = false;
}

void InteractRect::resetSwapped() {
	m_swapped = false;
}

void InteractRect::setCompared() {
	if (!m_swapped) {
		r = (COMPARED_COLOR & 255 << 24) >> 24;
		g = (COMPARED_COLOR & 255 << 16) >> 16;
		b = (COMPARED_COLOR & 255 << 8) >> 8;
	}
	m_compared = true;
}

void InteractRect::setSwapped() {
	r = (SWAPPED_COLOR & 255 << 24) >> 24;
	g = (SWAPPED_COLOR & 255 << 16) >> 16;
	b = (SWAPPED_COLOR & 255 << 8) >> 8;
	m_swapped = true;
}

void InteractRect::resetState() {
	if (m_swapped || m_compared) {
		r = (DEFAULT_COLOR & 255 << 24) >> 24;
		g = (DEFAULT_COLOR & 255 << 16) >> 16;
		b = (DEFAULT_COLOR & 255 << 8) >> 8;
	}
	resetChecked();
	resetSwapped();
}

void InteractRect::init_color(const float) {
	resetChecked();
}