#include <stdio.h>
#define MaxCol 20
#define MaxRen 20

typedef struct Matrix{
    int m, n;
    //El numero maximo de entradas que acepta es del de Max
    double C[MaxRen][MaxCol];
}Matrix;

//Este programa imprime matrices
int main(){
    Matrix Mat_1;
    printf("Ingrese el numero de renglones y columnas de la matriz (m n): ");
    scanf("%d %d", &Mat_1.m, &Mat_1.n);
    //Definicion del tamaño de la matriz
    if (Mat_1.m<0 || Mat_1.m>MaxRen)
    {
        Mat_1.m=2;
        printf("Numero de renglones fuera de rango, se asignaran 2 renglones\n");
    }
    if (Mat_1.n<0 || Mat_1.n>MaxCol)
    {
        Mat_1.n=2;
        printf("Numero de columnas fuera de rango, se asignaran 2 columnas\n");
    }
    //Ingreso de datos
    printf("Ingrese las entradas de la matriz:\n");
    for (int i=0; i<Mat_1.m; i++)
    {
        for (int j=0; j<Mat_1.n; j++)
        {
            printf("[%d, %d]: ", i, j);
            scanf("%lf", &Mat_1.C[i][j]);
        }
    }
    printf("La matriz ingresada es:\n");
    for (int i =0; i<Mat_1.m; i++)
    {
        for (int j=0; j<Mat_1.n; j++)
        {
            //"%g" imrpime en el formato mas pequeño, ya sea en notacion cientifica o flotante
            printf("%g ",Mat_1.C[i][j]);
        }
        printf("\n");
    }
    return 0;
}