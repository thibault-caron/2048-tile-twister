#include <SDL3/SDL.h>

#include <iostream>

int main() {
    // INIT SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erreur SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // CREATE WINDOW
    SDL_Window* window = SDL_CreateWindow(
        "Hello 2048",               
        640,                        
        480,                        
        SDL_WINDOW_RESIZABLE        // options
    );

    if (!window) {
        std::cerr << "Erreur création fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }
    //CREATE RENDERER
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        std::cerr << "Erreur création renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

           //CHANGE BACKGROUND COLOR
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
    }

 

    // DELAY
    SDL_Delay(16);

    // DESTROY WINDOW
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
