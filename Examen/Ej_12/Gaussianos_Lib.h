#ifndef Gaussianos_Lib
//Libreria de complejos con entradas en Z
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------------------------------------
typedef struct G{
    int a, b;
}G;

G Read_G(int a, int b){
    G g1;
    g1.a=a;
    g1.b=b;
    return g1;
}

void Write_G(G g1){
    printf("%+d%+di", g1.a, g1.b);
}

G Sum_G(G g1, G g2){
    G sum;
    sum.a=g1.a+g2.a;
    sum.b=g1.b+g2.b;
    return sum;
}

G Minus_G(G g1, G g2){
    G minus;
    minus.a=g1.a-g2.a;
    minus.b=g1.b-g2.b;
    return minus;
}

G Prod_G(G g1, G g2){
    G prod;
    prod.a=(g1.a*g2.a)-(g1.b*g2.b);
    prod.b=(g1.a*g2.b)+(g1.b*g2.a);
    return prod;
}
//------------------------------------------
#define Gaussianlos_Lib
#endif
