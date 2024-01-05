#ifndef MAINMENU_HPP_INCLUDED
#define MAINMENU_HPP_INCLUDED
#include <iomanip>
#include <iostream>
#include "Lista.hpp"
#include "Cancion.hpp"

class Menu {
    private:
        int opc;
        Lista viewList;
        Cancion music;
        Lista findMusic;
    public:

        int getOpc() const;
        void setOpc(const int&);
        void visualizacion();
        void submenu();
        void submenuFind();
        void capture();
    };

#endif // MAINMENU_HPP_INCLUDED
