
#include "next_scene.hpp"

NextScene::NextScene() {

    m_Platforms.emplace_back(
        Vector2{0, 650},
        Vector2{1280, 20}
    );

    m_Platforms.emplace_back(
        Vector2{120, 560},
        Vector2{180, 20}
    );

    m_Platforms.emplace_back(
        Vector2{420, 500},
        Vector2{160, 20}
    );

    m_Platforms.emplace_back(
        Vector2{700, 430},
        Vector2{200, 20}
    );

    m_Platforms.emplace_back(
        Vector2{980, 360},
        Vector2{160, 20}
    );

    m_Platforms.emplace_back(
        Vector2{760, 270},
        Vector2{140, 20}
    );

    m_Platforms.emplace_back(
        Vector2{450, 200},
        Vector2{180, 20}
    );

    m_Platforms.emplace_back(
        Vector2{170, 120},
        Vector2{150, 20}
    );
}

void NextScene::Update(float dt) {

    if (IsKeyPressed(KEY_H)) m_ShowHitbox = !m_ShowHitbox;

    ResolveCollisions();

    m_Player.Update(dt);
}

void NextScene::Draw() {
    
    for (const auto& platform : m_Platforms)
        platform.Draw();

    m_Player.Draw();

    if (m_ShowHitbox) 
        DrawRectangleLinesEx( m_Player.GetBounds(), 2, RED);
}

void NextScene::ResolveCollisions()
{
    m_Player.SetGrounded(false);

    Rectangle playerBounds = m_Player.GetBounds();

    for (const Platform& platform : m_Platforms)
    {
        Rectangle platformBounds = platform.GetBounds();

        if (!CheckCollisionRecs(playerBounds, platformBounds))
            continue;

        float overlapLeft =
            (playerBounds.x + playerBounds.width) - platformBounds.x;

        float overlapRight =
            (platformBounds.x + platformBounds.width) - playerBounds.x;

        float overlapTop =
            (playerBounds.y + playerBounds.height) - platformBounds.y;

        float overlapBottom =
            (platformBounds.y + platformBounds.height) - playerBounds.y;

        float overlapX = std::min(overlapLeft, overlapRight);
        float overlapY = std::min(overlapTop, overlapBottom);

        if (overlapX < overlapY)
        {
            // Resolve horizontally
            if (overlapLeft < overlapRight)
                playerBounds.x -= overlapLeft;
            else
                playerBounds.x += overlapRight;
        }
        else
        {
            // Resolve vertically
            if (overlapTop < overlapBottom)
            {
                // Landed on top
                playerBounds.y -= overlapTop;

                m_Player.Land();
            }
            else
            {
                // Hit underside
                playerBounds.y += overlapBottom;

                m_Player.SetVelocityY(0.0f);
            }
        }

        // Keep the player in sync with the corrected rectangle
        m_Player.SetPosition({ playerBounds.x - m_Player.HitboxOffsetX, playerBounds.y - m_Player.HitboxOffsetY});

        // Refresh the bounds in case there are more platforms
        playerBounds = m_Player.GetBounds();
    }
}
