#ifndef ALUMNOS_UNI_H
#define ALUMNOS_UNI_H
#include <iostream>
#include "alumnos.h"

using std::string;
using std::cout;
using std::endl;

class alumnos_uni : public alumnos
{
    protected:
        string nombre;
        int cantidadTarea;
        bool duerme;

    public:
        alumnos_uni();
        alumnos_uni(string, int, string, int, bool);
        virtual ~alumnos_uni();

        string grado;
        int anios;
        void visualizar(void)
        {
            cout<<"Es un estudiante de "<<grado<<" durara "<<anios<<" anios en el grado"<<endl;
        }
        void mostrarUni();

};

#endif // ALUMNOS_UNI_H
