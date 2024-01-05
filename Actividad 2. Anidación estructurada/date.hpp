#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

#include <string>

class Date {
    private:
        int year;
        int month;
        int day;
    public:
        Date();
        Date(const int&, int&, int&);

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        void setYear(const int&);
        void setMonth(const int&);
        void setDay(const int&);

        std::string toString1() const;
    };

#endif // DATE_HPP_INCLUDED
