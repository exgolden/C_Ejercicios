//Librerias
#include <stdio.h>
#include <string.h>

//Estructuras y variables
typedef struct Contacto{
    char Nombre[50];
    double Numero;
}Contacto;

static const struct Contacto EmptyStruct;
//Count nos lleva la cuenta de contactos llenos
int Count=3;
int Aux;

//Inicializamos la agenda con tres ejemplos y un maximo de 10 contactos
Contacto Agenda[10]={{"Crisel Escalante", 555555555},
                    {"Elisa Piña", 6666666666},
                    {"Kevin Calderon", 7777777777}                    
};

//1) Funcion Agenda
void Agenda_Lista(){
    printf("___Agenda___\n");
    for(int i=0; i<Count; i++){
        printf("%d) Nombre: %s\n"
            "Telefono: %.0lf\n\n", i, Agenda[i].Nombre, Agenda[i].Numero);
    }
    //Back_A();
}

//2) Funcion añadir contacto
void Add(){
    Aux=Count-1;
    printf("___Crear contacto___\n");
    printf("Nombre: ");
    scanf("%[^\n]s", &Agenda[Aux].Nombre);
    printf("\nNumero: ");
    scanf("%lf", &Agenda[Aux].Numero);
    Aux++;
    //Agenda_Lista();
}

//3) Funcion editar contacto
void Edit(){
    printf("___Editar contacto___\n");
    Agenda_Lista();
    printf("Ingrese el indice del contacto a editar: ");
    scanf("%d", &Aux);
    //Edicion
    printf("Nombre: ");
    scanf(" %[^\n]s", &Agenda[Aux].Nombre);
    printf("Numero: ");
    scanf("%lf", &Agenda[Aux].Numero);
    //Agenda_Lista();
}

//4) Funcion eliminar contacto
void Del_C(){
    printf("___Eliminar contacto___\n");
    Agenda_Lista();
    printf("Ingrese el contacto a eliminar: ");
    scanf("%d", &Aux);
    Agenda[Aux].Nombre="00000000";
    Agenda[Aux].Numero=0;
    Count-=1;
    printf("Contacto eliminado");
    //Back_A();
}

//5) Funcion eliminar agenda
void Del(){
    printf("___Eliminar agenda___");
    Agenda_Lista();
    printf("Esta seguro que desea eliminar la agenda(1/0)?: ");
    scanf("%d", &Aux);
    if (Aux==1)
    {
        for (int i=0; i<Count; i++)
        {
            Agenda[i].Nombre="00000000";
            Agenda[i].Numero=0;
            Count-=1;
        }
        printf("Agenda eliminada");
        //Menu_A();
    }
    //Agenda_Lista();
}

//Funcion Menu
void Menu_A(){
    printf("___Agenda Telefonica___ \n");
    printf("___Opciones___\n"
        "1) Agenda\n"
        "2) Crear Contacto\n"
        "3) Editar Contacto\n"
        "4) Eliminar Contacto\n"
        "5) Eliminar Agenda\n");
    printf("Que desea hacer: ");
    scanf("%d", &Aux);
    switch(Aux){
    case 1:
        Agenda_Lista();
        break;
    case 2:
        Add();
        break;
    case 3:
        Edit();
        break;
    case 4:
        Del_C();
        break;
    case 5:
        Del();
        break;
    }
}

/*Funcion back
void Back_A(){
    printf("Teclee \'0\' para salir: ");
    scanf("%d", &Aux);
    if (Aux==0)
    {
        Menu_A();
    }
}
*/
int main(){
    Menu_A();
    return 0;
}
//por el momento cada que se llama a una funcion se termina el programa pero debemos de hacer que vuelva al main
//hay que acer un caso especial para cuando Aux=0 o Aux=10 
//En la funcion de agenda debemos de hacer que el usuario decida salir de la duncion porque en realidad no hay algo que impida que salga d einmediaro
//Crear unba funcion de back
//Al momento de meter el indice apra hacer el delete debemos de checar que este sea mayoir a cero y menor al tamaño real del array
//No puedo vaciar las variables de las estructuras por lo que las cambio por una cadena de 0
//Tengo este error al tratar de cambiar .Nombre "array type 'char [50]' is not assignable"