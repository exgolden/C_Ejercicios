# include <stdio.h>
# define Texto(Cal) printf("La calificacion fue de: %d \n", Cal)

int main(){
    int Respuesta;
    printf("Elija la calificacion a consultar: \n");
    printf("\t 1) Calculo I \n"
           "\t 2) Algebra I \n"
           "\t 3) Fisica I \n"
           "\t 4) Geometria \n");
    scanf("%d", &Respuesta);
    switch (Respuesta){
        case 1:
            Texto(8);
            break;
        case 2:
            Texto(10);
            break;
        case 3:
            Texto(8);
            break;
        case 4:
            Texto(6);
            break;
        default:
            printf("Opcion desconocida \n");
    }
    return 0;
}