#include <stdio.h>
//Las funciones que operan con enteros estan en:
#include <stdlib.h>
//Las funciones que operan con flotantes estan en:
#include <math.h>

int main(){
    int a, b, MCD;
    printf("Este programa calcula el MCD de dos numeros a y b\n");
    //Antes tenia un problema cuando habioa dos inputs seguidos, me parece que esta en el ejercicio de la agenda del Examen
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    if (a==0 || b==0)
    {
        MCD=abs(a==0?b:a);
        //Nota que el '+' precede a d, eso es para que el programa imprimia por si solo el signo positivo
        printf("El MCD de %d, y %d es: %d\n"
                "Y su combinacion lineal es: %d(%d)%+d(%d)=%d",
                 a, b, MCD, a<0?-1:1, a, b<0?-1:1, b, MCD);
    }
    else
    {

    }
    return 0;
}
/*
    https://stackoverflow.com/questions/3589242/print-a-leading-for-positive-numbers-in-printf
*/