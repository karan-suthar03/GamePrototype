#pragma once

#include <unordered_map>

#include "Animation.hpp"

enum class AnimationState
{
    Idle,
    Run,
    Jump
};

class Animator
{
public:
    Animator();

    void Add(AnimationState state, Animation* animation);

    void Play(AnimationState state);

    void Update(float dt);

    void Draw(Vector2 position, Vector2 size, Direction direction);

private:
    std::unordered_map<AnimationState, Animation*> m_Animations;

    Animation* m_CurrentAnimation;

    AnimationState m_CurrentState;
};