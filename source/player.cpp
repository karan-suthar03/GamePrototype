#include "Player.hpp"
#include <iostream>

Player::Player()
    : m_Sprite("assets/textures/player.png"),
      m_Position({100.0f, 540.0f}),
      m_Velocity({0.0f, 0.0f}),
      m_Size({64.0f, 64.0f}),
      m_Idle("assets/textures/player_idle.png", 64, 64, 4 , 8.0f),
      m_Run("assets/textures/player_run.png"  , 80, 64, 8 , 8.0f),
      m_Jump("assets/textures/player_jump.png", 64, 64, 15, 8.0f)
{ 
    m_Animator.Add(AnimationState::Idle, &m_Idle);
    m_Animator.Add(AnimationState::Run, &m_Run);
    m_Animator.Add(AnimationState::Jump, &m_Jump);
}

void Player::Update(float dt) {

    if (!m_Grounded)
    {
        m_Animator.Play(AnimationState::Jump);
    }
    else if (std::abs(m_Velocity.x) > 0.0f)
    {
        m_Animator.Play(AnimationState::Run);
    }
    else
    {
        m_Animator.Play(AnimationState::Idle);
    }

    m_Animator.Update(dt);

    // Horizontal movement
    m_Velocity.x = 0.0f;

    if (IsKeyDown(KEY_A)) {
        m_Velocity.x = -m_MoveSpeed;
        m_Direction = Direction::Left;
    }


    if (IsKeyDown(KEY_D)) {
        m_Velocity.x = m_MoveSpeed;
        m_Direction = Direction::Right;
    }

    // Jump
    if (IsKeyPressed(KEY_SPACE) && m_Grounded)
    {
        m_Velocity.y = -600.0f;
        m_Grounded = false;
    }

    // Gravity
    m_Velocity.y += m_Gravity * dt;

    // Move
    m_Position.x += m_Velocity.x * dt;
    m_Position.y += m_Velocity.y * dt;
}

void Player::Draw() {

    m_Animator.Draw(m_Position, m_Size, m_Direction);
}

void Player::SetPosition(Vector2 position) {

    m_Position = position;
}

Vector2 Player::GetPosition() const {

    return m_Position;
}

Rectangle Player::GetBounds() const {

    constexpr float xOffset = 8.0f;

    return {
        m_Position.x + HitboxOffsetX,
        m_Position.y + HitboxOffsetY,
        64.0f - (HitboxOffsetX * 2.0f),
        64.0f - (HitboxOffsetY * 2.0f)
    };
}

void Player::SetVelocityY(float velocity) {

    m_Velocity.y = velocity;
}

void Player::SetGrounded(bool grounded) {

    m_Grounded = grounded;
}