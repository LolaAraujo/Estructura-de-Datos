#include "Cancion.hpp"

using namespace std;

Cancion::Cancion() { }

Cancion::Cancion(const Cancion& song):nameMusic(song.nameMusic),autor(song.autor),interprete(song.interprete),ranking(song.ranking),mp3(song.mp3) { }

Cancion& Cancion::operator=(const Cancion& song) {
    nameMusic = song.nameMusic;
    autor = song.autor;
    interprete = song.interprete;
    ranking = song.ranking;
    mp3 = song.mp3;

    return *this;
    }

bool Cancion::operator==(const Cancion& c) const {
    return nameMusic == c.nameMusic || interprete == c.interprete;
    }

bool Cancion::operator!=(const Cancion& c) const {
    return nameMusic != c.nameMusic || interprete != c.interprete; //!(*this == c);
    }

bool Cancion::operator>=(const Cancion& c) const {
    return nameMusic >= c.nameMusic || interprete >= c.interprete; //!(*this < c);
    }

bool Cancion::operator<=(const Cancion& c) const {
    return nameMusic <= c.nameMusic || interprete <= c.interprete; //*this < c || *this == c;
    }

bool Cancion::operator>(const Cancion& c) const {
    return nameMusic > c.nameMusic || interprete > c.interprete; //!(*this <= c);
    }

bool Cancion::operator<(const Cancion& c) const {
    return nameMusic < c.nameMusic || interprete < c.interprete;
    }

int Cancion::compareByNameMusic(const Cancion&, const Cancion&) {}

int Cancion::compareByInterprete(const Cancion&, const Cancion&) {}

string Cancion::getNameMusic() const {
    return nameMusic;
    }

string Cancion::getAutor() const {
    return autor;
    }

string Cancion::getInterprete() const {
    return interprete;
    }

int Cancion::getRanking() const{
    return ranking;
}

string Cancion::getMp3() const {
    return mp3;
    }

void Cancion::setNameMusic(const string& songs) {
    nameMusic=songs;
    }

void Cancion::setAutor(const string& creador) {
    autor=creador;
    }

void Cancion::setInterprete(const string& inter) {
    interprete=inter;
    }

void Cancion::setRanking(const int& rang){
    ranking = rang;
}

void Cancion::setMp3(const string& _mp3) {
    mp3=_mp3;
    }

string Cancion::toString1() const {
    string temp;

    temp = nameMusic;
    temp.resize(30,' ');
    temp += " || ";

    temp += autor;
    temp.resize(60, ' ');
    temp += " || ";

    temp += interprete;
    temp.resize(80,' ');
    temp += " || ";

    temp += to_string(ranking);
    temp.resize(93,' ');
    temp += " || ";

    temp += mp3;

    return temp;
    }
