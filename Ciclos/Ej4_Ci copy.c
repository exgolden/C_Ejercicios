#include <stdio.h>
#define MAX_CAR 10

//Este programa imprime un medio diamante
int main(){
    int i, j;
    char MI_CHAR='A';
    /*
        Este primer codigo imprime la parte superior del diamante
        El primer ciclo da las filas
        El segundo ciclo da las columnas, vease que j<i para que este sea un diamante
    */
    for (i=1; i<=MAX_CAR; i++)
    {
        for (j=1; j<i; j++)
        {
            printf("%c", MI_CHAR);
        }
        printf("\n");
    } 
    //Linea de separacion
    for (i = 0; i<MAX_CAR; i++)
    {
        printf("-");
    }
    printf("\n");
    /*
        La segunda seccion del codigo imprime la parte inferior del diamante
        El primer ciclo queda igual
        En el segundo ciclo se empieza con 9 elementos y se va restando uno hasta que se siga cumpliendo
            la condicion de que j sea m,ayor a 0
    */
   for (i=1; i<=MAX_CAR; i++)
   {
    for (j=10-i; j>0; j--)
    {
        printf("%c", MI_CHAR);
    }
    printf("\n");
   }
   



    
    return 0;
}