#include "Binario.h"

//ya no se necesita porque ya se desarrollo
/*
Binario::Binario()
{
    //ctor
}*/
//estatico . dinamico ->
// objX.operator+(obj)
Binario Binario::operator+(Binario &obj) // función miembro recibe 1 porque ya lo esta llamndo el objeto que invoca
{
    Binario aux;
    aux.x = this->x + obj.x; //se suma el x que esta invoncando, con el x de objeto y el xal que se le asigna
    aux.nom=this->nom+" "+obj.nom;
    return aux;
}
/*istream& Binario::operator>>(Binario &obj)
{
    //cin>>obj.x;
    return cin>>obj.x;
}*/

istream &operator>>(istream &entrada, Binario &obj)
{
    //entrada>>obj.x;
    //entrada>>obj.nom;
    entrada>>obj.x>>obj.nom;
    return entrada;
}

ostream& operator<<(ostream &salida, const Binario &obj)//paso por referencia
{
    //cout
    salida<<obj.x<<" "<<obj.nom;
    return salida;
}
//operator-(obj1,obj2)
Binario Binario::operator-(Binario &objB) // función amiga recibe 2
{
    Binario aux;
    aux.x = this->x - objB.x;

    aux.nom= this->nom+" menos "+objB.nom;

    return aux;
}
/*Binario operator-(Binario &obj, Binario &obj2) // función amiga recibe 2
{
    Binario aux;
    aux.x = obj.x - obj2.x;

    aux.nom=obj.nom+" menos "+obj2.nom;

    return aux;
}*/
void Binario::visualizar(void)
{
    cout << x << "\n";
    cout<<nom<<endl;
}

