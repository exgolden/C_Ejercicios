//Libreria de complejos con entradas en Z
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//------------------------------------------
typedef struct Q{
    int p ,q;
}Q;

int mcd(int a, int b){
    int Aux;
    a=abs(a);
    b=abs(b);
    if(b==0) return a;
    while ((Aux=a%b)!=0)
    {
        a=b;
        b=Aux;
    }
    return b;
}

Q Simple_Q(Q q1){
    int Aux;
    Q Simple;
    Simple=q1;
    Aux=mcd(q1.p, q1.q);
    if (Aux>1)
    {
        Simple.p/=Aux;
        Simple.q/=Aux;
    }
    if(Simple.q<0)
    {
        Simple.p*=-1;
        Simple.q*=-1;
    }
    return Simple;
}

Q Creat_Q(int p, int q){
    Q q1;
    q1.p=p;
    q1.q=q;
    q1=Simple_Q(q1);
    return q1;
}

void Write_Q(Q q1){
    printf("%d", q1.p);
    if(q1.q!=1) printf("/%d", q1.q);
}

Q Sum_Q(Q q1, Q q2){
    Q Sum;
    Sum.p=(q1.p*q2.q)+(q1.q*q2.p);
    Sum.q=q1.q*q2.q;
    Sum=Simple_Q(Sum);
    return Sum;
}

Q Minus_Q(Q q1, Q q2){
    Q Min;
    Min.p=(q1.p*q2.q)-(q1.q*q2.p);
    Min.q=q1.q*q2.q;
    Min=Simple_Q(Min);
    return Min;
}

Q Prod_Q(Q q1, Q q2){
    Q Prod;
    Prod.p=q1.p*q2.p;
    Prod.q=q1.q*q2.q;
    Prod=Simple_Q(Prod);
    return Prod;
}

Q Div_Q(Q q1, Q q2){
    Q Div;
    Div.p=q1.p*q2.q;
    Div.q=q1.q*q2.p;
    Div=Simple_Q(Div);
    return Div;
}

int main(){
    Q q1, q2, Sum, Minus, Prod, Div;
    int a, b, c, d;
    printf("Este programa opera con racionales\n");
    printf("Ingrese el primer racional (a b): ");
    scanf("%d %d", &a, &b);
    q1=Creat_Q(a, b);
    printf("Ingrese el segundo racional (c d): ");
    scanf("%d %d", &c, &d);
    q2=Creat_Q(c, d);
    printf("Usted ha ingresado los siguientes racionales: \n");
    printf("q1: ");
    Write_Q(q1);
    printf("\nq2: ");
    Write_Q(q2);
    Sum=Sum_Q(q1, q2);
    printf("\nSu suma es: ");
    Write_Q(Sum);
    Minus=Minus_Q(q1, q2);
    printf("\nSu resta es: ");
    Write_Q(Minus);
    Prod=Prod_Q(q1, q2);
    printf("\nSu multiplicacion es: ");
    Write_Q(Prod);
    Div=Div_Q(q1, q2);
    printf("\nSu division es: ");
    Write_Q(Div);
    return 0;
}
