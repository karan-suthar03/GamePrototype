#pragma once

#include <raylib.h>

class Platform {

public:
    Platform(Vector2 position, Vector2 size);

    void Draw() const;

    Rectangle GetBounds() const;

private:
    Rectangle m_Bounds;
};