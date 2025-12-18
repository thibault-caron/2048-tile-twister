#pragma once
#include <SDL3/SDL.h>

#include <vector>

#include "gameObject.hpp"
#include "tileView.hpp"

class GridView : public GameObject {
  std::vector<TileView> tiles;

 public:
  GridView(int x, int y, int width, int height,
           const std::vector<TileView>& tiles);
  void setTiles(const std::vector<TileView>& newTiles);
  void render(SDL_Renderer* renderer) override;
};
