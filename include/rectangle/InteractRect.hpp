#ifndef INCLUDE_INTERACTIVERECTANGLE_HPP
#define INCLUDE_INTERACTIVERECTANGLE_HPP

#include "Rect.hpp"

class InteractRect : public Rect {

    enum class RectState {
        IDLE,     // White
        COMPARED, // Red
        SWAPPED   // Green
    };

    static constexpr uint32_t IDLE_COLOR =
            (255 << 24) | (255 << 16) | (255 << 8) | 255;
    static constexpr uint32_t COMPARED_COLOR =
            (0 << 24) | (255 << 16) | (0 << 8) | 255;
    static constexpr uint32_t SWAPPED_COLOR =
            (255 << 24) | (0 << 16) | (0 << 8) | 255;

    bool m_compared, m_swapped;
    void resetChecked();
    void resetSwapped();

public:
    constexpr InteractRect(const float x, const float y, const float w,
                           const float h) : Rect(x, y, w, h), m_compared(false), m_swapped(false) {}

    void setCompared();
    void setSwapped();

    void resetState() override;
    void init_color(float) override;
    Rect *copy() override;
};

#endif /* INCLUDE_INTERACTIVERECTANGLE_HPP */
