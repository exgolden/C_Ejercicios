//Librerias y globales
#include <stdio.h>
#include <math.h>

int Residuo(int NUMERO, int EXP, int* array){
    int RES;
    RES=NUMERO%(int)pow(10, EXP);
    for (int i=0; i < count; i++){
        array[i]=
    }
    
    return RES;
}

int Modulo(int NUMERO){
    int i=0;
    int Aux;
    do{
        i++;
        Aux=NUMERO/(int)pow(10,i);
    } while(Aux!=0);
    return i;
}

int main(){
    int NUMERO;
    int SIZE;
    printf("Este programa evalua si un numero es capicua\n");
    printf("Digite el numero: "),
    scanf("%d", &NUMERO);
    SIZE=Modulo(NUMERO);
    //Creamos un puntero con la memoria necesaria para almacenar el array de tamaño n
    int *array=malloc(SIZE*sizeof(int));


    return 0;
}