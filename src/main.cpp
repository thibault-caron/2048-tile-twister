#include <SDL3/SDL.h>

#include <iostream>
#include "views/window.hpp"

int main() {
    Window window;
    window.init();
    window.loop();
    
    
    return 0;
}