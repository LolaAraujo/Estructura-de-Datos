#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED
#include <iostream>
#include <string>

template<class L, int ARRAY=100000>
class Lista {

    private:
        L data[ARRAY];
        int contLast;
        bool validPosition(const int&);
        void copyAll(const Lista<L, ARRAY>&);

        void swapData(L&, L&);
        void sortDataMerge(const int&, const int&);
        void sortDataQuick(const int&, const int&);

    public:
        Lista();
        Lista(const Lista<L, ARRAY>&);

        bool listVacia();
        bool listFull();
        bool isSorted() const;

        void insertList(const int&, const L&);
        void deletelist(const int&);

        ///Posiciones de la lista: Primera, Última, Anterior, Siguiente y Nula
        int getFirstPosition();
        int getLastPosition();
        int getBeforePosition(const int&);
        int getNextPosition(const int&);

        ///Metodos de busqueda lineal y binario
        int findDatLin(const L&);
        int findDatBin(const L&);

        L retrieve(const int&);

        friend std::iostream& operator >> (std::iostream&, const L&);
        friend std::ostream& operator << (std::ostream&, const L&);
        std::string toString();

        ///Metodos de ordenamiento
        void bubbleSort();
        void insrtSort();
        void selectSort();
        void shellSort();
        void mergeSort();
        void quickSort();

        Lista<L, ARRAY>& operator = (const Lista<L, ARRAY>&);
    };
#endif // LISTAA_HPP_INCLUDED

///IMPLEMENTACIÓN
using namespace std;

template<class L,int ARRAY>
void Lista<L, ARRAY>::copyAll(const Lista<L,ARRAY>& obj) {
    int i=0;
    while(i <= obj.contLast) {
        data[i] = obj.data[i];

        i++;
        }
    contLast = obj.contLast;
    }

template<class L, int ARRAY>
void Lista<L,ARRAY>::swapData(L& a, L& b) {
    L aux(a);
    a = b;
    b = aux;
    }

template<class L,int ARRAY>
Lista<L, ARRAY>::Lista() : contLast(-1) { }

template<class L,int ARRAY>
Lista<L, ARRAY>::Lista(const Lista<L,ARRAY>& obj) { }

template<class L, int ARRAY>
bool Lista<L,ARRAY>::listVacia() {
    return contLast == -1;
    }

template<class L, int ARRAY>
bool Lista<L,ARRAY>::listFull() {
    return contLast == 999999;
    }

template<class L, int ARRAY>
bool Lista<L,ARRAY>::isSorted() const {
    int i(0), j(contLast);
    bool flag;
    while(i < j) {
        if(data[i]<=data[i+1]) {
            flag = true;
            }
        else {
            return false;
            }
        i++;
        }
    return true;
    }

template<class L, int ARRAY>
bool Lista<L, ARRAY>::validPosition(const int& position) {
    return position >= 0 && position <= contLast;
    }

///METODO INSERTAR
template<class L, int ARRAY>
void Lista<L,ARRAY>::insertList(const int& position, const L& obj) {
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
                data[x+1]=data[x];
                x--;
                }
            data[position+1]= obj;
            }
        contLast++;
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        }
    }

