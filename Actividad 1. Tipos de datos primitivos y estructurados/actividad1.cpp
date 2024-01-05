#include "actividad1.h"

using namespace std;

actividad1::actividad1() {};

void actividad1::tabla(void) {
    cout <<"Tipo de dato    \t\t|Bits |\t  Valor Mínimo   |\tValor Máximo\t|"<<endl;
    cout <<"Carácter con signo:\t\t   "<< CHAR_BIT <<"\t   "<< SCHAR_MIN <<"\t\t\t  "<< SCHAR_MAX << '\n';
    cout <<"Carácter sin signo:\t\t   "<< CHAR_BIT <<"\t\t"<<WCHAR_MIN<<"\t\t  "<< UCHAR_MAX << '\n';
    cout <<"Entero con signo:\t\t   "<<sizeof(signed short int)*CHAR_BIT<<"\t   "<< INT_MIN <<"\t\t"<< INT_MAX << '\n';
    cout <<"Entero sin signo:\t\t   "<<sizeof(unsigned short int)*CHAR_BIT<<"\t\t"<<numeric_limits<unsigned short int>::min()<<"\t\t"<<UINT_MAX << '\n';
    cout <<"Entero Largo con signo:\t\t   "<<sizeof(signed long int)*CHAR_BIT<<"\t   "<<LONG_MIN<<"\t\t"<< LONG_MAX << '\n';
    cout <<"Entero Largo sin signo:\t\t   "<<sizeof(unsigned long int)*CHAR_BIT<<"\t\t"<<numeric_limits<unsigned long int>::min()<<"\t\t"<<ULONG_MAX << '\n';
    cout <<"Real de precisión simple:\t   "<<sizeof(float)*CHAR_BIT<<"\t   "<<numeric_limits<float>::min()<<"\t\t"<< numeric_limits<float>::max() << '\n';
    cout <<"Real de doble precisión:\t   "<<sizeof(double)*CHAR_BIT<<"\t   "<< numeric_limits<double>::min()<<"\t\t"<< numeric_limits<double>::max() << '\n';
    }

///FUNCIONES PARA LLENAR LA MATRIZ A y B
void actividad1::setMatriz(int f) {
    ///Crea los números aleatorios
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_real_distribution<float>rango(-100.0,100.0);

    for(int x=0; x<f; x++) {

        for(int y=0; y<f; y++) {
            matriz[x][y]=rango(generator);

            }
        }
    }
float actividad1::getMatriz(int f) {
    for(int x=0; x<f; x++) {

        for(int y=0; y<f; y++) {
            cout<<matriz[x][y]<<" \t ";

            }
        cout<<endl;
        }
    return num;
    }

///SOBRECARGA DE OPERADORES PARA REALIZAR LA SUMA EN MATRIZ C
actividad1 actividad1::operator+(actividad1 &matri1) { // función miembro recibe 1 porque ya lo esta llamndo el objeto que invoca
    actividad1 matrizC;
    for (int x=0; x < filas; x++) {
        for (int y=0; y < columnas; y++) {
            matrizC.matriz[x][y] = this->matriz[x][y] + matri1.matriz[x][y];
            }
        }
    return matrizC;
    }

///SOBRECARGA DE OPERADORES PARA REALIZAR LA MULTIPLICACIÓN EN MATRIZ D
actividad1 actividad1::operator*(actividad1 &matri2) {
    actividad1 matrizD;
    for (int x=0; x < filas; x++) {
        for (int y=0; y < columnas; y++) {
            matrizD.matriz[x][y] = this->matriz[x][y] * matri2.matriz[x][y];
            }
        }
    return matrizD;
    }

///FUNCIÓN PRINCIPAL
void actividad1::visualizacion(void) {
    int f, x, y;
    actividad1 matrizA;
    actividad1 matrizB;
    actividad1 matrizC;
    actividad1 matrizD;

    cout<<"Ingresa un valor entre 3-10: "<<endl;
    cin>>f;

    if(f>=3&&f<=10) {
        system("cls");
        fflush(stdin);

        cout<<"Matriz A: \n";
        matrizA.setMatriz(f);
        matrizA.getMatriz(f);

        cout<<"\nMatriz B: \n";
        matrizB.setMatriz(f);
        matrizB.getMatriz(f);

        cout<<"\nMatriz C: "<<endl;
        matrizC = matrizA + matrizB;
        for(x=0; x<f; x++) {
            for(y=0; y<f; y++) {
                cout<<matrizC.matriz[x][y]<<" \t ";

                }
            cout<<endl;
            }

        cout<<"\nMatriz D: "<<endl;
        matrizD = matrizA * matrizB;
        for(x=0; x<f; x++) {
            for(y=0; y<f; y++) {
                cout<<matrizD.matriz[x][y]<<" \t ";

                }
            cout<<endl;
            }
        }
    else {
        cout<<"Error No.444. Favor de digitar lo que se te pide"<<endl;
        }
    }

