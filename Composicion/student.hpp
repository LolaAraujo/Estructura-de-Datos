#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include <string>

#include "date.hpp"
#include "name.hpp"

class Student{
private:
    std::string code;
    Name name;
    Date birthDate;
    std::string career;
    Date startDate;
    float grade;

public:
    std::string getCode() const;
    Name getName() const;
    Date getBirthDate() const;
    std::string getCareer() const;
    Date getStartDate() const;
    float getGrade() const;

    void setCode(const std::string&);
    void setName(const Name&);
    void setBirthDate(const Date&);
    void setCareer(const std::string&);
    void setStartDate(const Date&);
    void setGrade(const float&);

    ///Compara valores de la misma clase
   // bool operator == (const Student&) const;
};


#endif // STUDENT_HPP_INCLUDED
