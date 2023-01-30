#include <stdio.h>
#include <stdlib.h>
#include "Coeficientes_Lib.h"



int main(){
    FILE *pEntrada=fopen("Entrada.txt", "r");
    FILE *pSalida=fopen("Salida.txt", "w");
    




    Coefficient Coeff1, Coeff2;
    fscanf(pEntrada, "%d", &Coeff1.Tipo);
    Coeff2.Tipo=Coeff1.Tipo;
    fscanf(pEntrada, "%d", &Coeff1.Tipo);





    fclose(pEntrada);
    fclose(pSalida);
    return 0;
}