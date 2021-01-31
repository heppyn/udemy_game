#include "./Game.h"
#include "./Map.h"
#include "./EntityManager.h"
#include "./Components/TileComponent.h"
#include <fstream>

extern EntityManager manager;

Map::Map(std::string textureId, int scale, int tileSize)
        : m_textureId(textureId), m_scale(scale), m_tileSize(tileSize) {}

void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY) {
    std::fstream mapFile;
    mapFile.open(filePath);

    for (int y = 0; y < mapSizeY; ++y) {
        for (int x = 0; x < mapSizeX; ++x) {
            char ch;
            mapFile.get(ch);
            int sourceRectY = (static_cast<int>(ch) - 48) * m_tileSize;
            mapFile.get(ch);
            int sourceRectX = (static_cast<int>(ch) - 48) * m_tileSize;
            AddTile(sourceRectX, sourceRectY, x * m_scale * m_tileSize, y * m_scale * m_tileSize);
            mapFile.ignore();
        }
    }

    mapFile.close();
}

void Map::AddTile(int sourceX, int sourceY, int x, int y) {
    Entity &newTile(manager.AddEntity("Tile", TILE_MAP_LAYER));
    newTile.AddComponent<TileComponent>(sourceX, sourceY, x, y, m_tileSize, m_scale, m_textureId);
}