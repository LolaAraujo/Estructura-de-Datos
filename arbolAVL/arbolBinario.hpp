#ifndef ARBOLBINARIO_HPP_INCLUDED
#define ARBOLBINARIO_HPP_INCLUDED
#include <iostream>
#include <string>
#include <exception>

template <class T>
class ArbolB {
    private:
        class Node {
            private:
                T* dataPtr;
                Node* left;
                Node* right;

            public:
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

                Node();
                Node(const T&);
                ~Node();

                T* getDataPtr() const;
                T getData() const;
                Node*& getLeft();
                Node*& getRight();

                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Node*&);
                void setRight(Node*&);
            };

    public:
        typedef Node* Position;

    private:
        Position root;

        void copyAll(const ArbolB<T>&);
        void insertData(Position&, const T&);
        void deleteData(Position&, const T&);

        Position& findData(Position&, const T&);
        Position& getLowest(Position&);
        Position& getHighest(Position&);

        void preOrder(Position&);
        void inOrder(Position&);
        void posOrder(Position&);



    public:
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

        ArbolB();
        ArbolB(const ArbolB<T>&);
        ~ArbolB();

        bool isEmpty() const;
        bool isLeaf(Position&) const;

        void insertData(const T&);
        void deleteData(const T&);
        void deleteAll();
        T retrieve(Position&) const;

        int getHeight(Position&);
        int getHeight();
        int getHeightRight();
        int getHeightLeft();
        Position& findData(const T&);
        Position& getLowest();
        Position& getHighest();

        void preOrder();
        void inOrder();
        void posOrder();

        ArbolB& operator = (const ArbolB&);
    };

#endif // ARBOLBINARIO_HPP_INCLUDED


///IMPLEMENTACION NODO

using namespace std;
template <class T>
ArbolB<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) { }

template <class T>
ArbolB<T>::Node::Node(const T& m) : dataPtr(new T(m)), left(nullptr), right(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, se creara un nodo");
        }
    }

