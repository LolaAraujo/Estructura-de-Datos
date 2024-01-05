#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
#define MAX 300

#include <iostream>

class Pila{
private:
    char pila[MAX];
    int top;

public:
    Pila(); ///Inicializacion

    bool pFull();
    bool pNull();

    int pop(); ///Vaciar elementos de la pila
    void push(const char&); ///Guardar elementos en la pila

    char getTop();
};

#endif // PILA_HPP_INCLUDED
