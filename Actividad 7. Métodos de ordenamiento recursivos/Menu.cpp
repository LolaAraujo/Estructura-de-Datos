#include "Menu.hpp"

using namespace std;

Menu::Menu(Lista<Integer> &firstList) {
    system("Color E5");
    view(firstList);
    }

void Menu::view(Lista<Integer> &firstList) {

    std::chrono::steady_clock::time_point begin, end;
    Lista<Integer> secondList;
    Integer ListNumbers;
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int>distribution(0,1000000);
    auto random = bind(distribution, generator);

    cout<<"LLENANDO LISTA..."<<endl;
    int i=0;
    while(i<MAX) {
        ListNumbers = random(generator);
        firstList.insertList(firstList.getLastPosition(), ListNumbers);
        i++;
        }

    cout<<"\t\t...LISTA LLENA"<<endl;

    ///BUBBLE
    cout<<"\n---------------- BUBBLESORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }
    begin = chrono::steady_clock::now();
    secondList.bubbleSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }


    ///INSERT
    cout<<"\n---------------- INSERTSORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }

    begin = chrono::steady_clock::now();
    secondList.insrtSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }


    ///SELECT
    cout<<"\n---------------- SELECTSORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }
    begin = chrono::steady_clock::now();
    secondList.selectSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }

    ///SHELL
    cout<<"\n---------------- SHELLSORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }
    begin = chrono::steady_clock::now();
    secondList.shellSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }

    ///MERGE
    cout<<"\n---------------- MERGESORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }
    begin = chrono::steady_clock::now();
    secondList.mergeSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }

    ///QUICK
    cout<<"\n---------------- QUICKSORT ----------------"<<endl;
    secondList = firstList;
    if(secondList.isSorted()) {
        cout<<"Lista Ordenada"<<endl;
        }
    else {
        cout<<"Lista No Ordenada :("<<endl;
        }
    begin = chrono::steady_clock::now();
    secondList.quickSort();
    end = chrono::steady_clock::now();
    if(secondList.isSorted()) {
        cout<<"Estado Actual: ORDENADA"<<endl;
        cout<<"Tiempo de ejecucion en milisegundos: "<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()<<" ms"<<endl;
        }

    }

