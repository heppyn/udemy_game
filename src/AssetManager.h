#ifndef GAME_ASSETMANAGER_H
#define GAME_ASSETMANAGER_H

#include <map>
#include <string>
#include "./TextureManager.h"
#include "./EntityManager.h"

class AssetManager {
public:
    AssetManager(EntityManager* manager);
    ~AssetManager();
    void ClearData() noexcept;
    void AddTexture(std::string textureId, const char* filePath);
    SDL_Texture* GetTexture(std::string textureId);

private:
    EntityManager* m_manager;
    std::map<std::string, SDL_Texture*> m_textures;
};


#endif //GAME_ASSETMANAGER_H
