#include <stdio.h>
#include <stdlib.h>

//Estructuras
enum TipoCoeff{Mod7, Integer, Rational, Real, Complex};

typedef struct Q{
    int p ,q;
}Q;

typedef struct C{
    double a ,b;
}C;

typedef union COEFF{
    int m7;
    int z;
    Q q1;
    double r;
    C c;
}COEFF;

typedef struct Coeficiente{
    int Tipo;
    COEFF Coeff;
}Coeficiente;

//Funciones auxiliares
Coeficiente Read_Coeficiente(){
    int Tipo;
    Coeficiente C1;
    printf(
        "Digite 0 para coefiientes de tipo Entero Mod_7\n"
        "Digite 1 para coefiientes de tipo Entero\n"
        "Digite 2 para coefiientes de tipo Racional\n"
        "Digite 3 para coefiientes de tipo Real\n"
        "Digite 4 para coefiientes de tipo Complejo\n"
    );
    printf("Su opcion: ");
    scanf("%d", &Tipo);
    C1.Tipo=Tipo;
    switch (Tipo)
    {
    case Mod7:
        printf("Digite un entero: ");
        scanf("%d", &C1.Coeff.m7);
        C1.Coeff.m7=abs(C1.Coeff.m7%7);
        break;
    case Integer: 
        printf("Digite un entero: ");
        scanf("%d", &C1.Coeff.z);
        break;
    case Rational:
        printf("Digite un numero racional en la forma (p q): ");
        scanf("%d %d", &C1.Coeff.q1.p, &C1.Coeff.q1.q);
        break;
    case Real:
        printf("Digite un numero real: ");
        scanf("%lf", &C1.Coeff.r);
        break;
    case Complex:
        printf("Digite un complejo en la forma(a b): ");
        scanf("%lf %lf", &C1.Coeff.c.a, &C1.Coeff.c.b);
        break;
    default:
        printf("Tipo de dato invalido \n");
    }
    return C1;
}

void Write_Coeficiente(Coeficiente C1){
    switch (C1.Tipo)
    {
    case Mod7:
        printf("%d", C1.Coeff.m7);
        break;
    case Integer:
        printf("%+d", C1.Coeff.z);
        break;
    case Rational:
        printf("%+d", C1.Coeff.q1.p);
        //CHECK:
        if(C1.Coeff.q1.q>1) printf("/%d", C1.Coeff.q1.q);
        break;
    case Real:
        printf("%+lf", C1.Coeff.r);
        break;
    case Complex:
        printf("%+lf", C1.Coeff.c.a);
        if(C1.Coeff.c.b!=0.0) printf("%+lfi", C1.Coeff.c.b);
        break;
    default:
        printf("Tipo de dato invalido");
    }
}

//Main
int main(){
    Coeficiente C1;
    printf("Por leer un coeficiente de acuerdo a las sigientes normas\n");
    C1=Read_Coeficiente();
    printf("El valor ingresado es: ");
    Write_Coeficiente(C1);
    printf("\nFin del programa\n");
    return 0;
}

//Arreglar el programa de complejos y ponerle entradas en double
//La funcion de Write originalmente era int pero la hice void
//la funcion de Read tenia como argumento "void" peor se lo quite
//En el check de write hay que terminar esa funcion para cuando q es negativo