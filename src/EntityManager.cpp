//
// Created by heppy on 10.10.20.
//

#include "EntityManager.h"

EntityManager::~EntityManager() {
    ClearData();
}

void EntityManager::ClearData() {
    for (auto entity : m_entities) {
//        entity->Destroy();
        delete entity;
    }
    m_entities.clear();
}

void EntityManager::Update(const float deltaTime) {
    for (auto& entity : m_entities) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto& entity : m_entities) {
        entity->Render();
    }
}

bool EntityManager::HasNoEntities() const {
    return m_entities.empty();
}

Entity& EntityManager::AddEntity(std::string entityName) {
    Entity* entity = new Entity(*this, entityName);
    m_entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const {
    return m_entities;
}

int EntityManager::GetEntityCount() const {
    return m_entities.size();
}

void EntityManager::PrintEntities() const {
    for (const auto* entity : m_entities) {
        entity->Print();
    }
}
