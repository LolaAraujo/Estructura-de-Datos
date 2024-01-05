#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
#include "LolException.hpp"

/// DEFINICION
template<class T, int ARRAY = 300>
class Stack {

    private:
        T pila[ARRAY];
        int top;
        void copyAll(const Stack<T,ARRAY>&);

    public:
        Stack();
        Stack(const Stack<T,ARRAY>& );
        bool isEmpty();
        bool full();

        void push(const T& );
        T pop();
        T getTop();

        Stack<T,ARRAY>& operator = (const Stack<T,ARRAY>& );
    };

/// IMPLEMENTACION
using namespace std;
template<class T, int ARRAY>
Stack<T, ARRAY>::Stack() {
    top = -1;
    }

template<class T, int ARRAY>
Stack<T, ARRAY>::Stack(const Stack<T,ARRAY>& obj) {
    copyAll(obj);
    }

template<class T, int ARRAY>
bool Stack<T, ARRAY>::isEmpty() {
    return top == -1;
    }

template<class T, int ARRAY>
bool Stack<T, ARRAY>::full() {
    return top == ARRAY - 1;
    }

template<class T, int ARRAY>
void Stack<T, ARRAY>::push(const T& obj) {
    if(full()) {
        throw LolException("Desbordamiento de datos.");
        }
    pila[++top] = obj;
    }

template<class T, int ARRAY>
T Stack<T, ARRAY>::pop() {
    if(isEmpty()) {
        throw LolException("Insuficiencia de datos.");
        }
    return pila[top--];
    }

template<class T, int ARRAY>
T Stack<T, ARRAY>::getTop() {
    if(isEmpty()) {
        throw LolException("Insuficiencia de datos.");
        }
    return pila[top];
    }

template<class T, int ARRAY>
Stack<T,ARRAY>& Stack<T, ARRAY>::operator = (const Stack<T,ARRAY>& obj) {
    copyAll(obj);
    return *this;
    }

template<class T, int ARRAY>
void Stack<T, ARRAY>::copyAll(const Stack<T,ARRAY>& obj) {
    int i = 0;
    while(i <= obj.top) {
        this -> pila[i] = obj.pila[i];
        i++;
        }
    this -> top = obj.top;
    }

#endif // STACK_HPP_INCLUDED
