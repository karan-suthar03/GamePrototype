#include <raylib.h>
#include "game.hpp"

int main() {

    constexpr int ScreenWidth = 1280;
    constexpr int ScreenHeight = 720;

    InitWindow(ScreenWidth, ScreenHeight, "Braid Prototype");
    SetTargetFPS(60);

    Game game;
    game.Init();

    while (!WindowShouldClose()) {

        game.Update(GetFrameTime());

        BeginDrawing(); 
        {
            ClearBackground(BLACK);
            game.Render();
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}