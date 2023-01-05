#include <stdio.h>
#include <stdlib.h>

// Funcion de input 
#define Leer(X) printf("Digite el valor de " #X ": ");\
    scanf("%lf", &X)
// Funcion de selector de determinante
#define Val_Det(X) X=(det##X)/det

int main(){
    printf("Este programa resuelve un sistema de 2 ecuaciones con dos incognitas \n");
    printf("ax+by=c \ncx+dy=f \n");
    double a, b, c, d, e, f, det, detx, dety, x, y;
    // Input
    Leer(a);
    Leer(b);
    Leer(c);
    Leer(d);
    Leer(e);
    Leer(f);
    // Determinante
    det=(a*e)-(b*d);
    if (det==0){
        printf("El sistema no tiene solucion unica\n");
    }
    else{
        detx=(c*e)-(b*f);
        dety=(a*f)-(c*d);
        Val_Det(x);
        Val_Det(y);
        printf("La solucion del sistema es: x=%lf, y=%lf \n",x, y);
    }
    return 0;
}