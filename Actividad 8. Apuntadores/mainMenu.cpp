#include "mainMenu.hpp"

using namespace std;

int Menu::getOpc() const {
    return opc;
    }

void Menu::setOpc(const int& num) {
    opc=num;
    }

void Menu::visualizacion() {
    system("Color E5");
    int x=0, val;
    string findSong, findinter, m;

    while(x==0) {
        system("cls");

        cout<<viewList.toString();  ///INICIALIZACIÓN DE LA LISTA

        cout<<"\n\n ---- Compu Radio ----"<<endl<<endl;
        cout<<"[1] Insertar Canciones "<<endl;
        cout<<"[2] Eliminar Canciones "<<endl;
        cout<<"[3] Recuperar Canciones "<<endl;
        cout<<"[4] Limpiar PlayList "<<endl;
        cout<<"[5] Busqueda Lineal"<<endl;
        cout<<"[6] Busqueda Binaria"<<endl;
        cout<<"[7] Ordenamiento de Canciones"<<endl;
        cout<<"[8] Salir"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                system("cls");
                submenu();
                break;

            case 2:
                system("cls");
                cout<<"Posicion de la cancion que quiere eliminar: ";
                cin>>val;
                cin.get();
                viewList.deleteMusic(val);
                break;

            case 3:
                system("cls");
                cout<<"Posicion de la cancion a recuperar: ";
                cin>>val;
                cout<<viewList.getRegain(val).toString()<<endl;
                system("PAUSE");
                break;

            case 4:
                viewList.getNull();
                break;

            ///Busqueda Lineal
            case 5:
                system("cls");
                cin.get();
                cout<<"Busqueda Lineal"<<endl;
                cout<<"[1] Busqueda por Cancion"<<endl;
                cout<<"[2] Busqueda por Interprete"<<endl;
                cin>>opc;

                if(opc==1) {
                    cin.ignore();
                    cout<<"\nCancion que desea buscar: "<<endl;
                    getline(cin, findSong);
                    music.setNameMusic(findSong);
                    val = viewList.findDatLin(music, viewList.compareByNameMusic);

                    }
                else if(opc==2) {
                    cin.ignore();
                    cout<<"Interprete que desea buscar: "<<endl;
                    getline(cin, findinter);

                    music.setInterprete(findinter);
                    val = viewList.findDatLin(music, viewList.compareByInterprete);

                    }
                else {
                    cout<<"Valor invalido"<<endl;
                    cin.get();
                    }
                if(val == -1) {
                    cout<<"\nLa cancion no se encuentra en la lista :("<<endl;
                    cin.get();
                    }
                else {
                    cout<<"\nREGISTRO ENCONTRADO \nEn la posicion "<< val+1 <<" del playlist"<<endl;;
                    cout<<"Mp3: "<<viewList.getRegain(val).getMp3();
                    cin.get();
                    }
                break;

            ///Busqueda Binaria
            case 6:
                system("cls");
                cin.get();
                cout<<"Busqueda Binaria"<<endl;
                cout<<"[1] Busqueda por Cancion"<<endl;
                cout<<"[2] Busqueda por Interprete"<<endl;
                cin>>opc;

                if(opc==1) {
                    cin.ignore();
                    cout<<"\nCancion que desea buscar: "<<endl;
                    getline(cin, findSong);
                    music.setNameMusic(findSong);
                    val = viewList.findDatBin(music, viewList.compareByNameMusic);

                    }
                else if(opc==2) {
                    cin.ignore();
                    cout<<"Interprete que desea buscar: "<<endl;
                    getline(cin, findinter);
                    music.setInterprete(findinter);
                    val = viewList.findDatBin(music, viewList.compareByInterprete);

                    }
                else {
                    cout<<"Valor invalido"<<endl;
                    cin.get();
                    }
                if(val == -1) {
                    cout<<"\nLa cancion no se encuentra en la lista :("<<endl;
                    cin.get();
                    }
                else {
                    cout<<"\nREGISTRO ENCONTRADO \nEn la posicion "<< val+1 <<" del playlist"<<endl;
                    cout<<"Mp3: "<<viewList.getRegain(val).getMp3();
                    cin.get();

                    }
                break;

            case 7:
                ordenamientos();
                break;

            case 8:
                cout<<"HASTA LA PROXIMA!! :D"<<endl;
                x+=1;
                break;

            default:
                cout<<"Ingresa solo valores que se te solicitan"<<endl;
                break;
            }
        if(opc==8) {
            break;
            }
        }
    }


