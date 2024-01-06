#include "hombre.h"

hombre::hombre(string _nombre,string _sex, int _edad, float _peso) : persona(_nombre,_sex, _edad)
{
    peso=_peso;
}

void hombre::mostrar()
{
    persona::mostrar();
    cout<<"Mi peso es: "<<peso<<"kg"<<endl;
}

hombre::~hombre()
{
    //ctor
}
