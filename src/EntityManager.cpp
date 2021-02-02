//
// Created by heppy on 10.10.20.
//

#include "EntityManager.h"
#include "./Collision.h"
#include "./Components/ColliderComponent.h"

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
    for (int layerNum = 0; layerNum < NUM_LAYERS; ++layerNum) {
        for (const auto &entity: GetEntitiesByLayer(static_cast<LayerType>(layerNum))) {
            entity->Render();
        }
    }
}

bool EntityManager::HasNoEntities() const {
    return m_entities.empty();
}

Entity &EntityManager::AddEntity(std::string entityName, LayerType layer) {
    Entity *entity = new Entity(*this, entityName, layer);
    m_entities.emplace_back(entity);
    return *entity;
}

std::vector<Entity *> EntityManager::GetEntities() const {
    return m_entities;
}

std::vector<Entity *> EntityManager::GetEntitiesByLayer(LayerType layer) const {
    std::vector < Entity * > selected;
    for (const auto &entity: m_entities) {
        if (entity->layer == layer) {
            selected.emplace_back(entity);
        }
    }

    return selected;
}

int EntityManager::GetEntityCount() const {
    return m_entities.size();
}

void EntityManager::PrintEntities() const {
    for (const auto *entity : m_entities) {
        entity->Print();
    }
}

CollisionType EntityManager::CheckEntityCollisions() const {
    for (const auto &entity: m_entities) {
        if (entity->HasComponent<ColliderComponent>()) {
            auto *collider = entity->GetComponent<ColliderComponent>();
            for (const auto &otherEntity: m_entities) {
                if (otherEntity->HasComponent<ColliderComponent>() &&
                    entity->m_name.compare(otherEntity->m_name) != 0) {
                    auto *otherCollider = otherEntity->GetComponent<ColliderComponent>();
                    if (Collision::CheckRectangleCollision(collider->collider, otherCollider->collider)) {
                        if (
                                collider->colliderTag.compare("PLAYER") == 0 &&
                                otherCollider->colliderTag.compare("ENEMY") == 0
                                ) {
                            return PLAYER_ENEMY_COLLISION;
                        }
                        if (
                                collider->colliderTag.compare("PLAYER") == 0 &&
                                otherCollider->colliderTag.compare("PROJECTILE") == 0
                                ) {
                            return PLAYER_PROJECTILE_COLLISION;
                        }
                        if (
                                collider->colliderTag.compare("ENEMY") == 0 &&
                                otherCollider->colliderTag.compare("FRIENDLY_PROJECTILE") == 0
                                ) {
                            return ENEMY_PROJECTILE_COLLISION;
                        }
                        if (
                                collider->colliderTag.compare("PLAYER") == 0 &&
                                otherCollider->colliderTag.compare("LEVEL_COMPLETE") == 0
                                ) {
                            return PLAYER_LEVEL_COMPLETE_COLLISION;
                        }
                    }
                }
            }
        }
    }
    return NO_COLLISION;
}
