#include "menu.hpp"

using namespace std;

Menu::Menu() {
    HANDLE wHnd;
    system("Color F5");
    marco(1,0,64,37);
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {20, 3, 85, 40};
    SetConsoleWindowInfo(wHnd, 3, &windowSize);

    ListRecipes<Recetas> listRecipe;
    view(listRecipe);
    }

///       MENU PRINCIPAL

void Menu::view(ListRecipes<Recetas> &listRecipe) {
    int opc, e(1);
    Recetas recipe;

    while(e == 1) {
        system("cls");
        marco(1,0,64,37);
        gotoxy(7, 5);
        cout<< "\t\t    RECETARIO DIGITAL" <<endl<<endl;
        cout<< "\t\t [1] Menu de Recetas" <<endl;
        cout<< "\t\t [2] Menu de Ingredientes "<<endl<<endl;

        cout << "\t\tMOSTAR RECETAS POR:"<<endl;
        cout<< "\t\t [3] Categoria Desayuno"<<endl;
        cout<< "\t\t [4] Categoria Comida "<<endl;
        cout<< "\t\t [5] Categoria Cena "<<endl;
        cout<< "\t\t [6] Categoria Navidenia"<<endl;
        cout<< "\t\t [7] Todas las Recetas "<<endl<<endl;
        cout<< "\t\t [8] Guardar a Disco"<<endl;
        cout<< "\t\t [9] Leer a Disco"<<endl;
        cout<< "\t\t [10] Salir "<<endl<<endl;
        cout<< "\t\t OPCION: ";
        cin>>opc;
        cin.ignore();

        switch(opc) {
            case 1:
                recipeMenu(listRecipe);
                break;

            case 2:
                ingrediMenu(listRecipe);
                break;

            case 3:
                system("cls");
                gotoxy(8,1);
                cout<<" RECETAS DE LA CATEGORIA DESAYUNO"<<endl<<endl;
                gotoxy(2,2);
                cout <<"--------------------------------------------------------------"<<endl<<endl;
                if(listRecipe.isEmpty()) {
                    cout<< "\tEl recetario se encuentra vacio"<<endl<<endl;
                    systemPause();
                    }
                else {
                    recipe.setCategory("Desayuno");
                    gotoxy(8,4);
                    cout << listRecipe.category(recipe, listRecipe.compareByCategory) << endl <<endl;
                    systemPause();
                    }
                break;

            case 4:
                system("cls");
                gotoxy(8,1);
                cout<<" RECETAS DE LA CATEGORIA COMIDA"<<endl<<endl;
                gotoxy(2,2);
                cout <<"--------------------------------------------------------------"<<endl<<endl;
                if(listRecipe.isEmpty()) {
                    cout<< "\tEl recetario se encuentra vacio"<<endl<<endl;
                    systemPause();
                    }
                else {
                    recipe.setCategory("Comida");
                    gotoxy(8,4);
                    cout << listRecipe.category(recipe, listRecipe.compareByCategory) << endl <<endl;
                    systemPause();
                    }
                break;

            case 5:
                system("cls");
                gotoxy(8,1);
                cout<<" RECETAS DE LA CATEGORIA COMIDA"<<endl<<endl;
                gotoxy(2,2);
                cout <<"--------------------------------------------------------------"<<endl<<endl;
                if(listRecipe.isEmpty()) {
                    cout<< "\tEl recetario se encuentra vacio"<<endl<<endl;
                    systemPause();
                    }
                else {
                    recipe.setCategory("Cena");
                    gotoxy(8,4);
                    cout << listRecipe.category(recipe, listRecipe.compareByCategory) << endl <<endl;
                    systemPause();
                    }
                break;

            case 6:
                system("cls");
                gotoxy(8,1);
                cout<<" RECETAS DE LA CATEGORIA NAVIDENIA"<<endl<<endl;
                gotoxy(2,2);
                cout <<"--------------------------------------------------------------"<<endl<<endl;
                if(listRecipe.isEmpty()) {
                    cout<< "\tEl recetario se encuentra vacio"<<endl<<endl;
                    systemPause();
                    }
                else {
                    recipe.setCategory("Navidenio");
                    gotoxy(8,4);
                    cout << listRecipe.category(recipe, listRecipe.compareByCategory) << endl <<endl;
                    systemPause();
                    }
                break;

            case 7:
                system("cls");
                gotoxy(8,1);
                cout<<"\t  RECETARIO COMPLETO"<<endl<<endl;
                gotoxy(2,2);
                cout <<"--------------------------------------------------------------"<<endl<<endl;
                if(listRecipe.isEmpty()) {
                    cout<< "\tEl recetario se encuentra vacio"<<endl<<endl;
                    systemPause();
                    }
                else {
                    gotoxy(8,4);
                    cout<<listRecipe.toString();
                    systemPause();
                    }
                break;

            case 8:
                writeFromDisk(listRecipe);
                break;

            case 9:
                readFromDisk(listRecipe);
                break;

            case 10:
                cout<<"\n\tHASTA LA PROXIMA!! :D"<<endl;
                e+=1;
                exit(EXIT_PROCESS_DEBUG_EVENT);
                break;

            default:
                std::cout<<"Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }
        }
    }

///          MENU PARA RECETAS

void Menu::recipeMenu(ListRecipes<Recetas> &listRecipe) {
    int opc, j = 0;
    while(j==0) {
        coordinates();
        gotoxy(7, 5);
        cout << "\t MENU PARA RECETAS" <<endl<<endl;
        cout << "\t [1] Ingresar Receta "<<endl;
        cout << "\t [2] Buscar Receta"<<endl;
        cout << "\t [3] Modificar Procediemiento de una Receta"<<endl;
        cout << "\t [4] Ordenar las Recetas "<<endl;
        cout << "\t [5] Eliminar una Receta "<<endl;
        cout << "\t [6] Eliminar Todas las Recetas "<<endl;
        cout <<"\t [7] Salir"<<endl<<endl;
        cout << "\t OPCION: ";
        cin>>opc;
        cin.ignore();

        switch(opc) {
            case 1:
                addRecipe();
                break;

            case 2:
                searchRecipe(listRecipe);
                break;

            case 3:
                modifyRecipe(listRecipe);
                break;

            case 4:
                sortRecipe(listRecipe);
                break;

            case 5:
                deleteeR(listRecipe);
                break;

            case 6:
                cout << "\n\t Eliminando..."<<endl;
                listRecipe.deleteAll();
                cout <<"\n\t----- SE ELIMINARON TODAS LAS RECETAS -----"<<endl<<endl;
                cin.ignore();
                break;

            case 7:
                view(listRecipe);
                j+=2;
                break;
            default:
                std::cout<<"\t Ingresa solo valores que se te solicitan"<<std::endl;
                cin.get();
                break;
            }
        }
    }

///        AÑADIR RECETA

ListRecipes<Recetas> Menu::addRecipe() {
    char x;
    int selec;
    Recetas recipe;
    NameA author;
    ListRecipes<Recetas> listRecipe;
    string myStr;

    do {
        coordinates();
        gotoxy(8,1);
        cout <<"\t\tINGRESAR RECETA"<<endl;
        gotoxy(2,2);
        cout <<"--------------------------------------------------------------"<<endl<<endl;
        gotoxy(8,4);
        cout <<"CATEGORIAS: "<<endl;
        cout <<"\t  [1] Desayuno" << endl;
        cout <<"\t  [2] Comida" << endl;
        cout <<"\t  [3] Cena" << endl;
        cout <<"\t  [4] Navidenio" << endl;
        cout <<"\t  Seleccion: ";
        cin >> selec;
        cin.ignore();

        switch(selec) {
            case 1:
                myStr = "Desayuno";
                break;
            case 2:
                myStr = "Comida";
                break;
            case 3:
                myStr = "Cena";
                break;
            case 4:
                myStr = "Navidenio";
                break;
            default:
                break;
            }
        recipe.setCategory(myStr);

        gotoxy(8,10);
        cout<<"Receta: ";
        getline(cin, myStr);
        recipe.setTitle(myStr);

        gotoxy(8,11);
        cout<<"Nombre Autor: ";
        getline(cin, myStr);
        author.setName(myStr);
        recipe.setNom(author);

        gotoxy(8,12);
        cout<<"Apellido Autor: ";
        getline(cin, myStr);
        author.setLastName(myStr);
        recipe.setNom(author);

        recipe.setIngredient(addIngredients(recipe.getIngredient()));

        cout<<"\n\tTiempo de Preparacion en min: ";
        getline(cin, myStr);
        recipe.setTime(atof(myStr.c_str()));

        cout<<"\tProceso: ";
        getline(cin, myStr);
        recipe.setProcess(myStr);

        listRecipe.insertData(listRecipe.getLastPosition(), recipe);
        cout<<endl<<endl<<"\n\t----------- RECETARIO ACTUALIZADO -----------"<<endl<<endl;
        cout << "\tDesea insertar otra receta? [y/n]: ";
        cin >> x;
        cin.ignore();
        }
    while(x=='y');
    recipeMenu(listRecipe);
    }

///        COMPLEMENTO DE INGREDIENTES A RECETA

ListIngredient<Ingredients> Menu::addIngredients(ListIngredient<Ingredients> listIngred) {
    char m;
    Ingredients food;
    string myStr;

    listIngred.deleteAll();
    do {
        cout<<"\tIngrediente: ";
        getline(cin, myStr);
        food.setNameIngr(myStr);

        cout<<"\tCantidad: ";
        getline(cin, myStr);
        food.setQuantity(myStr);

        listIngred.insertSortData(food);
        cout << "\tDesea agregar otro ingrediente? [y/n]: ";
        cin >> m;
        cin.ignore();
        }
    while(m=='y');
    return listIngred;
    }

///          BUSCAR RECETA

void Menu::searchRecipe(ListRecipes<Recetas> &listRecipe) {
    Recetas recipe;
    ListRecipes<Recetas>::Position pos;
    string myStr;

    system("cls");
    gotoxy(8,1);
    cout<<"\t\tBUSQUEDA DE RECETA"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"Receta:"<<endl;
    cout<<"\t - ";
    getline(cin, myStr);
    recipe.setCategory(myStr);
    recipe.setTitle(myStr);

    pos = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(pos == nullptr) {
        gotoxy(4,6);
        cout<<"No pudimos encontrar la receta en la lista :("<<endl;
        Sleep(2000);
        }
    else {
        Sleep(2000);
        gotoxy(4, 7);
        cout<<"\n\t----------- RECETA ENCONTRADA  ------------"<<endl<<endl;
        cout<< listRecipe.retrieve(pos).toString();
        cout<<endl;
        systemPause();
        }
    recipeMenu(listRecipe);
    }

///        MODIFICAR RECETA

void Menu::modifyRecipe(ListRecipes<Recetas> &listRecipe) {
    Recetas recipe, aux;
    ListRecipes<Recetas>::Position pos;
    string myStr;

    coordinates();
    gotoxy(9,1);
    cout<<"MODIFICAR PROCEDIMIENTO DE LA RECETA"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"Receta: "<<endl;
    cout <<"\t -";
    getline(cin, myStr);
    recipe.setTitle(myStr);
    pos = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(pos == nullptr) {
        cout<<"\t NO EXISTE LA RECETA"<<endl;
        cin.get();
        }
    else {
        string process;
        aux = Recetas(listRecipe.retrieve(pos));
        cout<<"\n\t Receta:"<<listRecipe.retrieve(pos).getTitle();
        cout<<"\n\t Proceso Nuevo: "<<endl;
        cout<<"\t ";
        getline(cin, process);

        aux.setProcess(process);
        listRecipe.insertData(pos, aux);
        listRecipe.deleteData(pos);
        cout<<endl<<endl<<endl<<"\n\t--------- MODIFICADO CON EXITO ----------"<<endl<<endl;
        systemPause();
        }
    }

///        ELIMINAR RECETA

void Menu::deleteeR(ListRecipes<Recetas> &listRecipe) {
    ListRecipes<Recetas>::Position pos;
    Recetas recipe;
    string myStr;

    coordinates();
    gotoxy(10,1);
    cout<<"\t ELIMINAR UNA RECETA"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"\t Receta a eliminar: "<<endl;
    cout << "\t - ";
    getline(cin, myStr);

    recipe.setTitle(myStr);
    pos = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);
    cout<<endl<<"\t Eliminando..."<<endl<<endl;
    Sleep(2000);

    if(pos == nullptr) {
        cout<<"\t No existe la receta"<<endl;
        }
    else {
        listRecipe.deleteData(pos);
        cout<<endl<<endl<<endl<<endl<<"\t------------ RECETA ELIMINADA -------------"<<endl<<endl;
        }
    systemPause();
    }

