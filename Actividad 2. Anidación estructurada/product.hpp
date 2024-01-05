#ifndef PRODUCT_HPP_INCLUDED
#define PRODUCT_HPP_INCLUDED

#include <string>
#include <iomanip>
#include "date.hpp"

class Product {
    private:
        std::string barras, name;
        int exisTotal;
        float peso, precioMay, precioMenudeo;
        Date dateInt;

    public:
        Product();
        Product(const Product&);
        int max_array;

        std::string getBarras() const;
        std::string getName() const;
        int getExisTotal() const;
        float getPeso() const;
        float getPrecioMay() const;
        float getPrecioMenudeo() const;
        Date getDateInt() const;

        void setBarras(const std::string&);
        void setName(const std::string&);
        void setExisTotal(const int&);
        void setPeso(const float&);
        void setPrecioMay(const float&);
        void setPrecioMenudeo(const float&);
        void setDateInt(const Date&);

        Product& operator =(const Product&);
        bool operator == (const Product&) const;
        std::string toString() const;
    };


#endif // PRODUCT_HPP_INCLUDED
