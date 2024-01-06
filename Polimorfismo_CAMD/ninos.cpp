#include "ninos.h"

ninos::ninos(string _nombre,string _sex ,int _edad, bool tool) : persona(_nombre, _sex, _edad)
{
    juguetes= tool;
}

void ninos::mostrar()
{
    persona::mostrar();
    cout<<"Es "<<juguetes<<" que tengo juguetes"<<endl;
}

ninos::~ninos()
{
    //dtor
}
