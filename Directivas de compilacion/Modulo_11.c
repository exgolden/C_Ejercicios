#include <stdio.h>
int main(){
    int b, inv_b;
    printf("Este programa calcula el inverso de b en modulo 11 \n");
    printf("Introduzca un entero: ");
    scanf("%d", &b);
    b=((b%11)+11)%11;
    inv_b= b==2?6: b==3?4: b==4?3: b==5?9: b==6?2: 
        b==7?8: b==8?7: b==2?6: b==9?5: b==10?10: b;
    b==0?printf("El 0 no tiene inverso"):
        printf("El inverso de %d en modulo 11 es: %d", b, inv_b);
    return 0;
}