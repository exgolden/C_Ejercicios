#include "Racionales_Lib.h"
#include "Cuaterniones_Lib.h"
#include "Gaussianos_Lib.h"
#include "GaussianosQ_Lib.h"
#include "Z5_Lib.h"
#include "Complex_Lib.h"
#include "Coeficientes_Lib.h"
#include "Poli_Lib.h"
#include <stdio.h>
enum TipoCoeff{Racionales, Cuaternion, Gaussianos, GaussianosQ, Mod5, Complex};
typedef union Coefficient_Base{
    Q q1;
    H h1;
    G g1;
    Gq gq1;
    int m5;
    C c1;
}Coefficient_Base;

typedef struct Coefficient{
    int Tipo;
    Coefficient_Base Coeff;
}Coefficient;


//Funciones de operacion

Coefficient Opera_Suma(Coefficient c1, Coefficient c2){
    Coefficient Suma_Resultado;
    switch (c1.Tipo)
    {
    case Racionales:
        Suma_Resultado.Coeff.q1=Sum_Q(c1.Coeff.q1, c2.Coeff.q1);
        break;
    case Cuaternion:
        Suma_Resultado.Coeff.h1=Sum_H(c1.Coeff.h1, c2.Coeff.h1);
        break;
    case Gaussianos:
        Suma_Resultado.Coeff.q1=Sum_Q(c1.Coeff.q1, c2.Coeff.q1);
        break;
    case GaussianosQ:
        Suma_Resultado.Coeff.gq1=Sum_Gq(c1.Coeff.gq1, c2.Coeff.gq1);
        break;
    case Mod5:
        Suma_Resultado.Coeff.m5=Sum_Z5(c1.Coeff.m5, c2.Coeff.m5);
        break;
    case Complex:
        Suma_Resultado.Coeff.c1=Sum_C(c1.Coeff.c1, c2.Coeff.c1);
        break;
    }
    return Suma_Resultado;
}








//Funciones
// Coefficient Read_Coefficient(){
//     Coefficient Coeff1;
//     printf(
//         "Digite 0 para coeficientes de tipo Racionales.\n"
//         "Digite 1 para coeficientes de tipo Cuaternion.\n"
//         "Digite 2 para coeficientes de tipo Gaussianos.\n"
//         "Digite 3 para coeficientes de tipo Modulo 5.\n"
//         "Digite 4 para coeficientes de tipo Complejo.\n"  
//     );
//     printf("Tipo: ");
//     scanf("%d", &Coeff1.Tipo);
//     switch (Coeff1.Tipo)
//     {
//     case Racionales:
//         printf("Digite un Racional en la forma (p q): ");
//         scanf("%d %d", &Coeff1.Coeff.q1.p, &Coeff1.Coeff.q1.q);
//         break;
//     case Cuaternion:
//         printf("Digite un Cuaternion en la forma (a b c d): ");
//         scanf("%lf %lf", &Coeff1.Coeff.h1.a, &Coeff1.Coeff.h1.b, &Coeff1.Coeff.h1.c, &Coeff1.Coeff.h1.d);
//         break;
//     case Gaussianos:
//         printf("Digite un Gaussiano en la forma (a b): ");
//         scanf("%d %d", &Coeff1.Coeff.g1.a, &Coeff1.Coeff.g1.b);
//         break;
//     case Mod5:
//         printf("Digite un entero para operar en modulo 5: ");
//         scanf("%d", &Coeff1.Coeff.m5);
//         break;
//     case Complex:
//         printf("Digite un Complejo en la forma (a b): ");
//         scanf("%lf %lf", &Coeff1.Coeff.c1.a, &Coeff1.Coeff.c1.b);
//         break;
//     default:
//         printf("Tipo de dato erroneo!");
//         break;
//     }
// }

