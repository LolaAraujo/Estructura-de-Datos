#ifndef ALUMNOS_PREPA_H
#define ALUMNOS_PREPA_H
#include <iostream>
#include "alumnos.h"

using std::string;
using std::cout;
using std::endl;

class alumnos_prepa : public alumnos
{
    public:
        string grado;
        int anios;

        alumnos_prepa();
        alumnos_prepa(string, int, int, string, bool, bool);

        void visualizar(void){cout<<"Estudiante de: "<<grado<<"\n Duracion: "<<anios<<" anios"<<endl;}
        void preparatorianos(void);

    protected:
        int tarea;
        string comportamiento;
        bool duerme;
        bool uniforme;
};

#endif // ALUMNOS_PREPA_H
