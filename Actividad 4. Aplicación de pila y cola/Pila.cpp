#include "Pila.hpp"

Pila::Pila(): top(-1) {}

bool Pila::pNull()
{
    return top == -1;
}

bool Pila::pFull()
{
    return top == MAX-1;
}

int Pila::pop()
{
    try{
        if(pNull()){
            throw "Insuficiencia de Datos";
            return -1;
        }
        else{
            return pila[top-1];
        }

    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}

void Pila::push(const char& element)
{
    try{
        if(pFull()){
            throw "Desbordamiento de Datos";
        }
        else{
            pila[++top]=element;

        }

    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}

char Pila::getTop()
{
    try{
        if(pNull()){
            throw "Insuficiencia de Datos";
            return -1;
        }
        else{
            return pila[top];
        }

    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}
