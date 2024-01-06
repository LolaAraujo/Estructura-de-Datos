#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class persona
{
    private:
        string nombre, orientacion;
        int edad;
    public:
        persona():nombre{""}, orientacion{""} ,edad{0}{};
        persona(string nnn,string ori, int ani):nombre{nnn},orientacion{ori} ,edad{ani}{};

        virtual void mostrar();
        virtual ~persona();
};

#endif // PERSONA_H
