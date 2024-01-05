#ifndef LISTCIRCULAR_HPP_INCLUDED
#define LISTCIRCULAR_HPP_INCLUDED
#include <string>
#include <iostream>
#include <exception>
#include <fstream>

template <class T>
class Lista {
    private:
        ///Clase anidada de NODO
        class Node {
            private:
                T data;
                Node* next;
            public:
                Node();
                Node(const T&);

                T getData() const;
                Node* getNext() const;

                void setData(const T&);
                void setNext(Node*);
            };

        Node *ancla;  //ancla con apuntador a nodo
        bool validPosition(Node*) const;
        void copyAll(const Lista<T>&);

    public:
        typedef Node* Position;

        ///CLASE DE EXCEPTION
        class Exception: public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception(const char* message): msg(message) {}
                explicit Exception(const std::string& message): msg(message) {}
                virtual ~Exception()throw() {}
                virtual const char* what() const throw() {
                    return msg.c_str();
                    }
            };


        ///CLASE LISTA
        Lista();
        Lista(const Lista<T>&);
        ~Lista();

        bool listVacia() const;

        void insertData(Node*, const T&);
        void deleteData(Node*);

        ///Posiciones de la lista: Primera, Última, Anterior y Siguiente
        Node* getFirstPosition() const;
        Node* getLastPosition() const;
        Node* getBeforePosition(Node*) const;
        Node* getNextPosition(Node*)  const;
        T retrieve(Node*) const;

        static int compareByNameMusic(const T&, const T&);
        static int compareByInterprete(const T&, const T&);

        ///Metodos de busqueda lineal
        Node* findDatLin(const T&,int (const T&,const T&)) const;
        void deleteAll();  ///Anula
        std::string toString() const;

        ///Disk
        void writeToDisk(const std::string&);
        void readToDisk(const std::string&);

        Lista<T>& operator = (const Lista<T>&);
    };

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using namespace std;
///Implementación NODO

template <class T>
Lista<T>::Node::Node() : next(nullptr) { }

template <class T>
Lista<T>::Node::Node(const T& m) : data(m), next(nullptr) { }

template <class T>
T Lista<T>::Node::getData() const {
    return data;
    }

template <class T>
//Lista:: pertenecia de tipo de dato
typename Lista<T>::Node* Lista<T>::Node::getNext() const {
    return next;
    }

template <class T>
void Lista<T>::Node::setData(const T& m) {
    data = m;
    }

template <class T>
void Lista<T>::Node::setNext(Node* pos) {
    next = pos;
    }

///Implementación LISTA
template <class T>
Lista<T>::Lista() : ancla(nullptr) { }

template <class T>
Lista<T>::Lista(const Lista& l) : ancla(nullptr) {
    copyAll(l);
    }

template <class T>
Lista<T>::~Lista() {
    deleteAll();
    }

template <class T>
void Lista<T>::copyAll(const Lista& l) {
    if(l.listVacia()) {
        return;
        }

    Node* aux(l.ancla);
    Node* last(nullptr);
    Node* newNode;

    do {
        newNode = new Node(aux->getData());
        if(newNode == nullptr) {
            throw Exception("Memoria no disponible");
            }

        if(last == nullptr) {
            ancla = newNode;
            }
        else {
            last->setNext(newNode);
            }

        last = newNode;
        aux = aux->getNext();
        }
    while(aux != l.ancla);
    last->setNext(ancla);
    }

///LISTA VACIA
template <class T>
bool Lista<T>::listVacia() const {
    return ancla == nullptr;
    }

template <class T>
bool Lista<T>::validPosition(Node* pos) const {
    if(!listVacia()) {
        Node* aux(ancla);

        do {
            if(aux==pos) {
                return true;
                }
            aux = aux->getNext();

            }
        while(aux != ancla);
        }
    return false;
    }

///METODO INSERTAR
template <class T>
void Lista<T>::insertData(Node* pos, const T& music) {
    if(pos != nullptr && !validPosition(pos)) {
        throw Exception("Posicion invalida, insertMusic");
        }

    Node* aux(new Node(music));

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, insertMusic");
        }

    ///Insertar al principio
    if(pos == nullptr) {
        if(listVacia()) { ///Primer nodo en ser insertado
            aux->setNext(aux);
            }
        else { ///Ya hay nodos
            aux->setNext(ancla);
            getLastPosition()->setNext(aux);
            }
        ancla = aux;
        }
    ///Insertar en cualquier otra posicion
    else {
        aux->setNext(pos->getNext());
        pos->setNext(aux);
        }
    }

