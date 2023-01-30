#ifndef Complex_Lib

typedef struct C{
    double a ,b;
}C;
C Read_C(double a, double b);
void Write_C(C c1);
C Sum_C(C c1, C c2);
C Minus_C(C c1, C c2);
C Prod_C(C c1, C c2);
C Div_C(C c1, C c2);

#define Complex_Lib
#endif