#ifndef Complex_Lib
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------------------------------------
typedef struct C{
    double a ,b;
}C;

C Read_C(int a, int b){
    C c1;
    c1.a=a;
    c1.b=b;
    return c1;
}

void Write_C(C c1){
    printf("%+.2lf%+.2lfi", c1.a, c1.b);
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

C Minus_C(C c1, C c2){
    C minus;
    minus.a=c1.a-c2.a;
    minus.b=c1.b-c2.b;
    return minus;
}

C Div_C(C c1, C c2){
    double Sq;
    C Div;
    Sq=pow(c2.a, 2)+pow(c2.b, 2);
    Div.a=((c1.a*c2.a)+(c1.b*c2.b))/Sq;
    Div.b=((c1.b*c2.a)-(c1.a*c2.b))/Sq;
    return Div;
}
#define Complex_Lib
#endif
