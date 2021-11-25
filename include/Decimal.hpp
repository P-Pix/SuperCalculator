#ifndef _DECIMAL_HPP_
#define _DECIMAL_HPP_

#include <iostream>
#include "Base.hpp"

namespace SC {
    class Decimal : public SC::Base<int> {
    private:

    protected:

    public:
        Decimal(void);

        ~Decimal(void);

        int *getValue() const;

        void print(std::ostream &os) const;
    };
}

#endif