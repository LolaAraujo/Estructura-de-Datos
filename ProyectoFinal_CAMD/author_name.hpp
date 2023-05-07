#ifndef AUTHOR_NAME_HPP_INCLUDED
#define AUTHOR_NAME_HPP_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>

class NameA {
    private:
        std::string name;
        std::string lastname;
        void copyAll(const NameA&);

    public:
        NameA();
        NameA(const NameA&);

        bool operator == (const NameA&) const;
        bool operator != (const NameA&) const;
        bool operator >= (const NameA&) const;
        bool operator <= (const NameA&) const;
        bool operator > (const NameA&) const;
        bool operator < (const NameA&) const;

        static int compareByName(const NameA&, const NameA&);

        std::string getName() const;
        std::string getLastName() const;

        void setName(const std::string&);
        void setLastName(const std::string&);

        std::string toString() const;

        friend std::istream& operator >> (std::istream&, NameA&);
        friend std::ostream& operator << (std::ostream&, NameA&);
        NameA& operator = (const NameA&);
    };
#endif // AUTHOR_NAME_HPP_INCLUDED
