#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <windows.h>
#include <functional>
#include "arbolBinario.hpp"

class Menu {
    private:
        void view(ArbolB<int>&);
    public:
        Menu(ArbolB<int>&);
    };
#endif // MENU_HPP_INCLUDED
