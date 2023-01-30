#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

//Estructura
typedef struct _entradaDirectorio_{
  char nombre[32];
  char apellidoPaterno[32];
  char apellidoMaterno[32];
  unsigned short lada;                                      
  unsigned int telFijo;
  unsigned int telCel;                             
  char anotacion[64];                                       
}EntradaDirectorio;                                         

//Declaracion de funciones
int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info);
int obtenEntrada(FILE *directorio, EntradaDirectorio *info);       
int mostrar(FILE *directorio);
int modificarcampo(FILE *directorio, int ncamp, int ncnt, int t);
int modificarcont(FILE *directorio, int ncnt, int t);
int borrar(FILE *directorio, int ncnt, int t);
int altf4(FILE *directorio);

//Funcion principal
int main(){       
	//Apertura de                         
	FILE *archivoBinario=fopen("Directorio.bin", "ab+");
	int i,Eleccion, Eleccion_2, Eleccion_3, Eleccion_4;
	int total;                 
	EntradaDirectorio Entrada;    
	
	//Errores de apertura
	if (archivoBinario == NULL)
	{
		int errAuxiliar;          
		errAuxiliar = errno;      
		fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
		errAuxiliar, strerror(errAuxiliar));                                            
		return 0;                                                                   
	}
	//Propio Menu  
	printf("\t\t\tMENU\n"
			"\t\t1)Agregar contacto\n"
			"\t\t2)Modificar contacto\n"
			"\t\t3)Borrar contacto\n"
			"\t\t4)Borrar directorio\n"
			"\t\t5)Mostrar directorio");
	printf("\nDigita el numero de la opcion que busca: ");
	scanf("%d",&Eleccion);
	if(Eleccion<1 || Eleccion>5)
	{
		printf("Opcion no valida");
		return 0;
	}

	//Opciones
	//Agregar contacto
	if(Eleccion==1)
	{
		printf("\t\t\tPor agregar un elemento al directorio: \n");
		printf("Nombre: ");
		scanf("%s", &Entrada.nombre);
		printf("Apellido paterno: "); 
		scanf("%s", &Entrada.apellidoPaterno);
		printf("Apellido materno: ");
		scanf("%s", &Entrada.apellidoMaterno);
		printf("Lada: ");
		scanf("%u", &(Entrada.lada));                    
		printf("Tel fijo: ");
		scanf("%u", &(Entrada.telFijo));             
		printf("Celular: ");
		scanf("%u", &(Entrada.telCel));
		printf("Contacto agregado");

		//Se agrega al archivo binario
		agregaEntradaAlFinal(archivoBinario, Entrada);
	}

	//Modificar un campo del contacto
	if(Eleccion==2)
	{
		printf("\t\t 1)Modificar un campo del contacto\n"
				"\t\t 2)Modificar el contacto");
		printf("\nDigita el numero de la opcion que busca:");
		scanf("%d",&Eleccion_2);
		if(Eleccion_2<1 || Eleccion_2>2)
		{
			printf("Opcion no valida");
			return 0;
		}
		if(Eleccion_2==1)
		{
			printf("\t\tModificar un campo del contacto");
	//ME PARECE QUE ESTA ES LA FUNCION PARA MOSTAR CONATCTOCHECK:
			total=mostrar(archivoBinario);
			if(total==0)
			{
				printf("\nNo hay contactos registrados");
				return 0;
			} 
			printf("\nSeleccione el numero del contacto que se modificara: ");
			scanf("%d",&Eleccion_3);
			if(Eleccion_3<1 || Eleccion_3>total)
			{
				printf("Opcion no valida");
				return 0;
			}
			printf("\t\t\tCampos del contacto\n"
					"\t\t1)Nombre\n"
					"\t\t2)Apellido paterno\n"
					"\t\t3)Apellido materno\n"
					"\t\t4)lada\n"
					"\t\t5)Telefono fijo\n"
					"\t\t6)Telefno celular");
			printf("\nDigite el numero del campo a modificar: ");
			scanf("%d",&Eleccion_4);
			//Modificar un campo de un contacto
			modificarcampo(archivoBinario, Eleccion_3, Eleccion_4, total);
			printf("Campo modificado");
		}	
	}

	//Eliminar un contacto
	if(Eleccion==3)
	{
		printf("\t\t\tBorrar Contacto");
		total=mostrar(archivoBinario);
		printf("\nEliga el numero del contacto que se elmininara: ");
		scanf("%d",&Eleccion_2);
		borrar(archivoBinario, Eleccion_2, total);
		printf("Contacto borrado exitosamente");
	}                    
	
	//Borrar la agenda
	if(Eleccion==4)
	{
		printf("\t\t\tDesea borrar todos los contactos del directorio?\n");
		printf("\t 1)Si\n"
				"\t 2)No\n"
				"Inserte la opcion desdeada: ");
		scanf("%d",&Eleccion_2);
		if(Eleccion_2==2)
		{
			printf("Directorio intacto");
			return 0;
		}
		if(Eleccion_2==1)
		{
			printf("Contactos eliminados de manera exitosa");
			//Al parecer elimina toda la agenda
			altf4(archivoBinario);
		}
		
	}

	//Mostrar directorio FAIL:
	// if(Eleccion==5)
	// {
	// 	printf("\t\t\tDirectorio");
	// 	//CHECK: NO SE QUE HACE FEOF
	// 	for (i=0; !feof(archivoBinario); i++)
	// 	{
	// 		printf("\n\n------------------------------------------------------------");
	// 		if (obtenEntrada(archivoBinario, &Entrada)<=0) break;
	// 		//FAIL:
	// 		//printf("\n\n\tNombre: %s %s %s", Entrada.nombre );
	// 		printf("\n\ttelefono fijo: %d", Entrada.telefonofijo);                                           
	// 		if (entrada.telFijo!=0) printf("(%u) %u", entrada.lada, entrada.telFijo);
	// 		else printf("sin numero telefonico");                                    
	// 		printf("\n\ttelefono celular: ");                                        
	// 		if (entrada.telCel!=0) printf("(%u) %u", entrada.lada, entrada.telCel);  
	// 		else printf("sin numero de telefonia celular");
	// 	} 
	// 	printf("\n\n\nFin\n\n");
	// }				
	fclose(archivoBinario); //Q: racionales, H: cuaterniones, G:gaussiano, Gq:gaussiano racionales, Zp: enteros modulo p, C: complejos
	return 0;
}

