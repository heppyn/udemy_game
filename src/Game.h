#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game {
public:
    void Initialize(int width, int height);
    [[nodiscard]] bool IsRunning() const;
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

private:
    bool m_isRunning = false;
    SDL_Window * m_window = nullptr;
    SDL_Renderer * m_renderer = nullptr;
    float m_ticksLastFrame;
};

#endif //GAME_GAME_H
