#ifndef PERSONAS_H
#define PERSONAS_H
#include <iostream>
#include "contenidos.h"
#include "plataformas.h"

using std::cout;
using std::endl;

class personas : public plataformas, public contenidos
{
    protected:
        string nombrePer;
        int hrs_Uso;

    public:
        personas();
        //personas():nombrePer{"Lola"},hrs_Uso{""}{}
        personas(string, string, string, string, string, string, int, string, int);
        ~personas(){cout<<"\n----HASTA LA PROXIMA!! :D----"<<endl;}

        void matarTiempo(void);
        int playlist(){return 30;}
};

#endif // PERSONAS_H