//Funciones auxiliares
//Agregar entrada
int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info)
{
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




int obtenEntrada(FILE *directorio, EntradaDirectorio *info)
{
  int ret;

  ret = fread(info, 1, sizeof(EntradaDirectorio), directorio);
  if (ret<sizeof(info)){
    int unError = errno;
    if (ret == 0) return -2;
    printf("\nError al leer informacion en el directorio (%d, %d, %s)\n",
           ret, unError, strerror(unError));
    return -1;
  }

  return 0;
}


int mostrar(FILE *directorio)
{
	EntradaDirectorio nuevo;
	int i,ret;
	ret = fseek(directorio, 0L, SEEK_SET);

  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
	for (i=0; !feof(directorio); i++){
    if (obtenEntrada(directorio, &nuevo)<0) break;
    printf("\n\n\t%d: %s %s %s", i+1,                   
           nuevo.nombre, nuevo.apellidoPaterno, nuevo.apellidoMaterno);
}
	return i;
	
}
int modificarcampo(FILE *directorio, int ncamp, int ncnt, int t)
{
	int i, ret, j;
	EntradaDirectorio mc[t];
	directorio = fopen("directorio.bin", "ab+");
	ret = fseek(directorio, 0L, SEEK_SET);

  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  	for (i=0; i<=t; i++)
	  {
    	if (obtenEntrada(directorio, &mc[i])<0) break;
      }
	switch(ncamp)
	{
		case 1:
			printf("\nNuevo nombre: ");
			gets(mc[ncnt-1].nombre);
			break;
		case 2:
			printf("\nNuevo apellido paterno: ");
			scanf("%s", &mc[ncnt-1].apellidoPaterno);
			break;
		case 3:
			printf("\nNuevo apellido materno: ");
			scanf("%s", &mc[ncnt-1].apellidoMaterno);
			break;
		case 4:
			printf("\nNueva lada: ");
			scanf("%u", &mc[ncnt-1].lada);
			break;
		case 5:
			printf("\nNuevo telefono fijo: ");
			scanf("%u", &mc[ncnt-1].telFijo);
			break;
		case 6:
			printf("\nNuevo telefono celular: ");
			scanf("%u", &mc[ncnt-1].telCel);
			break;
	}
fclose(directorio);

	directorio = fopen("directorio.bin", "wb+");
	ret = fseek(directorio, 0L, SEEK_SET);
  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  for(j=0;j<t;j++)
  {
  			agregaEntradaAlFinal(directorio, mc[j]);
  }
fclose(directorio);  
	return 0;
}
int modificarcont(FILE *directorio, int ncnt, int t)
{
int i, j, ret;
	EntradaDirectorio mc[t];
	directorio = fopen("directorio.bin", "ab+");
	ret = fseek(directorio, 0L, SEEK_SET);

  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  	for (i=0; i<=t; i++)
	  {
    	if (obtenEntrada(directorio, &mc[i])<0) break;
      }
			printf("\nNuevo nombre: ");
			gets(mc[ncnt-1].nombre);
			printf("\nNuevo apellido paterno: ");
			scanf("%s", &mc[ncnt-1].apellidoPaterno);
			printf("\nNuevo apellido materno: ");
			scanf("%s", &mc[ncnt-1].apellidoMaterno);
			printf("\nNueva lada: ");
			scanf("%u", &mc[ncnt-1].lada);
			printf("\nNuevo telefono fijo: ");
			scanf("%u", &mc[ncnt-1].telFijo);
			printf("\nNuevo telefono celular: ");
			scanf("%u", &mc[ncnt-1].telCel);
fclose(directorio);
directorio = fopen("directorio.bin", "wb+");
	ret = fseek(directorio, 0L, SEEK_SET);
  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  for(j=0;j<t;j++)
  {
  			agregaEntradaAlFinal(directorio, mc[j]);
  }
fclose(directorio); 
	return 0;	
}
int borrar(FILE *directorio, int ncnt, int t)
{
	int ret, i, j;
	EntradaDirectorio mc[t];
	directorio = fopen("directorio.bin", "ab+");
	ret = fseek(directorio, 0L, SEEK_SET);

  	if (ret < 0){
    	printf("Error al ir al final del archivo\n");
    	return -1;
  	}
  	for (i=0; i<=t; i++)
	  {
    	if (obtenEntrada(directorio, &mc[i])<0) break;
      }
fclose(directorio);
directorio = fopen("directorio.bin", "wb+");
	ret = fseek(directorio, 0L, SEEK_SET);
  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
	for(j=0;j<t;j++)
  	{
  		if(j!=ncnt-1)
  		{
  			agregaEntradaAlFinal(directorio, mc[j]);		
  		}
  	}
  	fclose(directorio);
}
int altf4(FILE *directorio)
{
	int ret;
	directorio = fopen("directorio.bin", "wb+");
	ret = fseek(directorio, 0L, SEEK_SET);
  if (ret < 0){
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  fclose(directorio);
}