#include "recipes.hpp"

using namespace std;

Recetas::Recetas() {}

Recetas::Recetas(const Recetas& r) {
    copyAll(r);
    }

void Recetas::copyAll(const Recetas& obj) {
    category = obj.category;
    title = obj.title;
    time = obj.time;
    nom = obj.nom;
    ingredient = obj.ingredient;
    process = obj.process;
    }

Recetas& Recetas::operator=(const Recetas& obj) {
    copyAll(obj);
    return *this;
    }

bool Recetas::operator==(const Recetas& obj) const {
    return title == obj.title;
    }

bool Recetas::operator!=(const Recetas& obj) const {
    return title != obj.title;
    }

bool Recetas::operator>=(const Recetas& obj) const {
    return title >= obj.title;
    }

bool Recetas::operator<=(const Recetas& obj) const {
    return title <= obj.title;
    }

bool Recetas::operator>(const Recetas& obj) const {
    return title > obj.title;
    }

bool Recetas::operator<(const Recetas& obj) const {
    return title < obj.title;
    }

int Recetas::compareByTitle(const Recetas& a, const Recetas& b) {
    return a.title.compare(b.title);
    }

int Recetas::compareByCategory(const Recetas& a, const Recetas& b) {
    return a.category.compare(b.category);
    }

int Recetas::compareByTime(const Recetas& a, const Recetas& b) {
    return a.time - b.time;
    }

NameA Recetas::getNom() const {
    return nom;
    }

ListIngredient<Ingredients> Recetas::getIngredient() const {
    return ingredient;
    }

string Recetas::getCategory() const {
    return category;
    }

string Recetas::getTitle() const {
    return title;
    }

int Recetas::getTime() const {
    return time;
    }

string Recetas::getProcess() const {
    return process;
    }

void Recetas::setNom(const NameA& _nom) {
    nom = _nom;
    }

void Recetas::setIngredient(const ListIngredient<Ingredients>& _ingredient) {
    ingredient = _ingredient;
    }

void Recetas::setCategory(const string& _category) {
    category = _category;
    }

void Recetas::setTitle(const string& _title) {
    title = _title;
    }

void Recetas::setTime(const int& _time) {
    time = _time;
    }

void Recetas::setProcess(const string& _process) {
    process= _process;
    }

std::ostream& operator << (std::ostream& os, Recetas& obj){
    ListIngredient<Ingredients>::Position aux;
    aux = obj.ingredient.getFirstPosition();

    os << obj.category << endl;
    os << obj.title<< endl;
    os << obj.nom <<endl;
    //os << obj.ingredient.toString() << endl;
    os << obj.time << endl;
    os << obj.process << endl;
    return os;
    }

std::istream& operator >> (istream& is, Recetas& obj) {
    ListIngredient<Ingredients>::Position aux;
    string myStr;
    aux = obj.ingredient.getFirstPosition();

    getline(is, obj.category);
    getline(is, obj.title);
    is >> obj.nom;
    /*do{
        is >> obj.ingredient.retrieve(aux);
        aux = aux->getNext();
    }while(aux != nullptr);*/
    getline(is, myStr);
    obj.time = atoi(myStr.c_str());
    getline(is, obj.process);
    return is;
    }

string Recetas::toString() const {
    string myStr;

    myStr += "\tCategoria: ";
    myStr += category;
    myStr += "\n";

    myStr += "\tReceta: ";
    myStr += title;
    myStr += "\n";

    myStr += "\tTiempo Estimado: ";
    myStr += to_string(time);
    myStr += " min.\n";

    myStr += "\tAuthor: ";
    myStr += nom.toString();
    myStr += "\n";

    myStr += "\n\tIngredientes: \n";
    myStr += getIngredient().toString();
    myStr += "\n";

    myStr += "\tProcedimiento: \n";
    myStr += process;
    myStr += "\n";
    return myStr;
    }
