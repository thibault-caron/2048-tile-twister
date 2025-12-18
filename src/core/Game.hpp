#pragma once
#include "grid.hpp"

class Game {
 private:
  Grid grid;

 public:
  bool move(Direction dir);
  void addRandomTile();
  bool isGameOver() const;
  Grid& getGrid();
};
