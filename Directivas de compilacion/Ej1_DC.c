//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Macros
#define Saludo printf("Hola Mundo\n")
#define Saludo_param(X) printf("Saludo dirigido a %s\n", X)
#define TamTipo(X) printf("El tamaño de %11s es %d\n", #X, sizeof(X))
#define Cubo(X) X*X*X
#define Cuadrado(X) X*X
#define OtroCubo(X) X*Cuadrado(X)
#define Valores(TIPO) \
    printf("Valores para " #TIPO "Maximo: %d, Minimo: %d\n", TIPO##_MAX, TIPO##_MIN)
//El operadro "#" convierte a string todo lo que le va despues de el
//El operadfor "##" concatena

int main(){
    printf("Este programa usa macros con y sin parametros\n");
    Saludo;
    Saludo_param("Isai");
    TamTipo(char);
    TamTipo(short);
    TamTipo(int);
    TamTipo(long);
    TamTipo(float);
    TamTipo(double);
    TamTipo(long double);
    printf("El cubo de 5 es: %d\n"
            "El cubo de 3+2 es: %d\n"
            "El cubo de (3+2) es: %d\n",
            Cubo(5), Cubo(3+2), Cubo((3+2)));
    printf("El cuadrado de 3+2 es: %d\n"
            "El otro cubo de 3+2 es: %d\n",
            Cuadrado(3+2), OtroCubo(3+2));
    printf("Por escribir los valores maximos y minimos de los enteros\n");
    Valores(CHAR);
    Valores(SHRT);
    Valores(INT);
    Valores(LONG);
    return 0;
}
