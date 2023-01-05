#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   
#include <time.h>     /*funciones de la biblioteca time, manejo de hora y fechas*/   
#include <string.h>   /*funciones de la biblioteca string, manejo de cadenas de caracteres*/

//Racionales--------------------------------------------------
//DONE:
typedef struct _Q_{
  int p, q;        
}Q;
//DONE:
int mcd(int a, int b)
{                    
  int r;             
  if (a < 0) a=-a;
  if (b < 0) b=-b;
  if (b == 0) return a;

  while ((r=a%b) != 0){
    a = b;             
    b = r;             
  }                    
  return b;
}          
//DONE:
Q simplificaQ(Q a)
{                     
  int d;
  Q regreso;
  regreso = a;
  d = mcd (a.p, a.q);
  if (d>1){            
    regreso.p /= d;         
    regreso.q /= d;         
  }                    
  if (regreso.q < 0){       
    regreso.p *= -1;        
    regreso.q *= -1;        
  }
  return regreso;
}
//DONE:
Q sumaQ(Q a, Q b)
{                
  Q r;           
  r.p = a.p*b.q + a.q*b.p;
  r.q = a.q*b.q;
  r=simplificaQ(r);
  return r;
}
//DONE:
Q creaQ(int num, int den)
{
  Q r = {num, den};
  r=simplificaQ(r);
  return r;
}
//FIXME:
void escribeQ(Q a)
{
  char buferTemporal[128];
  int l;
  sprintf(buferTemporal, "%d", a.p);
  l = strlen(buferTemporal);
  if (a.q!= 1) sprintf(buferTemporal+l, "/%d", a.q);
  printf("%7s", buferTemporal);
}
//Matrices-----------------------------------------------------
//DONE:
#define MAXREN 10
#define MAXCOL 10
//DONE:
typedef struct _matriz_{
  int n, m;
  Q A[MAXREN][MAXCOL];
}MATRIZ;
//DONE:
MATRIZ sumaM(MATRIZ X, MATRIZ Y)
{
  MATRIZ porRegresar;
  int i, j;
  porRegresar.m = porRegresar.n = 0;
  if ( (X.m!=Y.m) || (X.n!=Y.n)){
    printf("No se puede realizar la suma de las matrices...\n");
    return porRegresar;
  }
  porRegresar.m = X.m;
  porRegresar.n = X.n;
  for (i=0; i<X.m; i++)
    for (j=0; j<X.m; j++)
      porRegresar.A[i][j] = sumaQ(X.A[i][j], Y.A[i][j]);
  return porRegresar;
}
//DONE:
void escribeM(MATRIZ X)
{
  int i, j;
  for (i=0; i<X.m; i++){
    for (j=0; j<X.m; j++){
      escribeQ(X.A[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}
//--------------------------------------------------------------
int main(int argc, char *argv[])
{
  MATRIZ a, b, r;
  int i, j;

  a.m = b.m = 3;
  a.n = b.n = 4;
  srand(time(NULL));
  for (i=0; i<a.m; i++)
    for (j=0; j<a.n; j++){ 
      a.A[i][j] = creaQ(rand()%20, rand()%15);
      b.A[i][j] = creaQ(rand()%20, rand()%15);
    }

  printf("las matrices a sumar son:\n\tPrimera matriz mxn (%d x %d):\n", a.m, a.n);
  escribeM(a);
  printf("\n\tSegunda matriz mxn (%d x %d):\n", b.m, b.n);
  escribeM(b);

  r = sumaM(a, b);

  printf("\nEl resultado es una matriz  mxn (%d x %d):\n", r.m, r.n);
  escribeM(r);

  printf("\n\nFIN DEL PROGRAMA\n");      

  return 0;
}          

