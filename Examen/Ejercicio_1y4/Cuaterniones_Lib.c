#include <stdio.h>
#include <stdlib.h>
#include "Cuaterniones_Lib.h"
#include <math.h>

H Read_H(double a, double b, double c, double d){
    H h1;
    h1.a=a;
    h1.b=b;
    h1.c=c;
    h1.d=d;
    return h1;
}

void Write_H(H h1){
    printf("%+.2lf%+.2lfi%+.2lfj%+.2lfk", h1.a, h1.b,h1.c,h1.d);
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
    Min.a=h1.a-h2.a;
    Min.b=h1.b-h2.b;
    Min.c=h1.c-h2.c;
    Min.d=h1.d-h2.d;
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

H Div_H(H h1, H h2){
    double Sq;
    H Div;
    Sq=pow(h2.a, 2)+pow(h2.b, 2)+pow(h2.c, 2)+pow(h2.d, 2);
    Div.a=((h2.a*h1.a)+(h2.b*h1.b)+(h2.c*h1.c)+(h2.d*h1.d))/Sq;
    Div.b=((h2.a*h1.b)-(h2.b*h1.a)-(h2.c*h1.d)+(h2.d*h1.c))/Sq;
    Div.c=((h2.a*h1.c)+(h2.b*h1.d)-(h2.c*h1.a)-(h2.d*h1.b))/Sq;
    Div.d=((h2.a*h1.d)-(h2.b*h1.c)+(h2.c*h1.b)-(h2.d*h1.a))/Sq;
    return Div;
}

// int main(){
//     H h1, h2, Sum, Minus, Prod, Div;
//     double a, b, c ,d, f ,g, h ,i;
//     printf("Ingrese dos cuaterniones:\n");
//     printf("h1(a b c d): ");
//     scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
//     h1=Read_H(a, b, c, d);
//     printf("h2(f g h i): ");
//     scanf("%lf %lf %lf %lf", &f, &g, &h, &i);
//     h2=Read_H(f, g, h, i);6∞§

//     printf("\nSu suma es: ");
//     Sum=Sum_H(h1, h2);
//     Write_H(Sum);

//     printf("\nSu resta es: ");
//     Minus=Minus_H(h1, h2);
//     Write_H(Minus);

//     printf("\nSu producto es: ");
//     Prod=Prod_H(h1, h2);
//     Write_H(Prod);

//     //CHECK:
//     printf("\nSu division es: ");
//     Div=Div_H(h1, h2);
//     Write_H(Div);
//     return 0;
// }
//1 2 3 4
//5 6 7 8