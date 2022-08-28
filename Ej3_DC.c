#include <stdio.h>
#include <stdlib.h>
int main(){
    // No puedo declarar un entero con una operacion que entrega un float
    int Entero=2/5;
    /* Y al parecer no puedo decalarar un float, usando int, a pesar de que la operacion
       me entregue un float, entonces si quiero trtabajar con floats debo forzozamente
       entregarle un input float */
    float FailFloat=1/3;
    float GoodFloat=1.0/3.0;
    double UnDouble=1.0/3.0;
    printf("El entero mal declarado es: %d \n", Entero);
    printf("El float mal declarado es: %f \n", FailFloat);
    printf("El float bien declarado es: %f \n", GoodFloat);
    // el "." y los numeros me sriven ára imṕrimmir el numero de decimales deseados
    printf("El float con 10 decimales es: %.10f \n", UnDouble);
    return 0;
}