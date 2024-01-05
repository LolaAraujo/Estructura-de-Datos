#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

template <class A, int MAX = 300>
class List {
    private:
        // std::string listas[MAXIMO];
        int contLast;
        A playList[MAX]; //Cancion playList[MAX];
        void copyAll(const List<A, MAX>& );
        bool validPosition(const int&);
    public:
        Lista(); ///Inicialización de la lista
        Lista(const Lista&);


        bool listVacia();  ///Función de lista Vacia
        bool listFull();   ///Función de lista llena

        void insertMusic(const int&, const A& );//Cancion&);
        void deleteMusic(const int&); /// recibe la posición

        std::string getRegain(const int&); ///Recupera elemento de la lista

        ///Posiciones de la lista: Primera, Última, Anterior, Siguiente y Nula
        int getFirstPosition();
        int getLastPosition();
        int getBeforePosition(const int&);
        int getNextPosition(const int&);
        int getNull();

        std::string toString();
        List<A,MAX>& operator = (const List<A, MAX>&);
    };

///IMPLEMENTACION
using namespace std;

template<class A, int MAX>
void List<A, MAX>::copyAll(const List<A, MAX>& obj) {

    }

template<class A, int MAX>
List<A,MAX>::Lista(): contLast(-1) {} ///Inicialización

template<class A, int MAX>
List<A,MAX>::Lista(const Lista& element) {}

template<class A, int MAX>
bool List<A,MAX>::validPosition(const int& position) {
    return position >= 0 && position <= contLast;
    }

///LISTA VACIA
template<class A, int MAX>
bool List<A,MAX>::listVacia() {
    return contLast==-1;
    }

///LISTA LLENA
template<class A, int MAX>
bool List<A,MAX>::listFull() {
    return contLast == 49;
    }

///METODO INSERTAR
template<class A, int MAX>
void List<A,MAX>::insertMusic(const int& position, const Cancion& music) {
    int x=contLast;
    try {
        if(listFull()) {
            throw "Desbordamiento de Datos";
            return;
            }
        else if(position!=-1 && !validPosition(position)) {
            throw ("Posicion Invalida");
            return;
            }
        else if(listVacia()) {
            playList[contLast+1] = music;
            }
        else {
            while(x>position) {
                playList[x+1]=playList[x];
                x--;
                }
            playList[position+1]=music;
            }
        contLast++;
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        }
    }

///METODO ELIMINAR
template<class A, int MAX>
void List<A,MAX>::deleteMusic(const int& position) {
    int x(position);
    try {
        if(listVacia()) {
            throw "Insuficiencia de Datos";
            }
        else if(!validPosition(position)) {
            throw "Posicion Invalida";
            }
        else {
            while(x<contLast) {
                playList[x]=playList[x+1];

                x++;
                }
            contLast--;
            }
        }
    catch(const char *error) {
        cout<<error<<endl;
        getchar();
        }

    }

///RECUPERAR
template<class A, int MAX>
string List<A,MAX>::getRegain(const int& position) {
    try {
        if(!validPosition(position)) {
            throw "Cancion invalida en la lista";
            }
        }
    catch(const char *error) {
        cout<<error<<endl;
        }
    return playList[position].toString1();
    }

///PRIMERA POSICIÓN
template<class A, int MAX>
int List<A,MAX>::getFirstPosition() {
    if(listVacia()) {
        return -1;
        }
    return -1; ///Coloca en posición 0
    /// return 0 Coloca en posición 1
    }

///ÚLTIMA POSICIÓN
template<class A, int MAX>
int List<A,MAX>::getLastPosition() {
    return contLast;
    }

///ANTES DE CIERTA POSICIÓN
template<class A, int MAX>
int List<A,MAX>::getBeforePosition(const int& position) {
    if(position == getFirstPosition() || !validPosition(position)) {
        return -1;
        }
    return position-1;
    }

///DESPUÉS DE CIERTA POSICIÓN
template<class A, int MAX>
int List<A,MAX>::getNextPosition(const int& position) {
    if(position == getLastPosition() || !validPosition(position)) {
        return -1;
        }
    return position;
    }

///ANULAR/LIMPIAR LISTA
template<class A, int MAX>
int List<A,MAX>::getNull() {
    contLast=-1;
    }

template<class A, int MAX>
string List<A,MAX>::toString() {
    int i=0;
    string listComplete;
    char tam[5];

    while(i<=contLast) {
        sprintf(tam, "%i", i);
        listComplete += tam;
        listComplete += ". ";
        listComplete += playList[i].toString1();
        listComplete += "\n";
        i++;
        }
    return listComplete;
    }

template<class A, int MAX>
List<A,MAX>& List<A, MAX>::operator = (const List<A, MAX)& obj) {
    copyAll(obj);
    return *this;
    }

#endif // LIST_HPP_INCLUDED
