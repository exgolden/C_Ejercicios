#include <stdio.h>
#include <stdlib.h>

#define GRADMAX 20
typedef struct _P_{
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
int main(){
    P p1, p2, Sum, Minus, Prod, Div;
    printf("Este programa opera con polinomios\n");
    p1=Read_P();
    p2=Read_P();
    printf("Los polinomios son:\np1= ");
    Write_P(p1);
    printf("\np2= ");
    Write_P(p2);
    //Suma
    printf("\nSu suma es: ");
    Sum=Sum_P(p1, p2);
    Write_P(Sum);
    //Resta
    printf("\nSu resta es: ");
    Minus=Minus_P(p1, p2);
    Write_P(Minus);
    //Producto
    printf("\nSu producto es: ");
    Prod=Prod_P(p1, p2);
    Write_P(Prod);
    //Division
    printf("\nSu division es: ");
    Div=Div_P(p1, p2);
    Write_P(Div);
    printf("\nFin del programa");
    return 0;
}

//Funciones auxiliares
P Read_P(){
    P Pol;
    int i;
    printf("Digite el grado: ");
    scanf("%d", &(Pol.Grad));
    for (i=0; i<=Pol.Grad; i++)
    {
        printf("Digite el coeficiente del monomio x^%d: ", i);
        scanf("%lf", &(Pol.c[i]));
    }
    for (; i<=GRADMAX; i++)
    {
        Pol.c[i]=0.0;
    }
    return Pol;    
}

int Write_P(P p1){
    int i;
    //Se considera que el polinomio 0 es de grado -1
    if(p1.Grad<0)
    {
        printf(" 0");
        return 0;
    }
    for (i=p1.Grad; i>1; i--)
    {
        if (p1.c[i]!=0.0) printf("%+lg x^%d  ", p1.c[i], i);
    }
    if (p1.Grad>=1 && p1.c[1]!=0.0) printf("%+lg x ", p1.c[1]);
    if(p1.c[0]!=0.0) printf("%+lg ", p1.c[0]);
    return 0;
}

P Sum_P(P p1, P p2){
    P Sum;
    int i;
    for(i=0; i<=GRADMAX; i++) Sum.c[i]=0.0;
    Sum.Grad=p1.Grad<p2.Grad?p2.Grad:p1.Grad;
    for(i=0; i<=Sum.Grad; i++) Sum.c[i]=p1.c[i]+p2.c[i];
    //Uso este codigo ya que le grado del resultado puede ser menor al de alguno de los sumanos
    while(Sum.Grad>=0 && Sum.c[Sum.Grad]==0) Sum.Grad--;
    return Sum;
}

P Minus_P(P p1, P p2){
    P Minus;
    int i;
    for(i=0; i<=GRADMAX; i++) Minus.c[i]=0.0;
    Minus.Grad=p1.Grad<p2.Grad?p2.Grad:p1.Grad;
    for(i=0; i<=Minus.Grad; i++) Minus.c[i]=p1.c[i]-p2.c[i];
    //Uso este codigo ya que le grado del resultado puede ser menor al de alguno de los sumanos
    while(Minus.Grad>=0 && Minus.c[Minus.Grad]==0) Minus.Grad--;
    return Minus;
}

//FAIL:
P Prod_P(P p1, P p2){
    P Prod;
    int i, j;
    for(i=0; i<=GRADMAX; i++) Prod.c[i]=0.0;
    Prod.Grad=p1.Grad+p2.Grad;
    for(i=0; i<=p1.Grad; i++)
        for(j=0; j<=p2.Grad; j++)
            Prod.c[i+j]+=p1.c[i]+p2.c[j];
    return Prod;
}
//CHECK:
P Prod_Mon_P(P p1, double c, int e){
    P Prod_M;
    int i;
    for(i=0; i<=GRADMAX; i++) Prod_M.c[i]=0.0;
    Prod_M.Grad=p1.Grad+e;
    for(i=e; i<=Prod_M.Grad; i++) Prod_M.c[i]=p1.c[i-e]*c;
    return Prod_M;
}

//No se para que sirve esta funcion
int EsCero_P(P p1){
    return p1.Grad<0;
}

P Div_P(P p1, P p2){
    P q, r, Aux;
    int Grad, i;
    for(i=0; i<=GRADMAX; i++) q.c[i]=0.0;
    if (p1.Grad<p2.Grad)
    {
        q.Grad=-1;
        return q;
    }
    q.Grad=p1.Grad-p2.Grad;
    do
    {
        Grad=p1.Grad-p2.Grad;
        q.c[Grad]=p1.c[p1.Grad]/p2.c[p2.Grad];
        Aux=Prod_Mon_P(p2, q.c[Grad], Grad);
        p1=Minus_P(p1, Aux);
        r=p1;
    } while (!EsCero_P(r) && (p1.Grad>=p2.Grad));
    return q;
}