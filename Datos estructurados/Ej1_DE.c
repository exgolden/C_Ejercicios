#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, Size, Num;
    // Declaramos un array con un tamaño definido
    int Primos[10]={2,3,5,7,11,13,17,19,23,29};
    // Declaramos un array de enteros sin un tamaño definido
    int Pares[]={2,4,6,8,10,12,14,16,18,20};
    // Creamos un array vacio, con un tamañio "arbitrario"
    int Impares[10];
    // Accedemos a los elementos del array Primos
    // Sabemos hasta que elementoi leer pues conocemos el tamaño del array, en caso contrario debemos de encontrar su tamaño
    printf("A continuacion se enlistaran los primeros 10 numeros primos: \n");
    for(i=0; i<10; i++){
        printf("%d, ", (Primos[i]));
    }
    /*Para saber el tamaño de un array obtenemos si tamaño en bits y lo dividimos entre el tamaño del tipo del array, como todos
    los elementos de un array deben ser del mismo tipo entonces podemos simplemente dividir entre el tamaño en bits del primer elemento
    https://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c */
    Size=sizeof(Pares)/sizeof(Pares[0]);
    printf("\nA continuacion se enlistaran los primeros 10 numeros pares \n");
    for(i=0; i<Size; i++){
        printf("%d, ", Pares[i]);
    }
    // Guardar elementos en un array
    printf("\nIngrese un numero del 1 al 10: ");
    scanf("%d", &Num);
    if(Num<1 || Num>10){
        Num=5;
        printf("Numero fuera de rango, se usara 5 como valor por default \n");
    }
    for(i=0; i<Num; i++){
        printf("Digite un numero impar: ");
        scanf("%d",& (Impares[i]));
    }
    printf("Los primeros %d numeros impares son: \n", Num);
    for(i=0; i<Num; i++){
        printf("%d, ", Impares[i]);
    }
    return 0;
}