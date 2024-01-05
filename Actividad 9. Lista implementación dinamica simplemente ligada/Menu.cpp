#include "Menu.hpp"

using namespace std;

Menu::Menu(Lista<Cancion> &viewList) {
    system("Color E5");
    visualizacion(viewList);
    }

void Menu::visualizacion(Lista<Cancion> &viewList) {
    int x=0, opc;
    Cancion music;
    string findSong, findinter, song;

    Lista<Cancion>::Position pos;

    while(x==0) {
        system("cls");

        cout<<viewList.toString();
        //readToDisk(viewList);

        cout<<"\n\n ---- Compu Radio ----"<<endl<<endl;
        cout<<"[1] Insertar Canciones "<<endl;
        cout<<"[2] Eliminar Canciones "<<endl;
        cout<<"[3] Recuperar Canciones "<<endl;
        cout<<"[4] Busqueda Lineal"<<endl;
        cout<<"[5] Leer Canciones del Disco"<<endl;
        cout<<"[6] Guardar Canciones del Disco"<<endl;
        cout<<"[7] Limpiar PlayList "<<endl;
        cout<<"[8] Salir"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                system("cls");
                submenu(viewList);
                break;

            case 2:
                system("cls");
                cin.ignore();
                cout<<"Cancion que desea eliminar: ";
                getline(cin, song);

                music.setNameMusic(song);
                pos = viewList.findDatLin(music, viewList.compareByNameMusic);
                cout<<endl<<"Eliminando..."<<endl<<endl;
                Sleep(2000);

                if(pos == nullptr) {
                    viewList.deleteData(pos);
                    cin.get();
                    }
                else {
                    cout<<"CANCION ELIMINADA"<<endl;
                    viewList.deleteData(pos);
                    Sleep(2000);
                    }
                break;

            case 3:
                system("cls");
                cin.ignore();
                cout<<"Cancion que desea recuperar: ";
                getline(cin, song);

                music.setNameMusic(song);
                pos = viewList.findDatLin(music, viewList.compareByNameMusic);
                cout<<endl<<"Buscando..."<<endl<<endl;
                Sleep(2000);

                if(pos == nullptr) {
                    viewList.retrieve(pos);
                    cin.get();
                    }
                else {
                    cout<<"\nCANCION ENCONTRADA"<<endl<<endl;
                    cout<<"CANCION: " <<endl<< viewList.retrieve(pos).toString()<<endl<<endl;
                    }
                system("PAUSE");
                break;

            ///Busqueda Lineal
            case 4:
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
                    pos = viewList.findDatLin(music, viewList.compareByNameMusic);

                    }
                else if(opc==2) {
                    cin.ignore();
                    cout<<"Interprete que desea buscar: "<<endl;
                    getline(cin, findinter);

                    music.setInterprete(findinter);
                    pos = viewList.findDatLin(music, viewList.compareByInterprete);

                    }
                else {
                    cout<<"Valor invalido"<<endl;
                    cin.get();
                    }
                if(pos == nullptr) {
                    cout<<"\nNo pudimos encontrar la cancion en la lista :("<<endl;
                    Sleep(2000);
                    }
                else {
                    Sleep(2000);
                    cout<<"\nREGISTRO ENCONTRADO \nEn la posicion "<< pos <<" del playlist"<<endl<<endl;
                    cout<<"Mp3: "<<viewList.retrieve(pos).getMp3()<<endl;
                    cin.get();
                    }
                break;

            case 5:
                readToDisk(viewList);
                //viewList.deleteAll();
                break;

            case 6:
                writeToDisk(viewList);
                //cout<<"HASTA LA PROXIMA!! :D"<<endl;
                //x+=1;
                break;

            default:
                cout<<"Ingresa solo valores que se te solicitan"<<endl;
                break;
            }
        //if(opc==6) {
          //  break;
            //}
        }
    }


