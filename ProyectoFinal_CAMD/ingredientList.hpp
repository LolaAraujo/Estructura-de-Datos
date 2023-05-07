#ifndef INGREDIENTLIST_HPP_INCLUDED
#define INGREDIENTLIST_HPP_INCLUDED
#include <string>
#include <iostream>
#include <fstream>

template <class T>
class ListIngredient {
    private:
        ///Clase anidada de NODO
        class Node {
            private:
                T data;
                Node* next;
            public:
                Node();
                Node(const T&);

                T& getData();
                Node* getNext() const;

                void setData(const T&);
                void setNext(Node*);
            };

        Node *anchor;  //ancla con apuntador a nodo
        bool validPosition(Node*) const;
        void copyAll(const ListIngredient<T>&);

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

        ListIngredient();
        ListIngredient(const ListIngredient<T>&);
        ~ListIngredient();

        bool isEmpty();
        bool isSorted() const;

        void insertData(Node*, const T&);
        void insertSortData(T&);
        void deleteData(Node*);
        std::string category(const T&, int (const T&,const T&));
        T& retrieve(Node*&);

        Node* getFirstPosition();
        Node* getLastPosition();
        Node* getBeforePosition(Node*) const;
        Node* getNextPosition(Node*) const;

        static int compareByNameIngr(const T&, const T&);

        Node* findDatLin(const T&,int (const T&,const T&)) const;

        std::string toString() const;
        void deleteAll();
        void writeFromDisk(const std::string&);
        void readFromDisk(const std::string&);

        ListIngredient<T>& operator = (const ListIngredient<T>&);
    };

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using namespace std;
///Implementación NODO

template <class T>
ListIngredient<T>::Node::Node() : next(nullptr) { }

template <class T>
ListIngredient<T>::Node::Node(const T& m) : data(m), next(nullptr) { }

template <class T>
T& ListIngredient<T>::Node::getData() {
    return data;
    }

template <class T>
typename ListIngredient<T>::Node* ListIngredient<T>::Node::getNext() const {
    return next;
    }

template <class T>
void ListIngredient<T>::Node::setData(const T& m) {
    data = m;
    }

template <class T>
void ListIngredient<T>::Node::setNext(Node* pos) {
    next = pos;
    }

///IMPLEMENTACIÓN LISTA

template <class T>
ListIngredient<T>::ListIngredient() : anchor(nullptr) {}

template<class T>
ListIngredient<T>::ListIngredient( const ListIngredient& l) : anchor(nullptr) {
    copyAll(l);
    }

template<class T>
void ListIngredient<T>::copyAll(const ListIngredient<T>& obj) {
    Node* aux(obj.anchor);
    Node* last(nullptr);
    Node* newNode;

    while(aux != nullptr) {
        newNode = new Node(aux->getData());

        if(last == nullptr) {
            anchor = newNode;
            }
        else {
            last->setNext(newNode);
            }
        last = newNode;
        aux = aux->getNext();
        }
    }

template <class T>
ListIngredient<T>::~ListIngredient() {
    deleteAll();
    }

template<class T>
bool ListIngredient<T>::isEmpty() {
    return anchor == nullptr;
    }

