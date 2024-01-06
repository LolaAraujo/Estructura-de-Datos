#include <iostream>

using namespace std;

///Primera forma de hacer tl try...catch

int main()
{
    string nom;
    int edad;

    cout << "Ingresa tu nombre: " << endl;
    cin >> nom;
    cout << "Ingresa tu edad: " << endl;
    cin>>edad;
    try{
        if(edad<=0) // si ingresa bien el nombre pero mal la edad
        {
            throw "ERROR Nom.444. Ingresa lo que se te pide por favor";
        }
        cout<<"felicidades lo lograste :D";
    }catch(const char *a)
    {
        cout<<"aaaaa"<<endl;//<<<<endl;
    }

    return 0;
}


///Segunda manera de hacer un manejo de excepciones  >---NO SIRVE---<
/*char nombre[10];
int edad;
void datos()
{
    cout << "Ingresa tu nombre: " << endl;
    cin >> nombre;
    cout << "Ingresa tu edad: " << endl;
    cin>>edad;
}

int main()
{
    int fecha;
    try
    {
        datos();
        if(typeid(char)==typeid(nombre))
        {
            throw "Los nombres no llevan numeros :)";
        }
        cout<<"Come...\n";
    }
    catch(const char* error)
    {
        cout<<error<<endl;
        datos();
    }
    cout << "Ingresa la fecha de hoy con el formato ddmmaa\nEj. 181122"<< endl;
    cin >> fecha;
    try
    {
        if(typeid(int)==typeid(fecha)||fecha<=0)
        {
            throw "ERROR 444. No sabes seguir indicaciones :)";
        }
        cout<<"...PAN";
    }catch(const char* e)
    {
        cout<<e<<endl;
        cout << "Ingresa la fecha de hoy con el formato ddmmaa\nEj. 181122\n";
        cin >> fecha;
    }
    return 0;
}*/