void Menu::submenu(Lista<Cancion> &viewList) {
    int opc;
    char x;
    string song;
    Lista<Cancion>::Position pos;
    Cancion music;

    do {
        system("cls");
        cout<<"Elige en que lugar quieres insertar tus canciones"<<endl<<endl;
        cout<<"[1] Primer elemento de la lista "<<endl;
        cout<<"[2] Ultimo elemento de la lista "<<endl;
        cout<<"[3] Antes de cierta cancion de la lista "<<endl;
        cout<<"[4] Despues de cierta cancion de la lista "<<endl;
        cout<<"[5] Regresar al Menu Principal "<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                music = capture();
                viewList.insertData(viewList.getFirstPosition(), music);
                cout <<"Cancion agregada con exito :D"<<endl<<endl;
                break;

            case 2:
                music = capture();
                viewList.insertData(viewList.getLastPosition(), music);
                cout <<"Cancion agregada con exito :D"<<endl<<endl;
                break;

            case 3:
                cin.ignore();
                cout<<"Antes de cual cancion deseas ingresar otra cancion: ";
                getline(cin, song);

                music.setNameMusic(song);
                pos = viewList.findDatLin(music, viewList.compareByNameMusic);

                if(pos == nullptr) {
                    cout<<"NO EXISTE ESA CANCION\n"<<endl;
                    Sleep(2000);
                    }
                else {
                    cout<<"CANCION ENCONTRADA \n\n Inserte cancion:"<<endl;
                    music = capture();
                    viewList.insertData(viewList.getBeforePosition(pos), music);
                    cout <<"Cancion agregada con exito :D"<<endl<<endl;
                    }
                break;

            case 4:
                cin.ignore();
                cout<<"Despues de cual cancion deseas ingresar otra cancion: ";
                getline(cin, song);

                music.setNameMusic(song);
                pos = viewList.findDatLin(music, viewList.compareByNameMusic);

                if(pos == nullptr) {
                    cout<<"NO EXISTE ESA CANCION\n"<<endl;
                    Sleep(2000);
                    }
                else {
                    cout<<"CANCION ENCONTRADA \n\n Inserte cancion:"<<endl;
                    music = capture();
                    viewList.insertData(viewList.getNextPosition(pos), music);
                    cout <<"Cancion agregada con exito :D"<<endl<<endl;
                    }
                break;

            case 5:
                getchar();
                system("cls");
                visualizacion(viewList);
                x+=1;
                break;
            default:
                std::cout<<"Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }

        cout << "Desea insertar otra cancion? [y/n]: ";
        cin >> x;
        cin.ignore();
        }
    while(x == 'y');

    if(x == 'n'){
        cout<<"Guardar en el disco? [1]SI [2]NO"<<endl;
        cin >> opc;
        cin.ignore();

        if(opc==1){
            writeToDisk(viewList);
            cout<<":)"<<endl;
            getchar();
        }
    }
    }

Cancion Menu::capture() {
    string myStr;
    Cancion music;

    cin.ignore();
    cout<<"\nCancion: ";
    getline(cin, myStr);
    music.setNameMusic(myStr);

    cout<<"Autor: ";
    getline(cin, myStr);
    music.setAutor(myStr);

    cout<<"Interprete: ";
    getline(cin, myStr);
    music.setInterprete(myStr);

    cout<<"Ranking: ";
    getline(cin, myStr);
    music.setRanking(atof(myStr.c_str()));

    cout<<"MP3: ";
    getline(cin, myStr);
    music.setMp3(myStr);

    return music;

    }

void Menu::writeToDisk(Lista<Cancion>& viewList){
    cout<<"Escribiendo al disco..."<<endl;
    viewList.writeToDisk("Songs.txt");
    cout<<"Presione cualquier tecla para continuar."<<endl;
    system("PAUSE");
    system("cls");
}
void Menu::readToDisk(Lista<Cancion>& viewList){
    cout<<"Leyendo del disco..."<<endl;
    viewList.readToDisk("Songs.txt");
    //Sleep(2000);
    system("PAUSE");
    system("cls");
}
