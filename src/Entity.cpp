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

Entity::~Entity() {
    Destroy();
}

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
    for (auto comp : m_components) {
        delete comp;
    }
    m_components.clear();
}

bool Entity::IsActive() const {
    return m_isActive;
}

const std::string& Entity::Name() const {
    return m_name;
}

void Entity::Print() const {
    std::cout << "Entity name: " << m_name << '\n';

    for (const auto mapElem : m_componentTypeMap) {
        std::cout << "\tComponent<" << mapElem.first->name() << ">\n";
    }
}
