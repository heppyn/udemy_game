#include <iostream>
#include "Constants.h"
#include "./Game.h"

int main() {
    Game *game = new Game();

    game->Initialize(WINDOW_WITH, WINDOW_HEIGHT);

    while (game->IsRunning()) {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();
    std::cout << "Done\n";
    return 0;
}
