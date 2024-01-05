#include "mainMenu.hpp"

int Menu::getOpc() const {
    return opc;
    }

void Menu::setOpc(const int& nu) {
    opc=nu;
    }


void Menu::visualizacion() {
    int x=0;
    while(x==0) {
        system("cls");

        std::cout<<"ALMACENES LOLITA"<<std::endl<<std::endl;
        std::cout<<"[1] Ingresar nuevo producto"<<std::endl;
        std::cout<<"[2] Aumentar inventario del producto"<<std::endl;
        std::cout<<"[3] Eliminar inventario del producto"<<std::endl;
        std::cout<<"[4] Imprimir Inventario Total"<<std::endl;
        std::cout<<"[5] Salir"<<std::endl;
        std::cin>>opc;

        switch(opc) {
            case 1:
                system("cls");
                selec.newPtr();
                getchar();
                break;
            case 2:
                system("PAUSE()");
                system("cls");
                selec.addPtr();
                break;
            case 3:
                system("PAUSE()");
                system("cls");
                selec.deletPtr();
                break;
            case 4:
                system("PAUSE()");
                system("cls");
                selec.showPtr();
                break;
            case 5:
                getchar();
                system("cls");
                std::cout<<"HASTA LA PROXIMA!! :D"<<std::endl;
                x+=1;
                break;
            default:
                std::cout<<"Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }
        }
    }

