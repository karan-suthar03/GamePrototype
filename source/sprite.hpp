#pragma once

#include <string>
#include "raylib.h"

class Sprite {

public:

    Sprite(Texture2D texture) : m_Texture(texture) {}

    Sprite(const std::string& path) : m_Texture(LoadTexture(path.c_str())) { }

    ~Sprite() {
        UnloadTexture(m_Texture);
    }

    Sprite(const Sprite&) = delete;
    Sprite& operator=(const Sprite&) = delete;
    Sprite(Sprite&&) noexcept = default;
    Sprite& operator=(Sprite&&) noexcept = default;

    void Draw(Vector2 position, Vector2 size) {
        
        Rectangle source = {
            0.0f,
            0.0f,
            (float)m_Texture.width,
            (float)m_Texture.height
        };

        Rectangle destination = {
            position.x,
            position.y,
            size.x,
            size.y
        };

        Draw(source, destination);
    }

    void Draw(Rectangle src, Rectangle dst) { 

        DrawTexturePro(
            m_Texture,
            src,
            dst,
            {0.0f, 0.0f},
            0.0f,
            WHITE
        );
    }

private:
    Texture2D m_Texture;

};