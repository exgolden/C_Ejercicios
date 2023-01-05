#include <stdio.h>
// Solo guarda la variable para su sustitucion, no la imprime si llamamos a la macro
#define Macro_1 "Isaibb \n"
// No entiendo pára que nos enseño esta macro
#define Macro_2 Mientras no se use no hay sustitucion
// Al parecer nos muestra que cuando imprimimos cadenas no es necesario el formato %s siempre que usemos "#"
#define Macro_Parametros(X, Y, Z) printf("Strings: " #X ", " #Y ", " #Z ". \n")
#define Macro_Parametros_Format(X, Y, Z) printf("Strings: %s, %s, %s. \n", #X, #Y, #Z)
#define Macro_Par(X) printf("String: %s \n", #X)
// No entiendo porque en la priemra parte de la macro si usa el ";"
#define Macro_Concatenar(X, Y) printf("Las strings " #X " y " #Y " Se concatenan para usar como variable: \n"); \
    Macro_Par(Dentro de macro: X##Y)
int main(){
    printf("Inicio del programa \n");
    printf(Macro_1);
    Macro_Parametros(Uno, Dos, Tres);
    Macro_Parametros_Format(Uno, Dos, Tres);
    Macro_Concatenar(Uno, Dos);
    Macro_Concatenar(2, 5);
    printf("Fin del programa \n");
    return 0;
}
    