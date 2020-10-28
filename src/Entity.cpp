#include "./Entity.h"

#include <iostream>

Entity::Entity(EntityManager &manager)
    : Entity(manager, "")
{}

Entity::Entity(EntityManager &manager, std::string name)
        : m_manager(manager)
        , m_name(std::move(name))
        , m_isActive(true)
{}

void Entity::Update(const float deltaTime) {
    for (auto& component : m_components) {
        component->Update(deltaTime);
    }
}

void Entity::Render() {
    for (auto& component : m_components) {
        component->Render();
    }
}

void Entity::Destroy() {
    m_isActive = false;
}

bool Entity::IsActive() const {
    return m_isActive;
}

const std::string& Entity::Name() const {
    return m_name;
}

void Entity::Print() const {
    std::cout << "Entity name: " << m_name << '\n';

    for (const auto* comp : m_components) {
        std::cout << "\tComponent<";
        comp->Print();
        std::cout << ">\n";
    }
}
