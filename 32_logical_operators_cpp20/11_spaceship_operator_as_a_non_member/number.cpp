#include "number.h"


std::ostream& operator<<(std::ostream& out, const Number& number) {
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}