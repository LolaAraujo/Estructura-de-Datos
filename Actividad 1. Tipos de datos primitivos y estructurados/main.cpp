#include <iostream>
#include "actividad1.h"


using namespace std;

int main() {
    setlocale(LC_ALL,"");
    actividad1 tablaM;
    actividad1 opcionb;

    char i;
    int x=0;
    while(x==0) {
        system("cls");
        cout<<"BIENVENIDO :D"<<endl;
        cout<<"Seleciona una opción del menú:"<<endl;
        cout<<"a. Tamaño y Rangos de los Tipos de Dato Primitivos"<<endl;
        cout<<"b. Ejemplo de Uso de Tipo de Dato Estructurado"<<endl;
        cout<<"c. Salir "<<endl;
        cin>>i;

        switch (i) {
            case 'a':
                system("cls");
                tablaM.tabla();
                cout<<"\n";
                system("PAUSE()");
                break;
            case 'b':
                system("cls");
                fflush(stdin);
                opcionb.visualizacion();
                cout<<"\n";
                system("PAUSE()");
                break;
            case 'c':
                getchar(); system("cls");
                cout<<"HASTA LA PRÓXIMA!! :D"<<endl;
                x+=1;
                break;
            default:
                cout<<"Digita un valor dentro del rango, por favor\n"<<endl;
                system("PAUSE()");
                system("cls");
            }
        }
    return 0;
    }