int main(){
    //Entrada
    FILE *pEntrada=fopen("Entrada.txt", "r");
    FILE *pSalida=fopen("Salida.txt", "w");
    Coefficient Coeff1, Coeff2;
    //Me parece que la segunda linea es inecesaria pero por si acaso la añado
    fscanf(pEntrada, "%d", &Coeff1.Tipo);
    Coeff2.Tipo=Coeff1.Tipo;

    //Casos
    switch (Coeff1.Tipo)
    {
    case Racionales:
        fscanf(pEntrada, "%d %d", &Coeff1.Coeff.q1.p, &Coeff1.Coeff.q1.q);
        fscanf(pEntrada, "%d %d", &Coeff2.Coeff.q1.p, &Coeff2.Coeff.q1.q);
        Q q_Sum, q_Minus, q_Prod, q_Div;
        q_Sum=Sum_Q(Coeff1.Coeff.q1, Coeff2.Coeff.q1);
        q_Minus=Minus_Q(Coeff1.Coeff.q1, Coeff2.Coeff.q1);
        q_Prod=Prod_Q(Coeff1.Coeff.q1, Coeff2.Coeff.q1);
        q_Div=Div_Q(Coeff1.Coeff.q1, Coeff2.Coeff.q1);
        // Write_Q(Coeff1.Coeff.q1);
        // printf("\n");
        // Write_Q(Coeff2.Coeff.q1);
        // printf("\n");
        // Write_Q(q_Sum);
        // printf("\n");
        // Write_Q(q_Minus);
        // printf("\n");
        // Write_Q(q_Prod);
        // printf("\n");
        // Write_Q(q_Div);
        break;
    case Cuaternion:
        fscanf(pEntrada, "%lf %lf %lf %lf", &Coeff1.Coeff.h1.a, &Coeff1.Coeff.h1.b, &Coeff1.Coeff.h1.c, &Coeff1.Coeff.h1.d);
        fscanf(pEntrada, "%lf %lf %lf %lf", &Coeff2.Coeff.h1.a, &Coeff2.Coeff.h1.b, &Coeff2.Coeff.h1.c, &Coeff2.Coeff.h1.d);
        H h_Sum, h_Minus, h_Prod, h_Div;
        h_Sum=Sum_H(Coeff1.Coeff.h1, Coeff2.Coeff.h1);
        h_Minus=Minus_H(Coeff1.Coeff.h1, Coeff2.Coeff.h1);
        h_Prod=Prod_H(Coeff1.Coeff.h1, Coeff2.Coeff.h1);
        h_Div=Div_H(Coeff1.Coeff.h1, Coeff2.Coeff.h1);
        // Write_H(Coeff1.Coeff.h1);
        // printf("\n");
        // Write_H(Coeff2.Coeff.h1);
        // printf("\n");
        // Write_H(h_Sum);
        // printf("\n");
        // Write_H(h_Minus);
        // printf("\n");
        // Write_H(h_Prod);
        // printf("\n");
        // Write_H(h_Div);
        break;
    case Gaussianos:
        fscanf(pEntrada, "%d %d", &Coeff1.Coeff.g1.a, &Coeff1.Coeff.g1.b);
        fscanf(pEntrada, "%d %d", &Coeff2.Coeff.g1.a, &Coeff2.Coeff.g1.b);
        G g_Sum, g_Minus, g_Prod, g_Div;
        g_Sum=Sum_G(Coeff1.Coeff.g1, Coeff2.Coeff.g1);
        g_Minus=Minus_G(Coeff1.Coeff.g1, Coeff2.Coeff.g1);
        g_Prod=Prod_G(Coeff1.Coeff.g1, Coeff2.Coeff.g1);
        // Write_G(Coeff1.Coeff.g1);
        // printf("\n");
        // Write_G(Coeff2.Coeff.g1);
        // printf("\n");
        // Write_G(g_Sum);
        // printf("\n");
        // Write_G(g_Minus);
        // printf("\n");
        // Write_G(g_Prod);
        break;
    case GaussianosQ:
        fscanf(pEntrada, "%d %d %d %d", &Coeff1.Coeff.gq1.a.p, &Coeff1.Coeff.gq1.a.q, &Coeff1.Coeff.gq1.b.p, &Coeff1.Coeff.gq1.b.q);
        fscanf(pEntrada, "%d %d %d %d", &Coeff2.Coeff.gq1.a.p, &Coeff2.Coeff.gq1.a.q, &Coeff2.Coeff.gq1.b.p, &Coeff2.Coeff.gq1.b.q);
        Gq gq_Sum, gq_Min, gq_Prod, gq_Div;
        gq_Sum=Sum_Gq(Coeff1.Coeff.gq1, Coeff2.Coeff.gq1);
        gq_Min=Minus_Gq(Coeff1.Coeff.gq1, Coeff2.Coeff.gq1);
        gq_Prod=Prod_Gq(Coeff1.Coeff.gq1, Coeff2.Coeff.gq1);
        gq_Div=Div_Gq(Coeff1.Coeff.gq1, Coeff2.Coeff.gq1);
        // Write_Gq(Coeff1.Coeff.gq1);
        // printf("\n");
        // Write_Gq(Coeff2.Coeff.gq1);
        // printf("\n");
        // Write_Gq(gq_Sum);
        // printf("\n");
        // Write_Gq(gq_Min);
        // printf("\n");
        // Write_Gq(gq_Prod);
        // printf("\n");
        // Write_Gq(gq_Div);
        break;
    case Mod5:
        fscanf(pEntrada, "%d %d", &Coeff1.Coeff.m5, &Coeff2.Coeff.m5);
        int m5_Sum, m5_Minus, m5_Prod, m5_Div;
        m5_Sum=Sum_Z5(Coeff1.Coeff.m5, Coeff2.Coeff.m5);
        m5_Minus=Minus_Z5(Coeff1.Coeff.m5, Coeff2.Coeff.m5);
        m5_Prod=Prod_Z5(Coeff1.Coeff.m5, Coeff2.Coeff.m5);
        m5_Div=Div_Z5(Coeff1.Coeff.m5, Coeff2.Coeff.m5);
        // printf("%d", Coeff1.Coeff.m5);
        // printf("\n");
        // printf("%d", Coeff2.Coeff.m5);
        // printf("\n");
        // printf("%d", m5_Sum);
        // printf("\n");
        // printf("%d", m5_Minus);
        // printf("\n");
        // printf("%d", m5_Prod);
        // printf("\n");
        // printf("%d", m5_Div);
        // printf("\n");
        break;
    case Complex:
        fscanf(pEntrada, "%lf %lf", &Coeff1.Coeff.c1.a, &Coeff1.Coeff.c1.b);
        fscanf(pEntrada, "%lf %lf", &Coeff2.Coeff.c1.a, &Coeff2.Coeff.c1.b);
        C c_Sum, c_Minus, c_Prod, c_Div;
        c_Sum=Sum_C(Coeff1.Coeff.c1, Coeff2.Coeff.c1);
        c_Minus=Minus_C(Coeff1.Coeff.c1, Coeff2.Coeff.c1);
        c_Prod=Prod_C(Coeff1.Coeff.c1, Coeff2.Coeff.c1);
        c_Div=Div_C(Coeff1.Coeff.c1, Coeff2.Coeff.c1);
        // Write_C(Coeff1.Coeff.c1);
        // printf("\n");
        // Write_C(Coeff2.Coeff.c1);
        // printf("\n");
        // Write_C(c_Sum);
        // printf("\n");
        // Write_C(c_Minus);
        // printf("\n");
        // Write_C(c_Prod);
        // printf("\n");
        Write_C(c_Div);
        break;
    default:
        printf("Tipo de coeficiente erroneo!\n");
        printf("%d", Coeff1.Tipo);
        break;
    }
    fclose(pEntrada);
    fclose(pSalida);
    return 0;
}
//Q, H, G, Gq, Zp y C
//Falta implemebntar la biblioteca de gaussianos racionales
//Falta la division de cuaterniones
//Faltan los gaussianos racionales
//Usa p=5 en zp
//Checar con tiempo la biblioteca de gaussianos racionales, ver que funcione
//Cambie los tipos de C y cuaternioes, debo chera si funcionan
//Z_p ahora solo trabaja con 5
//Checar que pasa cuando un racional es negativo, este no imprime el signo
//crear el Read_Coefficente_Txt
//Tal vez tenga que crear una biblioteca extra para leer los polinomios
/*
gcc Coeficientes_Lib.c Racionales_Lib.c Gaussianos_Lib.c Z5_Lib.c Complex_Lib.c Coeficientes_Lib.c Poli_Lib.c -o Coeficientes_Lib && ./Coeficientes_Lib
gcc Coeficientes_Lib.c Racionales_Lib.c Cuaterniones_Lib.c Gaussianos_Lib.c Z5_Lib.c Complex_Lib.c GaussianosQ_Lib.c -o Coeficientes_Lib && ./Coeficientes_Lib
*/


//Quita las estructuras de la libreria de coeficientes
//Checar division de cuaterniones
//Borrar el main de cauterniones
//Tengo unas anotaciones ne la biblioteca de Gq que vienen desde Q
//Comprueba a mano que el producto y division de gaussianosq este bien, ya quedpo
//GaussianosQ usa racionales entonce sno se is la copile correctamente
//incluir los gaussainosq aqui