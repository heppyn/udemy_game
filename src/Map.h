#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>

class Map {
private:
    std::string m_textureId;
    int m_scale;
    int m_tileSize;
public:
    Map(std::string textureId, int scale, int tileSize);

    void LoadMap(std::string filePath, int mapSizeX, int maSizeY);

    void AddTile(int sourceX, int sourceY, int x, int y);
};

#endif //GAME_MAP_H
