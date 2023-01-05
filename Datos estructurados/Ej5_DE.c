#include <stdio.h>
typedef struct Figura{
    int H, A, E;
    char Car;
}Figura;

/*
    Este porgrama imrpime una figura como la siguiente 
    #   ##########
    ##   #########
    ###   ########
    ####   #######
    #####   ######
*/
int main(){
    int Tope_1, Tope_2;
    Figura Mi_Figura;
    printf("Introduzca Altura, Ancho y Espaciado: ");
    //La maestra uso el loop para evitar que el usuario de <enter> como caracater para imprimir
    //El programa solo usara aquel caracter que se encuentre entre dos saltos de linea
    //Sin embargo el programa aun corre sin ese loop y sin el *[\n] del segundo scan y ademas no acepta un <enter> como un caracter
    scanf("%d %d %d", &Mi_Figura.H, &Mi_Figura.A, &Mi_Figura.E);
    printf("Introdzca un caracter: ");
    //Al parecer usa este loop para almacenar todo lo que se encuntre enyte salto de lineas como caracter
        //ya que puede tomar el salti de linea como un caracter a la hora de dar el input
        //pero no se porque no habiamos visto esto hasta hoy
    //Debo de poner el espacio antes del sgfundo input para que este pueda accederse
    scanf(" %c", &Mi_Figura.Car);
    /*
    for (Mi_Figura.Car='\n'; Mi_Figura.Car=='\n';)
    {
        scanf("%c", &Mi_Figura.Car);
    }
    */
    printf("Los valores introducidos son:\n"
            "Ancho: %d\n"
            "Altura: %d\n"
            "Espaciado: %d\n"
            "Caracter: %c\n"
            "La figura es:\n",
            Mi_Figura.A, Mi_Figura.H, Mi_Figura.E, Mi_Figura.Car);
    //Este primer loop imprime las filas
    for (int i=0; i<Mi_Figura.H; i++)
    {
        //Limite vertical
        Tope_1=i;
        //Limite lateral
        Tope_2=Mi_Figura.A-i;
        if (Tope_1>Mi_Figura.A+Mi_Figura.E)
        {
            Tope_1=Mi_Figura.A+Mi_Figura.E;
        }
        //Estos loops imprimen las columnas
        for (int j=0; j<=Tope_1; j++) printf("%c", Mi_Figura.Car);
        for (int j=0; j<Mi_Figura.E; j++) printf(" ");
        for (int j=0; j<Tope_2; j++) printf("%c", Mi_Figura.Car);
        printf("\n");
    }
    
    return 0;
}