#include <iostream>

#include "Application.hpp"

int main() {

    auto app = std::make_unique<Application>();
    
    app->MainLoop();

    return 0;
} 