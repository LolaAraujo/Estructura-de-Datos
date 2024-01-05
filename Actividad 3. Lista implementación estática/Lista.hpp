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
        int findDatBin(const Cancion& ) const;
        void bubbleSort(const Cancion&) const;
        void insrtSort(const Cancion&) const;
        void selectSort(const Cancion&) const;
        void shellSort(const Cancion&) const;

        Lista& operator = (const Lista&);

        std::string toString() const;
    };

#endif // LISTA_HPP_INCLUDED
