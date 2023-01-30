#include "Complex_Lib.h"
#include "Cuaterniones_Lib.h"
#include "Gaussianos_Lib.h"
#include "Racionales_Lib.h"
#include "Zp_Lib.h"

//Estructuras
enum TipoCoeff{Mod7, Integer, Rational, Real, Complex};
typedef union COEFF{
    int m7;
    int z;
    Q q1;
    double r;
    C c;
}COEFF;

typedef struct Coeficiente{
    int Tipo;
    COEFF Coeff;
}Coeficiente;



int main(){

    return 0;
}

//Falta la division de cuaterniones
//En que modulo quiere Z_{p}