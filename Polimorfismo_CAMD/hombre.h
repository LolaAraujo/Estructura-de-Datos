#ifndef HOMBRE_H
#define HOMBRE_H
#include "persona.h"
#include <iostream>

using std::cout;
using std::endl;

class hombre : public persona
{
    private:
        float peso;
    public:
        hombre(string, string ,int, float);
        virtual ~hombre();
        void mostrar();
};

#endif // HOMBRE_H
