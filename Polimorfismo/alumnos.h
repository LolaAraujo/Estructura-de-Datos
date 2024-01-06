#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <iostream>

using std::string;
using std::cout;
using std::endl;

///CLASE BASE.

class alumnos
{
    public:
        alumnos();
        virtual string grado();
        virtual int anios();
        virtual void visualizar();
};

#endif // ALUMNOS_H
