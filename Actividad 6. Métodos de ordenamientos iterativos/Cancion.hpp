#ifndef CANCION_HPP_INCLUDED
#define CANCION_HPP_INCLUDED

#include <string>
#include <iomanip>

class Cancion {
    private:
        std::string nameMusic, autor, interprete, mp3;
        int ranking;

    public:
        Cancion();
        Cancion(const Cancion&);

        bool operator == (const Cancion&) const;
        bool operator != (const Cancion&) const;
        bool operator >= (const Cancion&) const;
        bool operator <= (const Cancion&) const;
        bool operator > (const Cancion&) const;
        bool operator < (const Cancion&) const;

        friend std::istream& operator >> (std::istream&, Cancion&);
        friend std::ostream& operator << (std::ostream&, Cancion&);

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

        std::string toString1() const;
        Cancion& operator = (const Cancion&);

    };

#endif // CANCION_HPP_INCLUDED
