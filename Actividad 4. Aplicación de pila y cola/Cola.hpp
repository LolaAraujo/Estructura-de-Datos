#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED
#define MAX 300

#include <iostream>

class Queue{
private:
    char cola[MAX];
    int fronPos;
    int endPos;


public:
    Queue(); ///Inicializacion

    bool pFull();
    bool pNull();

    void enqueue(const char&); ///push
    void dequeue();            ///pop

    char getFront();

};

#endif // COLA_HPP_INCLUDED
