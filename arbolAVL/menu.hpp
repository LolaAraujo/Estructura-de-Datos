#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include <string>
#include <random>
#include <chrono>
#include <iostream>
#include <windows.h>
#include <functional>
#include "arbolAVL.hpp"

class Menu {
    private:
        void view(ArbolAVL<int>&);
    public:
        Menu(ArbolAVL<int>&);
    };
#endif // MENU_HPP_INCLUDED