void Menu::submenu() {
    int x=0, val;
    while(x==0) {
        system("cls");

        cout<<"[1] En Primera Posicion "<<endl;
        cout<<"[2] En Ultima Posicion "<<endl;
        cout<<"[3] En Posicion Anterior "<<endl;
        cout<<"[4] En Posicion Despues "<<endl;
        cout<<"[5] Regresar al Menu Principal"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                capture();
                viewList.insertMusic(viewList.getFirstPosition(), music);
                break;

            case 2:
                capture();
                viewList.insertMusic(viewList.getLastPosition(), music);
                break;

            case 3:
                cin.ignore();
                cout<<"\nPosicion: ";
                cin>>val;
                capture();
                viewList.insertMusic(viewList.getBeforePosition(val-1), music);
                break;

            case 4:
                cout<<"\nPosicion: ";
                cin>>val;
                capture();
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

void Menu::ordenamientos() {
    int select, a=0;

    while(a==0) {
        system("cls");
        cout<<"Antes de continuar, escoga una manera de ordenar:"<<endl;
        cout<<"[1] Por Cancion"<<endl;
        cout<<"[2] Por Interprete"<<endl;
        cout<<"[3] Regresar"<<endl;
        cin>>opc;

        if(opc==3) visualizacion();
        cout<<"\n\nEscoge el Metodo de Ordenacion"<<endl;
        cout<<"[1] BubbleSort"<<endl;
        cout<<"[2] InsertSort"<<endl;
        cout<<"[3] SelectSort"<<endl;
        cout<<"[4] ShellSort"<<endl;
        cout<<"[5] MergeSort"<<endl;
        cout<<"[6] QuickSort"<<endl;
        cout<<"[7] Regresar a Menu Principal"<<endl;
        cin>>select;

        switch(select) {
            case 1:
                if(opc==1) {
                    viewList.bubbleSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.bubbleSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 2:
                if(opc==1) {
                    viewList.insrtSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.insrtSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 3:
                if(opc==1) {
                    viewList.selectSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.selectSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 4:
                if(opc==1) {
                    viewList.shellSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.shellSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 5:
                if(opc==1) {
                    viewList.mergeSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.mergeSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 6:
                if(opc==1) {
                    viewList.quickSort(viewList.compareByNameMusic);
                    }
                else {
                    viewList.quickSort(viewList.compareByInterprete);
                    }
                cout<<"\n\n ORDENAMIENTO REALIZADO CON EXITO!!"<<endl;
                Sleep(2000);
                break;

            case 7:
                cin.get();
                system("cls");
                visualizacion();
                a+=1;
                break;
            default:
                std::cout<<"Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }
        }
    }

void Menu::capture() {
    string auxCanc, auxAutor, auxInter, auxMp3;
    int auxRanking;

    cout<<"\nCancion: ";
    cin.ignore();
    getline(cin, auxCanc);

    cout<<"Autor: ";
    getline(cin, auxAutor);

    cout<<"Interprete: ";
    getline(cin, auxInter);

    cout<<"Ranking: ";
    cin>>auxRanking;

    cout<<"MP3: ";
    cin.ignore();
    getline(cin, auxMp3);

    music.setNameMusic(auxCanc);
    music.setAutor(auxAutor);
    music.setInterprete(auxInter);
    music.setRanking(auxRanking);
    music.setMp3(auxMp3);

    }
