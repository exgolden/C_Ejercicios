# include <stdio.h>
 int main(){
    float A, B, C, BC, AC, AB;
    printf("Este programa verifica se se puede construir un triangulo con rectas de longitud A, B y C \n");
    printf("Longitu de A: ");
    scanf("%f", &A);
    printf("Longitu de B: ");
    scanf("%f", &B);
    printf("Longitu de C: ");
    scanf("%f", &C);
    BC=B+C;
    AC=A+C;
    AB=A+B;
    if(BC>A && AC>B && AB>C){
        printf("Se puede construir un triangulo con longitudes %.2f, %.2f y %.2f.", A, B, C);
    }
    else{
        printf("No se puede construir un triangulo con longitudes %.2f, %.2f y %.2f.", A, B, C);
    }
    return 0;
 }