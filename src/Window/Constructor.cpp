#include "../../include/Window.hpp"

SC::Window::Window(int argc, char **argv): m_main(argc, argv){
    std::cout << "Window constructor" << std::endl;
    this->m_argc = argc;
    this->m_argv = argv;
}

SC::Window::~Window(void) {

}

void SC::Window::init(int width, int height, std::string title) {
    std::cout << "Init" << std::endl;
    this->m_window
}

void SC::Window::run(void) {
    std::cout << "Run" << std::endl;
    /// Lance la boucle d'evenements
    this->m_main.run();
    this->m_window.show_all();
}