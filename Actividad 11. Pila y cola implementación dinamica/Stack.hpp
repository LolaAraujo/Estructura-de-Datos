#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
#include "LolException.hpp"

/// DEFINICION
template<class T>
class Stack {
    private:
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

        Node* anchor;
        void copyAll(const Stack&);
        void deleteAll();

    public:
        Stack();
        Stack(const Stack&);
        ~Stack();

        bool isEmpty() const;

        void push(const T& );
        T pop();
        T getTop();

        Stack<T>& operator = (const Stack&);
    };

/// IMPLEMENTACION NODO
template <class T>
Stack<T>::Node::Node() : next(nullptr) { }

template <class T>
Stack<T>::Node::Node(const T& m) : data(m), next(nullptr) { }

template <class T>
T Stack<T>::Node::getData() const {
    return data;
    }

template <class T>
typename Stack<T>::Node* Stack<T>::Node::getNext() const {
    return next;
    }

template <class T>
void Stack<T>::Node::setData(const T& m) {
    data = m;
    }

template <class T>
void Stack<T>::Node::setNext(Node* pos) {
    next = pos;
    }

///IMPLEMENTACION STACK
using namespace std;
template<class T>
Stack<T>::Stack() : anchor(nullptr) {  }

template<class T>
Stack<T>::Stack(const Stack& obj) : anchor(nullptr) {
    copyAll(obj);
    }

template<class T>
Stack<T>::~Stack() {
    deleteAll();
    }

template<class T>
bool Stack<T>::isEmpty() const {
    return anchor == nullptr;
    }

template<class T>
void Stack<T>::push(const T& obj) {
    Node* aux(new Node(obj));

    if(aux==nullptr) {
        throw Exception("Desbordamiento de datos.");
        }
    aux->setNext(anchor);
    anchor = aux;
    //pila[++top] = obj;
    }

template<class T>
T Stack<T>::pop() {
    if(anchor == nullptr) {
        throw Exception("Insuficiencia de datos.");
        }

    T result(anchor->getData());
    Node* aux(anchor);
    anchor = anchor->getNext();

    delete aux;
    return result;
    //return pila[top--];
    }

template<class T>
T Stack<T>::getTop() {
    if(isEmpty()) {
        throw Exception("Insuficiencia de datos.");
        }
    return anchor->getData();
    }

template<class T>
Stack<T>& Stack<T>::operator = (const Stack& obj) {
    deleteAll();
    copyAll(obj);
    return *this;
    }

template<class T>
void Stack<T>::copyAll(const Stack<T>& obj) {
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

template<class T>
void Stack<T>::deleteAll() {
    Node* aux;
    while(anchor != nullptr) {
        aux = anchor;
        anchor = anchor->getNext();
        delete aux;
        }
    }

#endif // STACK_HPP_INCLUDED
