#ifndef GAME_KEYBOARDCONTROLLER_H
#define GAME_KEYBOARDCONTROLLER_H

#include "../Game.h"
#include "../EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class KeyboardController : public Component {
public:
    std::string upKey;
    std::string downKey;
    std::string leftKey;
    std::string rightKey;
    std::string shootKey;
    TransformComponent* transform;
    SpriteComponent* sprite;

    KeyboardController() = default;
    KeyboardController(std::string upKey, std::string downKey, std::string leftKey, std::string rightKey, std::string shootKey)
    : upKey(GetSDLKeyStringCode(upKey))
    , downKey(GetSDLKeyStringCode(downKey))
    , leftKey(GetSDLKeyStringCode(leftKey))
    , rightKey(GetSDLKeyStringCode(rightKey))
    , shootKey(GetSDLKeyStringCode(shootKey))
    {}

    void Initialize() override {
        transform = owner->GetComponent<TransformComponent>();
        sprite = owner->GetComponent<SpriteComponent>();
    }

    void Update(float deltaTime) override {
        constexpr int speed = 5000;
        std::string keyCode = std::to_string(Game::m_event.key.keysym.sym);
        if (Game::m_event.type == SDL_KEYDOWN) {
            if (keyCode.compare(upKey) == 0) {
                transform->m_velocity.y = -speed * deltaTime;
                transform->m_velocity.x = 0;
                sprite->Play("UpAnimation");
            }
            if (keyCode.compare(downKey) == 0) {
                transform->m_velocity.y = speed * deltaTime;
                transform->m_velocity.x = 0;
                sprite->Play("DownAnimation");
            }
            if (keyCode.compare(leftKey) == 0) {
                transform->m_velocity.y = 0;
                transform->m_velocity.x = -speed * deltaTime;
                sprite->Play("LeftAnimation");
            }
            if (keyCode.compare(rightKey) == 0) {
                transform->m_velocity.y = 0;
                transform->m_velocity.x = speed * deltaTime;
                sprite->Play("RightAnimation");
            }
            if (keyCode.compare(shootKey) == 0) {
                // TODO: shoot projectile
            }
        }

        if (Game::m_event.type == SDL_KEYUP) {
            if (keyCode.compare(upKey) == 0) {
                transform->m_velocity.y = 0;
            }
            if (keyCode.compare(downKey) == 0) {
                transform->m_velocity.y = 0;
            }
            if (keyCode.compare(leftKey) == 0) {
                transform->m_velocity.x = 0;
            }
            if (keyCode.compare(rightKey) == 0) {
                transform->m_velocity.x = 0;
            }
        }
    }

    static std::string GetSDLKeyStringCode(std::string key) {
        if (key.compare("up") == 0) return "1073741906";
        if (key.compare("down") == 0) return "1073741905";
        if (key.compare("left") == 0) return "1073741904";
        if (key.compare("right") == 0) return "1073741903";
        if (key.compare("space") == 0) return "32";

        return std::to_string(static_cast<int>(key[0]));
    }
};


#endif //GAME_KEYBOARDCONTROLLER_H
