#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Racionales_Lib.h"

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

Q Read_Q(int p, int q){
    Q q1;
    q1.p=p;
    q1.q=q;
    q1=Simple_Q(q1);
    return q1;
}

void Write_Q(Q q1){    
    printf("%+d", q1.p);
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

Q Square_Q(Q q1){
    Q exp;
    exp=Prod_Q(q1, q1);
    return exp;
}