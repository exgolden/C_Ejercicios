#include <stdio.h>
#include <stdlib.h>

//Estructuras y variables
#define MAX 50
typedef struct Contacto{
    char Nombre[MAX];
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
    printf("\n___Agenda___\n");
    for(int i=0; i<Count; i++){
        printf("%d) Nombre: %s\n"
            "Telefono: %.0lf\n\n", i+1, Agenda[i].Nombre, Agenda[i].Numero);
    }
    //Back_A();
}

//2) Funcion añadir contacto

//3) Funcion editar contacto
void Edit(){
    printf("___Editar contacto___\n");
    Agenda_Lista();
    printf("Ingrese el indice del contacto a editar: ");
    scanf("%d", &Aux);
    if (Aux>Count)
    {
        printf("Contacto vacio");
    }else{

        printf("Nombre: ");
        scanf(" %[^\n]s", Agenda[Aux-1].Nombre);
        printf("Numero: ");
        scanf("%lf", &Agenda[Aux-1].Numero);
        Agenda_Lista();
    }
    Agenda_Lista();
}

//4) Funcion eliminar contacto
void Del_C(){
    int j;
    printf("___Eliminar contacto___\n");
    Agenda_Lista();
    printf("Ingrese el contacto a eliminar: ");
    scanf("%d", &Aux);
    if (Aux>=Count+1)
    {
        printf("Contacto vacio");
    }else{
        for (j=Aux-1; j<Count-1; j++)
        {
            Agenda[j]=Agenda[j+1];
        }
        printf("Contacto eliminado");
        Count-=1;
    }
    Agenda_Lista();
}

//5) Funcion eliminar agenda
void Del(){
    int i, j;
    printf("___Eliminar agenda___");
    Agenda_Lista();
    printf("Esta seguro que desea eliminar la agenda(1/0)?: ");
    scanf("%d", &Aux);
    if (Aux==1)
    {
        for(i=1; i<=Count; i++)
        {
            for (j=Aux-1; j<Count-1; j++)
            {
                Agenda[j]=Agenda[j+1];
            }
            Count-=1;
        }
        //Count defnitivo
        Count-=1;
        printf("Agenda eliminada\n");
    }
    Agenda_Lista();
}

//Funcion Menu
void Menu_A(){
    printf("___Agenda Telefonica___ \n");
    printf("___Opciones___\n"
        "1) Agenda\n"
        "2) Crear Contacto\n"
        "3) Editar Contacto\n"
        "4) Eliminar Contacto\n"
        "5) Eliminar Agenda\n\n");
    printf("Que desea hacer: ");
    scanf("%d", &Aux);
    switch(Aux){
    case 1:
        Agenda_Lista();
        break;
    case 2:
        //Add();
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

int main(){
    Menu_A();
    return 0;
}
//Tanto la funcion editar como eliminar tiene problemitas con el indice de la agenda, recorri el numeor de la agenda para empezar desde 1
    //recorri el indice de la agenda en editar porque toma un elemento despues

//Como quitar los warnings https://stackoverflow.com/questions/45756630/warning-format-specifies-type-char-but-the-argument-has-type-char50
    //Al parecer cuando estoy tratando de guardar algo en una cadena de caracteres no tengo que usar '&' en el scanf

//Count definitivo: Como usamos emmoria estatica para crear la agenda, no podemos "borrar" los elementos del array, al final siempre existira uno
    //es por eso que al final de la "eliminacion" reducimos el Count=1 a count=0

//Codigo para elimiar elementos de un array https://www.programmingsimplified.com/c/source-code/c-program-delete-element-from-array