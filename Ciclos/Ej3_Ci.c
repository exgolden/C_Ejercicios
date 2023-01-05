#include <stdio.h>

int main(){
    //Usamos unsigned órque asi podemos usar todos los caracteres ASCII
    unsigned char C;

    printf("Programa para seleccionar un caracter\n");
    //Usamos un do para ejecutar el programa siempre que no se de 'E' como argumento
    do
    {
        printf("Escriba un caracter(Digite 'E'para salir): \n");
        scanf("%c", &C);
        printf("El codigo ASCII del caracter digitado es:\n"
                "Hex: %02x\n"
                "Dec: %3d\n"
                "Oct: %o\n", C, C, C);
        if (C>=0xc2) 
        {
            scanf("%c%*c", &C);
            printf("El codigo ASCII del segundo byte del caracter seleccionado es el siguiente hex:%02x, dec:%3d, oct:%o\n", C, C, C);
        } else scanf("%*c");
    } while (C!='E');
    return 0;
}
/*
    El codigo ASCII es un compendio de caracteres numerados hasta el 256, lo que hace es representar el caracter digitado en su
    corresdpondiente codigo ASCII en diferentes bases.
    Cuando el caracter se guarda en dos bytes entonces se ejecuta la segunda parte del codigo 
*/