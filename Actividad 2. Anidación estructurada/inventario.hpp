#ifndef INVENTARIO_HPP_INCLUDED
#define INVENTARIO_HPP_INCLUDED

#include <iostream>
#include <string>
#include "product.hpp"

class Inventario {
    private:
        Product collec[500];
        Date myDate;

    public:
        Inventario();
        Inventario(const Inventario&);

        void addPtr();
        void deletPtr();
        void newPtr();
        void showPtr();
    };

#endif // INVENTARIO_HPP_INCLUDED
