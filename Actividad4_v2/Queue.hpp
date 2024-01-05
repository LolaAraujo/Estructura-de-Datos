#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED
#include <iostream>
#include "LolException.hpp"

/// DEFINICION
template<class A, int ARRAY = 300>
class Queue {
    private:
        A cola[ARRAY];
        int endPos;
        int frontPos;
        void copyAll(const Queue<A, ARRAY>& );

    public:
        Queue();
        Queue(const Queue<A,ARRAY>& );

        bool isEmpty();
        bool full();
        void enqueue(const A& );
        A dequeue();
        A getFront();

        Queue<A,ARRAY>& operator = (const Queue<A,ARRAY>&);
    };

/// IMPLEMENTACION
using namespace std;
template<class A, int ARRAY>
void Queue<A, ARRAY>::copyAll(const Queue<A, ARRAY>& obj) {
    int i = obj.frontPos; // i = 2
    int j = obj.endPos; // j = 2

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
Queue<A, ARRAY>::Queue() {
    frontPos = 0;
    endPos = ARRAY - 1;
    }

template<class A, int ARRAY>
Queue<A, ARRAY>::Queue(const Queue<A,ARRAY>& obj) {
    copyAll(obj);
    }

template<class A, int ARRAY>
bool Queue<A, ARRAY>::isEmpty() {
    return (frontPos == endPos + 1) || (frontPos == 0 && endPos == ARRAY - 1);
    }

template<class A, int ARRAY>
bool Queue<A, ARRAY>::full() {
    return frontPos ==  endPos + 2 || (frontPos == 0 && endPos == ARRAY - 2) || (frontPos == 1 && endPos == ARRAY - 1);
    }

template<class A, int ARRAY>
void Queue<A, ARRAY>::enqueue(const A& obj) {
    if(full()) {
        throw LolException("Desbordamiento de datos.");
        }


    if(++endPos == ARRAY) {
        endPos = 0;
        }
    cola[endPos] = obj;
    }

template<class A, int ARRAY>
A Queue<A, ARRAY>::dequeue() {
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
A Queue<A, ARRAY>::getFront() {
    if(isEmpty()) {
        throw LolException("Insuficiencia de datos.");
        }

    return cola[frontPos];
    }

template<class A, int ARRAY>
Queue<A,ARRAY>& Queue<A, ARRAY>::operator = (const Queue<A, ARRAY>& obj) {
    copyAll(obj);
    return *this;
    }

#endif // QUEUE_HPP_INCLUDED
