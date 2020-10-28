#ifndef GAME_SPRITECOMPONENT_H
#define GAME_SPRITECOMPONENT_H

#include "../Component.h"
#include "../AssetManager.h"
#include "../TextureManager.h"
#include "TransformComponent.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component {
public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent(const char* fileName) {
        SetTexture(fileName);
    }

    void SetTexture(std::string assetTextureId) {
        m_texture = Game::m_assetManager->GetTexture(assetTextureId);
    }

    void Initialize() override {
        m_transform = owner->GetComponent<TransformComponent>();
        m_source.x = 0;
        m_source.y = 0;
        m_source.w = m_transform->m_width;
        m_source.h = m_transform->m_height;
    }

    void Update(float deltaTime) override {
        m_destination.x = (int)m_transform->m_position.x;
        m_destination.y = (int)m_transform->m_position.y;
        m_destination.w = (int)m_transform->m_width * m_transform->m_scale;
        m_destination.h = (int)m_transform->m_height * m_transform->m_scale;
    }

    void Render() override {
        TextureManager::Draw(m_texture, m_source, m_destination, spriteFlip);
    }

private:
    TransformComponent* m_transform;
    SDL_Texture* m_texture;
    SDL_Rect m_source;
    SDL_Rect m_destination;
};


#endif //GAME_SPRITECOMPONENT_H
