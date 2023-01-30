#include <stdio.h>
#include <stdlib.h>
#include "Coeficientes_Lib.h"
#include "PoliFull_Lib.h"

Pf Read_Pf(){
    Pf pf1;
    printf("Digite el grado del polinomio: ");
    scanf("%d", &pf1.Grado);
    if(pf1.C=(double*)malloc((pf1.Grado+1)*sizeof(double))==NULL)
    {
        printf("Error al generar espacio\n");
        pf1.Grado=-1;
        return pf1;
    }
    for (int i=0; i<=pf1.Grado; i++)
    {
        printf("Digite el coeficiente del mono,io x^%d: ", i);
        scanf("%lf", &pf1.C[i]);
    }
    return pf1;
}

void Write_Pf(Pf pf1){
    if (pf1.Grado<0)
    {
        printf("0");
        return 0;
    }
    for (int i=pf1.Grado; i>1; i--)
    {
        if(pf1.C[i]!=0.0) printf("%+lgx^%d ", pf1.C[i], i);
    }
    if (pf1.Grado>=1 && pf1.C[1]!=0.0 ) printf("%+lgx ", pf1.C[1]);
    if (pf1.C[0]!=0.0) printf("%+lg ", pf1.C[0]);
    return 0;
}

Pf Suma_Pf(Pf pf1, Pf pf2){
    int min, i;
    Pf Sum;
    if (pf1.Grado<0)
    {
    return pf2;
    }
    if (pf2.Grado<0){
    return pf1;
    }
    if (pf1.Grado<pf2.Grado){
        min=pf1.Grado;
        Sum.Grado=pf2.Grado;
    } else{
        min=pf2.Grado;
        Sum.Grado=pf1.Grado;
    }
    if((Sum.C=(double*)malloc((Sum.Grado+1)*sizeof(double)))==NULL){
        printf("Error al generar espacio.\n");
        Sum.Grado=-1;
        return Sum;
    }
    for (i=0; i<=min; i++) Sum.C[i]=pf1.C[i]+pf2.C[i];
    if (pf1.Grado==min){
        for (; i<=Sum.Grado; i++) Sum.C[i]=pf2.C[i];
    }
    if (pf2.Grado==min){
        for (; i<=Sum.Grado; i++) Sum.C[i]=pf1.C[i];
    }
    while(Sum.Grado>=0 && Sum.C[Sum.Grado]==0.0) Sum.Grado--;
    if (Sum.Grado<0){
        free(Sum.C);
        Sum.C=NULL;
    }
    return Sum;
}

Pf Minus_Pf(Pf pf1, Pf pf2)
{
  Pf Minus;
  int i, min;

  if (pf1.Grado<0){
    return pf2;
  }
  if (pf2.Grado<0){
    return pf1;
  }
  if (pf1.Grado<pf2.Grado){
    min=pf1.Grado;
    Minus.Grado=pf2.Grado;
  } else{
    min=pf2.Grado;
    Minus.Grado=pf1.Grado;
  }
  if((Minus.C=(double*)malloc((Minus.Grado+1)*sizeof(double)))==NULL){
    printf("Error al generar espacio.\n");
    Minus.Grado=-1;
    return Minus;
  }
  for (i=0; i<=min; i++) Minus.C[i]=pf1.C[i]-pf2.C[i];
  if (pf1.Grado==min){
    for (; i<=Minus.Grado; i++) Minus.C[i]=-pf2.C[i];
  }
  if (pf2.Grado==min){
    for (; i<=Minus.Grado; i++) Minus.C[i]=pf1.C[i];
  }
  while(Minus.Grado>=0 && Minus.C[Minus.Grado]==0.0) Minus.Grado--;
  if (Minus.Grado<0){
    free(Minus.C);
    Minus.C=NULL;
  }
  return Minus;
}

Pf Prod_Pf(Pf pf1, Pf pf2){
    Pf Prod;
    int i, j;
    if((Prod.C=(double*)malloc((Prod.Grado+1)*sizeof(double)))==NULL)
    {
    printf("Error al generar espacio.\n");
    Prod.Grado=-1;
    return Prod;
    }
    Prod.Grado=pf1.Grado+pf2.Grado;
    for(i=0; i<=Prod.Grado; i++) Prod.C[i]=0.0;
    for (i=0; i<=pf1.Grado; i++)
    {
        for (j=0; j<=pf2.Grado; j++)
        {
            Prod.C[i+j]+=pf1.C[i]+pf2.C[j];
        }
    }
    return Prod;
}








//Figma

/*


enBasePronombres SimpleCometer={"cometo     ", "cometes    ", "comete     ", "cometemos   ", "cometen    ", "cometen    ",
								"cometi      ", "cometiste   ", "cometio     ", "cometimos   ", "cometieron  ", "cometieron  ",
								"cometere    ", "cometeras   ", "cometera    ", "cometeremos ", "cometeran   ", "cometeran   ",
								"cometia     ", "cometias    ", "cometia     ", "cometiamos  ", "cometian    ", "cometian    ",
								"cometeria   ", "cometerias  ", "cometeria   ", "cometeriamos", "cometerian  ", "cometerian  ",};*/