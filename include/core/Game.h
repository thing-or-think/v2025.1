#ifndef GAME_H
#define GAME_H

#include <SDL.h>

class Game {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    static Game* instance;

    Game(): window(nullptr), renderer(nullptr), isRunning(false) {}
    ~Game() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
        SDL_Quit();
    }
public:
    static Game* GetInstance() {
        if (instance == nullptr) {
            instance = new Game();
        }
        return instance;
    }
    bool Init(const char* title);
    bool IsRunning() const  {   return isRunning;  }
    void HandleEvents();
    void Quit() {   isRunning = false;  }
    static void DestroyInstance();
};

#endif  // GAME_H