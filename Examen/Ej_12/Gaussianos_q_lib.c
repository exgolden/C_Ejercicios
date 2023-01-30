//Libreria de racionales------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
//Libreria de Gaussianos------------------------------------------
typedef struct Gq{
    Q a ,b;
}Gq;

Gq Read_Gq(Q q1, Q q2){
    Gq gq1;
    gq1.a=q1;
    gq1.b=q2;
    return gq1;
}

//TODO:
void Write_C(Gq gq1){
    printf("%+.2lf%+.2lfi", c1.a, c1.b);
}

Gq Sum_Gq(Gq gq1, Gq gq2){
    Gq sum;
    sum.a=gq1.a+gq2.a;
    sum.b=gq1.b+gq2.b;
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