///        ORDENAR RECETA

void Menu::sortRecipe(ListRecipes<Recetas> &listRecipe) {
    int opc;
    do {
        coordinates();
        gotoxy(8,1);
        cout <<"\t\t ORDENAR RECETAS"<<endl;
        gotoxy(2,2);
        cout <<"--------------------------------------------------------------"<<endl<<endl;
        gotoxy(4,4);
        cout << "[1] Ordenar por nombre"<<endl;
        gotoxy(4,5);
        cout << "[2] Ordenar por tiempo de preparacion" << endl;
        gotoxy(4,6);
        cout << "[3] Salir"<<endl<<endl;
        gotoxy(4,7);
        cout << "OPCION: ";
        cin >> opc;

        system("cls");
        if(opc == 1) {
            listRecipe.quickSort(listRecipe.compareByTitle);
            gotoxy(9,1);
            cout <<" ORDENADO POR NOMBRE"<<endl<<endl;
            gotoxy(2,2);
            cout <<"--------------------------------------------------------------"<<endl<<endl;
            gotoxy(4,4);
            cout<<listRecipe.toString();
            cin.get();
            }
        else if(opc == 2) {
            listRecipe.quickSort(listRecipe.compareByTime);
            gotoxy(7,1);
            cout <<"ORDENADO POR TIEMPO DE PREPARACION"<<endl<<endl;
            gotoxy(2,2);
            cout <<"--------------------------------------------------------------"<<endl<<endl;
            gotoxy(4,4);
            cout<<listRecipe.toString();
            cin.get();
            }
        else {
            cout<<"\t Ingresa solo lo que se te pide"<<endl<<endl;
            }
        systemPause();
        }
    while(opc>=3 || opc<=0 && opc == 3);
    recipeMenu(listRecipe);
    }

