#ifndef _MATHS_HPP_
#define _MATHS_HPP_

#include <cmath>
#include "Algebra.hpp"
#include "Trigo.hpp"
#include "Matrix.hpp"

namespace SC {
class Maths : public Algebra, public SC::Trigo<float>, public SC::Matrix<float> {
    private:

    protected:

    public:
        /// Default constructor
        Maths(void);

        /// Default destructor
        ~Maths(void);

        /// Sum
        template<typename T>
        T sum(T a, T b) {
            return a + b;
        }

        /// Subtraction
        template<typename T>
        T sub(T a, T b) {
            return a - b;
        }

        /// Multiplication
        template<typename T>
        T mul(T a, T b) {
            return a * b;
        }

        /// Division
        template<typename T>
        T div(T a, T b) {
            return a / b;
        }

    };
}
#endif