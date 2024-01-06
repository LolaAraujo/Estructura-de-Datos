#include <iostream>
#include "hombre.h"
#include "mujer.h"
#include "ninos.h"

using namespace std;

///Alumna. Cervantes Araujo Maria Dolores. F.E: 04/11/22.
///ACTIVIDAD. Crear un programa en el que hagas uso del polimorfismo con el método virtual y herencia simple.

int main()
{
    system("Color F5");
    cout<<"------------------\n   POLIMORFISMO\n------------------\n"<<endl;

    persona *conte[4];

    conte[0] = new mujer("Diana","hetero",20,1.70);
    conte[1] = new ninos("Aldo","nino",07,true);
    conte[2] = new hombre("Don Ramon","homosexual",45,79.89);
    conte[3] = new mujer("Escarleth","pansexual",25,1.40);

    cout<<"----CATEGORIA MUJER---"<<endl;
    conte[0] ->mostrar();
    cout<<"\n"; conte[3] ->mostrar();
    cout<<"\n\n----CATEGORIA NINO---"<<endl;
    conte[1] ->mostrar();
    cout<<"\n\n----CATEGORIA HOMBRE---"<<endl;
    conte[2] ->mostrar();

    persona();
    return 0;
}
