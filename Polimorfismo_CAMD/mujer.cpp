#include "mujer.h"

mujer::mujer(string _nombre,string _sex, int _edad, float _estatura) : persona(_nombre, _sex, _edad)
{
    estatura=_estatura;
}

void mujer::mostrar()
{
    persona::mostrar();
    cout<<"Mi estatura es: "<<estatura<<" mtrs."<<endl;
}

mujer::~mujer()
{
    //dtor
}
