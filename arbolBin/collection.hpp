#ifndef COLLECTION_HPP_INCLUDED
#define COLLECTION_HPP_INCLUDED

///DEFINICION
template <class T, int ARRAYSIZE = 1024>
class Collection {
    private:
        T** data;
        int last;
        bool isSorted;

        void addCollection(const Collection&);
        void sortData(const int&, const int&);
        void sortData(const int&, const int&, const std::function<int(const T&, const T&)>&);
        bool isValidPos(const int&) const;

        int findLinear(const T&) const;
        int findLinear(const T&, const std::function<int(const T&, const T&)>&) const;

        int findBinary(const T&) const;
        int findBinary(const T&, const std::function<int(const T&, const T&)>&) const;

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

        Collection();
        Collection(const Collection&);
        ~Collection();

        bool isEmpty() const;
        bool isFull() const;

        void insertData(const T&);
        void insertData(const int&, const T&);
        void insertSortedData(const T&);
        void insertSortedData(const T&, const std::function<int(const T&, const T&)>&);
        void push(const T&);
        void enqueue(const T&);
        void enqueuePriorized(const T&, const std::function<int(const T&, const T&)>&);

        void deleteData(const T&);
        void deleteData(const T&, const std::function<int(const T&, const T&)>&);
        void deleteDataByPos(const int&);
        T pop();
        T dequeue();

        T& retrieve(const int&);
        T& getTop();
        T& getFront();

        int getFirst() const;
        int getLast() const;
        int getPrev(const int&) const;
        int getNext(const int&) const;

        int findData(const T&) const;
        int findData(const T&, const std::function<int(const T&, const T&)>&) const;

        void sortData();
        void sortData(const std::function<int(const T&, const T&)>&);

        void deleteAll();

        T& operator [] (const int&);
        Collection<T, ARRAYSIZE>& operator = (const Collection&);
        Collection<T, ARRAYSIZE>& operator + (const Collection&) const;
        Collection<T, ARRAYSIZE>& operator += (const Collection&);
    };

///IMPLEMENTACION

#endif // COLLECTION_HPP_INCLUDED
