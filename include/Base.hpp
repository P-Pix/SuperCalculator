#ifndef _BASE_HPP_
#define _BASE_HPP_

#include <iostream>

namespace SC {
    template<typename T>
    class Base {
    private:

    protected:
        T m_data[];

    public:
        Base(void) {
        }

        ~Base(void) {
        }

        T *getData(void) {
            return &this->m_data;
        }

    };
}
#endif