#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED

#include <string>
#include <iostream>
#include <exception>
#include "Cancion.hpp"
#define MAXIMO 50

class Lista {
    private:
        int contLast;
        Cancion playList[MAXIMO];
        bool validPosition(const int&);
        void copyAll(const Lista&);
        void intercambia(Cancion&,Cancion&);
    public:
        Lista(); ///Inicialización de la lista
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
        int getNull();

        void insertMusic(const int&, const Cancion&);
        void deleteMusic(const int&); /// recibe la posición
        std::string getRegain(const int&); ///Recupera elemento de la lista

        ///Metodos de busqueda lineal y binario
        std::string findDatLin(Cancion& ) const;
        std::string findDatBin(Cancion& ) const;

        ///Metodos de ordenamiento
        void bubbleSort(int (const Cancion&,const Cancion&));
        void insrtSort(int (const Cancion&, const Cancion&));
        void selectSort(int (const Cancion&, const Cancion&));
        void shellSort(int (const Cancion&, const Cancion&));
        void writeToDisk(const std::string&);
        void readToDisk(const std::string&);

        Lista& operator = (const Lista&);

        std::string toString() const;
    };

#endif // LISTA_HPP_INCLUDED
