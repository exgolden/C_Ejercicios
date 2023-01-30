#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras
enum Pronombres{Yo, Tu, El, Nosotros, Ustedes, Ellos, TotalPronombres};
enum TiemposSimples{Presente, Preterito, Futuro, Copreterito, Pospreterito, TotalTiemposSimples};
#define LONGMAX 128
//No entiendo que esta haciendo aqui
typedef char enBasePronombres[TotalPronombres][LONGMAX];
char *ModoIndicativoSimple[]={"Presente", "Preterito", "Fututo", "Coprterito", "Postpreterito"};
enBasePronombres DesidenciaPresenteSimpleAR={"o", "as", "a", "amos", "an", "an"};
enBasePronombres Pronombres={"yo", "tu", "el", "nosotros", "ustedes", "ellos"};

//Funciones auxiliares
int ConjugacionRegular(FILE *archivo, enum TiemposSimples tiempo, char raizVerboAR[]);
int ConjugacionRegular(FILE *archivo, enum TiemposSimples tiempo, char raizVerboAR[]){
    int lpronombre=8;
    int ldesidencia=4;
    int lverbo, persona, centrado, titulo;
    char formato[1024];
    if (tiempo<0 || TotalTiemposSimples<=tiempo)
    {
        fprintf(stderr, "Tiempo para conjugacion invalido\n");
        fprintf(archivo, "Tiempo para conjugacion invalido\n");
        return -1;
    }
    







}