///METODO ELIMINAR
template <class T>
void Lista<T>::deleteData(Node* pos) {
    if(listVacia()) {
        throw Exception("Insuficiencia de datos, deleteMusic");
        }

    if(!validPosition(pos)) {
        throw Exception("Posicion invalida, deleteMusic");
        }
    ///Eliminar el primero
    if(pos == ancla) {
        if(pos->getNext() == pos) { ///Solo queda un nodo en la lista
            ancla = nullptr;
            }
        else { ///Hay mas de un nodo
            getLastPosition()->setNext(ancla->getNext());

            ancla = ancla->getNext();
            }
        }
    else { ///Eliminar cualquier otro
        getBeforePosition(pos)->setNext(pos->getNext());
        }
    delete pos;
    }

///RECUPERAR
template <class T>
T Lista<T>::retrieve(Node* pos) const {
    if(listVacia()) {
        throw Exception("Insuficiencia de datos, retrieve");
        }
    if(!validPosition(pos)) {
        throw Exception("Cancion invalida, retrieve");
        }
    return pos->getData();
    }

///PRIMERA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getFirstPosition() const {
    return ancla;
    }

///ÚLTIMA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getLastPosition() const {
    if(listVacia()) {
        return nullptr;
        }

    Node* aux(ancla);

    while(aux->getNext() != ancla) {
        aux = aux->getNext();
        }
    return aux;
    }

///ANTES DE CIERTA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getBeforePosition(Node* pos) const {
    if(listVacia() || pos == ancla) {
        return nullptr;
        }

    Node* aux(ancla);

    do {
        if(aux->getNext()==pos) {
            return aux;
            }

        aux = aux->getNext();

        }
    while(aux != ancla);

    return nullptr;
    }

///DESPUÉS DE CIERTA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getNextPosition(Node* pos) const {
    if(!validPosition(pos) || pos->getNext() == ancla) {
        return nullptr;
        }
    return pos->getNext();
    }

template <class T>
Lista<T>& Lista<T>::operator=(const Lista& l) {
    deleteAll();
    copyAll(l);
    return *this;
    }

template <class T>
int Lista<T>::compareByNameMusic(const T& orig, const T& copyc ) {
    return orig.getNameMusic().compare(copyc.getNameMusic());
    }

template <class T>
int Lista<T>::compareByInterprete(const T& orig, const T& copyc) {
    return orig.getInterprete().compare(copyc.getInterprete());
    }

///Busqueda-Localiza
template <class T>
typename Lista<T>::Node* Lista<T>::findDatLin(const T& song, int com(const T&, const T&)) const {
    if(!listVacia()) {
        Node* aux(ancla);

        do {
            if(com(aux->getData(), song) == 0) {
                return aux;
                }

            aux= aux->getNext();
            }
        while(aux != ancla);
        }
    return nullptr;
    }

///Escritura a disco
template <class T>
void Lista<T>::writeToDisk(const string& fileName) {
    ofstream myFile;

    Node* aux(ancla);
    T data;

    myFile.open(fileName, ios_base::trunc);

    if(!myFile.is_open()) {
        throw Exception("No se puede abrir el archivo para escritura, writeToDisk");
        }

    while(aux != nullptr) {
        //myFile << aux->getData().toString();
        //aux = aux->getNext();
        data = aux->getData();
        myFile << data << endl;
        aux = aux->getNext();
        }
    myFile.close();
    }

///Lectura a disco
template <class T>
void Lista<T>::readToDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()) {
        throw Exception("No se pudo abrir el archivo para lectura, readToDisk");
        }

    deleteAll();
    T myData;
    try {
        while(myFile >> myData) { //!myFile.eof()
            insertData(getLastPosition(), myData);
            }
        }
    catch(Exception ex) {
        myFile.close();
        throw Exception(ex.what());
        }

    myFile.close();
    }

template<class T>
string Lista<T>::toString() const {
    string listComplete;
    if(!listVacia()) {
        Node* aux(ancla);

        listComplete += "CANCION";
        listComplete.resize(30,' ');
        listComplete += " || ";

        listComplete += "AUTOR";
        listComplete.resize(60,' ');
        listComplete += " || ";

        listComplete += "INTERPRETE";
        listComplete.resize(100,' ');
        listComplete += " || ";

        listComplete += "Ranking";
        listComplete.resize(113,' ');
        listComplete += " || ";

        listComplete += "MP3";
        listComplete += "\n\n\n";

        do {
            listComplete += aux->getData().toString() + "\n";
            aux = aux->getNext();
            }
        while(aux != ancla);
        }
    return listComplete;
    }

///ANULA LA LISTA
template <class T>
void Lista<T>::deleteAll() {
    if(listVacia()) {
        return;
        }

    Node* mark(ancla);
    Node* aux;

    do {
        aux=ancla;
        ancla = ancla->getNext();
        delete aux;
        }
    while(ancla != mark);

    ancla = nullptr;
    }

#endif // LISTCIRCULAR_HPP_INCLUDED
