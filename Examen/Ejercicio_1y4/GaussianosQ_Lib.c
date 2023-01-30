#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "GaussianosQ_Lib.h"

Gq Read_Gq(int a, int b, int c, int d){
    Gq gq1;
    gq1.a=Read_Q(a, b);
    gq1.b=Read_Q(c, d);
    return gq1;
}

void Write_Gq(Gq gq1){
    Write_Q(gq1.a);
    Write_Q(gq1.b);
    printf("i");
}

Gq Sum_Gq(Gq gq1, Gq gq2){
    Gq Sum;
    Sum.a=Sum_Q(gq1.a, gq2.a);
    Sum.b=Sum_Q(gq1.b, gq2.b);
    return Sum;
}

Gq Minus_Gq(Gq gq1, Gq gq2){
    Gq Min;
    Min.a=Minus_Q(gq1.a, gq2.a);
    Min.b=Minus_Q(gq1.b, gq2.b);
    return Min;
}

Gq Prod_Gq(Gq gq1, Gq gq2){
    Gq Prod;
    Prod.a=Minus_Q(Prod_Q(gq1.a, gq2.a), Prod_Q(gq1.b, gq2.b));
    Prod.b=Sum_Q(Prod_Q(gq1.a, gq2.b), Prod_Q(gq1.b, gq2.a));
    return Prod;
}

Gq Div_Gq(Gq gq1, Gq gq2){
    Q gq_s;
    Gq Div;
    gq_s=Sum_Q(Square_Q(gq2.a), Square_Q(gq2.b));
    Div.a=Div_Q(Sum_Q(Prod_Q(gq1.a, gq2.a), Prod_Q(gq1.b, gq2.b)), gq_s);
    Div.b=Div_Q(Minus_Q(Prod_Q(gq1.b, gq2.a), Prod_Q(gq1.a, gq2.b)), gq_s);
    return Div;
}
//gcc GaussianosQ_Lib.c Racionales_Lib.c -o GaussianosQ_Lib && ./GaussianosQ_Lib