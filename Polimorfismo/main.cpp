#include <iostream>
#include "alumnos_uni.h"
#include "alumnos_prepa.h"
#include "alumnos_sec.h"
#include "alumnos.h"

///Alumna. Cervantes Araujo Maria Dolores. F.E: 04/11/22.
///ACTIVIDAD. Crear un programa en el que hagas uso del polimorfismo con el método virtual y herencia simple.

using namespace std;

int main()
{
    alumnos_sec *Cont[1];
    Cont[0]= new alumnos_sec("Secundaria",10, "muy cotorros, altaneros", false);

    alumnos_prepa *Conta[2];
    Conta[0]=new alumnos_prepa("Preparatoria", 3, 5, "se la pasan en el billar", true, false);
    Conta[1]=new alumnos_prepa("Preparatoria", 4, 5, "se la pasan durmiendo", true, true);

    alumnos_uni *ali[1];
    ali[0]= new alumnos_uni("Universidad", 4, "Aldo", 25, false);

    Cont[0]->visualizar(); cout<<"\n\n";
    Cont[0]->mostrarSec(); cout<<"\n\n\n";

    Conta[0]->visualizar(); cout<<"\n\n";
    Conta[0]->preparatorianos(); cout<<"\n\n\n";
    Conta[1]->visualizar(); cout<<"\n\n";
    Conta[1]->preparatorianos(); cout<<"\n\n\n";

    ali[0]->visualizar(); cout<<"\n\n";
    ali[0]->mostrarUni(); cout<<"\n\n\n";

    return 0;
}
