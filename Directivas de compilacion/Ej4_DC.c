#include <stdio.h>
#include <stdlib.h>

/*Cuando el programa identifica un operador bitwise convierte los operandos
a binario y despues realiza la operacion bit pot bit, nos entrega un  valor
en binario y al imprimirlo lo hace en decimal*/
#define BitOp(a, op, b) printf(#a #op #b "=%d \n", a op b)
#define UnarOp(a, op) printf(#op #a "=%d \n", op a )

/*No entiendo para que me servirian estos operadores en ejemplos cotidianos,
solo se me ocurren aplicacions enfocadas a computacion muy basica*/
int main ()
{
  /*Realiza un AND bit x bit, entrega:
     bitA==BITb: 1
     bitA!=BITb: 0 */
  BitOp (23, &, 34);
    /*Realiza un OR bit x bit, entrega:
     IF(bitA OR BITb): 1
     ELSE: 0 */
  BitOp (23, |, 34);
  /*Realiza un XOR bit x bit, entrega:
     bitA!=BITb: 1
     bitA==BITb: 0 */
  BitOp (23, ^, 3);
    /*Realiza A*(2B) */
  BitOp (23, <<, 3);
      /*Realiza A/(2B) */
  BitOp (23, >>, 3);
      /*Realiza un intercambio bit x bit, entrega:
     bitA==0: 1
     bitA==1: 0 */
  UnarOp(23, ~);
  return 0;
}
