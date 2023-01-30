//Ahora lo hice como lo escribio la profesora

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct _Contacto_{
    char Nombre[32];
    char ApellidoPaterno[32];
    char ApellidoMaterno[32];
    //4)
    unsigned short Lada;
    unsigned int TelFijo;
    unsigned int TelCel;
    char Anotacion[];
}Contacto;

//Funciones para agregar contactos al archivo
//5)
int AgregarContactoFinal(FILE *directorio, Contacto info);
int ObtenerContacto(FILE *directorio, Contacto *info)

int main(){
    //1)
    FILE *ArchivoBinario;
    int i;
    Contacto contacto;
    
    printf("Ejemplo de un archivo binario. Uso de un directorio...\n");
    //2)
    ArchivoBinario=fopen("directorio.bin", "ab+");
    if(ArchivoBinario==NULL)
    {
        int ErrorAuxiliar;
        //3)
        ErrorAuxiliar=errno;
        fprintf(stderr, "No se pudo abrir el archivo \"dirctorio.bin\" (%d:%s)",
        ErrorAuxiliar, strerror(ErrorAuxiliar));
        return 0;
    }

    //Funcion de lectura
    for (i=0; !feof(ArchivoBinario); i++)
    {
        if (ObtenerContacto(ArchivoBinario, &contacto)<0)break;
        printf("\n\n\tNombre: %s %s %s", contacto.Nombre, contacto.ApellidoPaterno, contacto.ApellidoMaterno);
        printf("\n\tTelefono fijo: ");
        if (contacto.TelFijo!=0) printf("(%u) %u", contacto.Lada, contacto.TelFijo);
        else printf("Sin telefono fijo");
        printf("Telefono celular: ");
        if (contacto.TelCel!=0) printf("(%u) %u", contacto.Lada, contacto.TelCel);
        else printf("Sin telefono celular");
    }
    if(i==0) printf("\nDirectorio vacio\n");
    else printf("\n%d Entradas en el directorio\n");

    //Funcion agregar
    //Hay que crear un contacto aqui
    printf("Por agregar un elemento al directorio: \n");
    printf("Nombre: ");
    scanf("%s", contacto.Nombre);
    printf("Apellido paterno: ");
    scanf("%s", contacto.ApellidoPaterno);
    printf("Apellido materno: ");
    scanf("%s", contacto.ApellidoMaterno);
    printf("Lada: ");
    scanf("%u", &(contacto.Lada));
    printf("Telefono fijo: ");}
    scanf("%u", &(contacto.TelFijo));
    printf("Telefono celular: ");
    scanf("%u", &(contacto.TelCel));
    AgregarContactoFinal(ArchivoBinario, contacto);
    fclose(ArchivoBinario);
    printf("\nFin");
    return 0;
}

int AgregarContactoFinal(FILE *directorio, Contacto info){
    long pos;
    int ret;

    pos=ftell(directorio);
    ret=fseek(directorio, 0L, SEEK_END);
    if (ret<0)
    {
        printf("Error al final de archivo\n");
        return -1;
    }
    ret=fwrite(&info, 1, sizeof(info), directorio);
    

}


//1) Me parece que crea un archivo binario
//2) Abre un binario para lectura y appending
    //https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm
//3) Nos marca un error sobre lo que ocurrrio
//4) Un unsigned de ahuevo debe ser positivo
//5) Por que isempre inicializa las funciones?

