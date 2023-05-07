#include "author_name.hpp"
using namespace std;

NameA::NameA() { }

NameA::NameA(const NameA& n) {
    copyAll(n);
    }

void NameA::copyAll(const NameA& obj) {
    name = obj.name;
    lastname = obj.lastname;
    }

NameA& NameA::operator=(const NameA& obj) {
    copyAll(obj);
    return *this;
    }

bool NameA::operator==(const NameA& obj) const {
    return name == obj.name && lastname == obj.lastname;
    }

bool NameA::operator!=(const NameA& obj) const {
    return name != obj.name && lastname != obj.lastname;
    }

bool NameA::operator>=(const NameA& obj) const {
    return name >= obj.name && lastname >= obj.lastname;
    }

bool NameA::operator<=(const NameA& obj) const {
    return name <= obj.name && lastname <= obj.lastname;
    }

bool NameA::operator>(const NameA& obj) const {
    return name > obj.name && lastname > obj.lastname;
    }

bool NameA::operator<(const NameA& obj) const {
    return name < obj.name && lastname < obj.lastname;
    }

string NameA::getName() const {
    return name;
    }

string NameA::getLastName() const {
    return lastname;
    }

void NameA::setName(const string& _name) {
    name = _name;
    }

void NameA::setLastName(const string& _lastname) {
    lastname = _lastname;
    }

istream& operator >> (istream& is, NameA& obj) {
    getline(is, obj.name);
    getline(is, obj.lastname);
    return is;
    }

ostream& operator << (std::ostream& os, NameA& obj) {
    os << obj.name << "  " << obj.lastname << std::endl;
    return os;
    }

string NameA::toString() const {
    string myStr;
    myStr += name;
    myStr += " ";
    myStr += lastname;
    return myStr;
    }