///         MENU PARA INGREDIENTES

void Menu::ingrediMenu(ListRecipes<Recetas> &listRecipe) {
    int opc, y=0;
    string myStr;
    Ingredients food;
    Recetas recipe, aux;
    ListIngredient<Ingredients> lisIngr;
    ListIngredient<Ingredients>::Position posI;
    ListRecipes<Recetas>::Position posR;


    while(y==0) {
        coordinates();
        gotoxy(7, 5);
        cout<< "\t MENU PARA INGREDIENTES"<<endl<<endl;
        cout<< "\t [1] Ingresar ingredientes a una receta"<<endl;
        cout<< "\t [2] Modificar la cantidad de un ingrediente"<<endl;
        cout<< "\t [3] Eliminar un ingrediente "<<endl;
        cout<< "\t [4] Eliminar todos los ingredientes "<<endl;
        cout<< "\t [5] Salir del Menu"<<endl<<endl;
        cout<< "\t OPCION: ";
        cin>>opc;
        cin.ignore();
        switch(opc) {
            case 1:
                ingredientIntoRecipe(listRecipe);
                break;

            case 2:
                modifyIngred(listRecipe);
                break;

            case 3:
                deleteeI(listRecipe);
                break;

            case 4:
                deleteAllIngred(listRecipe);
                break;

            case 5:
                view(listRecipe);
                y+=1;
                break;

            default:
                std::cout<<"\t Ingresa solo valores que se te solicitan"<<std::endl;
                break;
            }
        }
    }

