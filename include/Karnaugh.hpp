#ifndef _KARNAUGH_HPP_
#define _KARNAUGH_HPP_

#include <iostream>
#include "Matrix.hpp"

namespace SC {
    class Karnaugh : public SC::Matrix<bool> {
    private:
    protected:
    public:
        /// Constructors
        /// @param rows: number of rows
        /// @param cols: number of columns
        Karnaugh(const unsigned int rows, const unsigned int cols);

        /// Constructor
        /// @param tab: pointer to Karnaugh
        Karnaugh(const Karnaugh &tab);

        ~Karnaugh(void);

        /// Getter
        /// @param row: row index
        /// @param col: column index
        bool get(const unsigned int row, const unsigned int col) const;

        /// Setter
        /// @param row: row index
        /// @param col: column index
        /// @param value: value to set
        void set(const unsigned int row, const unsigned int col, const bool value);

        /// Operator
        Karnaugh &operator==(const Karnaugh &tab);
        Karnaugh &operator!=(const Karnaugh &tab);
        Karnaugh &operator+=(const Karnaugh &tab);
        Karnaugh &operator*=(const Karnaugh &tab);
    };
}
#endif