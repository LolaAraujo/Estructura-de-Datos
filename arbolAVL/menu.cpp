#include "menu.hpp"

using namespace std;

Menu::Menu(ArbolAVL<int> &tree) {
    system("Color E5");
    view(tree);
    }

void Menu::view(ArbolAVL<int> &tree) {

    int num, i=0, val;
    std::chrono::steady_clock::time_point begin, end;
    default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int>distribution(0,100000);
    auto random = bind(distribution, generator);

    cout<<"Cuantos numeros desea insertar en el arbol?"<<endl;
    cin>>num;
    cin.ignore();
    cout<<endl<<endl;

    while(i < num) {
        val = random();
        cout<<"Insertando: "<< val << endl;
        tree.insertData(val);
        i++;
        }

    cout << endl << endl << endl;

    cout << "------------ RECORRIDO PRE-ORDER ------------" << endl << endl;
    tree.preOrder();
    cout << endl << endl;

    cout << "------------ RECORRIDO IN-ORDER ------------" << endl << endl;
    tree.inOrder();
    cout << endl << endl;

    cout << "------------ RECORRIDO POST-ORDER ------------" << endl << endl;
    tree.posOrder();
    cout << endl << endl;

    cout << "------------ ELEMENTO MENOR EN EL ARBOL ------------" << endl << endl;
    cout<< "- " << tree.retrieve(tree.getLowest());
    cout << endl << endl;

    cout << "------------ ELEMENTO MAYOR EN EL ARBOL ------------" << endl << endl;
    cout<< "- " << tree.retrieve(tree.getHighest());
    cout << endl << endl;

    cout << "------------ ALTURA DEL ARBOL ------------" << endl << endl;
    cout<< "- " << tree.getHeight();
    cout << endl << endl;

    cout << "------------ ALTURA DEL SUB-ARBOL IZQUIERDO ------------" << endl << endl;
    cout<< "- " << tree.getHeightLeft();
    cout << endl << endl;

    cout << "------------ ALTURA DEL SUB-ARBOL DERECHO ------------" << endl << endl;
    cout<< "- " << tree.getHeightRight();
    cout << endl << endl;

    cout << "Eliminando arbol..."<< endl << endl;
    tree.deleteAll();
    cout << "Se elimino correctamente :)"<<endl;

    }
