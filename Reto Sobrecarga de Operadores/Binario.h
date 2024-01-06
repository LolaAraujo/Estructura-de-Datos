#ifndef BINARIO_H
#define BINARIO_H
#include <iostream>
using std::cout;
using std::ostream;
using std::endl;
using std::istream;
using std::cin;
using std::string;

class Binario
{
    float x;
    string nom;

    public:
        Binario():x{0},nom{""}{} //{x = 0;}
        Binario(float a, string nnn):x{a}, nom{nnn}{} //{ x = a;} CONSTRUCTOR
//recibir un objeto de esa clase por eso se pone el nombre de la clase

        Binario operator-(Binario&);
        Binario operator+(Binario&); // función miembro recibe 1 porque ya lo esta llamndo
        //friend Binario operator-(Binario&,Binario&); // función amiga recibe 2

        friend ostream& operator<<(ostream &, const Binario & );
        friend istream& operator>>(istream &, Binario & );
        ///friend istream& operator>>(istream &entrada, Binario & );
        //istream& operator>>(istream &entrada, Binario &);
        //istream& operator>>(Binario &);

        void visualizar(void);
};

#endif // BINARIO_H
