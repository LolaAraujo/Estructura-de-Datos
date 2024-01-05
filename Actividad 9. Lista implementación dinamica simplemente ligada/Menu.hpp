#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include <iostream>
//#include "ListCircular.hpp"
#include "Lista.hpp"
#include "Cancion.hpp"
#include <windows.h>

class Menu {
    private:
        void visualizacion(Lista<Cancion>&);
        void submenu(Lista<Cancion>&);
        void writeToDisk(Lista<Cancion>&);
        void readToDisk(Lista<Cancion>&);
        Cancion capture();
    public:
        Menu(Lista<Cancion>&);
    };

#endif // MENU_HPP_INCLUDED
