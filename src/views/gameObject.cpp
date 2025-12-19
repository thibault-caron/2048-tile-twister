#include "gameObject.hpp"
// No implementation needed for abstract base class

GameObject::GameObject(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

int GameObject::getX() { return this->x; }
int GameObject::getY() { return this->y; }
int GameObject::getWidth() { return this->width; }
int GameObject::getHeight() { return this->height; }