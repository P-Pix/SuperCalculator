#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <cmath>

namespace SC {
    template<typename T>
    class Matrix {
    private:
        int rows;
        int cols;
        T *data;

    protected:

    public:
        /// Constructors
        Matrix(int rows, int cols) {
            this->rows = rows;
            this->cols = cols;
            this->data = new T[rows * cols];
        }

        Matrix(const Matrix &m) {
            this->rows = m.rows;
            this->cols = m.cols;
            this->data = new T[rows * cols];
            for (int i = 0; i < rows * cols; i++) {
                this->data[i] = m.data[i];
            }
        }

        /// Destructor
        ~Matrix(void) {
            delete[] this->data;
        }

        /// Accessors
        int getRows(void) const {
            return this->rows;
        }

        int getCols(void) const {
            return this->cols;
        }

        T get(int row, int col) const {
            return this->data[row * cols + col];
        }

        /// Mutators
        void set(int row, int col, T value) {
            this->data[row * cols + col] = value;
        }

        /// Operators
        Matrix &operator=(const Matrix &m) {
            if (this == &m) {
                return *this;
            }
            delete[] this->data;
            this->rows = m.rows;
            this->cols = m.cols;
            this->data = new double[rows * cols];
            for (int i = 0; i < rows * cols; i++) {
                this->data[i] = m.data[i];
            }
            return *this;
        }

        Matrix operator+(const Matrix &m) const {
            if (this->rows != m.rows || this->cols != m.cols) {
                throw "Matrix dimensions do not match";
            }
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows * this->cols; i++) {
                result.data[i] = this->data[i] + m.data[i];
            }
            return result;
        }

        Matrix operator-(const Matrix &m) const {
            if (this->rows != m.rows || this->cols != m.cols) {
                throw "Matrix dimensions do not match";
            }
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows * this->cols; i++) {
                result.data[i] = this->data[i] - m.data[i];
            }
            return result;
        }

        Matrix operator*(const Matrix &m) const {
            if (this->cols != m.rows) {
                throw "Matrix dimensions do not match";
            }
            Matrix result(this->rows, m.cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    double sum = 0;
                    for (int k = 0; k < this->cols; k++) {
                        sum += this->data[i * this->cols + k] * m.data[k * m.cols + j];
                    }
                    result.data[i * m.cols + j] = sum;
                }
            }
            return result;
        }

        Matrix operator*(T d) const {
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows * this->cols; i++) {
                result.data[i] = this->data[i] * d;
            }
            return result;
        }

        Matrix operator/(T d) const {
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows * this->cols; i++) {
                result.data[i] = this->data[i] / d;
            }
            return result;
        }

        Matrix &operator+=(const Matrix &m) {
            if (this->rows != m.rows || this->cols != m.cols) {
                throw "Matrix dimensions do not match";
            }
            for (int i = 0; i < this->rows * this->cols; i++) {
                this->data[i] += m.data[i];
            }
            return *this;
        }

        Matrix &operator-=(const Matrix &m) {
            if (this->rows != m.rows || this->cols != m.cols) {
                throw "Matrix dimensions do not match";
            }
            for (int i = 0; i < this->rows * this->cols; i++) {
                this->data[i] -= m.data[i];
            }
            return *this;
        }

        Matrix &operator*=(const Matrix &m) {
            if (this->cols != m.rows) {
                throw "Matrix dimensions do not match";
            }
            Matrix result(this->rows, m.cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    double sum = 0;
                    for (int k = 0; k < this->cols; k++) {
                        sum += this->data[i * this->cols + k] * m.data[k * m.cols + j];
                    }
                    result.data[i * m.cols + j] = sum;
                }
            }
            *this = result;
            return *this;
        }

        Matrix &operator*=(T d) {
            for (int i = 0; i < this->rows * this->cols; i++) {
                this->data[i] *= d;
            }
            return *this;
        }

        Matrix &operator/=(T d) {
            for (int i = 0; i < this->rows * this->cols; i++) {
                this->data[i] /= d;
            }
            return *this;
        }

        bool operator==(const Matrix &m) const {
            if (this->rows != m.rows || this->cols != m.cols) {
                return false;
            }
            for (int i = 0; i < this->rows * this->cols; i++) {
                if (this->data[i] != m.data[i]) {
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const Matrix &m) const {
            return !*this == m;
        }

        Matrix transpose(void) const {
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    result.data[j * result.cols + i] = this->data[i * this->cols + j];
                }
            }
            return result;
        }

        Matrix inverse(void) const {
            if (this->rows != this->cols) {
                throw "Matrix is not square";
            }
            Matrix result(this->rows, this->cols);
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    result.data[i * result.cols + j] = this->data[j * result.cols + i];
                }
            }
            return result;
        }

        T determinant(void) const {
            if (this->rows != this->cols) {
                throw "Matrix is not square";
            }
            T result = 1;
            for (int i = 0; i < this->rows; i++) {
                result *= this->data[i * this->cols + i];
            }
            return result;
        }

        T trace(void) const {
            if (this->rows != this->cols) {
                throw "Matrix is not square";
            }
            double result = 0;
            for (int i = 0; i < this->rows; i++) {
                result += this->data[i * this->cols + i];
            }
            return result;
        }

        T norm(void) const {
            T result = 0;
            for (int i = 0; i < this->rows * this->cols; i++) {
                result += this->data[i] * this->data[i];
            }
            return sqrt(result);
        }

        T norm(int p) const {
            T result = 0;
            for (int i = 0; i < this->rows * this->cols; i++) {
                result += pow(this->data[i], p);
            }
            return pow(result, 1.0 / p);
        }

        T max(void) const {
            T result = this->data[0];
            for (int i = 1; i < this->rows * this->cols; i++) {
                if (this->data[i] > result) {
                    result = this->data[i];
                }
            }
            return result;
        }

        T min(void) const {
            T result = this->data[0];
            for (int i = 1; i < this->rows * this->cols; i++) {
                if (this->data[i] < result) {
                    result = this->data[i];
                }
            }
            return result;
        }

        Matrix &fill(T value) {
            this->fill(value, 0, this->rows * this->cols);
        }

        Matrix &fill(T value, int start, int end) {
            for (int i = start; i < end; i++) {
                this->data[i] = value;
            }
            return *this;
        }

        /// Friend functions
        std::ostream &operator<<(std::ostream &os, const Matrix &m) {
            for (int i = 0; i < m.rows; i++) {
                for (int j = 0; j < m.cols; j++) {
                    os << m.data[i * m.cols + j] << " ";
                }
                os << std::endl;
            }
            return os;
        }
    };
}
#endif