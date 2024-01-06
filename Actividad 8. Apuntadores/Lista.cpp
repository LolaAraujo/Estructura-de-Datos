#include "Lista.hpp"

using namespace std;

Lista::Lista() {
    contLast = -1;
    int i=4999;
    while(i!=contLast) {
        playList[i]=nullptr;
        i--;
        }
    }

Lista::Lista(const Lista& l) {}

Lista::~Lista() {
    delete playList[contLast];
    playList[contLast] = nullptr;
    }

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
    return contLast == 4999;
    }

bool Lista::validPosition(const int& position) {
    return position >= 0 && position <= contLast;
    }

///METODO INSERTAR
void Lista::insertMusic(const int& position, const Cancion& music) {
    if(listFull()) {
        throw LolException("Desbordamiento de Datos");
        }
    else if(position != -1 && !validPosition(position)) {
        throw LolException("Posicion Invalida");
        playList[position] = nullptr;
        }

    int x(contLast);

    while(x>position) {
        playList[x+1]=playList[x];
        x--;
        }
    playList[position+1]= new Cancion;
    *playList[position+1]=music;
    contLast++;
    }

///METODO ELIMINAR
void Lista::deleteMusic(const int& position) {
    if(listVacia()) {
        throw LolException("Insuficiencia de Datos");
        }
    else if(!validPosition(position)) {
        throw LolException("Posicion Invalida");
        }

    int x(position);
    while(x<contLast) {
        playList[x]=playList[x+1];
        x++;
        }
    playList[x] = nullptr;
    delete playList[x];
    contLast--;
    }

///RECUPERAR
Cancion Lista::getRegain(const int& position) {
    if(!validPosition(position)) {
        throw LolException("Cancion invalida en la lista");
        }
    return *playList[position];
    }

///PRIMERA POSICIÓN
int Lista::getFirstPosition() {
    if(listVacia()) {
        return -1;
        }
    return 0;
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
void Lista::getNull() {
    int i(contLast);
    while(i==-1) {
        delete playList[i];
        i--;
        }
    playList[contLast] = nullptr;
    contLast = -1;
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

int Lista::findDatLin(const Cancion& song, int com(const Cancion&, const Cancion&)) const {
    int i=0;
    while(i<=contLast) {
        if(com(*playList[i], song)== 0) {
            return i;
            }
        i++;
        }
    return -1;
    }

int Lista::findDatBin(const Cancion& song, int com(const Cancion&, const Cancion&)) const {
    int i=0, j(contLast), m;
    while(i<=j) {
        m = (i+j)/2;
        if(com(song, *playList[m]) == 0) {
            return m;
            }
        if(com (song, *playList[m]) < 0) {
            j = m -1;
            }
        else {
            i = m + 1;
            }
        }
    return -1;
    }

void Lista::swapData(Cancion* a, Cancion* b) {
    Cancion aux;
    aux = *a;
    *a = *b;
    *b = aux;
    }

void Lista::bubbleSort(int com(const Cancion&, const Cancion&)) {
    int i(contLast), j;
    bool bandera;
    do {
        j=0;
        bandera = false;
        while(j<i) {
            if(com(*playList[j],*playList[j+1])>0) {
                swapData(playList[j], playList[j+1]);

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
        obj = *playList[i];
        j=i;

        while(j>0 && com(obj, *playList[j-1])<0) {
            playList[j] = playList[j-1];
            j--;
            }
        if(i!=j) {
            playList[j] = new Cancion;
            *playList[j] = obj;
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
            if(com(*playList[j], *playList[a])<0) {
                a = j;
                }
            j++;
            }
        if(i!=a) {
            swapData(playList[i], playList[a]);
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

            while(j>= dif && com(*playList[j-dif],*playList[j])>0) {
                swapData(playList[j-dif], playList[j]);

                j-=dif;
                }
            i++;
            }
        dif*=factor;
        }
    }

void Lista::mergeSort(int cmp(const Cancion&,const Cancion&)) {
    sortDataMerge(0, contLast, cmp);
    }

void Lista::quickSort(int cmp (const Cancion&,const Cancion&)) {
    sortDataQuick(0, contLast, cmp);
    }

void Lista::sortDataMerge(const int& leftEdg, const int& rightEdg, int cmp(const Cancion&,const Cancion&)) {
    ///Criterio de paso
    if(leftEdg>=rightEdg) {
        return;
        }

    ///Divide y venceras. Llamados recursivos
    int m((leftEdg+rightEdg)/2);
    sortDataMerge(leftEdg, m, cmp);
    sortDataMerge(m+1, rightEdg, cmp);

    ///Copy aux
    static Cancion* aux[5000];
    int n(leftEdg);

    while(n<=rightEdg) {
        aux[n] = new Cancion;
        aux[n] = playList[n];
        n++;
        }

    ///Intercalacion
    int i(leftEdg), j(m+1), x(leftEdg);

    while(i <= m && j <= rightEdg) {
        while(i <= m && cmp(*aux[i], *aux[j])<=0) {
            playList[x++] = aux[i++];
            }
        if(i<=m) {
            while(j <= rightEdg && cmp(*aux[j], *aux[i])<=0) {
                playList[x++] = aux[j++];
                }
            }
        }

    while(i<=m) {
        playList[x++] = aux[i++];
        }

    while(j <= rightEdg) {
        playList[x++] = aux[j++];
        }
    }

void Lista::sortDataQuick(const int& leftExt, const int& rightExt, int cmp(const Cancion&,const Cancion&)) {
    if(leftExt >= rightExt) {
        return;
        }

    ///Separación de parametros y ubicación del pivote
    int i(leftExt), j(rightExt);

    while(i < j) {
        while(i < j && cmp(*playList[i], *playList[rightExt])<=0) {
            i++;
            }
        while(i < j && cmp(*playList[j], *playList[rightExt])>=0) {
            j--;
            }
        if(i!=j) {
            swapData(playList[i], playList[j]);
            }
        }

    if(i != rightExt) {
        swapData(playList[i], playList[rightExt]);
        }

    sortDataQuick(leftExt, i-1, cmp);
    sortDataQuick(i+1, rightExt, cmp);
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
        listComplete += playList[i]->toString();
        listComplete += '\n';
        i++;
        }
    return listComplete;
    }


