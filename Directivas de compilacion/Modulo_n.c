# include <stdio.h>
# include <stdlib.h>
int main(){
    int A, inv_A, Modulo, RES, i=1;
    printf("Este programa obtiene el inverso multiplicativo de A en modulo N \n");
    //jeje au no tengo muy claro como lanzar una advertencia por A==0 sin hacer tanto nest
    printf("Ingrese un entero A distinto de 0: \n");
    scanf("%d", &A);
    printf("Ingrese un primo N: \n");
    scanf("%d", &Modulo);
    /*Aqui Vero uso varias operaciones que supuse eran para obtener el modulo de A
    xk no uso solo abs()*/
    A=abs(A);
    if (A>=Modulo)
    {
        inv_A=A%Modulo;
        inv_A==0?printf("El 0 no tiene inverso"):
            printf("El inverso de %d modulo %d es: %d", A, Modulo, inv_A);
    } 
    else 
    {
        while (1)
        {
            RES=((A*i)-1)%Modulo;
            if (RES==0)
            {
                break;
            }
            i++;
        }
        printf("El inverso de %d modulo %d es: %d", A, Modulo, i);
    }
    return 0;
}