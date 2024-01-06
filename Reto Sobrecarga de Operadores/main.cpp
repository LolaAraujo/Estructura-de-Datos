#include <iostream>
#include "Binario.h"

using namespace std;

int main()
{
    //Binario a(8), b(15), c(21);
    //Binario a, b, c;
    Binario a(8,"juan"), b(78,"pepe"),c(11,"aldo");
    a.visualizar();
    b.visualizar();
    c.visualizar();

    c=a+b+c; ///a.operator+(b)
    c=c-a-a; ///operator-(c,a)

    //c=operator-(c,a);

    cout<<"Dame un valor y nombre:";
    cin>>a;

    cout<<"Dame un valor y nombre:";
    cin>>b;

    cout<<"Dame un valor y nombre:";
    cin>>c;

    cout<<a;
    cout<<b;
    cout<<c;

    ///Resta de string operator
    /*cout<<"dame el dato: ";
    //a.operator>>(a);
    cin>>a;

    cout<<"dame el dato: ";
    cin>>b;

    c=a+b;
    cout<<c;

    c=a-b; //especificación de la operación
    cout<<c;*/

    ///Resta de int //b.operator>>(b);
/*
    c=a+b; ///a.operator+(b) /// operator+(a,b)
    c=a+b+b+b;
    c=c-a;
    c=c-a;
    //c.visualizar();
    cout<<c; ///operator<<(cout,c)*/

    return 0;
}
