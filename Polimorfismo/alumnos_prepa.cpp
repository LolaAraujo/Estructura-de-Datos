#include "alumnos_prepa.h"

alumnos_prepa::alumnos_prepa():alumnos()
{
    tarea=0;
    comportamiento="";
    duerme=true;
    uniforme=false;
    grado="";
    anios=0;
}

alumnos_prepa::alumnos_prepa(string G, int _ani, int _tar, string _compor, bool zzz, bool _unfor):alumnos()
{
    this->tarea=_tar;
    this->comportamiento= _compor;
    this->duerme=zzz;
    this->uniforme=_unfor;
    this->grado=G;
    this->anios=_ani;
}

void alumnos_prepa::preparatorianos(void)
{
    visualizar();
    cout<<"Es "<<uniforme<<" que usan uniforme"<<endl;
    cout<<"Suelen tener "<<tarea<<" de tareas, por ende es "<<duerme<<" que ellos duermen"<<endl;
    cout<<"Su comportamiento es: "<<comportamiento<<endl;
}
