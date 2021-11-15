#include "../../include/Window.hpp"

SC::Window::Window(int argc, char **argv) : kit(argc, argv) {
    std::cout << "Window constructor" << std::endl;
    this->m_argc = argc;
    this->m_argv = argv;
}

SC::Window::~Window(void) {

}

void SC::Window::init(int width, int height, std::string title) {
    std::cout << "Init" << std::endl;
    this->set_default_size(width, height);
    this->set_title(title);
    this->set_border_width(10);
}

void SC::Window::run(void) {
    std::cout << "Run" << std::endl;
    Gtk::Main::run(*this);
}