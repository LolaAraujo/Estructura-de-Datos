#include "personas.h"
#include "contenidos.h"
#include "plataformas.h"

personas::personas()
{
    nombrePer="";
    hrs_Uso=0;
}

personas::personas(string nnn, string x, string c, string nC, string p, string crea, int v, string perS, int hora) : contenidos(nnn, x, c, nC, p, crea, v)
{
    this->nombrePer=perS;
    this->hrs_Uso=hora;
}

void personas::matarTiempo(void)
{
    mostrar_playlist();
    cout<<"\n\tLa persona: "<<nombrePer<<" esta "<<hrs_Uso<<" horas en dicha plataforma\n"<<endl;
    crear_albums();
}
