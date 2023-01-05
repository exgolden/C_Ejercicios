#include <stdio.h>
#include <stdlib.h>


/*Lee Polinomios
double Read(){
    int Grad;
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &Grad);
    int *Fx_0=malloc(Grad*sizeof(int));
    for (int i=0; i<Grad; i++)
    {
        printf("X^%d: ", Grad-1);
        scanf("%lf", &Fx_0[i]);
    }
    printf(Fx_0);
}
*/

int main(){
    printf("Este programa separa las raices simple de un polinomio con coeficientes reales\n"
            "en intervalos por medio del metodo de Sturm\n");
    //Entrada
    int Grad;
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &Grad);
    //Puedo usar Grad-1, Grad y Grad+1 sin problemas, por que=?
    int *Fx_0=malloc((Grad)*sizeof(int));
    for (int i=0; i<Grad+1; i++)
    {
        printf("x^%d: ", i);
        scanf("%d", &Fx_0[i]);
    }
    /*
        Derivada: Si bien la matriz asociada a la derivada no es diagonalizable, podemos fingir que esta es
        diagonal y no tomar enc cuenta el primer elemento
    */
   //Puedo usar Grad-1, Grad y Grad+1 sin problemas, por que=?
    int *Fx_2=malloc(Grad*sizeof(int));
    for (int i=0; i<=Grad; i++)
    {
        Fx_2[i]=i*Fx_0[i];
    }
    



    for (int i=0; i<=Grad; i++)
    {
        printf("Fx_2[%d]=%d\n", i, Fx_2[i]);
    }

    free(Fx_0);
    free(Fx_2);
    return 0;
}
//Preguntar porque puedo distinto tamaños para el array