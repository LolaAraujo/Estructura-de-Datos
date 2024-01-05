#ifndef ARBOLAVL_HPP_INCLUDED
#define ARBOLAVL_HPP_INCLUDED
#include <iostream>
#include <string>
#include <exception>

template <class T>
class ArbolAVL {
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

        Node* root;

        void copyAll(const ArbolAVL<T>&);
        void insertData(Node*&, const T&);
        void deleteData(Node*&, const T&);

        Node*& findData(Node*&, const T&);
        Node*& getLowest(Node*&);
        Node*& getHighest(Node*&);

        void preOrder(Node*&);
        void inOrder(Node*&);
        void posOrder(Node*&);

        int getBalanceFactor(Node*&);
        void simpleLeftRoot(Node*&);
        void simpleRightRoot(Node*&);
        void doubleLeftRoot(Node*&);
        void doubleRightRoot(Node*&);
        void balancing(Node*&);

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

        ArbolAVL();
        ArbolAVL(const ArbolAVL<T>&);
        ~ArbolAVL();

        bool isEmpty() const;
        bool isLeaf(Node*&) const;

        void insertData(const T&);
        void deleteData(const T&);
        void deleteAll();
        T retrieve(Node*&) const;

        int getHeight(Node*&);
        int getHeight();
        int getHeightRight();
        int getHeightLeft();
        Node*& findData(const T&);
        Node*& getLowest();
        Node*& getHighest();

        void preOrder();
        void inOrder();
        void posOrder();

        ArbolAVL& operator = (const ArbolAVL&);
    };

#endif // ARBOLAVL_HPP_INCLUDED


///IMPLEMENTACION NODO

using namespace std;
template <class T>
ArbolAVL<T>::Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) { }

template <class T>
ArbolAVL<T>::Node::Node(const T& m) : dataPtr(new T(m)), left(nullptr), right(nullptr) {
    if(dataPtr == nullptr) {
        throw Exception("Memoria insuficiente, se creara un nodo");
        }
    }

