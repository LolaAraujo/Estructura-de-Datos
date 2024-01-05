#include "Lista.hpp"
#include <fstream>

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

int Lista::compareByNameMusic(const Cancion& orig, const Cancion& copyc ) {
    return orig.getNameMusic().compare(copyc.getNameMusic());
    }

int Lista::compareByInterprete(const Cancion& orig, const Cancion& copyc) {
    return orig.getInterprete().compare(copyc.getInterprete());
    }

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

string Lista::findDatBin(Cancion& obj) const {
    int i=0, j(contLast), middle;
    string position="";
    char pos[3];

    while(i<=j) {
        middle = (i+j)/2;

        if(playList[middle].getNameMusic()==obj.getNameMusic() || playList[middle].getInterprete()==obj.getInterprete()) {
            if(i<10) {
                position = "0";
                }
            sprintf(pos, "%i", i);
            position += pos;
            position += playList[i].getMp3();
            return position;
            }
        if((obj.getNameMusic()<playList[middle].getNameMusic()&&obj.getNameMusic() != "") || (obj.getInterprete()<playList[middle].getInterprete()&&obj.getInterprete()!="")) {
            j = middle -1;
            }
        else {
            i = middle + 1;
            }
        }
    return "-1";
    }

void Lista::intercambia(Cancion& a, Cancion& b) {
    Cancion aux(a);
    a = b;
    b = aux;
    }

void Lista::bubbleSort(int com(const Cancion&, const Cancion&)) {
    int i(contLast), j;
    bool bandera;
    do {
        j=0;
        bandera = false;
        while(j<i) {
            if(com(playList[j],playList[j+1])>0) {
                intercambia(playList[j], playList[j+1]);

                bandera= true;
                }
            j++;
            }
        i--;
        }
    while(bandera);
    }

void Lista::insrtSort(int com(const Cancion&, const Cancion&)) {
    int i(1), j;
    Cancion obj;

    while(i<= contLast) {
        obj = playList[i];
        j=i;

        while(j>0 && com(obj, playList[j-1])<0) {
            playList[j] = playList[j-1];
            j--;
            }
        if(i!=j) {
            playList[j] = obj;
            }
        i++;
        }
    }

void Lista::selectSort(int com(const Cancion&, const Cancion&)) {
    int i(0), j, a;

    while(i<contLast) {
        a = i;
        j = i + 1;
        while(j<=contLast) {
            if(com(playList[j], playList[a])<0) {
                a = j;
                }
            j++;
            }
        if(i!=a) {
            intercambia(playList[i], playList[a]);
            }
        i++;
        }
    }

void Lista::shellSort(int com(const Cancion&, const Cancion&)) {
    float factor(1.0 / 2.0);
    int dif((contLast+1)*factor), i, j;

    while(dif>0) {
        i = dif;

        while(i<=contLast) {
            j=i;

            while(j>= dif && com(playList[j-dif],playList[j])>0) {
                intercambia(playList[j-dif], playList[j]);

                j-=dif;
                }
            i++;
            }
        dif*=factor;
        }
    }

///Escritura a disco
void Lista::writeToDisk(const string& fileName) {
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()) {
        cout << "No se puede abrir el archivo para escritura, writeToDisk";
        }

    int i(0);
    while(i <= contLast) {
        myFile << playList[i++] << endl;
        }
    myFile.close();
    }

///Lectura a disco
void Lista::readToDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()) {
        cout << "No se pudo abrir el archivo para lectura, readToDisk";
        }

    Cancion myData;
    try {
        while(myFile >> myData){
            insertMusic(getLastPosition(), myData);
            }
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        myFile.close();
        }

    myFile.close();
    }


string Lista::toString() const {
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
        listComplete += playList[i].toString1();
        listComplete += '\n';
        i++;
        }
    return listComplete;
    }


