#include <stdio.h>    /*funciones de entrada y salida est'andar*/
#include <stdlib.h>   /*funciones de la biblioteca est'andar*/   

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
void escribeQ(Q a)
{
  printf("%d", a.p);
  if (a.q!= 1) printf("/%d", a.q);
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
Q creaQ(int num, int den)
{
  Q r = {num, den};

  r=simplificaQ(r);

  return r;
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
/*
int mcd(int a, int b);
Q sumaQ(Q a, Q b);    
Q simplificaQ(Q a);
void escribeQ(Q a);    
Q creaQ(int num, int den);
*/


int main(int argc, char *argv[])
{                               
  Q x, y, r;                    

  printf("Por sumar los racionales: ");
  x = creaQ(2, 4);                     
  y = creaQ(15, -6);                   
  escribeQ(x);                         
  printf(" y ");                       
  escribeQ(y);                         
  printf("\n");                        
  r = sumaQ(x, y);                     
  printf("La suma es: ");              
  escribeQ(r);                         
  printf("\nFIN DEL PROGRAMA\n");      

  return 0;
}  
