#ifndef CANCION_HPP_INCLUDED
#define CANCION_HPP_INCLUDED
#include <iostream>
#include <string>

class Cancion {
    private:
        std::string nameMusic;
        std::string autor;
        std::string interprete;
        std::string mp3;
        int ranking;
        void copyAll(const Cancion&);

    public:
        Cancion();
        bool operator == (const Cancion&) const;
        bool operator != (const Cancion&) const;
        bool operator >= (const Cancion&) const;
        bool operator <= (const Cancion&) const;
        bool operator > (const Cancion&) const;
        bool operator < (const Cancion&) const;

        static int compareByNameMusic(const Cancion&, const Cancion&);
        static int compareByInterprete(const Cancion&, const Cancion&);

        std::string getNameMusic() const;
        std::string getAutor() const;
        std::string getInterprete() const;
        std::string getMp3() const;
        int getRanking() const;

        void setNameMusic(const std::string&);
        void setAutor(const std::string&);
        void setInterprete(const std::string&);
        void setMp3(const std::string&);
        void setRanking(const int&);

        std::string toString() const;
        friend std::istream& operator >> (std::istream&, Cancion&);
        friend std::ostream& operator << (std::ostream&, Cancion&);
        Cancion& operator = (const Cancion&);

    };

#endif // CANCION_HPP_INCLUDED
