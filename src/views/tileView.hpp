#pragma once
#include <SDL3/SDL.h>

#include <iostream>
#include <string>

#include "gameObject.hpp"

class TileView : public GameObject {
  int value;

 public:
  TileView(int x, int y, int width, int height, int value);
  void setValue(int newValue);
  int getValue();
  void render(SDL_Renderer* renderer) override;
};
