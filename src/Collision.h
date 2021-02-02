#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <SDL2/SDL.h>

class Collision {
public:
    static bool CheckRectangleCollision(const SDL_Rect &a, const SDL_Rect &b);
};


#endif //GAME_COLLISION_H
