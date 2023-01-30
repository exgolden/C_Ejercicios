#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Poli_Lib.h"

//Funcion de cambio de signo
int Cambios_Signo(double Eval[], int n){
    int Cambios=0;
    for (int i=0; i<n-1; i++)
    {
        int j=1;
        while (Eval[i+j]==0 && j<n-i-1)
        {
            j++;
        }
        if((Eval[i]>0 && Eval[i+j]<0) || (Eval[i]<0 && Eval[i+j]>0)) Cambios++; 
    }

    return Cambios;
}

int Signos(int NUM, P Polys[], int Val){
    double Sign[NUM+1];
    for (int i=0; i<NUM+1; i++)
    {
        Sign[i]=Poli_eval(Polys[i], Val);
    }
    int Signos;
    Signos=Cambios_Signo(Sign, NUM+1);
    return Signos;
}

int main(){
    P F_0;
    FILE *pPolinomio=fopen("Poli.txt", "r");
    FILE *pResultado=fopen("Resultado.txt", "w");
    F_0=Read_P_txt(pPolinomio);
    printf("El polinomio que usted ingreso es: ");
    Write_P(F_0);
    int N=F_0.Grad;
    P Polinomios[N+1];
    //Creamos un array de vectores y un array de cotas
    #define LIMITE 100
    double Lim_I=-LIMITE, Lim_D=LIMITE, Neg[N+1], Pos[N+1], Aux[N+1];
    Polinomios[0]=F_0;
    //Evaluamos los polinomios y nos quedamos con sus cotas
    Neg[0]=Poli_eval(Polinomios[0], Lim_I);
    Pos[0]=Poli_eval(Polinomios[0], Lim_D);
    Polinomios[1]=Deriva_P(Polinomios[0]);
    Neg[1]=Poli_eval(Polinomios[1], Lim_I);
    Pos[1]=Poli_eval(Polinomios[1], Lim_D);
    //Creamos los demas polinomios de sturm
    for (int i=2; i<N+1; i++)
    {
        Polinomios[i]=Poli_Sturm(Polinomios[i-2], Polinomios[i-1]);
        Neg[i]=Poli_eval(Polinomios[i], Lim_I);
        Pos[i]=Poli_eval(Polinomios[i], Lim_D);
    }
    //Implementamos el cambio de signos
    int N_Raices, N_Raices_Pos, N_Raices_Neg;
    N_Raices=Cambios_Signo(Neg, N+1)-Cambios_Signo(Pos, N+1);
    printf("\nHay %d raices reales: \n", N_Raices);
    //Raices positivas y negativas
    N_Raices_Pos=abs(Cambios_Signo(Pos, N+1)-Signos(N, Polinomios, 0));
    N_Raices_Neg=abs(Cambios_Signo(Neg, N+1)-Signos(N, Polinomios, 0));
    printf("\t%d raices reales positivas\n", N_Raices_Pos);
    printf("\t%d raices reales positivas\n", N_Raices_Neg);
    //Escritura del polinomio
    fprintf(pResultado, "%d ", Polinomios[0].Grad);
    for (int i=0; i<=Polinomios[0].Grad; i++)
    {
        fprintf(pResultado, "%.2lf ",Polinomios[0].c[i]);
    }
    //Loop para encontrar los intervalos iterando uno por uno, debe de haber una forma ams inteligente
    //Si, lo ideal es que acotemos las raices del polinomio
    
    if (N_Raices_Pos>0)
    {
        int i=0;
        do
        {
            if (Signos(N, Polinomios, i+1)-Signos(N, Polinomios, i)!=0)
            {
                fprintf(pResultado, "\n%d %d", i, i+1);
                //printf("]%d, %d[\n", i, i+1);
            }
            i++;
        } while (i<=N_Raices_Pos+1);
    }
    if (N_Raices_Neg>0)
    {
        int i=0;
        do
        {
            if (Signos(N, Polinomios, i-1)-Signos(N, Polinomios, i)!=0)
            {
                fprintf(pResultado, "\n%d %d", i-1, i);
                //printf("]%d, %d[\n", i-1, i);
            }
            i--;
        } while (abs(i)<=N_Raices_Neg+1);
    }
    printf("Programa terminado!");
    fclose(pPolinomio);
    fclose(pResultado);
    return 0;
}
//gcc Ejercicio_5_Second.c Poli_lib.c -o Ejercicio_5_Second && ./Ejercicio_5_Second
//Revisar si solo lee polinomios con coefientes enteros, segun yo no, porque es un P