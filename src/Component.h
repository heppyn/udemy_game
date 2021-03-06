#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include "./Entity.h"
#include <iostream>

class Entity;

class Component {
public:
    Entity* owner = nullptr;

    virtual ~Component() = default;
    virtual void Initialize() {}
    virtual void Update(const float deltaTime) {}
    virtual void Render() {}
    virtual void Print() const { std::cout << "Component"; }

protected:
};

#endif //GAME_COMPONENT_H
