#include <iostream>
#include "./Constants.h"
#include "./Game.h"


float projectilePosX = 0.0f;
float projectilePosY = 0.0f;
float projectileVelX = 1.0f;
float projectileVelY = 1.0f;

void Game::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL.\n";
    }

    m_window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_BORDERLESS
            );
    if (!m_window) {
        std::cerr << "Error creating SDL window.\n";
        return;
    }

    m_renderer = SDL_CreateRenderer(m_window,-1,0);
    if (!m_renderer) {
        std::cerr << "Error creating renderer\n";
        return;
    }

    m_isRunning = true;
}

bool Game::IsRunning() const {
    return m_isRunning;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: {
            m_isRunning = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                m_isRunning = false;
            }
            break;
        }
        default: {
            // unknown key pressed
            break;
        }
    }
}

void Game::Update() {
    projectilePosX += projectileVelX;
    projectilePosY += projectileVelY;
}

void Game::Render() {
    SDL_SetRenderDrawColor(m_renderer, 21, 21, 21, 255);
    SDL_RenderClear(m_renderer);

    SDL_Rect projectile {
        (int)projectilePosX,
        (int)projectilePosY,
        10,
        10
    };

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(m_renderer, &projectile);

    SDL_RenderPresent(m_renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
