#ifndef NINOS_H
#define NINOS_H
#include "persona.h"
#include <iostream>

using std::string;
using std::cout;

class ninos : public persona
{
    protected:
        bool juguetes;
    public:
        ninos(string,string, int, bool);
        virtual ~ninos();
        void mostrar();
};

#endif // NINOS_H
