#include "scene_manager.hpp"

void SceneManager::Update(float dt) {

    if (m_CurrentScene)
        m_CurrentScene->Update(dt);
}

void SceneManager::Draw() {

    if (m_CurrentScene)
        m_CurrentScene->Draw();
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> scene) {

    if (m_CurrentScene)
        m_CurrentScene->OnExit();

    m_CurrentScene = std::move(scene);

    if (m_CurrentScene)
        m_CurrentScene->OnEnter();
}

Scene* SceneManager::GetCurrentScene() const {

    return m_CurrentScene.get();
}