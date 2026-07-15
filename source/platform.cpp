#include "platform.hpp"

Platform::Platform(Vector2 position, Vector2 size) {

    m_Bounds = {
        position.x,
        position.y,
        size.x,
        size.y
    };
}

void Platform::Draw() const {

    DrawRectangleRec(m_Bounds, DARKGRAY);
}

Rectangle Platform::GetBounds() const {

    return m_Bounds;
}