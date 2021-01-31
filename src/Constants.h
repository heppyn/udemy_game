#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

const int WINDOW_WITH = 800;
const int WINDOW_HEIGHT = 600;

const int FPS = 60;
const int MIN_FPS = 5;
constexpr const float FRAME_TARGET_TIME = 1000.0 / FPS;
constexpr const float FRAME_TARGET_MIN_TIME = 1000.0 / MIN_FPS;

enum LayerType {
    TILE_MAP_LAYER = 0,
    VEGETATION_LAYER = 1,
    ENEMY_LAYER = 2,
    PLAYER_LAYER = 3,
    PROJECTILE_LAYER = 4,
    UI_LAYER = 5
};

constexpr const unsigned NUM_LAYERS = 6;

#endif //GAME_CONSTANTS_H
