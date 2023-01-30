#ifndef Polifull_Lib

typedef struct Pf{
    int Grado;
    double *C;
}Pf;
Pf Read_Pf();
void Write_Pf(Pf pf1);
Pf Suma_Pf(Pf pf1, Pf pf2);
Pf Minus_Pf(Pf pf1, Pf pf2);
Pf Prod_Pf(Pf pf1, Pf pf2);

#define Polifull_Lib
#endif