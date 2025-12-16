# 2048-tile-twister
Simple Tile Twister game in C++

## Arborescence du projet

```
2048-tile-twister/
│   main.cpp
│   README.md
│   LICENSE
├── include/
├── src/
│   ├── core/
│   │   ├── Game.h/.cpp
│   │   ├── Grid.h/.cpp
│   │   └── Tile.h/.cpp
│   └── sdl/
│       ├── Window.h/.cpp
│       ├── GameObject.h/.cpp
│       ├── TileView.h/.cpp
│       ├── GridView.h/.cpp
│       ├── AnimationManager.h/.cpp
│       └── InputManager.h/.cpp
```

## Diagramme de classes (Mermaid)

```mermaid
classDiagram
	class Game {
		-Grid grid
		+void move(Direction)
		+void addRandomTile()
		+bool isGameOver()
	}
	class Grid {
		-Tile[4][4] tiles
		+bool move(Direction)
		+bool canMove()
		+void mergeTiles(Direction)
		+void addTile(Tile)
	}
	class Tile {
		-int value
		-int x
		-int y
		+int getValue()
		+(x, y) getPosition()
	}
	class Window {
		+void init()
		+void render()
		+void handleEvents()
	}
	class GameObject {
		<<abstract>>
		-int x
		-int y
		-int width
		-int height
		+virtual void render()
	}
	class TileView {
		+void render()
	}
	class GridView {
		+void render()
	}
	class AnimationManager {
		+void animateMove()
	}
	class InputManager {
		+Direction getInput()
	}
	Game --> Grid
	Grid --> Tile
	Window --> GameObject
	TileView --|> GameObject
	GridView --|> GameObject
	Window --> AnimationManager
	Window --> InputManager
	Window --> GridView
	GridView --> TileView
```
git push