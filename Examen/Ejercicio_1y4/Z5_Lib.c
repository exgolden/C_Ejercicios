#include <stdio.h>
#include <stdlib.h>
#include "Z5_Lib.h"

int Sum_Z5(int a, int b){
    int Sum;
    Sum=(a+b)%5;
    return Sum;
}

int Minus_Z5(int a, int b){
    int Min;
    Min=abs((a-b)%5);
    return Min;
}

int Prod_Z5(int a, int b){
    int Prod;
    Prod=(a*b)%5;
    return Prod;
}

int Div_Z5(int a, int b){
    int Div;
    Div=(a%5)%(b%5);
    return Div;
}