#include <stdio.h>

union Tipos{
    char UnCar;
    int UnInt;
    double UnDouble;
};

int main(){
    union Tipos Ej1={UnCar:'I', UnInt:5, UnDouble.4.2};
    union Tipos Ej2;
    printf("Los valores de la primera union son: %c, %d y %lf\n", Ej1.UnCar, Ej1.UnInt, Ej1.UnDouble);



    return 0;
}
/*
    Una union es un tipo de estructura que usa el mismo bloque de memoria para cada objeto
    En una estructura el tamaño del bloque de memoria es mayor o igual a los objetos
    En una union el tamaño del bloque de memoria es igual a la memoria requerida por el objeto mas pesado
    https://www.geeksforgeeks.org/difference-structure-union-c/

    https://www.quora.com/What-does-*c-mean-in-C-C++-programming
*/