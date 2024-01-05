#include <iostream>
#include "product.hpp"

using namespace std;

Product::Product() {

    }

Product::Product(const Product& pd): barras(pd.barras), name(pd.name), exisTotal(pd.exisTotal),peso(pd.peso), precioMay(pd.precioMay),precioMenudeo(pd.precioMenudeo), dateInt(pd.dateInt), max_array(pd.max_array) {}

Product& Product::operator=(const Product& pd) {
    barras=pd.barras;
    name=pd.name;
    exisTotal=pd.exisTotal;
    peso=pd.peso;
    precioMay=pd.precioMay;
    precioMenudeo=pd.precioMenudeo;
    dateInt=pd.dateInt;
    max_array=0;

    return *this;
    }


string Product::getBarras() const {
    return barras;
    }

string Product::getName() const {
    return name;
    }

int Product::getExisTotal() const {
    return exisTotal;
    }

float Product::getPeso() const {
    return peso;
    }

float Product::getPrecioMay() const {
    return precioMay;
    }

float Product::getPrecioMenudeo() const {
    return precioMenudeo;
    }

Date Product::getDateInt() const {
    return dateInt;
    }

void Product::setBarras(const std::string& bar) {
    barras=bar;
    }

void Product::setName(const string& nom) {
    name=nom;
    }

void Product::setExisTotal(const int& exT) {
    exisTotal=exT;
    }

void Product::setPeso(const float& pes) {
    peso=pes;
    }

void Product::setPrecioMay(const float& preM) {
    precioMay = preM;
    }

void Product::setPrecioMenudeo(const float& prMn) {
    precioMenudeo=prMn;
    }

void Product::setDateInt(const Date& starD) {
    dateInt = starD;
    }

bool Product::operator==(const Product& ptr) const {
    return getBarras()== ptr.getBarras();
    }

string Product::toString() const {
    string temp;
    char cantidades[50];

    temp = barras;
    temp += "|";
    setw(10);
    temp += name;
    temp += "|";
    setw(10);
    sprintf(cantidades, "%d", exisTotal);
    temp += cantidades;
    temp += "|";
    setw(10);
    sprintf(cantidades, "%.2f", peso);
    temp += cantidades;
    temp += "|";
    setw(10);
    sprintf(cantidades, "%.2f", precioMay);
    temp += cantidades;
    temp += "|";
    setw(10);
    sprintf(cantidades, "%.2f", precioMenudeo);
    temp += cantidades;
    temp += "|";
    setw(10);
    temp += dateInt.toString1();

    return temp+="\n";
    }
