#ifndef GAME_COLLIDERCOMPONENT_H
#define GAME_COLLIDERCOMPONENT_H

#include <SDL2/SDL.h>
#include "../EntityManager.h"
#include "../Game.h"
#include "./TransformComponent.h"

class ColliderComponent : public Component {
public:
    std::string colliderTag;
    SDL_Rect collider;
    SDL_Rect sourceRect;
    SDL_Rect destRect;
    TransformComponent *transform;

    ColliderComponent(std::string tag, int x, int y, int w, int h)
            : colliderTag(tag), collider({x, y, w, h}) {}

    void Initialize() override {
        if (owner->HasComponent<TransformComponent>()) {
            transform = owner->GetComponent<TransformComponent>();
            sourceRect = {0, 0, transform->m_width, transform->m_height};
            destRect = {collider.x, collider.y, collider.w, collider.h};
        }
    }

    void Update(float deltaTime) override {
        collider.x = static_cast<int>(transform->m_position.x);
        collider.y = static_cast<int>(transform->m_position.y);
        collider.w = transform->m_width * transform->m_scale;
        collider.h = transform->m_height * transform->m_scale;

        destRect.x = collider.x - Game::m_camera.x;
        destRect.y = collider.y - Game::m_camera.y;
    }

    void Render() override {

    }
};


#endif //GAME_COLLIDERCOMPONENT_H
