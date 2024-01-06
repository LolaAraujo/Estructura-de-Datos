#ifndef ALUMNOS_SEC_H
#define ALUMNOS_SEC_H
#include <iostream>
#include "alumnos.h"

using std::string;
using std::cout;
using std::endl;

class alumnos_sec : public alumnos
{
    protected:
         int tarea;
         string comportamiento;
         bool talleres;
    public:
        alumnos_sec();
        alumnos_sec(string, int, string, bool);

        string grado;
        void visualizar(void){cout<<"Estudiante de: "<<grado<<endl;}
        void mostrarSec(void)
        {
            visualizar();
            cout<<"\n\nLos de secundaria tienen: "<<tarea<<" de tarea, es "<<talleres<<" que hay talleres"<<endl;
            cout<<"Y se comportan: "<<endl;
        }
};

#endif // ALUMNOS_SEC_H
