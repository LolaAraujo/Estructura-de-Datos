#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include <string>
#include <iostream>
#include <exception>
#include "Cancion.hpp"
#include "LolException.hpp"
#define MAXIMO 5000

class Lista {
    private:
        int contLast;
        Cancion* playList[MAXIMO];
        bool validPosition(const int&);
        void copyAll(const Lista&);
        void swapData(Cancion*, Cancion*);
        void sortDataMerge(const int&, const int&, int (const Cancion&, const Cancion&));
        void sortDataQuick(const int&, const int&, int (const Cancion&, const Cancion&));
    public:
        Lista(); ///Inicialización de la lista
        ~Lista();
        Lista(const Lista&);

        bool listVacia();  ///Función de lista Vacia
        bool listFull();   ///Función de lista llena

        static int compareByNameMusic(const Cancion&, const Cancion&);
        static int compareByInterprete(const Cancion&, const Cancion&);

        ///Posiciones de la lista: Primera, Última, Anterior, Siguiente y Nula
        int getFirstPosition();
        int getLastPosition();
        int getBeforePosition(const int&);
        int getNextPosition(const int&);
        void getNull();

        void insertMusic(const int&, const Cancion&);
        void deleteMusic(const int&); /// recibe la posición
        Cancion getRegain(const int&); ///Recupera elemento de la lista

        ///Metodos de busqueda lineal y binario
        int findDatLin(const Cancion&,int (const Cancion&,const Cancion&)) const;
        int findDatBin(const Cancion&,int (const Cancion&,const Cancion&)) const;


        ///Metodos de ordenamiento
        void bubbleSort(int (const Cancion&,const Cancion&));
        void insrtSort(int (const Cancion&, const Cancion&));
        void selectSort(int (const Cancion&, const Cancion&));
        void shellSort(int (const Cancion&, const Cancion&));
        void mergeSort(int (const Cancion&,const Cancion&));
        void quickSort(int (const Cancion&,const Cancion&));

        Lista& operator = (const Lista&);

        std::string toString() const;
    };

#endif // LISTA_HPP_INCLUDED
