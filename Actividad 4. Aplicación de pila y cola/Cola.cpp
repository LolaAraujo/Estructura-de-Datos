#include "Cola.hpp"

Queue::Queue(): fronPos(0), endPos(MAX-1){}

bool Queue::pFull()
{
    return fronPos == endPos + 2
       || (fronPos == 0 && endPos == MAX-2)
       || (fronPos == 1 && endPos == MAX-1);
}

bool Queue::pNull()
{
    return fronPos == endPos + 1
       or (fronPos == 0 and endPos == MAX-1);
}

void Queue::enqueue(const char& elm)
{
    try{
        if(pFull()){
            throw "Desbordamiento de Datos";
        }
        /*else if(++endPos == MAX){
            endPos = 0;
        }*/
        else{
            cola[++endPos]=elm;
        }

    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}

void Queue::dequeue()
{
    try{
        if(pNull()){
            throw "Insuficiencia de Datos";
            //return -1;
        }
        else{ //if(++fronPos == MAX){
            cola[++fronPos];
            //fronPos=0;
        }

    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}

char Queue::getFront()
{
    try{
        if(pNull()){
            throw "Insuficiencia de Datos";
            return -1;
        }
        else{
            return cola[fronPos+1];
        }
    }catch(const char *error) {
        std::cout<<error<<std::endl;
        getchar();
    }
}
