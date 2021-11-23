#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <iostream>
#include "gtkmm-3.0/gtkmm.h"
#include "Maths.hpp"

namespace SC {
class Window {
    private:
        int m_argc;
        char **m_argv;

        Gtk::Main m_main;
        Gtk::Window m_window;

    protected:

    public:
        /// Constructor
        Window(int argc, char **argv);

        /// Destructor
        ~Window(void);

        /// Initialize the window
        void init(int width, int height, std::string title);

        /// Run the window
        void run(void);
    };
}
#endif