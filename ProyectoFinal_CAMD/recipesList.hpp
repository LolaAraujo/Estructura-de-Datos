#ifndef RECIPESLIST_HPP_INCLUDED
#define RECIPESLIST_HPP_INCLUDED
#include <string>
#include <iostream>
#include <exception>
#include <fstream>

template <class T>
class ListRecipes {
    private:
        ///Clase anidada de NODO
        class Node {
            private:
                T* dataPtr;
                Node* prev;
                Node* next;

            public:
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

                Node();
                Node(const T&);
                ~Node();

                T* getDataPtr() const;
                T& getData();
                Node* getPrev() const;
                Node* getNext() const;

                void setDataPtr(const T*);
                void setData(const T&);
                void setPrev(Node*);
                void setNext(Node*);
            };

        Node* header;
        bool validPosition(Node*) const;
        void copyAll(const ListRecipes<T>&);
        void swapData(T&, T&);
        Node* sortDataQuick(Node*, Node*, int cmp(const Recetas&, const Recetas&));

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

        ListRecipes();
        ListRecipes(const ListRecipes<T>&);
        ~ListRecipes();

        bool isEmpty();

        void insertData(Node*, const T&);
        void insertSortData(T&);
        void deleteData(Node*);
        std::string category(const T&, int (const T&,const T&));
        T& retrieve(Node*&);

        Node* getFirstPosition() ;
        Node* getLastPosition() ;
        Node* getBeforePosition(Node*) const;
        Node* getNextPosition(Node*)const;
        Node* localiza(const T&) const;

        static int compareByNameIngr(const T&, const T&);
        static int compareByCategory(const T&, const T&);
        static int compareByTitle(const T&, const T&);
        static int compareByTime(const T&, const T&);
        static int compareByName(const T&, const T&);

        Node* findDatLin(const T&,int (const T&,const T&)) const;
        void quickSort(int cmp(const Recetas&, const Recetas&));

        std::string toString() const;
        void deleteAll();
        void writeFromDisk(const std::string&);
        void readFromDisk(const std::string&);

        ListRecipes<T>& operator = (const ListRecipes<T>&);
    };

#endif // RECIPESLIST_HPP_INCLUDED

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using namespace std;
///------------Implementación NODO

template <class T>
ListRecipes<T>::Node::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

template <class T>
ListRecipes<T>::Node::Node(const T& m) : dataPtr(new T(m)), prev(nullptr), next(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, se creara un nodo");
        }
    }

template <class T>
ListRecipes<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* ListRecipes<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T& ListRecipes<T>::Node::getData() {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr;
    }

template <class T>
typename ListRecipes<T>::Node* ListRecipes<T>::Node::getPrev() const {
    return prev;
    }

template <class T>
typename ListRecipes<T>::Node* ListRecipes<T>::Node::getNext() const {
    return next;
    }

template <class T>
void ListRecipes<T>::Node::setDataPtr(const T* pos) {
    dataPtr = pos;
    }

template <class T>
void ListRecipes<T>::Node::setData(const T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class T>
void ListRecipes<T>::Node::setPrev(Node* pos) {
    prev = pos;
    }

template <class T>
void ListRecipes<T>::Node::setNext(Node* pos) {
    next = pos;
    }


///IMPLEMENTACION LISTA
template <class T>
ListRecipes<T>::ListRecipes() : header(new Node) {
    if(header == nullptr) {
        throw Exception("Memoria no disponible, inicializando lista...");
        }
    header->setPrev(header);
    header->setNext(header);
    }

template <class T>
ListRecipes<T>::ListRecipes(const ListRecipes& obj) : ListRecipes() {
    copyAll(obj);
    }

template <class T>
ListRecipes<T>::~ListRecipes() {
    deleteAll();
    delete header;
    }

template <class T>
void ListRecipes<T>::copyAll(const ListRecipes& obj) {
    Node* aux(obj.header->getNext());
    Node* newNode;

    while(aux != obj.header) {
        try {
            if((newNode = new Node(aux->getData())) == nullptr) {
                throw Exception("Memoria no disponible, copyAll");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
        }
    }

template <class T>
bool ListRecipes<T>::isEmpty() {
    return header->getNext() == header;
    }

template <class T>
bool ListRecipes<T>::validPosition(Node* pos) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(aux == pos) {
            return true;
            }
        aux = aux->getNext();
        }
    return false;
    }

///METODO INSERTAR
template<class T>
void ListRecipes<T>::insertData(Node* pos, const T& obj) {
    if(pos != nullptr && !validPosition(pos)) {
        throw Exception("Posicion invalida, insertData");
        }

    Node* aux;
    try {
        aux = new Node(obj);
        }
    catch (typename Node::Exception ex) {
        throw Exception(ex.what());
        }

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, insertData");
        }
    if(pos == nullptr) {
        pos = header;
        }

    aux->setPrev(pos);
    aux->setNext(pos->getNext());

    pos->getNext()->setPrev(aux);
    pos->setNext(aux);
    }

template <class T>
void ListRecipes<T>::insertSortData(T& obj) {
    Node* aux(header->getNext());
    if(isEmpty()) {
        insertData(obj, getLastPosition());
        }

    while(aux != header) {
        if(obj < aux->getData()) {
            insertData(obj, getBeforePosition(aux));
            }
        aux = getNextPosition(aux);
        }
    }

///METODO ELIMINAR
template<class T>
void ListRecipes<T>::deleteData(Node* pos) {
    if(!validPosition(pos)) {
        throw Exception("Posicion invalida, deleteData");
        }
    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());
    delete pos;
    }

