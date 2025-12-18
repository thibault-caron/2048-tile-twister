#include "game.hpp"

// bool Game::move(Direction dir) { return grid.move(dir); }

void Game::addRandomTile() { grid.addRandomTile(); }

bool Game::isGameOver() const { return !grid.canMove(); }

Grid& Game::getGrid() { return grid; }


void Game::move(Direction dir) {
    if (grid.move(dir)) {
        grid.mergeTiles(dir);   
        grid.move(dir);         
        addRandomTile();        
    }
}
