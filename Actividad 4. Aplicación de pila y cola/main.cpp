#include <iostream>
#include "ReceiveCola.hpp"

using namespace std;

int main()
{
    ReceiveCola infija;
    string operacion;
    cin>>operacion;
    infija.conversorPostfixed();

//    cout<<infija.conversorPostfixed(operacion);
    //cout<<infija.toString()<<endl;
   // cout << "Hello world!" << endl;
    return 0;
}
