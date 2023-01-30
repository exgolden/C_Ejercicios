#ifndef Cuaterniones_Lib
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

H Minus_H(H h1, H h2){
    H Min;
    Min.a=h1.a+h2.a;
    Min.b=h1.b+h2.b;
    Min.c=h1.c+h2.c;
    Min.d=h1.d+h2.d;
    return Min;
}

H Prod_H(H h1, H h2){
    H Prod;
    Prod.a=(h1.a*h2.a)-(h1.b*h2.b)-(h1.c*h2.c)-(h1.d*h2.d);
    Prod.b=(h1.a*h2.b)+(h1.b*h2.a)+(h1.c*h2.d)-(h1.d*h2.c);
    Prod.c=(h1.a*h2.c)-(h1.b*h2.d)+(h1.c*h2.a)+(h1.d*h2.b);
    Prod.d=(h1.a*h2.d)+(h1.b*h2.c)-(h1.c*h2.b)+(h1.d*h2.a);
    return Prod;
}
#define Cuaterniones_Lib
#endif