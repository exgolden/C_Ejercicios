#include <stdio.h>
#include <stdlib.h>

#define Determinante(x11, x12, x21, x22) ((x11*x22)-(x12*x21))
// Tuve muchos problemas para declarar esta macro, simplemente se arreglo cortando y pegando mmm 
#define Leer(X, FMT) printf("Digite el valor de " #X ": ");      \
  scanf(#FMT, &(X))
int main(){
    double a, b, c, d, e, f, Det, Det_X, Det_Y, X, Y;
    printf("Este programa resuelve un sistema de dos ecuaciones de dos variables, de la forma \n");
    printf("ax+by=c \ndx+ey=f \n");
    // Input
    Leer(a, %lg);
    Leer(b, %lg);
    Leer(c, %lg);
    Leer(d, %lg);
    Leer(e, %lg);
    Leer(f, %lg);
    //Determinante principal
    Det=Determinante(a, b, d, e);
    // Determinante X
    // La maestra invirtio el calculo de este determinante, por que?
    Det_X=Determinante(c, b, f, e);
    // Determinante Y
    Det_Y=Determinante(a, c, d, f);
    // Calculamos los valores X e Y
    X=Det_X/Det;
    Y=Det_Y/Det;
    printf("La solucion es \n X=%lg Y=%lg \n", X, Y);
    printf("Fin del programa");
    return 0; 
}