#include "game.hpp"

bool Game::move(Direction dir) { return grid.move(dir); }

void Game::addRandomTile() { grid.addRandomTile(); }

bool Game::isGameOver() const { return !grid.canMove(); }

Grid& Game::getGrid() { return grid; }
