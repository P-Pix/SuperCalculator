#include <iostream>
#include "../include/Window.hpp"

int main(int argc, char **argv) {
    /*
    SC::Window window(argc, argv);
    window.init(800, 600, "Super Calculator");
    window.run();
     */
    testMatrix();
    return 0;
}

int testMatrix(void) {
    try {
        SC::Matrix<int> matrix(3, 3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix.set(i, j, i * j);
            }
        }
        std::cout << matrix << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}