# include <stdio.h>
# include <math.h>

int main(){
    int Numero, Inv, RES, Digito, i=1, Modulo=10;
    int Digitos[]={};
    printf("Este programa evalua si un numero de 5 digitos es capicua \n");
    printf("Digite el numero a evaluar: \n");
    scanf("%d", &Numero);
    while(i<3){
        Digito=round(pow(Modulo, i));
        Digitos[i+1]=Digito;
    }
    printf("%d \n", Digitos[2]);
    return 0;
}