///METODO ELIMINAR
template<class L, int ARRAY>
void Lista<L, ARRAY>::deletelist(const int& position) {
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
                data[x]=data[x+1];
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
template<class L, int ARRAY>
L Lista<L, ARRAY>::retrieve(const int& position) {
    try {
        if(!validPosition(position)) {
            throw "Posicion invalida en la lista";
            }
        }
    catch(const char *error) {
        cout<<error<<endl;
        }
    return data[position];
    }

///PRIMERA POSICIÓN
template<class L, int ARRAY>
int Lista<L, ARRAY>::getFirstPosition() {
    if(listVacia()) {
        return -1;
        }
    return -1;
    }

///ÚLTIMA POSICIÓN
template<class L, int ARRAY>
int Lista<L, ARRAY>::getLastPosition() {
    return contLast;
    }

///ANTES DE CIERTA POSICIÓN
template<class L, int ARRAY>
int Lista<L, ARRAY>::getBeforePosition(const int& position) {
    if(position == getFirstPosition() && !validPosition(position)) {
        return -1;
        }
    return position-1;
    }

///DESPUÉS DE CIERTA POSICIÓN
template<class L, int ARRAY>
int Lista<L,ARRAY>::getNextPosition(const int& position) {
    if(position == getLastPosition() && !validPosition(position)) {
        return -1;
        }
    return position;
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::bubbleSort() {
    int i(contLast), j;
    bool flag;
    do {
        j=0;
        flag = false;
        while(j<i) {
            if(data[j]>data[j+1]) {
                swapData(data[j], data[j+1]);
                flag= true;
                }
            j++;
            }
        i--;
        }
    while(flag);
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::insrtSort() {
    int i(1), j;
    L aux;

    while(i<= contLast) {
        aux = data[i];
        j=i;

        while(j>0 && aux < data[j-1]) {
            data[j] = data[j-1];
            j--;
            }
        if(i!=j) {
            data[j] = aux;
            }
        i++;
        }
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::selectSort() {
    int i(0), j, m;

    while(i<contLast) {
        m = i;
        j = i + 1;
        while(j<=contLast) {
            if(data[j] < data[m]) {
                m = j;
                }
            j++;
            }
        if(i!=m) {
            swapData(data[i], data[m]);
            }
        i++;
        }
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::shellSort() {
    float factor(1.0 / 2.0);
    int dif((contLast+1)*factor), i, j;

    while(dif>0) {
        i = dif;

        while(i<=contLast) {
            j=i;

            while(j>= dif && data[j-dif] > data[j]) {
                swapData(data[j-dif], data[j]);
                j-=dif;
                }
            i++;
            }
        dif*=factor;
        }
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::mergeSort() {
    sortDataMerge(0, contLast);
    }

template<class L, int ARRAY>
void Lista<L, ARRAY>::sortDataMerge(const int& leftEdg, const int& rightEdg) {
    ///Criterio de paso
    if(leftEdg>=rightEdg) {
        return;
        }

    ///Divide y venceras. Llamados recursivos
    int m((leftEdg+rightEdg)/2);
    sortDataMerge(leftEdg, m);
    sortDataMerge(m+1, rightEdg);

    ///Copy aux
    static L aux[ARRAY];
    int n(leftEdg);

    while(n<=rightEdg) {
        aux[n] = data[n];
        n++;
        }

    ///Intercalacion
    int i(leftEdg), j(m+1), x(leftEdg);

    while(i <= m && j <= rightEdg) {
        while(i <= m && aux[i] <= aux[j]) {
            data[x++] = aux[i++];
            }
        if(i<=m) {
            while(j <= rightEdg && aux[j] <= aux[i]) {
                data[x++] = aux[j++];
                }
            }
        }

    while(i<=m) {
        data[x++] = aux[i++];
        }

    while(j <= rightEdg) {
        data[x++] = aux[j++];
        }
    }

template<class L,int ARRAY>
void Lista<L, ARRAY>::quickSort() {
    sortDataQuick(0, contLast);
    }

template<class L, int ARRAY>
void Lista<L, ARRAY>::sortDataQuick(const int& leftExt, const int& rightExt) {
    if(leftExt >= rightExt) {
        return;
        }

    ///Separación de parametros y ubicación del pivote
    int i(leftExt), j(rightExt);

    while(i < j) {
        while(i < j && data[i] <= data[rightExt]) {
            i++;
            }
        while(i < j && data[j] >= data[rightExt]) {
            j--;
            }
        if(i!=j) {
            swapData(data[i], data[j]);
            }
        }

    if(i != rightExt) {
        swapData(data[i], data[rightExt]);
        }

    sortDataQuick(leftExt, i-1);
    sortDataQuick(i+1, rightExt);

    }

template<class L, int ARRAY>
std::iostream& operator >> (std::iostream& is, const L& obj) {
    is >> obj.data;
    return is;
    }

template<class L, int ARRAY>
std::ostream& operator << (std::ostream& os, const L& obj) {
    os << obj.data;
    return os;
    }

template<class L, int ARRAY>
Lista<L, ARRAY>& Lista<L,ARRAY>::operator = (const Lista<L, ARRAY>& obj) {
    copyAll(obj);
    return *this;
    }

template<class L,int ARRAY>
string Lista<L, ARRAY>::toString() {
    string listComplete;
    int i=0;
    while(i<=contLast) {
        listComplete += data[i];
        listComplete += '\n';
        i++;
        }
    return listComplete;
    }

