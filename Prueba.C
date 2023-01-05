
# include <stdio.h>
# include <math.h>

int main(){
    int A, inv_A, RES, i=1, Modulo=10;
    int Digitos[]={};
    printf("Este programa obtiene el inverso multiplicativo de A en modulo N \n");
    printf("Ingrese un entero A de dos digitos o mas: \n");
    scanf("%d", &A);
  while(1){
      Modulo=Modulo
  }



    //inv_A=A%Modulo;

    //printf("El inverso de %d modulo %d es: %d \n", A, Modulo, inv_A);


    /*
    if (A>=Modulo)
    {
        inv_A=A%Modulo;
            printf("El inverso de %d modulo %d es: %d", A, Modulo, inv_A);
    } 
    else 
    {
        while (1)
        {
            RES=((A*i)-1)%Modulo;
            if (RES==0)
            {
                break;
            }
            i++;
        }
        printf("El inverso de %d modulo %d es: %d", A, Modulo, i);
    }*/
    return 0;
}