#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Poli_Lib.h"
#define RAICES 6
#define PAR 2
#define EPSILON 0.0001
#define CONSTANTE 0.5

int main(){
    //Entrada
    double Aux, Root_1;
    P Polinomios[2];
    FILE *pIntervalos=fopen("Resultado.txt", "r");
    FILE *pSoluciones=fopen("Soluciones.txt", "w");
    int Intervalos[RAICES][PAR];
    Polinomios[0]=Read_P_txt(pIntervalos);
    Polinomios[1]=Deriva_P(Polinomios[0]);
    for (int i=1; i<=RAICES; i++)
    {
        fscanf(pIntervalos, "%d %d", &Intervalos[i][0], &Intervalos[i][1]);
    }
    //Newton
    for (int i=1; i<=RAICES-1; i++)
    {
        Aux=Intervalos[i][0]+CONSTANTE;
        do
        {
            Root_1=Newton(Polinomios[0], Polinomios[1], Aux);
            Aux=Newton(Polinomios[0], Polinomios[1], Root_1);
        } while (fabs(Root_1-Aux)>=EPSILON);
        fprintf(pSoluciones, "]%d %d[: %lf\n", Intervalos[i][0], Intervalos[i][1], Aux);
    }
    fclose(pIntervalos);
    fclose(pSoluciones);
    return 0;
}
//Raices deberia ser una variable
//El 1 debe de leer el tipo de coeficiente
    //El grado del polinomio
    //Las entradas de los coeficeintes
//gcc Ejercicio_6.c Poli_lib.c -o Ejercicio_6 && ./Ejercicio_6
//ROOT deberia ser uan avriable pero me da hueva usar el puntero
//Agregue una constante porque cuando hay dos raices que tienen un elemento en conjunto en sus intevralos
    //]0, 1[ y ]1, 2[, entonces a veces el algoritmo converge a una sola raiz en los dos intentso
    //por lo que he agregado una constante, sin embargo esto solo es al tanteo