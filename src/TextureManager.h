#ifndef GAME_TEXTUREMANAGER_H
#define GAME_TEXTUREMANAGER_H

#include "./Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip);
};


#endif //GAME_TEXTUREMANAGER_H
