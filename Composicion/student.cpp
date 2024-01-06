#include "student.hpp"

using namespace std;
string Student::getCode() const
{
    return code;
}

Name Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

string Student::getCareer() const
{
    return career;
}

Date Student::getStartDate() const
{

}

float Student::getGrade() const
{
    return grade;
}

//sprintf.rezise(40+ "); size para aumentar tamaño

void Student::setCode(const string& co)
{
    code=co;
}

void Student::setName(const Name& n)
{
    name=n;
}

void Student::setBirthDate(const Date& bd)
{
    birthDate=bd;
}

void Student::setCareer(const string& ca)
{
    career=ca;
}

void Student::setStartDate(const Date& sd)
{
    startDate=sd;
}
