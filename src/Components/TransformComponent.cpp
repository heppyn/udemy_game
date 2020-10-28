#include "TransformComponent.h"

TransformComponent::TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
    : m_position(posX, posY), m_velocity(velX, velY), m_width(w), m_height(h), m_scale(s)
{}

void TransformComponent::Initialize() {

}

void TransformComponent::Update(float deltaTime) {
    m_position.x += m_velocity.x * deltaTime;
    m_position.y += m_velocity.y * deltaTime;
}

void TransformComponent::Render() {}
