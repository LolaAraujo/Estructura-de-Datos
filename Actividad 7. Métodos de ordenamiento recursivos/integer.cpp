#include "Integer.hpp"

using namespace std;

Integer::Integer() {
    setData(0);
    }

Integer::Integer(int& obj) {
    data = obj;
    }

Integer::Integer(const Integer& obj) {
    data = obj.data;
    }

void Integer::setData(const int& obj) {
    data = obj;
    }

int Integer::getData() const {
    return data;
    }

std::string Integer::toString() const {
    string result;
    result += to_string(data);
    return result;
    }

Integer& Integer::operator = (const Integer& obj) {
    data = obj.data;
    return *this;
    }

Integer& Integer::operator = (const int& obj) {
    data = obj;
    return *this;
    }

Integer& Integer::operator -= (const Integer& obj) {
    data = data - obj.data;
    return *this;
    }

Integer& Integer::operator %= (const Integer& obj) {
    data = data % obj.data;
    return *this;
    }

Integer& Integer::operator - (const Integer& obj) {
    data += obj.data;
    return *this;
    }

Integer& Integer::operator / (const Integer& obj) {
    data /= obj.data;
    return *this;
    }

Integer& Integer::operator % (const Integer& obj) {
    data %= obj.data;
    return *this;
    }

bool Integer::operator == (const Integer& obj) const {
    return data == obj.data;
    }

bool Integer::operator != (const Integer& obj) const {
    return data != obj.data;
    }

bool Integer::operator < (const Integer& obj) const {
    return data < obj.data;
    }

bool Integer::operator <= (const Integer& obj) const {
    return data <= obj.data;
    }

bool Integer::operator > (const Integer& obj) const {
    return data > obj.data;
    }

bool Integer::operator >= (const Integer& obj) const {
    return data >= obj.data;
    }

Integer& Integer::operator * (const Integer& obj) {
    data *= obj.data;
    return *this;
    }

Integer& Integer::operator + (const Integer& obj) {
    data += obj.data;
    return *this;
    }

Integer& Integer::operator /= (const Integer& obj) {
    data /= obj.data;
    return *this;
    }

Integer& Integer::operator += (const Integer& obj) {
    data += obj.data;
    return *this;
    }

Integer& Integer::operator *= (const Integer& obj) {
    data *= obj.data;
    return *this;
    }

Integer& Integer::operator++() {
    data++;
    return *this;
    }

Integer Integer::operator++(int) {
    Integer tmp(*this);
    operator++();
    return tmp;
    }

Integer& Integer::operator--() {
    data--;
    return *this;
    }

Integer Integer::operator--(int) {
    Integer tmp(*this);
    operator--();
    return tmp;
    }

std::istream& operator >> (std::istream& is, Integer& obj) {
    is >> obj.data;
    return is;
    }

std::ostream& operator << (std::ostream& os, Integer& obj) {
    os << obj.data;
    return os;
    }
