#ifndef GAME_TRANSFORMCOMPONENT_H
#define GAME_TRANSFORMCOMPONENT_H

#include "../EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include "../Game.h"
#include <SDL_rect.h>
#include <SDL_render.h>


class TransformComponent : public Component{
public:
    TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s);

    void Initialize () override;
    void Update(float deltaTime) override;
    void Render() override;
private:
    glm::vec2 m_position;
    glm::vec2 m_velocity;
    int m_width;
    int m_height;
    int m_scale;
};


#endif //GAME_TRANSFORMCOMPONENT_H
