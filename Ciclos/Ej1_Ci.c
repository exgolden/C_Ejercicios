#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Este programa muestra la tabla de multiplicar de un numero entre 1 y 100 \n");
    int Base, Start, End;
    int Counter=0;
    // Input de base
    printf("Ingrese el numero base: \n");
    scanf("%d", &Base);
    if(Base<1 || Base>100){
        Base=10;
        printf("Base fuera de rango, se usara Base=%d \n", Base);
    }
    // Input de inicio y fin
    printf("Introduzca el indice inicial: \n");
    scanf("%d", &Start);
    if(Start<1 || Start>100){
        Start=1;
        printf("Indice inicial fuera de rango, se usara Indicie inicial=%d \n", Start);
    }
    printf("Intrduzca el indice final: \n");
    scanf("%d", &End);
    if(End<=Start || End>100){
        End=10;
        printf("Indice final fuera de rango, se usara Indicie final=%d \n", End);
    }
    // Tabla
    printf("La tabla de multiplicar de %d, del %d al %d es: \n", Base, Start, End);
    for(Counter=Start; Counter<=End; Counter++){
        printf("\t %d x %d = %d \n", Base, Counter, Base*Counter);
    }
    return 0;
}


