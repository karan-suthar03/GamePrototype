#include "Animation.hpp"

Animation::Animation(
    const std::string& path,
    int frameWidth,
    int frameHeight,
    int frameCount,
    float fps)
    :
    m_Sprite(path),
    m_FrameWidth(frameWidth),
    m_FrameHeight(frameHeight),
    m_FrameCount(frameCount),
    m_CurrentFrame(0),
    m_FPS(fps),
    m_Timer(0.0f)
{
}

void Animation::Update(float dt)
{
    m_Timer += dt;

    float frameTime = 1.0f / m_FPS;

    while (m_Timer >= frameTime)
    {
        m_CurrentFrame++;

        if (m_CurrentFrame >= m_FrameCount)
            m_CurrentFrame = 0;

        m_Timer -= frameTime;
    }
}

void Animation::Draw(Vector2 position, Vector2 size, Direction direction)
{
    Rectangle source;

    if (direction == Direction::Right) {
        source = {
            (float)(m_CurrentFrame * m_FrameWidth),
            0.0f,
            (float)m_FrameWidth,
            (float)m_FrameHeight
        };
    }
    else {
        source = {
            (float)((m_CurrentFrame + 1) * m_FrameWidth),
            0.0f,
            -(float)m_FrameWidth,
            (float)m_FrameHeight
        };
    }

    Rectangle destination = {
        position.x,
        position.y,
        size.x,
        size.y
    };

    m_Sprite.Draw(source, destination);
}

void Animation::Reset()
{
    m_CurrentFrame = 0;
    m_Timer = 0.0f;
}