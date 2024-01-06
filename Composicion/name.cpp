#include "name.hpp"

///En el archivo de implementación si es valido el namespace

using namespace std;

string Name::getLast() const {
    return last;
    }
string Name::getFirst() const {
    return first;
    }

void Name::setLast(const string& l) {
    last=l;
    }

void Name::setFirst(const string& f) {
    first =f;
    }
