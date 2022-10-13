#include <stdio.h>
int main(){
    char Caracter='I';
    int Entero=5;
    float Flotante=0.1;
    double Large=3.14e5;
    char *Cadena="Isai"; /* Aun no se porque usamos "*" */
    printf("Esta es una lista: \n"); /* "\n" nos sirve para dar un salto de linea*/
    printf("\t Esto es un caracter: %c \n", Caracter); /* "\t" nos da una sangria */
    printf("\t Esto es un entero: %d \n", Entero);
    printf("\t Esto es un float: %f \n", Flotante);
    printf("\t Esto es un flotante largo: %lf \n", Large);
    printf("\t Esto es un cadena: %s \n", Cadena);
    printf("\t Algunos valores: (Caracter) %c, (Entero) %d",Caracter, Entero);
  return 0;
}