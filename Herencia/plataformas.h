#ifndef PLATAFORMAS_H
#define PLATAFORMAS_H
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class plataformas
{
    protected:
        string platfor, color;

    public:
        plataformas(): platfor{""},color{""}{};
        plataformas(string nnn, string x): platfor{nnn}, color{x}{};

        virtual int playlist()=0;

        void mostrarPlataforma(){cout<<"\tEl color "<<color<<" pertenece a la plataforma "<<platfor<<endl;};
};

#endif // PLATAFORMAS_H
