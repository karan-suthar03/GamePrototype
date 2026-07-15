#pragma once

#include <vector>

#include "scene.hpp"
#include "player.hpp"
#include "platform.hpp"

class GameScene : public Scene {

public:

    GameScene();
    void Update(float dt) override;
    void Draw() override;

    void ResolveCollisions();

private:

    Player m_Player;
    bool m_ShowHitbox = false;

    std::vector<Platform> m_Platforms;
};