///        AÑADIR MAS INGREDIENTES A RECETAS

ListRecipes<Recetas> Menu::ingredientIntoRecipe(ListRecipes<Recetas> & listRecipe) {
    Ingredients food;
    Recetas recipe, aux;
    ListIngredient<Ingredients> listIngred;
    ListRecipes<Recetas>::Position posR;
    string myStr;

    coordinates();
    gotoxy(8,1);
    cout<<"\t  INGRESAR OTRO INGREDIENTE"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"\tReceta: ";
    getline(cin, myStr);
    recipe.setTitle(myStr);
    posR = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(posR == nullptr) {
        cout<<"\t NO EXISTE LA RECETA"<<endl;
        Sleep(1000);
        ingrediMenu(listRecipe);
        }

    aux = Recetas(listRecipe.retrieve(posR));
    listIngred = aux.getIngredient();
    gotoxy(2,6);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t"<<aux.getTitle()<<endl<<endl;
    cout<<"\tIngredientes Actuales:"<<endl<<endl;
    cout<<aux.getIngredient().toString();
    cout<<endl<<endl<<"\tNuevo Ingrediente: ";
    getline(cin, myStr);
    food.setNameIngr(myStr);

    cout<<"\tCantidad: ";
    getline(cin, myStr);
    food.setQuantity(myStr);

    listIngred.insertSortData(food);
    aux.setIngredient(listIngred);
    listRecipe.insertData(posR, aux);
    listRecipe.deleteData(posR);

    cout<<endl<<endl<<endl<<"\t---------- INGREDIENTES ACTUALIZADOS ----------"<<endl<<endl;
    systemPause();
    return listRecipe;
    }

