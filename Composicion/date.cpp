#include "date.hpp"

using namespace std;

int Date::getYear() const
{
    return year;

}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

void Date::setYear(const int& y)
{
    year=y;
}

void Date::setMonth(const int& m)
{
    month=m;
}

void Date::setDay(const int& d)
{
    day=d;

}
