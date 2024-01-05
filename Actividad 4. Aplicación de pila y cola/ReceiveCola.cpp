#include "ReceiveCola.hpp"

using namespace std;

ReceiveCola::ReceiveCola(){}

void ReceiveCola::conversorPostfixed()
{
    char c[100];
    char aux;
    int i=0,tam,oper;

    cout<<"Digita una operacion"<<endl;
    cin.getline(c,100,'\n');
    tam=strlen(c);
    while(i<tam) {
        colaIn.enqueue(c[i]);
        i++;
        }
    while(!colaIn.pNull()) {

        if(isOperador(colaIn.getFront())) {
            oper=precedence(colaIn.getFront());
            while(!Spila.pNull()
                    && (aux=Spila.getTop()!='(')      ///Si parentesis de apertura: apilarlo
                    && oper<= precedence(Spila.getTop())) {
                colaOut.enqueue(Spila.pop());
                }
            Spila.push(colaIn.dequeue());
            }
        else if(colaIn.getFront()=='(') {
            Spila.push(colaIn.dequeue());
            }

        ///Si parentesis de cierre:
        /// o que la pila este vacia desapilar operadores y pasarlos al resultado hasta enocntrar un parentesis de apertura
        else if(colaIn.getFront()==')') {

            while((aux=Spila.getTop())!='(') {
                colaOut.enqueue(aux);
                Spila.pop();        ///Y desapilar el parentesis de apertura
                }
            colaIn.dequeue();
            Spila.pop();
            }
        else {
            colaOut.enqueue(colaIn.dequeue());
            }
        }
    while(!Spila.pNull()) {
        colaOut.enqueue(Spila.pop());
        }
    while(!colaOut.pNull()) {
        cout<<colaOut.dequeue();
        }

}

///Si se encuentran operadores.
///Desapilar operadore y pasarlos al resultado mientras estos sean de mayor o igual precedencia que el que se esta leyendo
///Y no se encuentre con un parentesis de apertura o la pila este vacia
///apilar el operador leido Y Si es un operando/numero: pasarlo a la cola del resultado

bool ReceiveCola::isOperador(const char&c) {
    char operadores[5]= {'+','-','*','/','^'};
    bool val(false);
    for(int i=0; i<5; i++) {
        if(c==operadores[i]) {
            val=true;
            }
        }
    return val;
    }

///PRIORIDAD DE OPERADORES
int ReceiveCola::precedence(const char&c) {
    return(c=='+'||c =='-')? 1:
          (c=='*'||c =='/')? 2:
          (c=='^')? 3:0;
    }
