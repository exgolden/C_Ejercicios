#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x, y;
}R2;
typedef struct{
    R2 p, q;
}Recta;
typedef struct{
    double r;
    R2 c;
}Circle;

int main(){
    R2 P1;
    Recta R1;
    Circle C1;
    double aux;
    // Circulo
    printf("Ingrese los datos del circulo \n");
    printf("Ingrese las coordenadas en formato 'h,k': ");
    /* Dentro de circulo tenemos una sub estructura para almacenar las coordenadas del punto
       por eso abrimos memoria con "C" de la estrucutra del circulo y "c" de la estrucura de la coordenada 
       Vero uso "%lg%lg" para el scanf pero uso "(h, k)" como formato, lo cual causa confusion a la hora del
       input, lo correcto seria usar "%lg,%lg" y el input deberia ser "h,k" que para mi es el estandar */
    scanf("%lg,%lg", &C1.c.x, &C1.c.y);
    printf("Ingrese la longitud del radio 'r': ");
    scanf("%lg", &C1.r);
    // Recta
    printf("Ingrese las coordenadas de dos puntos P y Q: \n");
    printf("Ingrese las coordenadas el punto P en formato 'x,y': ");
    scanf("%lg,%lg", &R1.p.x, &R1.p.y);
    printf("Ingrese las coordenadas del punto Q en formato 'x,y': ");
    scanf("%lg,%lg", &R1.q.x, &R1.q.y);
    // Punto
    printf("Ingrese las coordenadas de un punto en formato 'x,y': ");
    scanf("%lg,%lg", &P1.x, &P1.y);
    // Calculo del punto dentro de la circunferencia
    if(sqrt(pow((P1.x-C1.c.x), 2)+pow((P1.y-C1.c.y), 2))<=C1.r){
        printf("El punto (%lg, %lg) esta dentro de la circunferencia con centro en (%lg, %lg) y radio %lg \n", P1.x, P1.y, C1.c.x, C1.c.y, C1.r);
    }
    else{
        printf("El punto (%lg, %lg) esta fuera de la circunferencia con centro en (%lg, %lg) y radio %lg \n", P1.x, P1.y, C1.c.x, C1.c.y, C1.r);
    }
    // Calculo del punto en la recta
    if((P1.y-R1.p.y)*(R1.p.x-R1.q.x)==(R1.p.y-R1.q.y)*(P1.x-R1.p.x)){
        printf("El punto (%lg, %lg) se encuentra en la recta entre los puntos P(%lg, %lg) y Q(%lg, %lg) \n", P1.x, P1.y, R1.p.x, R1.p.y, R1.q.x, R1.q.y);
    }
    else{
        printf("El punto (%lg, %lg) se encuentra fuera de la recta entre los puntos P(%lg, %lg) y Q(%lg, %lg) \n", P1.x, P1.y, R1.p.x, R1.p.y, R1.q.x, R1.q.y);
    }
    return 0;
}