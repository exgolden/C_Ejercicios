
#include<stdio.h>
#include<stdlib.h>

#define GRADMAX 20

typedef struct _Rx_{
  int g;
  double c[GRADMAX+1];
}Rx;

Rx leeP();
int escP(Rx p);
Rx suma(Rx a, Rx b);
Rx rest(Rx a, Rx b);
Rx mult(Rx a, Rx b);
Rx multMonomio(Rx a, double c, int e);
Rx divR(Rx a, Rx b);
int esCero(Rx a);

int main(int argc, char *argv[])
{
  Rx a, b, q, s, m, p;

  printf("Por leer los polinomios.\n");
  a=leeP();
  b=leeP();
  printf("Los polinomios son:\na = ");
  escP(a);
  printf("\nb = ");
  escP(b);
  printf("\nProducto: \n");
  q=mult(a, b);
  printf("\n\nprod = ");
  escP(q);


  printf("\n\nFin del programa\n");

  return 0;
}

//DONE:
Rx leeP()
{
  Rx ret;
  int i;

  printf("digite el grado:");
  scanf("%d", &(ret.g));
  for (i=0; i<=ret.g; i++){
    printf("digite el coeficiente del monomio x^%d:", i);
    scanf("%lf", &(ret.c[i]));
  }
  for (; i<=GRADMAX; i++) ret.c[i]=0.0;

  return ret;
}

//DONE:
int escP(Rx p)
{
  int i;

  /* Estamos considerando que el polinomio cero
   * tiene grado -1 por conveniencia.
   */
  if(p.g<0){
    printf(" 0");
    return 0;
  }

  /* si no fue el polinomio cero, entonces solo
   * escribiremos los coeficientes que no sean cero.
   * Empezamos por el coeficiente principal.
   */
  for(i=p.g; i>1; i--)
    if (p.c[i]!=0.0) printf("%+lg x^%d ", p.c[i], i);
  /* si el polinomio es constante, entonces su grado
   * es cero y no se debe escribir la informacion del
   * arreglo en su indice 1.
   */
  if (p.g>=1 && p.c[1]!=0.0 ) printf("%+lg x ", p.c[1]);
  /* Como el polinomio no es cero. Si fuera un polinomio
   * constante, necesariamente su coeficiente debe ser
   * distinto de cero. Si su grado es positivo, entonces
   * el coeficiente constante podria ser cero y no lo 
   * escribimos.
   */
  if (p.c[0]!=0.0) printf("%+lg ", p.c[0]);

  return 0;
}

//DONE:
Rx suma(Rx a, Rx b)
{
  Rx ret;
  int i;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g = a.g<b.g?b.g:a.g;
  for (i=0; i<=ret.g; i++) ret.c[i]=a.c[i]+b.c[i];
  /* En la suma, los sumandos podrian haber tenido el
   * mismo grado, lo que podria implicar que el grado
   * del polinomio suma fuera menor que el de los
   * sumandos.
   */
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  return ret;
}

//DONE:
Rx rest(Rx a, Rx b)
{
  Rx ret;
  int i;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g = a.g<b.g?b.g:a.g;
  for (i=0; i<=ret.g; i++) ret.c[i]=a.c[i]-b.c[i];
  /* En la resta, el minuendo y el sustraendo podrian haber 
   * tenido el mismo grado, lo que podria implicar que el 
   * grado del polinomio diferencia fuera menor que el del minuendo
   * y el del sustraendo.
   */
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  return ret;
}

//FAIL:
Rx mult(Rx a, Rx b)
{
  int i, j;
  Rx ret;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g=a.g+b.g;
  for (i=0; i<=a.g; i++)
    for(j=0; j<=b.g; j++)
      ret.c[i+j]+=a.c[i]+b.c[j];

  return ret;
}

//DONE:
Rx multMonomio(Rx a, double c, int e)
{
  int i;
  Rx ret;

  for (i=0; i<=GRADMAX; i++) ret.c[i]=0.0;
  ret.g=a.g+e;
  for (i=e; i<=ret.g; i++) ret.c[i]=a.c[i-e]*c;

  return ret;
}

//DONE:
int esCero(Rx a)
{
  return a.g <0;
}

//DONE:
Rx divR(Rx a, Rx b)
{
  Rx q, aux, r;
  int grad, i;

  for (i=0; i<=GRADMAX; i++) q.c[i]=0.0;
  if (a.g<b.g){
    q.g=-1;

    return q;
  }

  q.g=a.g-b.g;
  do{
    grad=a.g-b.g;
    q.c[grad] = a.c[a.g]/b.c[b.g];
    aux = multMonomio(b, q.c[grad], grad);
    a = rest(a, aux);
    r=a;
  }while(!esCero(r) && (a.g>=b.g));


  return q;
}


  