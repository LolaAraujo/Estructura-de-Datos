#ifndef CONTENIDOS_H
#define CONTENIDOS_H
#include "plataformas.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class contenidos : public plataformas
{
    protected:
        string categoria, nombre_Ca, podcast,creador;
        int vistas;

    public:
        contenidos();
        contenidos(string, string, string, string, string, string, int);

        void mostrar_playlist(void);
        void crear_albums(void);

        int playlist(){return 10;}
};

#endif // CONTENIDOS_H
