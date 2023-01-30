/*
 * Profesora: Veronica Bola~nos 
 * 
 * Curso de Programaci'on I
 * 
 * no olvidar escribir en el rengl'on anterior al de return 0; la l'inea:
 *    system("PAUSE");
 * 
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct _Rx_{
  int g;
  double *c;
}Rx;

Rx leeP();
int escP(Rx p);
Rx suma(Rx a, Rx b);
Rx rest(Rx a, Rx b);
Rx mult(Rx a, Rx b);
Rx multMonomio(Rx a, double c, int e);
Rx divR(Rx a, Rx b, Rx *r);
int esCero(Rx a);
Rx copiaP(Rx a);
Rx copiaMenosP(Rx a);
int  liberaP(Rx *a);

int main(int argc, char *argv[])
{
  Rx a, b, q, r={c:NULL, g:-1};

  printf("Por leer los polinomios.\n");
  a=leeP();
  b=leeP();
  printf("Los polinomios son:\na = ");
  escP(a);
  printf("\nb = ");
  escP(b);
  printf("\nCociente y residuo:\n");
  q=divR(a, b, &r);
  printf("\n\nq = ");
  escP(q);
  printf("\nr = ");
  escP(r);
  printf("\n\nFin del programa\n");
  liberaP(&a);
  liberaP(&b);
  liberaP(&q);
  liberaP(&r);
  /*Despu�s de cada operaci�n y escribir el resultado, que hagan hay que liberar
   la variable  donde se guarda el resultado*/ 
  
  return 0;
}


Rx leeP()
{
  Rx ret;
  int i;

  printf("digite el grado:");
  scanf("%d", &(ret.g));

  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for (i=0; i<=ret.g; i++){
    printf("digite el coeficiente del monomio x^%d:", i);
    scanf("%lf", &(ret.c[i]));
  }

  return ret;
}

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

Rx suma(Rx a, Rx b)
{
  Rx ret;
  int i, min;

  if (a.g<0){
    return copiaP(b);
  }
  if (b.g<0){
    return copiaP(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=min; i++) ret.c[i]=a.c[i]+b.c[i];
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  /* En la suma, los sumandos podrian haber tenido el
   * mismo grado, lo que podria implicar que el grado
   * del polinomio suma fuera menor que el de los
   * sumandos.
   */
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx rest(Rx a, Rx b)
{
  Rx ret;
  int i, min;

  if (a.g<0){
    return copiaMenosP(b);
  }
  if (b.g<0){
    return copiaP(a);
  }
  if (a.g<b.g){
    min = a.g;
    ret.g = b.g;
  } else{
    min = b.g;
    ret.g = a.g;
  }
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=min; i++) ret.c[i]=a.c[i]-b.c[i];
  if (a.g==min){
    for (; i<=ret.g; i++) ret.c[i]=-b.c[i];
  }
  if (b.g==min){
    for (; i<=ret.g; i++) ret.c[i]=a.c[i];
  }
  /* En la resta, el minuendo y el sustraendo podrian haber 
   * tenido el mismo grado, lo que podria implicar que el 
   * grado del polinomio diferencia fuera menor que el del minuendo
   * y el del sustraendo.
   */
  while(ret.g>=0 && ret.c[ret.g]==0.0) ret.g--;
  if (ret.g<0){
    free(ret.c);
    ret.c = NULL;
  }
  return ret;
}

Rx mult(Rx a, Rx b)
{
  int i, j;
  Rx ret;

  ret.g=a.g+b.g;
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }
  for (i=0; i<=ret.g; i++) ret.c[i]=0.0;
  for (i=0; i<=a.g; i++)
    for(j=0; j<=b.g; j++)
      ret.c[i+j]+=a.c[i]*b.c[j];

  return ret;
}

Rx multMonomio(Rx a, double c, int e)
{
  int i;
  Rx ret;

  ret.g=a.g+e;
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for (i=0; i<=ret.g; i++) ret.c[i]=0.0;
  for (i=e; i<=ret.g; i++) ret.c[i]=a.c[i-e]*c;
  escP(ret);

  return ret;
}

int esCero(Rx a)
{
  return a.g <0;
}


Rx divR(Rx a, Rx b, Rx *r)
{
  Rx q, aux, a_aux;
  double coef;
  int grad, i;
  
  /*a.c tiene una direcci�n de memoria v�lida, la cual queremos conservar*/
  a_aux= copiaP(a);
  /*a_aux.c tiene otra direcci�n de memoria v�lida distinta a a.c, 
  pero los campos c tienen la misma informaci�n de coeficientes*/
  a=a_aux;
  /*a.c tiene una direcci�n de memoria v�lida distinta 
    a la original del par�metro en la entrada*/

  if (a.g<b.g){
    q.g=-1;
    q.c=NULL;
    *r = copiaP(a);

    return q;
  }

  q.g=a.g-b.g;
  if((q.c=(double*)malloc((q.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    q.g = -1;
    return q;
  }
  for (i=0; i<=q.g; i++) q.c[i]=0.0;

  do{
    grad=a.g-b.g;
    q.c[grad] = a.c[a.g]/b.c[b.g];
    aux = multMonomio(b, q.c[grad], grad);
    /*a_aux.c y a,c apuntan a la misma direcci�n de memoria antes de entrar a la resta*/
    a_aux = rest(a, aux);
    /*a_aux.c tiene ahora otra direci�n de memoria por lo que s�lo se nececita liberar a a*/
    liberaP(&a);
    liberaP(&aux);
    a = a_aux;
  liberaP(r);
    *r=copiaP(a);
  }while(!esCero(*r) && (r->g>=b.g));


  return q;
}

Rx copiaP(Rx a)
{
  Rx ret;
  int i;

  ret.g = a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for(i=0; i<=ret.g; i++) ret.c[i]=a.c[i];

  return ret;
}

Rx copiaMenosP(Rx a)
{
  Rx ret;
  int i;

  ret.g = a.g;
  if (ret.g<0){
    ret.c=NULL;
    return ret;
  }
  if((ret.c=(double*)malloc((ret.g+1)*sizeof(double)))==NULL){
    printf("error al generar espacio.\n");
    ret.g = -1;
    return ret;
  }

  for(i=0; i<=ret.g; i++) ret.c[i]=-a.c[i];

  return ret;
}

int  liberaP(Rx *a) 
{
  if(a->c!=NULL) free(a->c);
  a->g=-1;
  a->c=NULL;
  return 0;	
}