///        MODIFICAR INGREDIENTES

void Menu::modifyIngred(ListRecipes<Recetas> &listRecipe) {
    Recetas recipe, aux;
    Ingredients food;
    ListIngredient<Ingredients>::Position posI;
    ListRecipes<Recetas>::Position posR;
    ListIngredient<Ingredients> listIngred;
    string myStr;

    coordinates();
    gotoxy(7,1);
    cout<<"\t\tMODIFICAR CANTIDAD DE UN INGREDIENTE"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"Receta: ";
    getline(cin, myStr);
    recipe.setTitle(myStr);
    posR = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(posR==nullptr) {
        cout<<"\t NO EXISTE LA RECETA"<<endl;
        }
    else {
        aux = Recetas(listRecipe.retrieve(posR));
        listIngred = aux.getIngredient();
        gotoxy(2,6);
        cout <<"--------------------------------------------------------------"<<endl<<endl;
        cout<<"\t\t"<<aux.getTitle()<<endl;
        cout<<aux.getIngredient().toString()<<endl;
        cout<<endl<<"\n\tIngrediente: ";
        getline(cin, myStr);
        food.setNameIngr(myStr);
        posI = listIngred.findDatLin(food, listIngred.compareByNameIngr);

        if(posI == nullptr) {
            cout<<"\t NO EXISTE EL INGREDIENTE"<<endl;
            }

        else {

            string quantity;
            cout<<"\tCambio de Cantidad: ";
            getline(cin, quantity);

            listIngred.retrieve(posI).setQuantity(quantity);
            aux.setIngredient(listIngred);
            listRecipe.insertData(posR, aux);
            listRecipe.deleteData(posR);

            cout<<endl<<endl<<endl<<"\t------------ MODIFICADO CON EXITO ------------"<<endl<<endl;
            }
        }
    systemPause();
    }

///        ELIMINAR INGREDIENTE

void Menu::deleteeI(ListRecipes<Recetas> &listRecipe) {
    Recetas recipe, aux;
    Ingredients food;
    ListIngredient<Ingredients>::Position posI;
    ListRecipes<Recetas>::Position posR;
    ListIngredient<Ingredients> listIngred;
    string myStr;

    coordinates();
    gotoxy(7,1);
    cout <<"\t  ELIMINAR UN INGREDIENTE"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,4);
    cout<<"\tReceta: ";
    getline(cin, myStr);
    recipe.setTitle(myStr);
    posR = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(posR == nullptr) {
        cout<<"\t NO EXISTE LA RECETA"<<endl;
        }
    else {
        aux = Recetas(listRecipe.retrieve(posR));
        listIngred = aux.getIngredient();

        gotoxy(2,6);
        cout <<"--------------------------------------------------------------"<<endl<<endl;
        cout<<"\t\t"<<aux.getTitle()<<endl;
        cout<<aux.getIngredient().toString()<<endl;
        cout<<endl<<"\t Ingrediente: ";
        getline(cin, myStr);
        food.setNameIngr(myStr);

        posI = listIngred.findDatLin(food, listIngred.compareByNameIngr);

        if(posI == nullptr) {
            cout<<endl<<"\t NO EXISTE EL INGREDIENTE"<<endl;
            }

        else {
            cout<<endl<<endl<<"\t Eliminando..."<< endl;
            listIngred.deleteData(posI);
            aux.setIngredient(listIngred);

            listRecipe.insertData(posR, aux);
            listRecipe.deleteData(posR);
            cout<<endl<<endl<<endl<<"\t--------- ELIMINADO CON EXITO ---------" <<endl<<endl;
            }
        }
    systemPause();
    }

///      ELIMINAR TODOS LOS INGREDIENTES

