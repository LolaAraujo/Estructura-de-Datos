#include "alumnos_uni.h"

alumnos_uni::alumnos_uni()
{
    nombre="";
    cantidadTarea=0;
    duerme=false;

    grado="";
    anios=0;
}

alumnos_uni::alumnos_uni(string G, int _ani, string nnn, int tar, bool zzz):alumnos()
{
    this->nombre=nnn;
    this->cantidadTarea=tar;
    this->duerme=zzz;

    this->grado=G;
    this->anios=_ani;
}

void alumnos_uni::mostrarUni(void)
{
    visualizar();
    cout<<nombre<<"Tiene "<<cantidadTarea<<" de tareas por ende es "<<duerme<<" que duerme"<<endl;
}

alumnos_uni::~alumnos_uni()
{
    cout<<"Destructor del programa"<<endl;
}
