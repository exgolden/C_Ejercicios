#ifndef Poli_Lib

#define GRADMAX 20
typedef struct P{
    int Grad;
    double c[GRADMAX+1];
}P;
P Read_P();
int Write_P(P p1);
P Sum_P(P p1, P p2);
P Minus_P(P p1, P p2);
P Prod_P(P p1, P p2);
P Prod_Mon_P(P p1, double c, int e);
P Div_P(P p1, P p2);
P Neg_P(P p1);
P Div_P_r(P p1, P p2);
P Read_P_txt(FILE *Entrada);
P Deriva_P(P p1);
double Poli_eval(P p1, double a);
P Poli_Sturm(P p1, P p2);
double Newton(P p1, P p2, double Alpha);
#define Poli_Lib
#endif

/*
+1 x^5  +5 x^4  -20 x^2  -10 x +2 
+5 x^4  +20 x^3  -40 x -10 
+4 x^3  +12 x^2  -4 
+15 x^2  +35 x +5 
+7.55556 x +4.88889 
+11.3668 %  

*/