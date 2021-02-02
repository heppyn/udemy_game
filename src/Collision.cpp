//
// Created by heppy on 02.02.21.
//

#include "Collision.h"


bool Collision::CheckRectangleCollision(const SDL_Rect &a, const SDL_Rect &b) {
    return (
            a.x + a.w >= b.x &&
            b.x + b.w >= a.x &&
            a.y + a.h >= b.y &&
            b.y + b.h >= a.y
    );
}