#include <stdlib.h>
#include <stdio.h>

// Como C no nos permite definir un array vacio sin un tamaño definido, entonces creamos un tamaño maximo
#define GradoMax 20
// No le asignamos un nombre a la estructura pero si un alias
typedef struct{
    int Grado;
    double Coeff[GradoMax];
}Polinomio;

int main(){
    Polinomio P1;
    int i;
    printf("Este programa presenta polinomios con grado menor a 20 \n");
    // Grados
    printf("Digite el grado del poliniomio: ");
    scanf("%d", &P1.Grado);
    if(P1.Grado<=0){
        printf("El polinomio ingresado es el polinomio cero");
        return 0;
    }
    if(P1.Grado>20){
        P1.Grado=GradoMax;
        printf("Grado fuera de rango, se usara por default grado=%d \n", GradoMax);
    }
    // Coeficientes
    printf("Digite los coeficientes del polinomio: \n");
    for(i=0; i<=P1.Grado; i++){
        printf("Ingrese el coeficiente de grado %d: ", i);
        scanf("%lg", &(P1.Coeff[i]));
    }
    // Presentacion
    printf("El polinomio ingresado es: \n");
    for(i=P1.Grado; i>1; i--){
        if(P1.Coeff[i]!=0){
            printf("%+lgx^%d", P1.Coeff[i], i);
        }
    }
    // Elemento grado 1
    if(P1.Coeff[1]!=0){
        printf("%+lgx", P1.Coeff[1]);
    }
    // Elemento grado 0
    if(P1.Coeff[0]!=0){
        printf("%+lg", P1.Coeff[0]);
    }
    return 0;
    // En la linea 36 usamos %+lg, si usamos el signo despues de % entonces C reconoce que quiero el signo del elemento
    // Al parecer %lg solo imprime los decimales que SI usamos
    // https://www.delftstack.com/howto/c/struct-and-typedef-struct-in-c/
    // https://stackoverflow.com/questions/1343890/how-do-i-restrict-a-float-value-to-only-two-places-after-the-decimal-point-in-c
}