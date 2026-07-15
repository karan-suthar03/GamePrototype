cmake_minimum_required(VERSION 3.20)

project(game_prototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add Raylib
add_subdirectory(dependencies/raylib)

# Collect all source files
file(GLOB_RECURSE GAME_SOURCES
  source/main.cpp source/game.cpp source/scene_manager.cpp source/game_scene.cpp source/player.cpp source/platform.cpp source/animation.cpp source/animator.cpp source/next_scene.cpp
)

# Create executable
add_executable(${PROJECT_NAME}
    ${GAME_SOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        source
)

# Link Raylib
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
)

# Copy assets next to the executable after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
