#ifndef Cuaterniones_Lib

typedef struct H{
    double a, b, c, d;
}H;
H Read_H(double a, double b, double c, double d);
void Write_H(H h1);
H Sum_H(H h1, H h2);
H Minus_H(H h1, H h2);
H Prod_H(H h1, H h2);
H Div_H(H h1, H h2);

#define Cuaterniones_Lib
#endif