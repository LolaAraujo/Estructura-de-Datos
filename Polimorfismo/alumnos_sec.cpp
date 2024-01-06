#include "alumnos_sec.h"

alumnos_sec::alumnos_sec()
{
    grado="";
    tarea=0;
    comportamiento="";
    talleres=true;
}

alumnos_sec::alumnos_sec(string G, int _tar, string _comport, bool _tall) : alumnos()
{
    this->grado=G;
    this->tarea=_tar;
    this->comportamiento=_comport;
    this->talleres=_tall;
}

