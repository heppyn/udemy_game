#ifndef GAME_TILECOMPONENT_H
#define GAME_TILECOMPONENT_H

#include "../Component.h"
#include <SDL2/SDL.h>
#include "../../lib/glm/glm.hpp"
#include "../EntityManager.h"
#include "../AssetManager.h"

class TileComponent : public Component {
public:
    SDL_Texture *texture;
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;
    glm::vec2 position;

    TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale,
                  std::string assetTextureId) {
        texture = Game::m_assetManager->GetTexture(assetTextureId);

        sourceRectangle.x = sourceRectX;
        sourceRectangle.y = sourceRectY;
        sourceRectangle.w = tileSize;
        sourceRectangle.h = tileSize;

        destinationRectangle.x = x;
        destinationRectangle.y = y;
        destinationRectangle.w = tileSize * tileScale;
        destinationRectangle.h = tileSize * tileScale;

        position.x = x;
        position.y = y;
    }

    ~TileComponent() {
        SDL_DestroyTexture(texture);
    }

    void Update(float deltaTime) override {
        destinationRectangle.x = position.x - Game::m_camera.x;
        destinationRectangle.y = position.y - Game::m_camera.y;
    }

    void Render() override {
        TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
    }
};

#endif //GAME_TILECOMPONENT_H
