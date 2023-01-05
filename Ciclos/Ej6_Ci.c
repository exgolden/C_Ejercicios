#include <stdio.h>

int main (){
    int N, N2, j, i;
    printf("Digite un natural: ");
    scanf("%d", &N);
    if (N<=0)
    {
        N=20;
    }
    //Me saca de pedo que es lo que ocurre cuando N es impar, se supone que N2 no seria un entero pero esta declarado como uno
    //Al parecer usa la funcion piso
    N2=N/2;
    for (i=0; i<N2; i++)
    {
        for (j=0; j<N2-i; j++)
            {
            printf("   ");
            }
        //Empieza con la 'j' anterior
        for(;j<N2+i; j++)
            printf(" X ");
            printf("\n");
    }


}
/*
    El primer y segundo ciclo for imprime los espacios de los lados
    El tercer ciclo for imprime el patron en si
    
    Al parecer el codigo no funciona si uso los brackets internos en el loop, lo que me parece raro
    es que al ser mas de una instruciion en el ultimo loop, en teoria deberia de incluir estos
    ultimos brackest, sin embargo, si los uso el pograma no funciona. Se supone que puedo ahorrarme los brackets
    cuando solo debio de ejecutar una orden. 
    https://stackoverflow.com/questions/39579686/why-i-dont-need-brackets-for-loop-and-if-statement
*/