template <class T>
string ListRecipes<T>::category(const T& obj, int cmp(const T&,const T&)) {
    std::string resCateg;
    Node* aux(header->getNext());
    while(aux != header) {
        if(cmp(obj, aux->getData()) == 0) {
            resCateg += aux->getData().toString();
            resCateg += '\n';
            }
        aux = aux->getNext();
        }
    return resCateg;
    }

///RECUPERAR
template<class T>
T& ListRecipes<T>::retrieve(Node*& pos) {
    if(!validPosition(pos)) {
        throw Exception("Dato invalida, retrieve");
        }
    return pos->getData();
    }

template <class T>
typename ListRecipes<T>::Node* ListRecipes<T>::localiza(const T& obj) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(aux->getData() = obj) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

///PRIMERA POSICIÓN
template<class T>
typename ListRecipes<T>::Node* ListRecipes<T>::getFirstPosition() {
    if(isEmpty()) {
        return nullptr;
        }
    return header->getNext();
    }

///ÚLTIMA POSICIÓN
template <class T>
typename ListRecipes<T>::Node* ListRecipes<T>::getLastPosition() {
    if(isEmpty()) {
        return nullptr;
        }
    return header->getPrev();
    }

///ANTES DE CIERTA POSICIÓN
template<class T>
typename ListRecipes<T>::Node* ListRecipes<T>::getBeforePosition(Node* pos) const {
    if(!validPosition(pos) || pos == header->getNext()) {
        return nullptr;
        }
    if(pos->getPrev() == header) {
        return header->getPrev();
        }
    return pos->getPrev();
    }

///DESPUÉS DE CIERTA POSICIÓN
template<class T>
typename ListRecipes<T>::Node* ListRecipes<T>::getNextPosition(Node* pos) const {
    if(!validPosition(pos) || pos == header->getPrev()) {
        return nullptr;
        }
    if(pos->getNext() == header) {
        return header->getNext();
        }
    return pos->getNext();
    }

template <class T>
int ListRecipes<T>::compareByNameIngr(const T& orig, const T& copyc ) {
    return orig.getNameIngr().compare(copyc.getNameIngr());
    }

template <class T>
int ListRecipes<T>::compareByTime(const T& orig, const T& copyc ) {
    return orig.getTime() - copyc.getTime();
    }

template <class T>
int ListRecipes<T>::compareByTitle(const T& orig, const T& copyc ) {
    return orig.getTitle().compare(copyc.getTitle());
    }

template <class T>
int ListRecipes<T>::compareByName(const T& orig, const T& copyc ) {
    return orig.getName().compare(copyc.getName());
    }

template <class T>
int ListRecipes<T>::compareByCategory(const T& orig, const T& copyc) {
    return orig.getCategory().compare(copyc.getCategory());
    }

template <class T>
typename ListRecipes<T>::Node* ListRecipes<T>::findDatLin(const T& obj, int com(const T&, const T&)) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(com(aux->getData(), obj) == 0) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

template<class T>
void ListRecipes<T>::swapData(T& a, T& b) {
    T aux(a);
    a = b;
    b = aux;
    }

template<class T>
void ListRecipes<T>::quickSort(int cmp(const Recetas&, const Recetas&)) {
    Node* aux(header->getNext());
    sortDataQuick(aux, getLastPosition(), cmp);
    }

template<class T>
typename ListRecipes<T>::Node* ListRecipes<T>::sortDataQuick(Node* leftExt, Node* rightExt, int cmp(const Recetas&, const Recetas&)) {
    Node* extrem(rightExt);
    Node* i(leftExt->getPrev());
    Node* j(leftExt);

    if(rightExt != nullptr && leftExt != rightExt && leftExt != rightExt->getNext()) {
        while(j != rightExt) {
            if(cmp(j->getData(), extrem->getData()) <= 0) {
                i = (i==nullptr) ? leftExt : i->getNext();
                swapData(i->getData(), j->getData());
                }
            j = j->getNext();
            }

        i = (i == nullptr) ? leftExt : i->getNext();
        swapData(i->getData(), extrem->getData() );
        Node* pivot = i;
        sortDataQuick(leftExt, pivot->getPrev(), cmp);
        sortDataQuick(pivot->getNext(), rightExt, cmp);
        }
    }

template <class T>
void ListRecipes<T>::writeFromDisk(const string& fileName) {
    ofstream myFile;
    myFile.open(fileName, ios_base::trunc);

    if(!myFile.is_open()) {
        throw Exception("No se puede abrir el archivo para escritura, writeFromDisk");
        }

    Position aux;
    aux = header->getNext();
    while(aux != header) {
        myFile << aux->getData() << endl;
        aux = aux->getNext();
        }
    myFile.close();
    }

///Lectura a disco
template <class T>
void ListRecipes<T>::readFromDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);
    if(!myFile.is_open()) {
        throw Exception("No se pudo abrir el archivo para lectura, readFromDisk");
        }

    deleteAll();
    T myData;
    try {
        while(myFile >> myData) {
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
string ListRecipes<T>::toString() const {
    string listComplete;
    Node* aux(header->getNext());
    while(aux != header) {
        listComplete += aux->getData().toString() + "\n";
        aux = aux->getNext();
        }
    return listComplete;
    }

template <class T>
void ListRecipes<T>::deleteAll() {
    Node* aux;

    while(header->getNext() != header) {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
        }
    header->setPrev(header);
    }

template<class T>
ListRecipes<T>& ListRecipes<T>::operator = (const ListRecipes<T>& obj) {
    deleteAll();
    copyAll(obj);
    return *this;
    }
