#ifndef MAINMENU_HPP_INCLUDED
#define MAINMENU_HPP_INCLUDED

#include <iostream>
#include "Lista.hpp"
#include "Cancion.hpp"

class Menu {
    private:
        int opc;
        Lista viewList;
        Cancion music;
    public:

        int getOpc() const;
        void setOpc(const int&);
        void visualizacion();
        void submenu();
    };

#endif // MAINMENU_HPP_INCLUDED
