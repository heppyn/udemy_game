#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "./Entity.h"
#include "./Component.h"
#include "./EntityManager.h"

class AssetManager;

class Game {
public:
    void Initialize(int width, int height);

    [[nodiscard]] bool IsRunning() const;

    void ProcessInput();

    void Update();

    void Render();

    void Destroy();

    void LoadLevel(int levelNumber);

    void HandleCameraMovement();

    void CheckCollisions();

    void ProcessNextLevel(int level);

    void ProcessGameOver();

    static SDL_Renderer *m_renderer;
    static AssetManager *m_assetManager;
    static SDL_Event m_event;
    static SDL_Rect m_camera;

private:
    bool m_isRunning = false;
    SDL_Window *m_window = nullptr;
    float m_ticksLastFrame{};
};

#endif //GAME_GAME_H
