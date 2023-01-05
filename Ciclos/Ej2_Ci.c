#include <stdlib.h>
#include <stdio.h>

int main(){
    int Numero, Base, Aux;
    printf("Este programa transforma un numero en base 10 a otra base (2-9) \n");
    printf("Escriba el numero a transformar: ");
    scanf("%d", &Numero);
    // Vero multiplico por -1 pero es mas facil usar las funciones de stdlib
    Aux=abs(Numero);
    printf("Escriba la base a usar: ");
    scanf("%d", &Base);
    if(Base<2 || Base>9){
        Base=2;
        printf("Base fuera de rango, se usara Base=%d \n", Base);
    }
    // Pura aritmetica modular padrino
    printf("ADVERTENCIA: El numero se debe de leer de derecha a izquierda \n");
    printf("El numero: %d en base %d es: ",Numero, Base);
    // No entiendo como uso la condicion para el while
    while(Aux){
        printf("%d", Aux%Base);
        Aux /=Base;
    }
    return 0;
}
// http://recursostic.educacion.es/secundaria/edad/4esotecnologia/quincena5/4q2_contenidos_2c.htm#:~:text=Lógica%20binaria&text=Para%20hacer%20la%20conversión%20de,a%20arriba%20es%20el%20resultado.