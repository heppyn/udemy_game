#ifndef GAME_ENTITYMANAGER_H
#define GAME_ENTITYMANAGER_H

#include "./Entity.h"
#include "./Component.h"
#include <vector>
#include <string>

class EntityManager {
public:
    ~EntityManager();
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntities() const;
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    int GetEntityCount() const;
    void PrintEntities() const;
private:
    std::vector<Entity*> m_entities;
};


#endif //GAME_ENTITYMANAGER_H
