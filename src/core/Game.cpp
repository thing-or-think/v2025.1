#include <iostream>
#include "core/Game.h"
#include "core/Config.h"

Game* Game::instance = nullptr;

bool Game::Init(const char* title) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "SDL_CreateRender Error: " << SDL_GetError() << std::endl;
        return false;
    }
    isRunning = true;
    return true;
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            Quit();
        }
    }
}

void Game::DestroyInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}
