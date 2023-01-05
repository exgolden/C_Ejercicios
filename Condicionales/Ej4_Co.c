# include <stdio.h>
# include <math.h>

int main(){
    float x, y, R, Sum;
    printf("Este programa determina si un punto P(x, y) se encuentra dentro de una circunferenica de radio R con centro en el origen");
    printf("Digite las coordenadas del punto P: \n");
    printf("x: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);
    printf("Digite el radio R \n");
    printf("R: ");
    scanf("%f", &R );
    Sum=round(pow(x, 2))+round(pow(y, 2));
    if(Sum>R){
        printf("El punto P (%f, %f) esta fuera de la circunferencia con radio %f ", x, y, R);
    }
    else if (Sum==R){
        printf("El punto P (%f, %f) esta sobre la circunferencia con radio %f ", x, y, R);
    }
    else{
        printf("El punto P (%f, %f) esta dentro de la circunferencia con radio %f ", x, y, R);
    }
    return 0;
}