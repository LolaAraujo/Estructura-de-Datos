#ifndef ACTIVIDAD1_H
#define ACTIVIDAD1_H
#include <limits>
#include <iostream>
#include <random>
#include <chrono>
#define filas 10
#define columnas 10

class actividad1 {
        float matriz[filas][columnas];
        float num;
    public:
        actividad1();

        void tabla(void);
        void visualizacion(void);
        float getMatriz(int);
        void setMatriz(int);

        actividad1 operator+(actividad1&);
        actividad1 operator*(actividad1&);
    };

#endif // ACTIVIDAD1_H
