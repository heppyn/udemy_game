#include <iostream>
#include "./Constants.h"
#include "./Game.h"
#include "./Components/TransformComponent.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::m_renderer;

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

    LoadLevel(0);

    m_isRunning = true;
    m_ticksLastFrame = SDL_GetTicks();
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
    // wait until 16.6ms has elapsed since the last frame
    float timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - m_ticksLastFrame);
    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay((unsigned)timeToWait);
    }

    float deltaTime = (SDL_GetTicks() - m_ticksLastFrame) / 1000.0f;
    // set minimum frame rate
    deltaTime = (deltaTime > FRAME_TARGET_MIN_TIME) ? FRAME_TARGET_MIN_TIME : deltaTime;
    m_ticksLastFrame = SDL_GetTicks();

    manager.Update(deltaTime);
}

void Game::Render() {
    SDL_SetRenderDrawColor(m_renderer, 21, 21, 21, 255);
    SDL_RenderClear(m_renderer);

    if (manager.HasNoEntities()) {
        return;
    }
    manager.Render();

    SDL_RenderPresent(m_renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Game::LoadLevel(int levelNumber) {
    Entity& newEntityA(manager.AddEntity("projectileA"));
    newEntityA.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);

    Entity& newEntityB(manager.AddEntity("projectileB"));
    newEntityB.AddComponent<TransformComponent>(WINDOW_WITH - 32, 0, -20, 20, 32, 32, 1);

    Entity& newEntityC(manager.AddEntity("projectileC"));
    newEntityC.AddComponent<TransformComponent>(WINDOW_WITH - 32, WINDOW_HEIGHT - 32, -20, -20, 32, 32, 1);

    Entity& newEntityD(manager.AddEntity("projectileD"));
    newEntityD.AddComponent<TransformComponent>(0, WINDOW_HEIGHT - 32, 20, -20, 32, 32, 1);

    manager.PrintEntities();
}
