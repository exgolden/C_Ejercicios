#ifndef Zp_Lib
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------
int Sum_Zp(int p, int a, int b){
    int Sum;
    Sum=(a+b)%p;
    return Sum;
}

int Minus_Zp(int p, int a, int b){
    int Min;
    Min=abs((a-b)%p);
    return Min;
}

int Prod_Zp(int p, int a, int b){
    int Prod;
    Prod=(a*b)%p;
    return Prod;
}

int Div_Zp(int p, int a, int b){
    int Div;
    Div=a%b;
    return Div;
}
//------------------------------------------
#define Zp_Lib
#endif