#include "game.hpp"
#include "game_scene.hpp"
#include "next_scene.hpp"
#include "player.hpp"

void Game::Init() {

    m_SceneManager.ChangeScene(std::make_unique<GameScene>());
}

void Game::Update(float dt) {

    m_SceneManager.Update(dt);

    if (IsKeyPressed(KEY_Q))
        m_SceneManager.ChangeScene(std::make_unique<NextScene>());

    if (IsKeyPressed(KEY_Z))
        m_SceneManager.ChangeScene(std::make_unique<GameScene>());
}

void Game::Render() {

    m_SceneManager.Draw();
}
