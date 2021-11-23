#include <iostream>
#include "../include/Window.hpp"

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
    return EXIT_SUCCESS;
}

int testTrigo(void) {
    try {

    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    std::cout << "---------- Test Matrix ----------" << std::endl;
    testMatrix();
    std::cout << "---------- Test Trigo ----------" << std::endl;
    testTrigo();
    SC::Window window(argc, argv);
    //window.init(800, 600, "Test");
    //window.run();
    return 0;
}
