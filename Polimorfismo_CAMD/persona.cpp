#include "persona.h"

void persona::mostrar()
{
    cout<<"Mi nombre es: " << nombre << endl;
    cout<<"Me considero: "<<orientacion<<endl;
    cout<<"Mi edad es: " << edad <<" anios" << endl;
}

persona::~persona()
{
    cout<<"\n\nFin del Polimorfismo D:"<<endl;
}
