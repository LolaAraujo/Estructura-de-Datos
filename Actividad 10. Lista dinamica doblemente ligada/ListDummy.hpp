#ifndef LISTDUMMY_HPP_INCLUDED
#define LISTDUMMY_HPP_INCLUDED
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
                T getData() const;
                Node* getPrev() const;
                Node* getNext() const;

                void setDataPtr(const T*);
                void setData(const T&);
                void setPrev(Node*);
                void setNext(Node*);
            };

        Node* header;
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

        bool isEmpty() const;

        void insertData(Node*, const T&);
        void deleteData(Node*);

        Node* getFirstPosition() const;
        Node* getLastPosition() const;
        Node* getBeforePosition(Node*) const;
        Node* getNextPosition(Node*)  const;
        T retrieve(Node*) const;
        Node* localiza(const T&) const;

        static int compareByNameMusic(const T&, const T&);
        static int compareByInterprete(const T&, const T&);

        Node* findDatLin(const T&,int (const T&,const T&)) const;
        void deleteAll();
        std::string toString() const;

        ///Disk
        void writeFromDisk(const std::string&);
        void readFromDisk(const std::string&);

        Lista<T>& operator = (const Lista<T>&);
    };

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using namespace std;
///------------Implementación NODO

template <class T>
Lista<T>::Node::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

template <class T>
Lista<T>::Node::Node(const T& m) : dataPtr(new T(m)), prev(nullptr), next(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, se creara un nodo");
        }
    }

template <class T>
Lista<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* Lista<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T Lista<T>::Node::getData() const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr; //desferenciacion para obtener el dato
    }

template <class T>
typename Lista<T>::Node* Lista<T>::Node::getPrev() const {
    return prev;
    }

template <class T>
typename Lista<T>::Node* Lista<T>::Node::getNext() const {
    return next;
    }

template <class T>
void Lista<T>::Node::setDataPtr(const T* pos) {
    dataPtr = pos;
    }

template <class T>
void Lista<T>::Node::setData(const T& e) {
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
void Lista<T>::Node::setPrev(Node* pos) {
    prev = pos;
    }

template <class T>
void Lista<T>::Node::setNext(Node* pos) {
    next = pos;
    }

///----------Implementación LISTA
//Constructor
template <class T>
Lista<T>::Lista() : header(new Node) {
    if(header == nullptr) {
        throw Exception("Memoria no disponible, inicializando lista...");
        }

    header->setPrev(header);
    header->setNext(header);
    }

template <class T>
Lista<T>::Lista(const Lista& l) : Lista() {
    copyAll(l);
    }

template <class T>
Lista<T>::~Lista() {
    deleteAll();
    delete header;
    }

template <class T>
void Lista<T>::copyAll(const Lista& l) {
    Node* aux(l.header->getNext());
    Node* newNode;

    while(aux != l.header) {
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

///LISTA VACIA
template <class T>
bool Lista<T>::isEmpty() const {
    return header->getNext() == header;
    }

template <class T>
bool Lista<T>::validPosition(Node* pos) const {
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
template <class T>
void Lista<T>::insertData(Node* pos, const T& music) {
    if(pos != nullptr && !validPosition(pos)) {
        throw Exception("Posicion invalida, insertData");
        }

    Node* aux;
    try {
        aux = new Node(music);
        }
    catch (typename Node::Exception ex) {
        throw Exception(ex.what());
        }

    if(aux == nullptr) {
        throw Exception("Memoria no disponible, insertData");
        }

    //Insertar en el encabezado
    if(pos == nullptr) {
        pos = header;
        }

    aux->setPrev(pos);
    aux->setNext(pos->getNext());

    pos->getNext()->setPrev(aux);
    pos->setNext(aux);
    }

///METODO ELIMINAR
template <class T>
void Lista<T>::deleteData(Node* pos) {
    if(!validPosition(pos)) {
        throw Exception("Posicion invalida, deleteMusic");
        }
    pos->getPrev()->setNext(pos->getNext());
    pos->getNext()->setPrev(pos->getPrev());
    delete pos;
    }

///RECUPERAR
template <class T>
T Lista<T>::retrieve(Node* pos) const {
    if(!validPosition(pos)) {
        throw Exception("Cancion invalida, retrieve");
        }
    return pos->getData();
    }

///Localiza
template <class T>
typename Lista<T>::Node* Lista<T>::localiza(const T& music) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(aux->getData = music) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

///PRIMERA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getFirstPosition() const {
    if(isEmpty()) {
        return nullptr;
        }
    return header->getNext();
    }

///ÚLTIMA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getLastPosition() const {
    if(isEmpty()) {
        return nullptr;
        }
    return header->getPrev();
    }

///ANTES DE CIERTA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getBeforePosition(Node* pos) const {
    if(!validPosition(pos) || pos == header->getNext()) {
        return nullptr;
        }
    if(pos->getPrev() == header) {
        return header->getPrev();
        }
    return pos->getPrev();
    }

///DESPUÉS DE CIERTA POSICIÓN
template <class T>
typename Lista<T>::Node* Lista<T>::getNextPosition(Node* pos) const {
    if(!validPosition(pos) || pos == header->getPrev()) {
        return nullptr;
        }
    if(pos->getNext() == header) {
        return header->getNext();
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

template <class T>
typename Lista<T>::Node* Lista<T>::findDatLin(const T& song, int com(const T&, const T&)) const {
    Node* aux(header->getNext());

    while(aux != header) {
        if(com(aux->getData(), song) == 0) {
            return aux;
            }
        aux = aux->getNext();
        }
    return nullptr;
    }

///Escritura a disco
template <class T>
void Lista<T>::writeFromDisk(const string& fileName) {
    ofstream myFile;

    myFile.open(fileName, ios_base::trunc);

    if(!myFile.is_open()) {
        throw Exception("No se puede abrir el archivo para escritura, writeToDisk");
        }

    Node* aux = header->getNext();
    T data;

    while(aux != header) {
        data = aux->getData();
        myFile << data << endl;
        aux = aux->getNext();
        }
    myFile.close();
    }

///Lectura a disco
template <class T>
void Lista<T>::readFromDisk(const string& fileName) {
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
    Node* aux(header->getNext());
    string listComplete;

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
    listComplete += "\n\n";

    while(aux != header) {
        listComplete += aux->getData().toString() + "\n";
        aux = aux->getNext();
        }
    return listComplete;
    }

template <class T>
void Lista<T>::deleteAll() {
    Node* aux;

    while(header->getNext() != header) {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
        }
    header->setPrev(header);
    }

#endif // LISTDUMMY_HPP_INCLUDED
