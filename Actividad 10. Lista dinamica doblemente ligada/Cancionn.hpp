#ifndef CANCIONN_HPP_INCLUDED
#define CANCIONN_HPP_INCLUDED

template <class T>
class Cancion {
    private:
        std::string nameMusic;
        std::string autor;
        std::string interprete;
        std::string mp3;
        int ranking;
        void copyAll(const T&);

    public:
        Cancion();
        Cancion(const Cancion<T>&);

        bool operator == (const T&) const;
        bool operator != (const T&) const;
        bool operator >= (const T&) const;
        bool operator <= (const T&) const;
        bool operator > (const T&) const;
        bool operator < (const T&) const;

        static int compareByNameMusic(const T&, const T&);
        static int compareByInterprete(const T&, const T&);

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
        friend std::istream& operator >> (std::istream&, T&);
        friend std::ostream& operator << (std::ostream&, T&);
        Cancion<T>& operator = (const Cancion<T>&);

    };

///IMPLEMENTACION

using namespace std;

template <class T>
Cancion<T>::Cancion() { }

template <class T>
Cancion<T>::Cancion(const Cancion& c) {
    copyAll(c);
    }

template <class T>
void Cancion<T>::copyAll(const T& song) {
    nameMusic = song.nameMusic;
    autor = song.autor;
    interprete = song.interprete;
    ranking = song.ranking;
    mp3 = song.mp3;
    }

template <class T>
Cancion<T>& Cancion<T>::operator=(const Cancion& song) {
    copyAll(song);
    return *this;
    }

template <class T>
bool Cancion<T>::operator==(const T& c) const {
    return nameMusic == c.nameMusic || interprete == c.interprete;
    }

template <class T>
bool Cancion<T>::operator!=(const T& c) const {
    return nameMusic != c.nameMusic || interprete != c.interprete; //!(*this == c);
    }

template <class T>
bool Cancion<T>::operator>=(const T& c) const {
    return nameMusic >= c.nameMusic || interprete >= c.interprete; //!(*this < c);
    }

template <class T>
bool Cancion<T>::operator<=(const T& c) const {
    return nameMusic <= c.nameMusic || interprete <= c.interprete; //*this < c || *this == c;
    }

template <class T>
bool Cancion<T>::operator>(const T& c) const {
    return nameMusic > c.nameMusic || interprete > c.interprete; //!(*this <= c);
    }

template <class T>
bool Cancion<T>::operator<(const T& c) const {
    return nameMusic < c.nameMusic || interprete < c.interprete;
    }

template <class T>
int Cancion<T>::compareByNameMusic(const T& a, const T& b) {
    return a.nameMusic.compare(b.nameMusic);
    }

template <class T>
int Cancion<T>::compareByInterprete(const T& a, const T& b) {
    return a.interprete.compare(b.interprete);
    }

template <class T>
string Cancion<T>::getNameMusic() const {
    return nameMusic;
    }

template <class T>
string Cancion<T>::getAutor() const {
    return autor;
    }

template <class T>
string Cancion<T>::getInterprete() const {
    return interprete;
    }

template <class T>
int Cancion<T>::getRanking() const {
    return ranking;
    }

template <class T>
string Cancion<T>::getMp3() const {
    return mp3;
    }

template <class T>
void Cancion<T>::setNameMusic(const string& songs) {
    nameMusic=songs;
    }

template <class T>
void Cancion<T>::setAutor(const string& creador) {
    autor=creador;
    }

template <class T>
void Cancion<T>::setInterprete(const string& inter) {
    interprete=inter;
    }

template <class T>
void Cancion<T>::setRanking(const int& rang) {
    ranking = rang;
    }

template <class T>
void Cancion<T>::setMp3(const string& _mp3) {
    mp3=_mp3;
    }

template <class T>
ostream& operator << (std::ostream& os, T& obj) {
    os << obj.nameMusic << endl;
    os << obj.autor << endl;
    os << obj.interprete << endl;
    os << obj.ranking << endl;
    os << obj.mp3;
    return os;
    }

template <class T>
istream& operator >> (istream& is, T& obj) {
    string myStr;

    getline(is, obj.nameMusic);
    getline(is, obj.autor);
    getline(is, obj.interprete);
    getline(is, myStr);
    obj.ranking = atoi(myStr.c_str());
    getline(is, obj.mp3);
    }

template <class T>
string Cancion<T>::toString() const {
    string temp;

    temp += nameMusic;
    temp.resize(30,' ');
    temp += " || ";

    temp += autor;
    temp.resize(60, ' ');
    temp += " || ";

    temp += interprete;
    temp.resize(100,' ');
    temp += " || ";

    temp += to_string(ranking);
    temp.resize(113,' ');
    temp += " || ";

    temp += mp3;
    temp += " ";

    return temp;
    }

#endif // CANCIONN_HPP_INCLUDED
