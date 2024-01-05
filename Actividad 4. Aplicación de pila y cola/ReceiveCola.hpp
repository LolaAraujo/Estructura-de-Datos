#ifndef RECEIVECOLA_HPP_INCLUDED
#define RECEIVECOLA_HPP_INCLUDED

#include "Pila.hpp"
#include "Cola.hpp"
#include <iostream>
#include <string>
#include <cstring>

class ReceiveCola {
    private:
        int op;
        Pila Spila;
        Queue colaIn;
        Queue colaOut;
        char aux;
    public:
        ReceiveCola();
        void conversorPostfixed();
        bool isOperador(const char&);
        int precedence(const char&);


    };

#endif // RECEIVECOLA_HPP_INCLUDED
