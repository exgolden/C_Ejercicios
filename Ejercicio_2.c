#include <stdio.h>
int main(){
    /* Inicializamos las variables */
    char Caracter;
    int Entero;
    float Flotante;
    printf("Digite un caracter: ");
    scanf("%c", &Caracter); 
    /* Por lo que entiendo el "&" le indica a scanf en que slot de memoria
    guardar nuestra variable */
    printf("Digite un entero: ");
    scanf("%d", &Entero);
    printf("Digite un flotante: ");
    scanf("%f", &Flotante); 
    /* No entiendo porque debo de poner "%x" entre comillas */
    printf("Los valores escritos fueron: %c, %d, %f",
    Caracter, Entero, Flotante);
    /* Vero ocupo varios saltos de linea pero aunque los ponga el 
    codigo se ejecuta igual */
}
