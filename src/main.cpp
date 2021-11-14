#include <iostream>
#include "../include/Window.hpp"

int main(int argc, char **argv)
{
    Window window(argc, argv);
    window.init(800, 600, "Super Calculator");
    window.run();
    return 0;
}