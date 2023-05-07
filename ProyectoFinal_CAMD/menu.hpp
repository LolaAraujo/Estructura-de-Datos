#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED
#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "recipes.hpp"
#include "ingredientes.hpp"
#include "recipesList.hpp"
#include "ingredientList.hpp"

class Menu {
    private:
        void marco(int, int, int, int);
        void gotoxy(int, int);
        void coordinates();

        void view(ListRecipes<Recetas> &);
        void recipeMenu(ListRecipes<Recetas> &);
        ListRecipes<Recetas> addRecipe();
        ListIngredient<Ingredients> addIngredients(ListIngredient<Ingredients>);
        void searchRecipe(ListRecipes<Recetas> &);
        void modifyRecipe(ListRecipes<Recetas> &);
        void deleteeR(ListRecipes<Recetas> &);
        void sortRecipe(ListRecipes<Recetas> &);

        void ingrediMenu(ListRecipes<Recetas> &);
        ListRecipes<Recetas> ingredientIntoRecipe(ListRecipes<Recetas>&);
        void modifyIngred(ListRecipes<Recetas> &);
        void deleteeI(ListRecipes<Recetas>&);
        void deleteAllIngred(ListRecipes<Recetas>&);

        void systemPause();
        void writeFromDisk(ListRecipes<Recetas> &);
        void readFromDisk(ListRecipes<Recetas> &);

    public:
        Menu();
    };

#endif // MENU_HPP_INCLUDED
