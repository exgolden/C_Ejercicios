#include "Coeficientes_Lib.h"

//Estructuras
enum TipoCoeff{Complex, Cuaternion, Gaussianos, Racionales, Mod5};
typedef union COEFF{
    C c1;
    H h1;
    G g1;
    Q q1;
    int m5;
}COEFF;

typedef struct Coeficiente{
    int Tipo;
    COEFF Coeff;
}Coeficiente;

int main(){
    Co
    return 0;
}

//Falta la division de cuaterniones
//Faltan los gaussianos racionales
//Usa p=5 en zp
//Checar con tiempo la biblioteca de gaussianos racionales, ver que funcione
//Cambie los tipos de C y cuaternioes, debo chera si funcionan
//Z_p ahora solo trabaja con 5
//Checar que pasa cuando un racional es negativo, este no imprime el signo