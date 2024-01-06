#ifndef NODO_H
#define NODO_H


class Nodo
{
    public:
        Nodo();
        Nodo(int dato, Nodo *sig){
            this->sig=sig;
            this->dato=dato;
        };


    private:
        int dato;
        Nodo *sig;

        friend class Lista;

};

#endif // NODO_H
