#include "Lista.h"
/*
Lista::Lista()
{
    h=nullptr;
    //ctor
}*/

Lista::~Lista()
{
  Nodo *tmp=h;
  Nodo *tmpAnt=nullptr;

  int cont=0;

  while(tmp)
  {
      tmpAnt=tmp;
      tmp=tmp->sig;
      delete tmpAnt;
      cout<<++cont<<endl;
  }

}

void Lista::insertarFinal(int d)
{
    Nodo *aux=new Nodo(d,nullptr);
    Nodo *tmp=h;

    //cout<<h<<endl;
    if(tmp==nullptr)
    {
        h=aux;
     //   cout<<"Lista vacia"<<endl;
    }
    else
    {
        //si solo es una linea de codigo no se pone entre llaves y si son más expresiones se ponen llaves
        while(tmp->sig)
            tmp=tmp->sig;

        tmp->sig=aux;
    }

}

void Lista::mostrar(void)
{
    Nodo *tmp=h;

    while(tmp)
    {
        cout<<tmp->dato<<", ";
        tmp=tmp->sig;
    }

}
