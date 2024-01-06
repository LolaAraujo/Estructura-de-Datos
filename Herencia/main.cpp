#include <iostream>
#include "personas.h"
#include "contenidos.h"

///Herencia simple y multiple.
///Cervantes Araujo Maria Dolores. F.E: 30/10/22

using namespace std;

int main()
{
    system("Color F5");

    contenidos album("spotify","verde","trap","Du-Hash","Como dormir sin estres","Luis Miguel",1500);
    personas suj("youtube","rojo","pop","XT4S1S","Hablame de Ciencia","UdG",1000,"Lola",10);

    ///HERENCIA SIMPLE. class contenidos : public plataformas
    cout<<"\t\t---DATOS DE LA HERENCIA SIMPLE---\n\n"<<endl;
    album.mostrar_playlist(); cout<<"\n";
    album.crear_albums(); cout<<"\n";


    ///HERENCIA MULTIPLE. class personas : public plataformas, public contenidos
    cout<<"\n\t\t---DATOS DE LA HERENCIA MULTIPLE---\n\n"<<endl;
    suj.matarTiempo();cout<<"\n";

    return 0;
}
