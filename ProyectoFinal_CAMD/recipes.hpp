#ifndef RECIPES_HPP_INCLUDED
#define RECIPES_HPP_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
#include "author_name.hpp"
#include "ingredientes.hpp"
#include "ingredientList.hpp"

class Recetas {
    private:
        NameA nom;
        ListIngredient<Ingredients> ingredient;
        std::string category;
        std::string title;
        int time;
        std::string process;
        void copyAll(const Recetas&);

    public:
        Recetas();
        Recetas(const Recetas&);

        bool operator == (const Recetas&) const;
        bool operator != (const Recetas&) const;
        bool operator >= (const Recetas&) const;
        bool operator <= (const Recetas&) const;
        bool operator > (const Recetas&) const;
        bool operator < (const Recetas&) const;

        static int compareByCategory(const Recetas&, const Recetas&);
        static int compareByTitle(const Recetas&, const Recetas&);
        static int compareByTime(const Recetas&, const Recetas&);

        NameA getNom() const;
        ListIngredient<Ingredients> getIngredient() const;
        std::string getCategory() const;
        std::string getTitle() const;
        int getTime() const;
        std::string getProcess() const;

        void setNom(const NameA&);
        void setIngredient(const ListIngredient<Ingredients>&);
        void setCategory(const std::string&);
        void setTitle(const std::string&);
        void setTime(const int&);
        void setProcess(const std::string&);

        std::string toString() const;

        friend std::istream& operator >> (std::istream&, Recetas&);
        friend std::ostream& operator << (std::ostream&, Recetas&);
        Recetas& operator = (const Recetas&);

    };

#endif // RECIPES_HPP_INCLUDED
