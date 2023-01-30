#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *pEntrada=fopen("Entrada.txt", "r");
    int Grado;
    int a, b, c, d;
    fscanf(pEntrada, "%d", &Grado);
    fscanf(pEntrada, "%d %d %d %d", &a, &b, &c, &d);
    printf("Grado: %d\n", Grado);
    printf("a %d\nb %d\nc %d\nd %d\n", a, b, c, d);
    return 0;


}