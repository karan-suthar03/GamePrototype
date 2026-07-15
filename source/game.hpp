#pragma once 
#include "scene_manager.hpp"

class Game {

public:

    Game() = default;
    ~Game() = default;

    void Init();

    void Update(float dt);
    void Render();

private:

    SceneManager m_SceneManager;
};