template<class T>
bool ListIngredient<T>::validPosition(Node* pos) const {
    Node* aux(anchor);

    while(aux != nullptr) {
        if(aux == pos) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

///METODO INSERTAR
template<class T>
void ListIngredient<T>::insertData(Node* pos, const T& obj) {
    if(pos != nullptr && !validPosition(pos)) {
        throw Exception("Posicion invalida, insertData");
        }

    Node* aux(new Node(obj));

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, insertData");
        }

    ///Insertar al principio
    if(pos == nullptr) {
        aux->setNext(anchor);
        anchor = aux;
        }
    ///Insertar en cualquier otra posicion
    else {
        aux->setNext(pos->getNext());
        pos->setNext(aux);
        }
    }

template <typename T>
void ListIngredient<T>::insertSortData(T& obj) {
    Node* aux(anchor);
    bool flag = false;

    while(aux != nullptr && flag != true) {
        if(obj < aux->getData()) {
            insertData(getBeforePosition(aux), obj);
            flag = true;
            }
        aux = getNextPosition(aux);
        }

    if(flag == false) {
        insertData(getLastPosition(), obj);
        }
    }

///METODO ELIMINAR
template<class T>
void ListIngredient<T>::deleteData(Node* pos) {
    if(!validPosition(pos)) {
        throw Exception("Posicion invalida, deleteData");
        }
    ///Eliminar el primero
    if(pos == anchor) {
        anchor = anchor->getNext();
        }
    else {
        getBeforePosition(pos)->setNext(pos->getNext());
        }
    delete pos;
    }

template <class T>
string ListIngredient<T>::category(const T& obj, int cmp(const T&,const T&)) {
    std::string resCateg;
    Node* aux;
    while(aux != nullptr) {
        if(cmp(obj, aux->getData()) == 0) {
            resCateg += aux->toString();
            resCateg += '\n';
            }
        aux->getNext();
        }
    return resCateg;
    }

///RECUPERAR
template<class T>
T& ListIngredient<T>::retrieve(Node*& pos) {
    if(!validPosition(pos)) {
        throw Exception("Receta invalida, retrieve");
        }
    return pos->getData();
    }

///PRIMERA POSICIÓN
template <class T>
typename ListIngredient<T>::Node* ListIngredient<T>::getFirstPosition() {
    return anchor;
    }

///ÚLTIMA POSICIÓN
template <class T>
typename ListIngredient<T>::Node* ListIngredient<T>::getLastPosition() {
    if(isEmpty()) {
        return nullptr;
        }

    Node* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }
    return aux;
    }

///ANTES DE CIERTA POSICIÓN
template <class T>
typename ListIngredient<T>::Node* ListIngredient<T>::getBeforePosition(Node* pos) const {
    if(pos == anchor) {
        return nullptr;
        }

    Node* aux(anchor);

    while(aux != nullptr && aux->getNext() != pos) {
        aux = aux->getNext();
        }
    return aux;
    }

///DESPUÉS DE CIERTA POSICIÓN
template <class T>
typename ListIngredient<T>::Node* ListIngredient<T>::getNextPosition(Node* pos) const {
    if(!validPosition(pos)) {
        return nullptr;
        }
    return pos->getNext();
    }

template <class T>
int ListIngredient<T>::compareByNameIngr(const T& orig, const T& copyc ) {
    return orig.getNameIngr().compare(copyc.getNameIngr());
    }

template <class T>
typename ListIngredient<T>:: Node* ListIngredient<T>::findDatLin(const T& obj, int com(const T&, const T&)) const {
    Node* aux(anchor);
    while(aux != nullptr && com(aux->getData(), obj)!=0) {
        aux = aux->getNext();
        }
    return aux;
    }

template <class T>
void ListIngredient<T>::writeFromDisk(const string& fileName) {
    ofstream myFile;
    myFile.open(fileName, ios_base::trunc);

    if(!myFile.is_open()) {
        throw Exception("No se puede abrir el archivo para escritura, writeToDisk");
        }

    Node* aux = anchor;
    while(aux != nullptr) {
        myFile << aux->getData();
        aux = aux->getNext();
        }
    myFile.close();
    }

///Lectura a disco
template <class T>
void ListIngredient<T>::readFromDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()) {
        throw Exception("No se pudo abrir el archivo para lectura, readToDisk");
        }

    deleteAll();
    T myData;
    ListIngredient myListIng;

    try {
        while(myFile >> myData) {
            insertData(getLastPosition(), myData);
            //myListIng.insertSortData(myData);
            }
        }
    catch(Exception ex) {
        myFile.close();
        throw Exception(ex.what());
        }

    myFile.close();
    }

template<class T>
string ListIngredient<T>::toString() const {
    string listComplete;
    Node* aux(anchor);
    while(aux!=nullptr) {
        listComplete += aux->getData().toString() + "\n";
        aux = aux->getNext();
        }
    return listComplete;
    }

template <class T>
void ListIngredient<T>::deleteAll() {
    Node* aux;

    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

template<class T>
ListIngredient<T>& ListIngredient<T>::operator = (const ListIngredient<T>& obj) {
    deleteAll();
    copyAll(obj);
    return *this;
    }

#endif // INGREDIENTLIST_HPP_INCLUDED

