#include "../../include/Decimal.hpp"

SC::Decimal::Decimal(void) : this->m_data[10] {
    for (int i = 0; i < 10; i++) {
        this->m_data[i] = i;
    }
}

SC::Decimal::~Decimal(void) {
    delete[] this->m_data;
}

int* SC::Decimal::getValue() const {
    return &this->m_data;
}

void SC::Decimal::print(std::ostream &os) const {
    os << "Decimal: ";
    for (int i = 0; i < 10; i++) {
        os << this->m_data[i] << ", ";
    }
    os << std::endl;
}