template <class T>
ArbolAVL<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* ArbolAVL<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T ArbolAVL<T>::Node::getData() const {
    if(dataPtr == nullptr) {
        throw Exception("Dato inexistente, getData");
        }
    return *dataPtr;
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::Node::getLeft() {
    return left;
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::Node::getRight() {
    return right;
    }

template <class T>
void ArbolAVL<T>::Node::setDataPtr(T* pos) {
    dataPtr = pos;
    }

template <class T>
void ArbolAVL<T>::Node::setData(const T& e) {
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
void ArbolAVL<T>::Node::setLeft(Node*& pos) {
    left = pos;
    }

template <class T>
void ArbolAVL<T>::Node::setRight(Node*& pos) {
    right = pos;
    }

///IMPLEMENTACION ARBOL

template <class T>
ArbolAVL<T>::ArbolAVL() : root(nullptr) {}

template <class T>
ArbolAVL<T>::ArbolAVL(const ArbolAVL& t) : root(nullptr) {
    copyAll(t);
    }

template <class T>
ArbolAVL<T>::~ArbolAVL() {
    deleteAll();
    }

template <class T>
void ArbolAVL<T>::copyAll(const ArbolAVL<T>& l) {
    Node* newNode;

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
bool ArbolAVL<T>::isEmpty() const {
    return root == nullptr;
    }

template <class T>
void ArbolAVL<T>::insertData(const T& d) {
    insertData(root, d);
    }

template <class T>
void ArbolAVL<T>::insertData(Node*& r, const T& d) {
    if(r == nullptr) {  ///esta balanceado, inserta como hoja
        try {
            if((r= new Node(d)) == nullptr) {
                throw Exception("Memoria no disponible, insertData");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    ///inserta recursivamente
    else {
        if(d < r->getData()) {
            insertData(r->getLeft(), d);
            }
        else {
            insertData(r->getRight(), d);
            }
        balancing(r);
        }
    }

template <class T>
int ArbolAVL<T>::getBalanceFactor(Node*& e) {
    return (e == nullptr) ? 0 : getHeight(e->getRight()) - getHeight(e->getLeft());
    }

template <class T>
void ArbolAVL<T>::simpleLeftRoot(Node*& e) {
    Node* aux1(e->getRight());
    Node* aux2(aux1->getLeft());

    e->setRight(aux2);
    aux1->setLeft(e);
    e = aux1;
    }

template <class T>
void ArbolAVL<T>::simpleRightRoot(Node*& e) {
    Node* aux1(e->getLeft());
    Node* aux2(aux1->getRight());

    e->setLeft(aux2);
    aux1->setRight(e);
    e = aux1;
    }

template <class T>
void ArbolAVL<T>::doubleLeftRoot(Node*& e) {
    simpleRightRoot(e->getRight());
    simpleLeftRoot(e);
    }

template <class T>
void ArbolAVL<T>::doubleRightRoot(Node*& e) {
    simpleLeftRoot(e->getLeft());
    simpleRightRoot(e);
    }

template <class T>
void ArbolAVL<T>::balancing(Node*& e) {
    switch(getBalanceFactor(e)) {
        ///Desbalanceado a la izq
        case -2:
            getBalanceFactor(e->getLeft()) == -1 ? simpleRightRoot(e) : doubleRightRoot(e);
            break;
        ///desbalanceado a la der
        case 2:
            getBalanceFactor(e->getRight()) == 1 ? simpleLeftRoot(e) : doubleLeftRoot(e);
            break;
        }
    }

template <class T>
void ArbolAVL<T>::deleteData(const T& d) {
    deleteData(root, d);
    }

template <class T>
void ArbolAVL<T>::deleteData(Node*& e, const T& d) {
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
        Node* aux(e);
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
T ArbolAVL<T>::retrieve(Node*& r) const {
    return r->getData();
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::findData(const T& e) {
    return findData(root, e);
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::findData(Node*& r, const T& e) {
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
typename ArbolAVL<T>::Node*& ArbolAVL<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::getLowest(Node*& r) {
    if(r == nullptr || r->getLeft() == nullptr) {
        return r;
        }
    return getLowest(r->getLeft());
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
typename ArbolAVL<T>::Node*& ArbolAVL<T>::getHighest(Node*& r) {
    if(r == nullptr || r->getRight() == nullptr) {
        return r;
        }
    return getHighest(r->getRight());
    }

template <class T>
bool ArbolAVL<T>::isLeaf(Node*& r) const {
    return r != nullptr && r->getLeft() == r->getRight();
    }

template <class T>
int ArbolAVL<T>::getHeight() {
    return getHeight(root);
    }

template <class T>
int ArbolAVL<T>::getHeight(Node*& r) {
    if(r == nullptr) {
        return 0;
        }

    int lH(getHeight(r->getLeft()));
    int rH(getHeight(r->getRight()));

    return(lH > rH ? lH : rH) + 1;
    }

template <class T>
int ArbolAVL<T>::getHeightRight() {
    return getHeight(root->getRight());
    }

template <class T>
int ArbolAVL<T>::getHeightLeft() {
    return getHeight(root->getLeft());
    }

template <class T>
void ArbolAVL<T>::preOrder() {
    preOrder(root);
    }

template <class T>
void ArbolAVL<T>::preOrder(Node*& r) {
    if(r == nullptr) {
        return;
        }
    std::cout << r->getData() << ", ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
    }

template <class T>
void ArbolAVL<T>::inOrder() {
    inOrder(root);
    }

template <class T>
void ArbolAVL<T>::inOrder(Node*& r) {
    if(r == nullptr) {
        return;
        }
    inOrder(r->getLeft());
    std::cout << r->getData() << ", ";
    inOrder(r->getRight());
    }

template <class T>
void ArbolAVL<T>::posOrder() {
    posOrder(root);
    }

template <class T>
void ArbolAVL<T>::posOrder(Node*& r) {
    if(r == nullptr) {
        return;
        }
    posOrder(r->getLeft());
    posOrder(r->getRight());
    std::cout << r->getData() << ", ";
    }

template <class T>
void ArbolAVL<T>::deleteAll() {
    if(root == nullptr) {
        return;
        }
    deleteData(root->getLeft(), root->getData());
    deleteData(root->getRight(), root->getData());
    delete root;
    root = nullptr;
    }

template <class T>
ArbolAVL<T>& ArbolAVL<T>::operator = (const ArbolAVL& e) {
    deleteAll();
    copyAll(e);
    return *this;
    }
