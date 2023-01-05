#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    int len;
    char Texto[1024];
    char Cadena[1024];
    printf("Antes de la llamada al Buffer\nEcriba una cadena: ");
    scanf("%[^\n]%*c", Cadena);
    //sprintf le da formato al texto y despues lo almacena en un puntero, asi ya no tenemos que darle formato a cada rato
    //Aqui le pedimos imprimir 30 caracteres junto con nuestrta variable
    //Al parecer el espacio en blanco es un flag para formato, en ese caso solo da un espacio
    //Si cambiamos el espacio por 0 entonces rellena los epsacios en blanco por el numero de ceros que hayamos usado
    sprintf(Texto, "%3sHola %s!!!", " ", Cadena);
    printf("La cadena generada es: <<%s>>\n", Texto);
    printf("---------------------------------------------------------------------\n");

    len=strlen(Texto);
    //Este loop mueve el texto como si fuera un letrero
    //Hace un cambio tres veces
    for (int j=0; j<3; j++)
    {
        for (int i=0; i<len; i++)
        {
            //"\r" lleva el cursor al inicio de la linea
            //Mueve el primer caracter de Texto al ultimo lugar de la cadena de Texto
            printf("\r%s", Texto);
            // fflush elimina lo que tengamos almacenado en la memoria inmediata de salida
            fflush(stdout);
            sprintf(Texto, "%s%c", &(Texto[1]), Texto[0]);
            sleep(2);
        }
        
    }
    return 0;
}
// https://www.carlospes.com/curso_de_lenguaje_c/01_11_la_funcion_fflush.php