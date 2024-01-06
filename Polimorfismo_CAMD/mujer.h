#ifndef MUJER_H
#define MUJER_H
#include "persona.h"
#include <iostream>

using std::cout;
using std::endl;

class mujer : public persona
{
    private:
        float estatura;
    public:
        mujer(string, string,int, float);

        virtual ~mujer();
        void mostrar();
};

#endif // MUJER_H
