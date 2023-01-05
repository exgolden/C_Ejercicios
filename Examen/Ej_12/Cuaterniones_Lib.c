#include <stdio.h>
#include <stdlib.h>
//------------------------------------------
typedef struct H{
    int a, b, c, d;
}H;

H Read_H(int a, int b, int c, int d){
    H h1;
    h1.a=a;
    h1.b=b;
    h1.c=c;
    h1.d=d;
    return h1;
}

void Write_H(H h1){
    printf("%d%+di%+dj%+dk", h1.a, h1.b,h1.c,h1.d);
}

H Sum_H(H h1, H h2){
    H Sum;
    Sum.a=h1.a+h2.a;
    Sum.b=h1.b+h2.b;
    Sum.c=h1.c+h2.c;
    Sum.d=h1.d+h2.d;
    return Sum;
}

H Prod_H(H h1, H h2){
    H Prod;
    Prod.a=(h1.a*h2.a)-(h1.b*h2.b)-(h1.c*h2.c)-(h1.d*h2.d);
    Prod.b=(h1.a*h2.b)+(h1.b*h2.a)+(h1.c*h2.d)-(h1.d*h2.c);
    Prod.c=(h1.a*h2.c)-(h1.b*h2.d)+(h1.c*h2.a)+(h1.d*h2.b);
    Prod.d=(h1.a*h2.d)+(h1.b*h2.c)-(h1.c*h2.b)+(h1.d*h2.a);
    return Prod;
}
//------------------------------------------
int main(){
    H h1, h2, Sum, Prod;
    printf("Esta libreria opera Cuaterniones\n");
    printf("Ingrese el primer Cuaternion (a b c d): ");
    scanf("%d %d %d %d", &h1.a, &h1.b, &h1.c, &h1.d);
    printf("Ingrese el segundo Cuaternion (a b c d): ");
    scanf("%d %d %d %d", &h2.a, &h2.b, &h2.c, &h2.d);
    printf("Los cuaterniones ingresados son:\n");
    printf("h1= ");
    Write_H(h1);
    printf("\nh2= ");
    Write_H(h2);
    printf("\nSu suma es: ");
    Sum=Sum_H(h1, h2);
    Write_H(Sum);
    printf("\nSu producto es: ");
    Prod=Prod_H(h1, h2);
    Write_H(Prod);
    printf("\nFin del programa");
    return 0;
}

//1+2i+3j+4k
//5+6i+7j+8k