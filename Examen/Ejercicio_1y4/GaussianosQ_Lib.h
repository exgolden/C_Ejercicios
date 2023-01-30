#include "Racionales_Lib.h"
#ifndef GaussianosQ_Lib
typedef struct Gq{
    Q a;
    Q b;
}Gq;
Gq Read_Gq(int a, int b, int c, int d);
void Write_Gq(Gq gq1);
Gq Sum_Gq(Gq gq1, Gq gq2);
Gq Minus_Gq(Gq gq1, Gq gq2);
Gq Prod_Gq(Gq gq1, Gq gq2);
Gq Div_Gq(Gq gq1, Gq gq2);

#define GaussianosQ_Lib
#endif