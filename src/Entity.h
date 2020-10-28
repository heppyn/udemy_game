#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include "./Component.h"
#include "./EntityManager.h"
#include <vector>
#include <string>
#include <map>
#include <newt.h>

class EntityManager;
class Component;

class Entity {
public:
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    [[nodiscard]] bool IsActive() const;
    [[nodiscard]] const std::string& Name() const;
    void Print() const;

    template<typename T, typename... TArgs>
    T& AddComponent(TArgs&&... args) {
        T* newComponent(new T(std::forward<TArgs>(args)...));

        newComponent->owner = this;
        m_components.emplace_back(newComponent);
        m_componentTypeMap[&typeid(*newComponent)] = newComponent;
        newComponent->Initialize();

        return *newComponent;
    }

    template<typename T>
    T* GetComponent() {
        return static_cast<T*>(m_componentTypeMap[&typeid(T)]);
    }

protected:
    EntityManager& m_manager;
    bool m_isActive;
    std::vector<Component*> m_components;
    std::string m_name;
    std::map<const std::type_info*, Component*> m_componentTypeMap;
};

#endif //GAME_ENTITY_H
