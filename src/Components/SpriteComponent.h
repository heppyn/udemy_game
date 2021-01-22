#ifndef GAME_SPRITECOMPONENT_H
#define GAME_SPRITECOMPONENT_H

#include "../Component.h"
#include "../AssetManager.h"
#include "../TextureManager.h"
#include "TransformComponent.h"
#include "Animation.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component {
public:
    SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    SpriteComponent(const char* fileName) {
        SetTexture(fileName);
    }

    SpriteComponent(std::string id, int numFrames, int animationSpeed, bool hasDirections, bool isFixed)
    : m_isAnimated(true), m_numFrames(numFrames), m_animationSpeed(animationSpeed), m_isFixed(isFixed)
    {
        if (hasDirections) {
            Animation down(0, numFrames, animationSpeed);
            Animation right(1, numFrames, animationSpeed);
            Animation left(2, numFrames, animationSpeed);
            Animation up(3, numFrames, animationSpeed);

            m_animations.emplace("DownAnimation", down);
            m_animations.emplace("UpAnimation", up);
            m_animations.emplace("LeftAnimation", left);
            m_animations.emplace("RightAnimation", right);

            m_animationIndex = 0;
            m_currentAnimationName = "DownAnimation";
        }
        else {
            m_animations.emplace("SingleAnimation", Animation(0, numFrames, animationSpeed));
            m_animationIndex = 0;
            m_currentAnimationName = "SingleAnimation";
        }

        Play(m_currentAnimationName);
        SetTexture(id);
    }

    void Play(std::string animationName) {
        m_numFrames = m_animations[animationName].m_numFrames;
        m_animationIndex = m_animations[animationName].m_index;
        m_animationSpeed = m_animations[animationName].m_animationSpeed;
        m_currentAnimationName = animationName;
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
        if (m_isAnimated) {
            m_source.x = m_source.w * static_cast<int>((SDL_GetTicks() / m_animationSpeed) % m_numFrames);
        }
        m_source.y = m_animationIndex * m_transform->m_height;
        m_destination.x = static_cast<int>(m_transform->m_position.x);
        m_destination.y = static_cast<int>(m_transform->m_position.y);
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
    bool m_isAnimated{false};
    int m_numFrames{0};
    int m_animationSpeed{0};
    bool m_isFixed{false}; // do not move ever, like label
    std::map<std::string, Animation> m_animations{};
    std::string m_currentAnimationName;
    unsigned m_animationIndex{0};
};


#endif //GAME_SPRITECOMPONENT_H
