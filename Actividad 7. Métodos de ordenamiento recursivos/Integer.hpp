#ifndef INTEGER_HPP_INCLUDED
#define INTEGER_HPP_INCLUDED
#include <iostream>

class Integer {
    private:
        unsigned int data;

    public:
        Integer();
        Integer(int&);
        Integer(const Integer&);

        void setData(const int& );
        int getData() const;

        std::string toString() const;

        //OPERATORS
        Integer& operator = (const Integer&);
        Integer& operator = (const int&);

        Integer& operator *= (const Integer&);
        Integer& operator /= (const Integer&);
        Integer& operator += (const Integer&);
        Integer& operator -= (const Integer&);
        Integer& operator %= (const Integer&);

        Integer& operator - (const Integer&);
        Integer& operator + (const Integer&);
        Integer& operator * (const Integer&);
        Integer& operator / (const Integer&);
        Integer& operator % (const Integer&);

        Integer& operator ++();
        Integer operator ++(int);
        Integer& operator --();
        Integer operator --(int);

        bool operator == (const Integer&) const;
        bool operator != (const Integer&) const;
        bool operator >= (const Integer&) const;
        bool operator <= (const Integer&) const;
        bool operator > (const Integer&) const;
        bool operator < (const Integer&) const;

        int compareTo(const Integer&) const;
        static int compare(const Integer&, const Integer&);
        friend std::istream& operator >> (std::istream&, Integer&);
        friend std::ostream& operator << (std::ostream&, Integer&);

    };

#endif // INTEGER_HPP_INCLUDED
