#ifndef LOLEXCEPTION_HPP_INCLUDED
#define LOLEXCEPTION_HPP_INCLUDED
#include <exception>
#include <iostream>
class Exception: public std::exception {

    private:
        std::string msg;
    public:
        explicit Exception(const char* message): msg(message) {}
        explicit Exception(const std::string& message): msg(message) {}
        virtual ~Exception()throw() {}
        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

#endif // LOLEXCEPTION_HPP_INCLUDED
