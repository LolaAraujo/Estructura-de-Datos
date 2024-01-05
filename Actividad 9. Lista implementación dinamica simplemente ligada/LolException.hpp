#ifndef LOLEXCEPTION_HPP_INCLUDED
#define LOLEXCEPTION_HPP_INCLUDED
#include <exception>
#include <iostream>
class LolException: public std::exception {
    private:
        std::string msg;
    public:
        explicit LolException(const char* message): msg(message) {}
        explicit LolException(const std::string& message): msg(message) {}
        virtual ~LolException()throw() {}
        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

#endif // LOLEXCEPTION_HPP_INCLUDED
