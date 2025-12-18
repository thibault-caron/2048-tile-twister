
#include "window.hpp"

#include <iostream>
#include <vector>
#include <SDL3_ttf/SDL_ttf.h>

#include "gridView.hpp"
#include "tileView.hpp"


Window::Window()
  : window(nullptr), renderer(nullptr), running(true), gridView(nullptr) {}

Window::~Window() {
  if (gridView) delete gridView;
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_Quit();
  SDL_Quit();
}

void Window::init() {
  SDL_Init(SDL_INIT_VIDEO);
  if (TTF_Init() < 0) {
    std::cerr << "TTF_Init failed: " << SDL_GetError() << std::endl;
  }
  window =
      SDL_CreateWindow("2048 - Tile Twister", 640, 480, SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, nullptr);
  game.addRandomTile();
  game.addRandomTile();
  updateGridView();
}

void Window::render() {
  SDL_SetRenderDrawColor(renderer, 200, 200, 255, 255);
  SDL_RenderClear(renderer);
  if (gridView) gridView->render(renderer);
  SDL_RenderPresent(renderer);
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        } else if (event.type == SDL_EVENT_KEY_DOWN) {
            switch (event.key.key) {
                case SDLK_LEFT:  game.move(Direction::LEFT); break;
                case SDLK_RIGHT: game.move(Direction::RIGHT); break;
                case SDLK_UP:    game.move(Direction::UP);    break;
                case SDLK_DOWN:  game.move(Direction::DOWN);  break;
            }
            updateGridView(); // si tu veux rafraîchir l’affichage
        }
    }
}

void Window::loop() {
  while (running) {
    handleEvents();
    render();
    if (!game.isGameOver()) {
      // Optionally show game over message
    }
    SDL_Delay(16);
  }
}

void Window::updateGridView() {
  // Build a vector of TileView from the current grid state
  if (gridView) delete gridView;
  // Grid layout
  int cellSize = 100;
  int gridW = 4 * cellSize;
  int gridH = 4 * cellSize;
  int winW = 640, winH = 480;
  if (renderer) SDL_GetRenderOutputSize(renderer, &winW, &winH);
  int offsetX = (winW - gridW) / 2;
  int offsetY = (winH - gridH) / 2;
  std::vector<TileView> tileViews;
  Grid& grid = game.getGrid();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      Tile* tile = grid.getTile(i, j);
      if (tile) {
        int val = tile->getValue();
        tileViews.emplace_back(offsetX + j * cellSize, offsetY + i * cellSize,
                               cellSize, cellSize, val);
      }
    }
  }
  gridView = new GridView(offsetX, offsetY, gridW, gridH, tileViews);
}
