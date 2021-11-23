#ifndef _GEOMETRIC_HPP_
#define _GEOMETRIC_HPP_

#include <cmath>
#include <iostream>

namespace SC {
    template<typename T>
    class Geometric {
    private:
        T m_x;
        T m_y;
        T m_z;

    protected:

    public:
        Geometric() : m_x(0), m_y(0), m_z(0) {}

        Geometric(T x, T y, T z) {
            m_x = x;
            m_y = y;
            m_z = z;
        }

        Geometric(const Geometric &geometric) {
            m_x = geometric.m_x;
            m_y = geometric.m_y;
            m_z = geometric.m_z;
        }

        ~Geometric() {}

        T getX() const { return m_x; }

        T getY() const { return m_y; }

        T getZ() const { return m_z; }

        void setX(T x) { m_x = x; }

        void setY(T y) { m_y = y; }

        void setZ(T z) { m_z = z; }

        void setXYZ(T x, T y, T z) {
            m_x = x;
            m_y = y;
            m_z = z;
        }

        void setXYZ(const Geometric &geometric) {
            m_x = geometric.m_x;
            m_y = geometric.m_y;
            m_z = geometric.m_z;
        }

        void setXYZ(const Geometric *geometric) {
            m_x = geometric->m_x;
            m_y = geometric->m_y;
            m_z = geometric->m_z;
        }

        T distance(const Geometric &geometric) const {
            return sqrt(pow(m_x - geometric.m_x, 2) + pow(m_y - geometric.m_y, 2) + pow(m_z - geometric.m_z, 2));
        }

        T distance(const Geometric *geometric) const {
            return sqrt(pow(m_x - geometric->m_x, 2) + pow(m_y - geometric->m_y, 2) + pow(m_z - geometric->m_z, 2));
        }

        T distance(T x = 0, T y = 0, T z = 0) const {
            return sqrt(pow(m_x - x, 2) + pow(m_y - y, 2) + pow(m_z - z, 2));
        }
    };
}

#endif