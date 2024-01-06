#ifndef NAME_HPP_INCLUDED
#define NAME_HPP_INCLUDED
///Archivo de definición no usar namespace, definir las cosas en privado
#include <string>

class Name {
    private:
        std::string last;
        std::string first;

    public:
        std::string getLast() const;
        std::string getFirst() const;
        void setLast(const std::string&);
        void setFirst(const std::string&);
    };


#endif // NAME_HPP_INCLUDED
