#include "inventario.hpp"

using namespace std;

Inventario::Inventario() {}

void Inventario::newPtr() {
    int i=collec[0].max_array;

    cout<<"Codigo de Barras (13 digitos): ";
    string auxBarras;
    cin.ignore();
    getline(cin, auxBarras);
    collec[i].setBarras(auxBarras);

    cout<<"Nombre: ";
    string auxName;
    getline(cin, auxName);
    collec[i].setName(auxName);

    cout<<"Fecha de Entrada AA MM DD: ";
    int auxD, auxM, auxA;
    cin>>auxA;
    cin>>auxM;
    cin>>auxD;
    Date myDate(auxA, auxM, auxD);
    collec[i].setDateInt(myDate);

    cout<<"Existencia Actual: ";
    int auxEA;
    cin>>auxEA;
    collec[i].setExisTotal(auxEA);

    cout<<"Peso: ";
    float auxP;
    cin>>auxP;
    collec[i].setPeso(auxP);

    cout<<"Precio de Mayoreo: ";
    float auxPmy;
    cin>>auxPmy;
    collec[i].setPrecioMay(auxPmy);

    cout<<"Precio de Menudeo: ";
    float auxMn;
    cin>>auxMn;
    collec[i].setPrecioMenudeo(auxMn);

    collec[i+1].max_array=-1;
    collec[i].max_array=0;
    collec[0].max_array+=1;
    }

void Inventario::addPtr() {
    int i, mod, sum;
    string cod;

    std::cout<<"Ingresa el codigo en barras del producto: ";
    std::cin>>cod;

    for(i=0; i<sizeof(collec); i++) {
        if(collec[i].max_array==-1) {
            system("PAUSE");
            break;
            }
        else if(cod==collec[i].getBarras()) {
            cout << "Cantidad de productos a agregar: ";
            cin >> mod;
            sum=mod+collec[i].getExisTotal();
            collec[i].setExisTotal(sum);
            break;
            }
        }
    }

void Inventario::deletPtr() {
    int i, rest, mod1;
    string cod;

    std::cout<<"Ingresa el codigo en barras del producto: ";
    std::cin>>cod;

    for(i=0; i<sizeof(collec); i++) {
        if(collec[i].max_array==-1) {
            system("PAUSE");
            break;
            }
        else if(cod==collec[i].getBarras()) {
            cout<<"Cantidad de productos a elimminar: ";
            cin>>mod1;
            rest=collec[i].getExisTotal()-mod1;
            collec[i].setExisTotal(rest);
            break;
            }
        }
    }

void Inventario::showPtr() {
    int i;

    for(i=0; i<sizeof(collec); i++) {
        ///ITERACIÓN QUE IMPIDE IMPRIMIR LOS 500 ESPACIOS DEL ARREGLO
        if(collec[i].max_array==-1) {
            system("PAUSE");
            break;
            }
        cout<<collec[i].toString();
        }
    }

