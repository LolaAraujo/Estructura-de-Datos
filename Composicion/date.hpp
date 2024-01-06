#ifndef DATE_HPP_INCLUDED
#define DATE_HPP_INCLUDED

class Date{
private:
    int year;
    int month;
    int day;
public:
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);
};

#endif // DATE_HPP_INCLUDED
