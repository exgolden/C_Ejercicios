#include <stdio.h>

int main(){
    int a, b, c, d, Contador,
     Min_1, Min_2, Max_1, Max_2,
     Uno, Dos, Tres, Cuatro;
    
    printf("Digite cuatro enteros distintos: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    //Primera comparacion
    if (a<b)
    {
        Min_1=a;
        Max_1=b;
        Contador++;
    }
    else
    {
        Min_1=b;
        Max_1=a;
        Contador++;  
    }
    //Segunda comparacion
    if (c<d)
    {
        Min_2=c;
        Max_2=d;
        Contador++;
    }
    else 
    {
        Min_2=d;
        Max_2=c;
        Contador++; 
    }
    //Tercera comparacion, aqui pudimos haber hecho dos comparaciones pero al comprar naximos con minimios lo redujimos a una
    if (Max_1<Min_2)
    {   //Quedan ordenados
        Uno=Min_1;
        Dos=Max_2;
        Tres=Min_2;
        Cuatro=Max_2;
        Contador++;
    }
    else //Max_1>Min_2
    {
        if (Max_1<Max_2)
        {   
            Tres=Max_1;
            Cuatro=Max_2;
            Contador++;
        }
        else
        {
            Tres=Max_2;
            Cuatro=Max_1;
        }
        if (Min_1<Min_2)
        {
            Uno=Min_1;
            Dos=Min_2;
            Contador++;
        }
        else
        {
            Uno=Min_2;
            Dos=Min_1;
        }
    }
    printf("%d\n%d\n%d\n%d\n", Uno, Dos, Tres, Cuatro);
    return 0;
}