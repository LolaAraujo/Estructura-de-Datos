#include "contenidos.h"
#include "plataformas.h"

contenidos::contenidos()
{
    categoria="";
    nombre_Ca="";
    podcast="";
    creador="";
    vistas=0;
}
contenidos::contenidos(string nnn, string x, string c, string nC, string p, string crea, int v) : plataformas(nnn, x)
{
    this->categoria=c;
    this->nombre_Ca=nC;
    this->podcast=p;
    this->creador=crea;
    this->vistas=v;
}

void contenidos::mostrar_playlist(void)
{
    mostrarPlataforma();
    cout<<"\n\tTiene categorias como: "<<categoria<<endl;
    cout<<"\tTambien canciones como: "<<nombre_Ca<<endl;
    cout<<"\tO si quieres podcast, hay de: "<<podcast<<endl;
    cout<<"\tTodo esto de diversos creadores como por ejemplo: "<<creador<<endl;
}

void contenidos::crear_albums(void)
{
    cout<<"\tEscucha el podcast de "<<podcast<<" de "<<creador<<" se llama "<<nombre_Ca<<" puedes encontrarlo en "<<platfor<<endl;
    cout<<"\tPara hacer la tarea tengo un album de canciones "<<categoria<<", mientras que para hacer quehacer pongo mas de "<<nombre_Ca<<endl;
}

