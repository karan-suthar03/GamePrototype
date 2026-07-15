#include "Animator.hpp"

Animator::Animator()
    : m_CurrentAnimation(nullptr),
      m_CurrentState(AnimationState::Idle)
{
}

void Animator::Add(AnimationState state, Animation* animation)
{
    m_Animations[state] = animation;

    if (m_CurrentAnimation == nullptr)
    {
        m_CurrentAnimation = animation;
        m_CurrentState = state;
    }
}

void Animator::Play(AnimationState state)
{
    if (m_CurrentState == state)
        return;

    auto it = m_Animations.find(state);

    if (it == m_Animations.end())
        return;

    m_CurrentState = state;
    m_CurrentAnimation = it->second;

    m_CurrentAnimation->Reset();
}

void Animator::Update(float dt)
{
    if (m_CurrentAnimation)
        m_CurrentAnimation->Update(dt);
}

void Animator::Draw(Vector2 position, Vector2 size, Direction direction)
{
    if (m_CurrentAnimation)
        m_CurrentAnimation->Draw(position, size, direction);
}