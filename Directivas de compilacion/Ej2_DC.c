#include <stdio.h>

int main(int argc, char *argv[]){
    printf("El nombre del programa es: %s\n", argv[0]);
    printf("Un saludo para: %s", argc>1?argv[1]:"El mundo");
    return 0;
}
/*
Los comandos de linea nos sirven para manerjar nuestro programa desde el exterior 
argc nos da el numeor de argumentos que le pasamos al programa
*argv[] es un vector de punteros que nos lleva  la direccion donde se aloca cada argumento
por defecto argv[0] nos da el nombre del programa
argv[1] nos da el primer comando que se le da programa

Para correr un programa en la terminal use: https://stackoverflow.com/questions/32337643/how-can-i-run-a-c-program-on-mac-os-x-using-terminal
Explicacion sobre los argumentos de linea: https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
*/