template <class T>
ArbolB<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* ArbolB<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T ArbolB<T>::Node::getData() const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr;
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::Node::getLeft() {
    return left;
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::Node::getRight() {
    return right;
    }

template <class T>
void ArbolB<T>::Node::setDataPtr(T* pos) {
    dataPtr = pos;
    }

template <class T>
void ArbolB<T>::Node::setData(const T& e) {
    if(dataPtr == nullptr) {
        if((dataPtr = new T(e)) == nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr = e;
        }
    }

template <class T>
void ArbolB<T>::Node::setLeft(Position& pos) {
    left = pos;
    }

template <class T>
void ArbolB<T>::Node::setRight(Position& pos) {
    right = pos;
    }

///IMPLEMENTACION ARBOL

template <class T>
ArbolB<T>::ArbolB() : root(nullptr) {}

template <class T>
ArbolB<T>::ArbolB(const ArbolB& t) : root(nullptr) {
    copyAll(t);
    }

template <class T>
ArbolB<T>::~ArbolB() {
    deleteAll();
    }

template <class T>
void ArbolB<T>::copyAll(const ArbolB<T>& l) {
    Position newNode;

    try {
        if((newNode = new Node(l.aux->getData())) == nullptr) {
            throw Exception("Memoria no disponible, copyAll");
            }
        }
    catch(Exception ex) {
        throw Exception(ex.what());
        }
    root = new Node(l.root->getData());
    root->getLeft() = l.root->getLeft();
    root->getRight() = l.root->getRight();
    }

template <class T>
bool ArbolB<T>::isEmpty() const {
    return root == nullptr;
    }

template <class T>
void ArbolB<T>::insertData(const T& d) {
    insertData(root, d);
    }

template <class T>
void ArbolB<T>::insertData(Position& r, const T& d) {
    if(r == nullptr) {
        try {
            if((r= new Node(d)) == nullptr) {
                throw Exception("Memoria no disponible, insertData");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if(d < r->getData()) {
            insertData(r->getLeft(), d);
            }
        else {
            insertData(r->getRight(), d);
            }
        }
    }

template <class T>
void ArbolB<T>::deleteData(const T& d) {
    deleteData(root, d);
    }

template <class T>
void ArbolB<T>::deleteData(Position& e, const T& d) {
    if(e == nullptr) {
        return;
        }

    if(e->getData() == d) {
        if(isLeaf(e)) { ///si es hoja
            delete e;
            e = nullptr;
            return;
            }

        ///caso de dos hojas
        if(e->getLeft() != nullptr && e->getRight() != nullptr) {
            T myData(getHighest(e->getLeft())->getData());

            deleteData(e->getLeft(), myData);
            e->setData(myData);
            return;
            }

        ///Casi una sola hoja
        Position aux(e);
        e = e->getLeft() == nullptr ? e->getRight() : e->getLeft();
        delete aux;
        return;
        }

    if(d < e->getData()) {
        deleteData(e->getLeft(), d);
        }
    else {
        deleteData(e->getRight(), d);
        }
    }

template <class T>
T ArbolB<T>::retrieve(Position& r) const {
    return r->getData();
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::findData(const T& e) {
    return findData(root, e);
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::findData(Position& r, const T& e) {
    if(r == nullptr || r->getData() == e) {
        return r;
        }

    if(e < r->getData()) {
        return findData(r->getLeft(), e);
        }
    else {
        return findData(r->getRight(), e);
        }
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::getLowest(Position& r) {
    if(r == nullptr || r->getLeft() == nullptr) {
        return r;
        }
    return getLowest(r->getLeft());
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
typename ArbolB<T>::Position& ArbolB<T>::getHighest(Position& r) {
    if(r == nullptr || r->getRight() == nullptr) {
        return r;
        }
    return getHighest(r->getRight());
    }

template <class T>
bool ArbolB<T>::isLeaf(Position& r) const {
    return r != nullptr && r->getLeft() == r->getRight();
    }

template <class T>
int ArbolB<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
int ArbolB<T>::getHeight(Position& r) {
    if(r == nullptr) {
        return 0;
        }

    int lH(getHeight(r->getLeft()));
    int rH(getHeight(r->getRight()));

    return(lH > rH ? lH : rH) + 1;
    }

template <class T>
int ArbolB<T>::getHeightRight() {
    return getHeight(root->getRight());
    }

template <class T>
int ArbolB<T>::getHeightLeft() {
    return getHeight(root->getLeft());
    }

template <class T>
void ArbolB<T>::preOrder() {
    preOrder(root);
    }

template <class T>
void ArbolB<T>::preOrder(Position& r) {
    if(r == nullptr) {
        return;
        }
    std::cout << r->getData() << ", ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
    }

template <class T>
void ArbolB<T>::inOrder() {
    inOrder(root);
    }

template <class T>
void ArbolB<T>::inOrder(Position& r) {
    if(r == nullptr) {
        return;
        }
    inOrder(r->getLeft());
    std::cout << r->getData() << ", ";
    inOrder(r->getRight());
    }

template <class T>
void ArbolB<T>::posOrder() {
    posOrder(root);
    }

template <class T>
void ArbolB<T>::posOrder(Position& r) {
    if(r == nullptr) {
        return;
        }
    posOrder(r->getLeft());
    posOrder(r->getRight());
    std::cout << r->getData() << ", ";
    }

template <class T>
void ArbolB<T>::deleteAll() {
    if(root == nullptr) {
        return;
        }
    deleteData(root->getLeft(), root->getData());
    deleteData(root->getRight(), root->getData());
    delete root;
    root = nullptr;
    }

template <class T>
ArbolB<T>& ArbolB<T>::operator = (const ArbolB& e) {
    deleteAll();
    copyAll(e);
    return *this;
    }
