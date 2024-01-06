#ifndef MAINMENU_HPP_INCLUDED
#define MAINMENU_HPP_INCLUDED
#include <iomanip>
#include <iostream>
#include "Lista.hpp"
#include "Cancion.hpp"
#include <windows.h>

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
        void capture();
        void ordenamientos();
    };

#endif // MAINMENU_HPP_INCLUDED
