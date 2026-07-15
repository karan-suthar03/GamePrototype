#pragma once

#include "sprite.hpp"
#include "direction.hpp"

class Animation {

public:

    Animation(
        const std::string& path,
        int frameWidth,
        int frameHeight,
        int frameCount,
        float fps

    );

    Animation(const Animation&) = delete;
    Animation& operator=(const Animation&) = delete;
    
    Animation(Animation&&) noexcept = default;
    Animation& operator=(Animation&&) noexcept = default;

    void Update(float dt);

    void Draw(Vector2 position, Vector2 size, Direction direction);

    void Reset();

private:

    Sprite m_Sprite;

    int m_FrameWidth;
    int m_FrameHeight;

    int m_FrameCount;

    int m_CurrentFrame;

    float m_FPS;

    float m_Timer;
};