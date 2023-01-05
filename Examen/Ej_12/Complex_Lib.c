//Libreria de complejos con entradas en Z
#include <stdio.h>
//------------------------------------------
typedef struct C{
    int a ,b;
}C;

C Read_C(int a, int b){
    C c1;
    c1.a=a;
    c1.b=b;
    return c1;
}

void Write_C(C c1){
    printf("%d%+di", c1.a, c1.b);
}

C Sum_C(C c1, C c2){
    C sum;
    sum.a=c1.a+c2.a;
    sum.b=c1.b+c2.b;
    return sum;
}

C Prod_C(C c1, C c2){
    C prod;
    prod.a=(c1.a*c2.a)-(c1.b*c2.b);
    prod.b=(c1.a*c2.b)+(c1.b*c2.a);
    return prod;
}
//------------------------------------------

int main(){
    C c1, c2, Sum, Prod;
    printf("Esta libreria opera complejos\n");
    printf("Ingrese el primer complejo (a b): ");
    scanf("%d %d", &c1.a, &c1.b);
    printf("Ingrese el segundo complejo (c d): ");
    scanf("%d %d", &c2.a, &c2.b);

    printf("Los complejos ingresados fueron:\n");
    printf("c1: ");
    Write_C(c1);
    printf("\nc2: ");
    Write_C(c2);
    printf("\nSu suma es: ");
    Sum=Sum_C(c1, c2);
    Write_C(Sum);
    printf("\nSu producto es: ");
    Prod=Prod_C(c1, c2);
    Write_C(Prod);
    printf("\nFin del programa");
    return 0;
}