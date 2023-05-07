#include "ingredientes.hpp"

using namespace std;

Ingredients::Ingredients() { }

Ingredients::Ingredients(const Ingredients& i) {
    copyAll(i);
    }

void Ingredients::copyAll(const Ingredients& obj) {
    nameIngr = obj.nameIngr;
    quantity = obj.quantity;
    }

Ingredients& Ingredients::operator=(const Ingredients& obj) {
    copyAll(obj);
    return *this;
    }

bool Ingredients::operator==(const Ingredients& obj) const {
    return nameIngr == obj.nameIngr;
    }

bool Ingredients::operator!=(const Ingredients& obj) const {
    return nameIngr != obj.nameIngr; //!(*this == c);
    }

bool Ingredients::operator>=(const Ingredients& obj) const {
    return nameIngr >= obj.nameIngr; //!(*this < c);
    }

bool Ingredients::operator<=(const Ingredients& obj) const {
    return nameIngr <= obj.nameIngr; //*this < c || *this == c;
    }

bool Ingredients::operator>(const Ingredients& obj) const {
    return nameIngr > obj.nameIngr; //!(*this <= c);
    }

bool Ingredients::operator<(const Ingredients& obj) const {
    return nameIngr < obj.nameIngr;
    }

int Ingredients::compareByNameIngr(const Ingredients& a, const Ingredients& b) {
    return a.nameIngr.compare(b.nameIngr);
    }

string Ingredients::getNameIngr() const {
    return nameIngr;
    }

string Ingredients::getQuantity() const {
    return quantity;
    }

void Ingredients::setNameIngr(const string& _nameIngr) {
    nameIngr = _nameIngr;
    }

void Ingredients::setQuantity(const string& _quantity) {
    quantity = _quantity;
    }

std::istream& operator >> (istream& is, Ingredients& obj) {
    getline(is, obj.nameIngr);
    getline(is, obj.quantity);
    return is;
    }

std::ostream& operator << (std::ostream& os, Ingredients& obj) {
    os << obj.nameIngr << "   " << obj.quantity<< std::endl;
    return os;
    }

string Ingredients::toString() const {
    string myStr;
    myStr += "\t--> ";
    myStr += nameIngr;
    myStr.resize(25,' ');
    myStr += quantity;
    return myStr;
    }
