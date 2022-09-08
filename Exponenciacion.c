#include <stdio.h>
//Este programa tiene problemas con exponentes menores a 2, por la forma en la que diseñe el loop
int Exponente(int Base, int n){
  int i, Resultado;
  Resultado=Base*Base;
  for (i=0; i<(n-1); i++){
    Resultado=Resultado*Base;
  }
  return Resultado;
}
int main(){
    int Resultado;
    Resultado=Exponente(10, 1);
    printf("%d \n", Resultado);
    return 0;
}