#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include "QueuePosfijo.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string.h>

class Menu {
    private:
        int op;
        Stack<char> Spila;
        Queue<char>colaInserc;
        QueuePosfijo<char>colaOut;
        char aux;

    public:
        Menu();
        Menu(const Menu& );

        void convertinfijo_Postfijo();
        bool isOperador(const char&);
        int precedence(const char&);
        Menu& operator = (const Menu& );
    };

#endif // MENU_HPP_INCLUDED
