//Libreria de enteros modulos p (con p primo)
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------
int Sum_Zp(int p, int a, int b){
    int Sum;
    Sum=(a+b)%p;
    return Sum;
}
int Prod_Zp(int p, int a, int b){
    int Prod;
    Prod=(a*b)%p;
    return Prod;
}
//------------------------------------------

int main(){
    int p, a, b, Sum, Prod;
    printf("Ingrese un primo p: ");
    scanf("%d", &p);
    printf("Usted esta trabajando en los enteros modulo %d\n", p);
    printf("Ingrese los numeros a operar en modulo %d (a b): ", p);
    scanf("%d %d", &a, &b);
    a=abs(a);
    b=abs(b);
    Sum=Sum_Zp(p, a, b);
    printf("La suma de %d y %d en modulo %d es: %d\n", a, b, p, Sum);
    Prod=Prod_Zp(p, a, b);
    printf("El producto de %d y %d en modulo %d es: %d\n", a, b, p, Prod);
    return 0;
}