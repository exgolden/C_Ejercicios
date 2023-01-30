#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <unistd.h>

typedef struct Cumpleanios{
	int Dia;
	int Mes;
	int Anio;
}Cumpleanios;

typedef struct entradaDirectorio{
  char Nombre[32];
  char ApellidoPaterno[32];
  char ApellidoMaterno[32];
  unsigned short Lada;                                      
  unsigned int Telefono;
  unsigned int Celular;                                                 
  int* pPuntero;  
  Cumpleanios Cumpleanios;
  char Sexo;                 
}EntradaDirectorio;

//Funciones auxiliares
void Error_Num(int Eleccion, int baja, int alta){
    if(Eleccion<baja || Eleccion>alta) printf("Opcion no valida");
}

int Agregar(FILE *directorio, EntradaDirectorio info){
  long pos;
  int ret;

  pos = ftell(directorio);
  ret = fseek(directorio, 0L, SEEK_END);

  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }

  ret=fwrite(&info, 1, sizeof(info), directorio);

  if (ret<sizeof(info)){
    printf("Error al escribir la informacion en el directorio\n");
    return -2;
  }

  ret = fseek(directorio, pos, SEEK_SET);

  return 0;
}





//Funcion principal
int main(){
    FILE *Binario=fopen("Directorio.bin", "ab+");
    EntradaDirectorio Entrada;
    int Ciclo, Eleccion_1, i;
    char data[200];
    if(Binario==NULL) printf("Error al crear/abrir archivo");
    do
    {
        printf("\t\t\tMENU\n"
        "\t\t1)Agregar contacto\n"
        "\t\t2)Modificar contacto\n"
        "\t\t3)Borrar contacto\n"
        "\t\t4)Borrar directorio\n"
        "\t\t5)Mostrar directorio\n"
        "Digita el numero de la opcion que busca: ");
        scanf("%d", &Eleccion_1);
        Error_Num(Eleccion_1, 1, 5);
        switch (Eleccion_1)
        {
        case 1:
            //system(cls);
            printf("\t\tPor agregar un elemento al directorio:\n");
            fflush(stdin);
            printf("Nombre: ");
            scanf("%[^\n]%*c", Entrada.Nombre);
            printf("Apellido paterno: ");
            scanf("%s", Entrada.ApellidoPaterno);
            printf("Apellido materno: ");
            scanf("%s", Entrada.ApellidoMaterno);
            printf("Lada: ");
            scanf("%hu", &Entrada.Lada);
            printf("Numero de celular: ");
            scanf("%d", &Entrada.Celular);
            printf("Telefono fijo: ");
            scanf("%d", &Entrada.Telefono);
            printf("Sexo: ");
            fflush(stdin);
            scanf("%[^\n]%*c", &Entrada.Sexo);
            printf("Fecha de nacimiento(d m a): ");
            scanf("%d %d %d", &Entrada.Cumpleanios.Dia,
                &Entrada.Cumpleanios.Mes, &Entrada.Cumpleanios.Anio);
            Agregar(Binario, Entrada);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            //system(cls);
            printf("\t\tDesea borrar todos los contactos de la agenda?\n"
                    "1) Si\n"
                    "2) No\n"
                    "Inserte la opcion deseada: ");
            scanf("%d", &Eleccion_1);
            Error_Num(Eleccion_1, 1, 2);
            if(Eleccion_1==1)
            {
                if(ftruncate(fileno(Binario), 0)==-1) printf("Agenda borrada con exito");
            }
            if(Eleccion_1==2) printf("Agenda intacta");
            break;
        case 5:
            printf("\t\t\tDirectorio\n");
            fseek(Binario, 0, SEEK_SET);
            for (i=0; !feof(Binario); i++)
            {
                printf("___________________________________________________________\n");
                if(fread(&Entrada, 1, sizeof(EntradaDirectorio), Binario)<0) break;
                fread(data, 1, sizeof(EntradaDirectorio), Binario);
                printf("\tNombre: %s %s %s\n", Entrada.Nombre, Entrada.ApellidoPaterno,
                    Entrada.ApellidoMaterno);
                printf("\tCelular: %d\n", Entrada.Celular);
                printf("\tTelefono fijo: (%u) %d\n",Entrada.Lada, Entrada.Celular);
                printf("\tSexo: %c\n",Entrada.Sexo);
                printf("\tFecha de nacimiento: %d/%d/%d\n",Entrada.Cumpleanios.Dia,
                        Entrada.Cumpleanios.Mes, Entrada.Cumpleanios.Anio);
            }
            break; 
        }
    printf("\nPresiona 1 para continuar o 0 para terminar: ");
    scanf("%d", &Ciclo);
    } while (Ciclo==1);
    fclose(Binario);
    return 0;
}

/*

            printf("%s\n", Entrada.ApellidoPaterno);
            printf("%s\n", Entrada.ApellidoMaterno);
            printf("%u\n", Entrada.Lada);
            printf("%d\n", Entrada.Celular);
            printf("%d\n", Entrada.Telefono);
            printf("%c\n", Entrada.Sexo);
            printf("%d %d %d \n", Entrada.Cumpleanios.Dia,
            Entrada.Cumpleanios.Mes, Entrada.Cumpleanios.Anio);


*/
