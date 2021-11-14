#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <iostream>
#include "gtkmm-3.0/gtkmm.h"
#include "Maths.hpp"

class Window
{
private:

protected:

public:
    Window(int argc, char **argv);
    ~Window(void);
    void init(int width, int height, std::string title);
    void run(void);
};

#endif