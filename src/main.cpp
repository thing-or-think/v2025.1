#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "core/Game.h"

int main(int argc, char* argv[]) {
    std::cerr << "Game init attempted \n";
    if (Game::GetInstance() -> Init("Game Window")) {
        std::cerr << "Game initializaed successfully \n";
        while (Game::GetInstance() -> IsRunning()) {
            Game::GetInstance() -> HandleEvents();
        }
    } else {
        std::cerr << "Game initialization false \n";
    }
    std::cerr << "Game instance destroyed \n";
    Game::DestroyInstance();
    std::cout << "Game instance destroyed successfully \n";
    return 0;
}