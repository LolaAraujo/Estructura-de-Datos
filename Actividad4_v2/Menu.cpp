#include "Menu.hpp"

using namespace std;
Menu::Menu() {
    }

Menu::Menu(const Menu& m) {
    colaInserc = m.colaInserc;
    colaOut = m.colaOut;
    Spila = m.Spila;
    }

void Menu::convertinfijo_Postfijo() {
    char c[150];
    char aux;
    int i=0,tam,oper;

    cout<<"\n--> Digita una operacion"<<endl;
    cin.getline(c,150,'\n');
    tam=strlen(c);
    while(i<tam) {
        colaInserc.enqueue(c[i]); ///Inserta la operacion inija
        i++;
        }
    while(!colaInserc.isEmpty()) {

        if(isOperador(colaInserc.getFront())) {
            oper=precedence(colaInserc.getFront());
            ///Si no es parentesis de apertura && parentesis menor a precendente apila el operador
            while(!Spila.isEmpty()&& (aux=Spila.getTop()!='(') && oper<= precedence(Spila.getTop())) {
                colaOut.enqueue(Spila.pop());  ///Se apila el digito en la cola del resultado y se eliminan los operadores
                }
            Spila.push(colaInserc.dequeue()); ///Se recorren las posiciones de la cola
            }
        else if(colaInserc.getFront()=='(') {
            Spila.push(colaInserc.dequeue());
            }

        ///Si parentesis de cierre:
        /// o que la pila este vacia desapilar operadores y pasarlos al resultado hasta enocntrar un parentesis de apertura
        else if(colaInserc.getFront()==')') {

            while((aux=Spila.getTop())!='(') {
                colaOut.enqueue(aux);
                Spila.pop();        ///Y desapilar el parentesis de apertura
                }
            colaInserc.dequeue();
            Spila.pop();
            }
        else {
            colaOut.enqueue(colaInserc.dequeue());
            }
        }
    while(!Spila.isEmpty()) {
        colaOut.enqueue(Spila.pop());
        }
    while(!colaOut.isEmpty()) {
        cout<<colaOut.dequeue();
        }
    }


///Si se encuentran operadores.
///Desapilar operadores y pasarlos al resultado mientras estos sean de mayor o igual precedencia que el que se esta leyendo
///Y no se encuentre con un parentesis de apertura o la pila este vacia
///apilar el operador leido Y Si es un operando/numero: pasarlo a la cola del resultado

bool Menu::isOperador(const char&c) {
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
int Menu::precedence(const char&c) {
    return(c=='+'||c =='-')? 1:
          (c=='*'||c =='/')? 2:
          (c=='^')? 3:0;
    }

Menu& Menu::operator = (const Menu& m) {
    Spila = m.Spila;
    colaInserc = m.colaInserc;
    colaOut = m.colaOut;

    return *this;
    }