void Menu::deleteAllIngred(ListRecipes<Recetas> &listRecipe) {
    Recetas recipe, aux;
    Ingredients food;
    ListIngredient<Ingredients>::Position posI;
    ListRecipes<Recetas>::Position posR;
    ListIngredient<Ingredients> listIngred;
    string myStr;

    coordinates();
    gotoxy(7,1);
    cout <<"\t  ELIMINAR LISTA DE INGREDIENTES"<<endl;
    gotoxy(2,2);
    cout <<"--------------------------------------------------------------"<<endl<<endl;
    gotoxy(4,5);
    cout<<"\t Receta: ";
    getline(cin, myStr);
    recipe.setTitle(myStr);
    posR = listRecipe.findDatLin(recipe, listRecipe.compareByTitle);

    if(posR==nullptr) {
        cout<<endl<<"\t NO EXISTE LA RECETA"<<endl;
        }
    else {
        aux = Recetas(listRecipe.retrieve(posR));
        listIngred = aux.getIngredient();

        cout<<endl<<endl<<"\t Eliminando..."<<endl;
        listIngred.deleteAll();
        aux.setIngredient(listIngred);
        listRecipe.insertData(posR, aux);
        listRecipe.deleteData(posR);
        cout<<endl<<endl<<endl<<endl<<endl<<"\t----- SE ELIMINARON TODOS LOS INGREDIENTES ------"<<endl<<endl;
        }
    systemPause();
    }

void Menu::systemPause() {
    cout <<"\t Presiona enter para continuar...";
    cin.ignore();
    system("cls");
    }

///LECTURA Y ESCRITURA DE DISCO
void Menu::writeFromDisk(ListRecipes<Recetas>& listRecipe) {
    Recetas aux;
    ListIngredient<Ingredients> lisIngr;
    string title;
    ListRecipes<Recetas>::Position posR;

    cout<<endl<<endl<<endl<<"\t Escribiendo al disco..."<<endl;
    posR = listRecipe.getFirstPosition();

    while(posR != nullptr) {
        aux = listRecipe.retrieve(posR);//posR->getData();
        title = aux.getTitle();

        lisIngr = listRecipe.retrieve(posR).getIngredient();
        lisIngr.writeFromDisk(title+"_ingredients.txt");
        lisIngr.deleteAll();
        listRecipe.retrieve(posR).setIngredient(lisIngr);
        //auxRecipe.setIngredient(lisIngr);
        posR = posR->getNext();
        }
    listRecipe.writeFromDisk("RecipeBook.txt");
    cout<<"\n\t------------- Accion Completada ---------------"<<endl<<endl;
    systemPause();
    }

void Menu::readFromDisk(ListRecipes<Recetas>& listRecipe) {
    Recetas auxRecipe;
    ListIngredient<Ingredients> lisIngr;
    ListRecipes<Recetas>::Position posR;
    string title;

    listRecipe.readFromDisk("RecipeBook.txt");
    cout<<endl<<endl<<endl<<"\t Leyendo del disco..."<<endl;
    posR = listRecipe.getFirstPosition();

    while(posR != nullptr) {

        auxRecipe = posR->getData();
        title = auxRecipe.getTitle();

        lisIngr.readFromDisk(title+"_ingredients.txt");
        listRecipe.retrieve(posR).setIngredient(lisIngr);
       // listRecipe.readFromDisk(title+"_recipe.txt");
        posR = posR->getNext();
        }
    cout<<"\n\t------------- Accion Completada ---------------"<<endl<<endl;
    systemPause();
    }

void Menu::gotoxy(int x, int y) {
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
    }

void Menu::marco(int xs, int ys, int xi, int yi) {
    int i;

    i=xs;
    while(i<=xi) {
        gotoxy(i,ys);
        cout<<"=";
        gotoxy(i,yi);
        cout<<"=";
        i++;
        }

    i=ys;
    while(i<=yi) {
        gotoxy(xs,i);
        cout<<"|";
        gotoxy(xi,i);
        cout<<"|";
        i++;
        }

    gotoxy(xs, ys);
    cout<<"=";
    gotoxy(xi, yi);
    cout<<"=";
    gotoxy(xi, ys);
    cout<<"=";
    gotoxy(xs, yi);
    cout<<"=";
    }

void Menu::coordinates() {
    system("cls");
    marco(1,0,64,37);
    }
