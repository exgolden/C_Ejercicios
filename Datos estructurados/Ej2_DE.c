#include <stdlib.h>
#include <stdio.h>

// Primero hay que crear la estrucutrua y despues la macro para hacer mas legible el codigo
typedef struct{
    double Re;
    double Im;
}Complex;
#define COMP_COMPLEJOS(Z1, Z2) (((Z1).Re==(Z2).Re)&&((Z1).Im==(Z2).Im))
// Vero uso un salto de linea con esta macro pero a mi me genero problemas al compilar
// Esto nos va a dar un True si se cumple el And y un False si no es asi 

int main(){
  /* Vero uso Zr={Im:0.0, Re:1.0} pero ":" me da problemas al compilar,
     lo que supongo trato de hacer fue modificar el orden de entrada de los datos al struct */
  Complex Zr={1, 0}, Zi={0, 1}, Z1, Z2;
  printf("Lectura de un numero complejo \nDigite la parte real: ");
  scanf("%lg", &(Z1.Re));
  printf("Digite la parte imaginaria ");
  scanf("%lg", &(Z1.Im));
  // Comparador
  if(COMP_COMPLEJOS(Z1, Zr)){
    printf("Usted digito la unidad real \n");
  }
  else if(COMP_COMPLEJOS(Z1, Zi)){
    printf("Usted digito la unidad imaginaria \n");
  }
  else{
    printf("Usted digito el numero complejo: %lg%+lgi \n", Z1.Re, Z1.Im);
  }
  // Suma de complejos
  printf("Lectura de un segundo numero complejo \nDigite la parte real: ");
  scanf("%lg", &(Z2.Re));
  printf("Digite la parte imaginaria ");
  scanf("%lg", &(Z2.Im));
  printf("La suma es: \n%lg%+lgi + %lg%+lgi = %lg%+lgi \n", Z1.Re, Z1.Im, Z2.Re, Z2.Im, (Z1.Re+Z2.Re), (Z1.Im+Z2.Im));
  return 0;
  // No entiendo por que Vero se come las llaves en los If, cuando puedo hacer eso?
}