#include "Game.h"

int main(int argc, char** argv) {
    Uint32 frameStart;
    int frameTime;

    Game* game = new Game();
    if (game->init() == false) return 1;

    while (game->running()) {
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    game->quit();

    return 0;
}