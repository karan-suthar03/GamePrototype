#pragma once
#include <raylib.h>
#include "sprite.hpp"
#include "animation.hpp"
#include "animator.hpp"
#include "direction.hpp"

class Player {

public:
    Player();

    void Update(float dt);
    void Draw();

    void SetPosition(Vector2 position);

    Vector2 GetPosition() const;

    Vector2 GetSize() const { return m_Size; }

    Vector2 GetVelocity() const { return m_Velocity; }

    Rectangle GetBounds() const;

    void SetVelocityY(float velocity);

    bool isGrounded() const { return m_Grounded; }
    void SetGrounded(bool grounded);

    void Land() { 

        // prevent landing if the player is moving upwards
        if(m_Velocity.y < 0){
            return;
        }
        
        m_Grounded = true; 
        m_Velocity.y = 0.0f; 
    }

    float HitboxOffsetX = 14.0f;
    float HitboxOffsetY = 0.0f;

private:
    Sprite m_Sprite;

    Vector2 m_Position;
    Vector2 m_Velocity;
    Vector2 m_Size;

    float m_Gravity = 1000.0f;

    bool m_Grounded = true;

    float m_MoveSpeed = 300.0f;
    
    Direction m_Direction = Direction::Right;

    Animation m_Idle;
    Animation m_Run;
    Animation m_Jump;

    Animator m_Animator;
};