#ifndef QUEUEPOSFIJO_HPP_INCLUDED
#define QUEUEPOSFIJO_HPP_INCLUDED
#include <iostream>
#include "LolException.hpp"

/// DEFINICION
template<class A, int ARRAY = 300>
class QueuePosfijo {
    private:
        A cola[ARRAY];
        int endPos;
        int frontPos;
        void copyAll(const QueuePosfijo<A, ARRAY>& );

    public:
        QueuePosfijo();
        QueuePosfijo(const QueuePosfijo<A,ARRAY>& );

        bool isEmpty();
        bool full();
        void enqueue(const A& );
        A dequeue();
        A getFront();

        QueuePosfijo<A,ARRAY>& operator = (const QueuePosfijo<A,ARRAY>&);
    };

/// IMPLEMENTACION
using namespace std;
template<class A, int ARRAY>
void QueuePosfijo<A, ARRAY>::copyAll(const QueuePosfijo<A, ARRAY>& obj) {

    int i = obj.frontPos;
    int j = obj.endPos;

    if(i ==  obj.endPos + 2) {
        while(i <= ARRAY) {
            this -> cola[i] = obj.cola[i];
            i++;
            }

        while(j >= 0) {
            this -> cola[j] = obj.cola[j];
            j--;
            }
        }

    if(i == 0 or i == j or i < j) {
        while(i <= j) {
            this-> cola[i] = obj.cola[i];
            i++;
            }
        }
    this -> frontPos = obj.frontPos;
    this -> endPos = obj.endPos;
    }

template<class A, int ARRAY>
QueuePosfijo<A, ARRAY>::QueuePosfijo() {
    frontPos = 0;
    endPos = ARRAY - 1;
    }

template<class A, int ARRAY>
QueuePosfijo<A, ARRAY>::QueuePosfijo(const QueuePosfijo<A,ARRAY>& obj) {
    copyAll(obj);
    }

template<class A, int ARRAY>
bool QueuePosfijo<A, ARRAY>::isEmpty() {
    return (frontPos == endPos + 1) || (frontPos == 0 && endPos == ARRAY - 1);
    }

template<class A, int ARRAY>
bool QueuePosfijo<A, ARRAY>::full() {
    return frontPos ==  endPos + 2 || (frontPos == 0 && endPos == ARRAY - 2) || (frontPos == 1 && endPos == ARRAY - 1);
    }

template<class A, int ARRAY>
void QueuePosfijo<A, ARRAY>::enqueue(const A& obj) {
    if(full()) {
        throw LolException("Desbordamiento de datos.");
        }
    if(++endPos == ARRAY) {
        endPos = 0;
        }
    cola[endPos] = obj;
    }

template<class A, int ARRAY>
A QueuePosfijo<A, ARRAY>::dequeue() {
    if(isEmpty()) {
        throw LolException("Insuficiencia de datos.");
        }
    A aux(cola[frontPos]);

    if(++frontPos == ARRAY) {
        frontPos = 0;
        }
    return aux;
    }

template<class A, int ARRAY>
A QueuePosfijo<A, ARRAY>::getFront() {
    if(isEmpty()) {
        throw LolException("Insuficiencia de datos.");
        }

    return cola[frontPos];
    }

template<class A, int ARRAY>
QueuePosfijo<A,ARRAY>& QueuePosfijo<A, ARRAY>::operator = (const QueuePosfijo<A, ARRAY>& obj) {
    copyAll(obj);
    return *this;
    }

#endif // QUEUEPOSFIJO_HPP_INCLUDED
