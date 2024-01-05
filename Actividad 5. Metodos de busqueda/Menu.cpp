#include "mainMenu.hpp"

using namespace std;

int Menu::getOpc() const {
    return opc;
    }

void Menu::setOpc(const int& num) {
    opc=num;
    }

void Menu::visualizacion() {
    int x=0, val;
    while(x==0) {
        system("cls");

        cout<<viewList.toString();  ///INICIALIZACIÓN DE LA LISTA

        cout<<"\n\n ---- Compu Radio ----"<<endl<<endl;
        cout<<"[1] Insertar Canciones "<<endl;
        cout<<"[2] Eliminar Canciones "<<endl;
        cout<<"[3] Recuperar Canciones "<<endl;
        cout<<"[4] Limpiar PlayList "<<endl;
        cout<<"[5] Salir"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                system("cls");
                getchar();
                submenu();
                break;

            case 2:
                system("cls");
                cout<<"Posicion de la cancion que quiere eliminar: ";
                cin>>val;
                getchar();
                viewList.deleteMusic(val);
                break;

            case 3:
                system("cls");
                cout<<"Posicion de la cancion a recuperar: ";
                cin>>val;
                cout<<viewList.getRegain(val)<<endl;
                system("PAUSE");
                break;

            case 4:
                viewList.getNull();
                break;

            case 5:
                cout<<"HASTA LA PROXIMA!! :D"<<endl;
                x+=1;
                break;

            default:
                cout<<"Ingresa solo valores que se te solicitan"<<endl;
                break;
            }
        if(opc==5) {
            break;
            }
        }
    }

void Menu::submenu() {
    int x=0, val;
    string auxCanc, auxAutor, auxInter;
    while(x==0) {
        system("cls");

        viewList.toString();

        cout<<"[1] En Primera Posicion "<<endl;
        cout<<"[2] En Ultima Posicion "<<endl;
        cout<<"[3] En Posicion Anterior "<<endl;
        cout<<"[4] En Posicion Despues "<<endl;
        cout<<"[5] Regresar al Menu Principal"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                cout<<"\n\nCancion: ";
                cin.ignore();
                getline(cin, auxCanc);

                cout<<"Autor: ";
                getline(cin, auxAutor);

                cout<<"Interprete: ";
                getline(cin, auxInter);

                music.setNameMusic(auxCanc);
                music.setAutor(auxAutor);
                music.setInterprete(auxInter);

                getchar();
                viewList.insertMusic(viewList.getFirstPosition(), music);
                break;

            case 2:
                cout<<"\n\nCancion: ";
                cin.ignore();
                getline(cin, auxCanc);

                cout<<"Autor: ";
                getline(cin, auxAutor);

                cout<<"Interprete: ";
                getline(cin, auxInter);

                music.setNameMusic(auxCanc);
                music.setAutor(auxAutor);
                music.setInterprete(auxInter);

                getchar();
                viewList.insertMusic(viewList.getLastPosition(), music);
                break;

            case 3:
                cin.ignore();
                cout<<"Posicion: ";
                cin>>val;

                cout<<"\nCancion: ";
                cin.ignore();
                getline(cin, auxCanc);

                cout<<"Autor: ";
                getline(cin, auxAutor);

                cout<<"Interprete: ";
                getline(cin, auxInter);

                music.setNameMusic(auxCanc);
                music.setAutor(auxAutor);
                music.setInterprete(auxInter);

                getchar();
                viewList.insertMusic(viewList.getBeforePosition(val-1), music);
                break;

            case 4:
                cout<<"\n Posicion: ";
                cin>>val;

                cout<<"\nCancion: ";
                cin.ignore();
                getline(cin, auxCanc);

                cout<<"Autor: ";
                getline(cin, auxAutor);

                cout<<"Interprete: ";
                getline(cin, auxInter);

                music.setNameMusic(auxCanc);
                music.setAutor(auxAutor);
                music.setInterprete(auxInter);

                getchar();
                viewList.insertMusic(viewList.getNextPosition(val), music);
                break;

            case 5:
                getchar();
                system("cls");
                visualizacion();
                x+=1;
                break;
            default:
                std::cout<<"Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }
        }
    }
