#include <stdio.h>
#include <stdlib.h>

int main(){
    int MAX, i, j;
    char CAR;
    printf("Este programa imprime medio diamante con un caracter dado y una longitud maxima \n");
    printf("Ingrese el caracter a usar: ");
    // El espacio en blacno es importamnte para casos mas generales
    // https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
    scanf(" %c", &CAR);
    printf("Ingrese la longitud maxima del diamante: ");
    scanf("%d", &MAX);
    // Primera mitad del diamante
    for(i=0; i<MAX; i++){
        for(j=0; j<=i; j++)
            printf("%c", CAR);
        printf("\n");
    }
    // Segunda mitad del doamante
    for(i=0; i<=MAX; i++){
        for(j=MAX-i; j>=0; j--)
            printf("%c", CAR);
        printf("\n");
    }
    return 0;
    // Para este ejercicio solo hay que tener cuidado con las desigualdades
}