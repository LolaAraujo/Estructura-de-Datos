#ifndef MAINMENU_HPP_INCLUDED
#define MAINMENU_HPP_INCLUDED

#include "inventario.hpp"
#include <iostream>

class Menu {
    private:
        int opc;

        Inventario selec;
    public:

        int getOpc() const;
        void setOpc(const int&);
        void visualizacion();

    };

#endif // MAINMENU_HPP_INCLUDED
