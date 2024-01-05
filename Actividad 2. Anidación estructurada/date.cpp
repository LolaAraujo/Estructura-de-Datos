#include "date.hpp"

Date::Date() {

    }

Date::Date(const int& y, int& m, int& d) {
    year=y;
    month=m;
    day=d;
    }

using namespace std;

int Date::getYear() const {
    return year;

    }

int Date::getMonth() const {
    return month;
    }

int Date::getDay() const {
    return day;
    }

void Date::setYear(const int& y) {
    year=y;
    }

void Date::setMonth(const int& m) {
    month=m;
    }

void Date::setDay(const int& d) {
    day=d;

    }
string Date::toString1() const {
    string temp;
    char out[10];

    sprintf(out, "%i", day);
    temp += out;
    temp += '/';
    sprintf(out, "%i", month);
    temp += out;
    temp += '/';
    sprintf(out, "%i", year);
    temp += out;

    return temp;
    }

