#include "../../include/Karnaugh.hpp"

SC::Karnaugh::Karnaugh(const unsigned int rows, const unsigned int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = new bool[rows * cols];
}

SC::Karnaugh::Karnaugh(const Karnaugh &tab) {
    this->rows  = tab.rows;
    this->cols = tab.cols;
    this->data = tab.data;
}

SC::Karnaugh::~Karnaugh() {
    delete[] this->data;
}

bool SC::Karnaugh::get(const unsigned int row, const unsigned int col) const {
    return this->data[row * this->cols + col];
}

void SC::Karnaugh::set(const unsigned int row, const unsigned int col, const bool value) {
    this->data[row * this->cols + col] = value;
}

SC::Karnaugh &SC::Karnaugh::operator==(const Karnaugh &tab) {
    Karnaugh tmp(tab.rows, tab.cols);
    for (unsigned int i = 0; i < this->rows; i++) {
        for (unsigned int j = 0; j < this->cols; j++) {
            tmp.set(i, j, this->get(i, j) == tab.get(i, j));
        }
    }
    return tmp;
}

SC::Karnaugh &SC::Karnaugh::operator!=(const Karnaugh &tab) {
    return !(*this == tab);
}

SC::Karnaugh &SC::Karnaugh::operator*=(const Karnaugh &tab) {
    for (unsigned int i = 0; i < this->rows; i++) {
        for (unsigned int j = 0; j < this->cols; j++) {
            this.set(i, j, this->get(i, j) && tab.get(i, j));
        }
    }
    return this;
}

SC::Karnaugh &SC::Karnaugh::operator+=(const Karnaugh &tab) {
    for (unsigned int i = 0; i < this->rows; i++) {
        for (unsigned int j = 0; j < this->cols; j++) {
            this.set(i, j, this->get(i, j) || tab.get(i, j));
        }
    }
    return this;
}