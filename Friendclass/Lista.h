#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista
{
    public:
        Nodo *h;

        Lista():h{nullptr}{}
        Lista(Nodo* ptr):h{ptr}{}

        ~Lista();

        void insertarFinal(int);
        void mostrar(void);

};

#endif // LISTA_H
