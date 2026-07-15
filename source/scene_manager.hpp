#pragma once

#include <memory>

#include "scene.hpp"

class SceneManager {

public:
    SceneManager() = default;
    ~SceneManager() = default;

    void Update(float dt);
    void Draw();

    void ChangeScene(std::unique_ptr<Scene> scene);

    Scene* GetCurrentScene() const;

private:
    std::unique_ptr<Scene> m_CurrentScene;
};