#ifndef INGREDIENTES_HPP_INCLUDED
#define INGREDIENTES_HPP_INCLUDED
#include <string>
#include <iostream>

class Ingredients {
    private:
        std::string nameIngr;
        std::string quantity;
        void copyAll(const Ingredients&);

    public:
        Ingredients();
        Ingredients(const Ingredients&);

        bool operator == (const Ingredients&) const;
        bool operator != (const Ingredients&) const;
        bool operator >= (const Ingredients&) const;
        bool operator <= (const Ingredients&) const;
        bool operator > (const Ingredients&) const;
        bool operator < (const Ingredients&) const;

        static int compareByNameIngr(const Ingredients&, const Ingredients&);

        std::string getNameIngr() const;
        std::string getQuantity() const;

        void setNameIngr(const std::string&);
        void setQuantity(const std::string&);

        std::string toString() const;

        friend std::istream& operator >> (std::istream&, Ingredients&);
        friend std::ostream& operator << (std::ostream&, Ingredients&);
        Ingredients& operator = (const Ingredients&);

    };

#endif // INGREDIENTES_HPP_INCLUDED
