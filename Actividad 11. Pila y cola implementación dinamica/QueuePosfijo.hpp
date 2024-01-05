#ifndef QUEUEPOSFIJO_HPP_INCLUDED
#define QUEUEPOSFIJO_HPP_INCLUDED
#include <iostream>
#include "LolException.hpp"

/// DEFINICION
template<class A>
class QueuePosfijo {
    private:
        class Node {
            private:
                A* dataPtr;
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
                Node(const A&);
                ~Node();

                A* getDataPtr() const;
                A getData() const;
                Node* getPrev() const;
                Node* getNext() const;

                void setDataPtr(const A*);
                void setData(const A&);
                void setPrev(Node*);
                void setNext(Node*);
            };

        Node* header;
        void copyAll(const QueuePosfijo<A>&);
        void deleteAll();

    public:
        QueuePosfijo();
        QueuePosfijo(const QueuePosfijo& );
        ~QueuePosfijo();

        bool isEmpty();
        void enqueue(const A& );
        A dequeue();
        A getFront();

        QueuePosfijo<A>& operator = (const QueuePosfijo&);
    };

///IMPLEMENTACION NODO
using namespace std;
template <class A>
QueuePosfijo<A>::Node::Node() : dataPtr(nullptr), prev(nullptr), next(nullptr) { }

template <class A>
QueuePosfijo<A>::Node::Node(const A& m) : dataPtr(new A(m)), prev(nullptr), next(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, se creara un nodo");
        }
    }

template <class A>
QueuePosfijo<A>::Node::~Node() {
    delete dataPtr;
    }

template <class A>
A* QueuePosfijo<A>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class A>
A QueuePosfijo<A>::Node::getData() const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr;
    }

template <class A>
typename QueuePosfijo<A>::Node* QueuePosfijo<A>::Node::getPrev() const {
    return prev;
    }

template <class A>
typename QueuePosfijo<A>::Node* QueuePosfijo<A>::Node::getNext() const {
    return next;
    }

template <class A>
void QueuePosfijo<A>::Node::setDataPtr(const A* pos) {
    dataPtr = pos;
    }

template <class A>
void QueuePosfijo<A>::Node::setData(const A& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new A(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class A>
void QueuePosfijo<A>::Node::setPrev(Node* pos) {
    prev = pos;
    }

template <class A>
void QueuePosfijo<A>::Node::setNext(Node* pos) {
    next = pos;
    }

/// IMPLEMENTACION QUEUEPOSTFIJO
using namespace std;
template<class A>
void QueuePosfijo<A>::copyAll(const QueuePosfijo<A>& obj) {
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

template<class A>
QueuePosfijo<A>::QueuePosfijo() : header(new Node) {
    if(header == nullptr) {
        throw Exception("Memoria no disponible");
        }

    header->setPrev(header);
    header->setNext(header);
    }

template<class A>
QueuePosfijo<A>::QueuePosfijo(const QueuePosfijo& obj) : QueuePosfijo() {
    copyAll(obj);
    }

template<class A>
QueuePosfijo<A>::~QueuePosfijo() {
    deleteAll();
    delete header;
    }

template<class A>
bool QueuePosfijo<A>::isEmpty() {
    return (header->getNext() == header);
    }

template<class A>
void QueuePosfijo<A>::enqueue(const A& obj) {
    Node* aux;
    try {
        if((aux = new Node(obj)) == nullptr) {
            throw Exception("Memoria no disponible, EnqueuePostFija");
            }
        }
    catch(typename Node::Exception ex) {
        throw Exception(ex.what());
        }
    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
    }

template<class A>
A QueuePosfijo<A>::dequeue() {
    if(isEmpty()) {
        throw Exception("Insuficiencia de datos.");
        }

    A result(header->getNext()->getData());
    Node* aux(header->getNext());

    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());

    delete aux;
    return result;
    }

template<class A>
A QueuePosfijo<A>::getFront() {
    if(isEmpty()) {
        throw Exception("Insuficiencia de datos.");
        }
    return header->getNext()->getData();
    }

template<class A>
QueuePosfijo<A>& QueuePosfijo<A>::operator = (const QueuePosfijo& obj) {
    copyAll(obj);
    return *this;
    }

template <class A>
void QueuePosfijo<A>::deleteAll() {
    Node* aux;

    while(header->getNext() != header) {
        aux = header->getNext();
        header->setNext(aux->getNext());
        delete aux;
        }
    header->setPrev(header);
    }

#endif // QUEUEPOSFIJO_HPP_INCLUDED
