#include "Lista.hpp"

using namespace std;

Lista::Lista(): contLast(-1) {} ///Inicialización

Lista::Lista(const Lista& element) {}

void Lista::copyAll(const Lista& lit) {
    int i=0;
    while(i <= lit.contLast) {
        playList[i] = lit.playList[i];

        i++;
        }
    contLast = lit.contLast;
    }

///LISTA VACIA
bool Lista::listVacia() {
    return contLast == -1;
    }

///LISTA LLENA
bool Lista::listFull() {
    return contLast == 49;
    }

bool Lista::validPosition(const int& position) {
    return position >= 0 && position <= contLast;
    }

///METODO INSERTAR
void Lista::insertMusic(const int& position, const Cancion& music) {
    int x=contLast;
    try {
        if(listFull()) {
            throw "Desbordamiento de Datos";
            }
        else if(position != -1 && !validPosition(position)) {
            throw ("Posicion Invalida");
            return;
            }
        else {

            while(x>position) {
                playList[x+1]=playList[x];
                x--;
                }
            playList[position+1]=music;
            }
        contLast++;
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        }
    }

///METODO ELIMINAR
void Lista::deleteMusic(const int& position) {
    int x(position);
    try {
        if(listVacia()) {
            throw "Insuficiencia de Datos";
            }
        else if(!validPosition(position)) {
            throw "Posicion Invalida";
            }
        else {
            while(x<contLast) {
                playList[x]=playList[x+1];
                x++;
                }
            contLast--;
            }
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        }
    }

///RECUPERAR
string Lista::getRegain(const int& position) {
    try {
        if(!validPosition(position)) {
            throw "Cancion invalida en la lista";
            }
        //return playList[position].toString1();
        }
    catch(const char *error) {
        cout<<error<<endl;
        }
    return playList[position].toString1();
    }

///PRIMERA POSICIÓN
int Lista::getFirstPosition() {
    if(listVacia()) {
        return -1;
        }
    return -1;
    }

///ÚLTIMA POSICIÓN
int Lista::getLastPosition() {
    return contLast;
    }

///ANTES DE CIERTA POSICIÓN
int Lista::getBeforePosition(const int& position) {
    if(position == getFirstPosition() && !validPosition(position)) {
        return -1;
        }
    return position-1;
    }

///DESPUÉS DE CIERTA POSICIÓN
int Lista::getNextPosition(const int& position) {
    if(position == getLastPosition() && !validPosition(position)) {
        return -1;
        }
    return position;
    }

///ANULAR/LIMPIAR LISTA
int Lista::getNull() {
    contLast=-1;
    return contLast;
    }

Lista& Lista::operator=(const Lista& lit) {
    copyAll(lit);
    return *this;
    }

int Lista::compareByNameMusic(const Cancion&, const Cancion&) {}

int Lista::compareByInterprete(const Cancion&, const Cancion&) {}

string Lista::findDatLin(Cancion& obj) const {
    int i=0;
    string position="";
    char pos[3];

    while(i<=contLast) {
        if(playList[i].getNameMusic() == obj.getNameMusic() || playList[i].getInterprete() == obj.getInterprete()) {
            if(i<10) {
                position = "0";
                }
            sprintf(pos, "%i", i);
            position += pos;
            position += playList[i].getMp3();
            return position;
            }
        i++;
        }
    return "-1";
    }

int Lista::findDatBin(const Cancion& obj) const {
    int i=0, j= contLast, middle;
    while(i<=j) {
        middle = (i+j)/2;
        if(playList[middle]==obj) {
            return i;
            }
        if(obj < playList[middle]) {
            j = middle -1;
            }
        else {
            i = middle + 1;
            }
        }
    return -1;
    }

void Lista::bubbleSort(const Cancion&) const {

    }

void Lista::insrtSort(const Cancion&) const {

    }

void Lista::selectSort(const Cancion&) const {

    }

void Lista::shellSort(const Cancion&) const {

    }


string Lista::toString() const{
    int i=0;
    string listComplete;

    listComplete += "CANCION";
    listComplete.resize(30,' ');
    listComplete += " || ";

    listComplete += "AUTOR";
    listComplete.resize(60,' ');
    listComplete += " || ";

    listComplete += "INTERPRETE";
    listComplete.resize(80,' ');
    listComplete += " || ";

    listComplete += "Ranking";
    listComplete.resize(93,' ');
    listComplete += " || ";

    listComplete += "MP3";
    listComplete += "\n\n";

    while(i<=contLast) {
        //sprintf(tam, "%i", i);
        //listComplete += tam;
        //listComplete += ". ";
        listComplete += playList[i].toString1();
        listComplete += '\n';
        i++;
        }
    return listComplete;
    }


