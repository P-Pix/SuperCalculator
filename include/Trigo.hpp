#ifndef _TRIGO_HPP_
#define _TRIGO_HPP_

#include <cmath>
#include <iostream>

namespace SC {
    template<typename T>
    class Trigo {
    private:

    protected:

    public:
        Trigo() {
        }

        ~Trigo() {
        }

        static T toRadian(T angle) {
            return angle * M_PI / 180;
        }

        static T toDegree(T angle) {
            return angle * 180 / M_PI;
        }
    };
}

#endif