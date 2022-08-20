#include <stdio.h>
int main(){
    int a, inv_a;
    printf("Este programa calcula el inverso de a en modulo 5 \n");
    printf("Introduzca un entero: ");
    scanf("%d", &a);
    a=((a%5)+5)%5;
    inv_a= a==2?3: a==3?2: a==4?4: a;
    a==0?printf("El 0 no tiene inverso"):
        printf("El inverso de %d en modulo 5 es: %d", a, inv_a);
    return 0;
}