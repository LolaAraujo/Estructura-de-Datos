#include <iostream>

#include "Lista.h"

using namespace std;

int main()
{
    Lista *lis=new Lista(nullptr);

    lis->insertarFinal(8);
    lis->insertarFinal(4);
    lis->insertarFinal(5);
    lis->insertarFinal(6);
    lis->insertarFinal(87);

    lis->mostrar();

    lis->~Lista();

    return 0;
}
