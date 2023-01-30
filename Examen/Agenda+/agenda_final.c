#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

typedef struct cumpleanios{
	int dia;
	int mes;
	int anio;
}cumpleanios;

typedef struct _entradaDirectorio_{
  char nombre[32], apellidoPaterno[32], apellidoMaterno[32];
  unsigned short lada;                                      
  unsigned int telFijo, telCel;                             
  char anotacion[64];                    
  int* pPuntero;  
  cumpleanios cumpleanios;
  char sexo;                 
}EntradaDirectorio;                                         

int agregaEntradaAlFinal(FILE *directorio, EntradaDirectorio info);
int obtenEntrada(FILE *directorio, EntradaDirectorio *info);       
int mostrar(FILE *directorio);
int modificarcampo(FILE *directorio, int ncamp, int ncnt, int t);
int modificarcont(FILE *directorio, int ncnt, int t);
int borrar(FILE *directorio, int ncnt, int t);
int altf4(FILE *directorio
);

int main(int argc, char *argv[])
{                               
  FILE *archivoBinario;         
  int i,n,m,z,total,l, v1,v2, cicle, mod, eleccion;
                          
  EntradaDirectorio entrada;    


  archivoBinario = fopen("directorio.bin", "ab+");
        
if (archivoBinario == NULL)
{
    int errAuxiliar;          
    errAuxiliar = errno;      
    fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
	errAuxiliar, strerror(errAuxiliar));                                            
    return 0;                                                                   
}
  do
  {   
	system("cls");   
	printf("\t\t\tMENU\n"
			"\t\t1)Agregar contacto\n"
			"\t\t2)Modificar contacto\n"
			"\t\t3)Borrar contacto\n"
			"\t\t4)Borrar directorio\n"
			"\t\t5)Mostrar directorio\n");
	printf("Digita el numero de la opcion que busca:");
	scanf("%d",&n);
	if(n<1 || n>5)
	{
		system("cls");
		printf("Opcion no valida");
		return 0;
	}
	switch(n)
	{
		case 1:
			system("cls");
			printf("\t\t\tPor agregar un elemento al directorio:\n");
			fflush(stdin);
		 	printf("Nombre: ");
		 	scanf("%[^\n]%*c", entrada.nombre);
			//scanf("%[^\n]%*c", entrada.nombre);
			fflush(stdin);
			printf("Apellido paterno: ");
			scanf("%s", entrada.apellidoPaterno);
			printf("Apellido materno: ");
			scanf("%s", entrada.apellidoMaterno);
			printf("Lada: ");
			scanf("%u", &(entrada.lada));                    
			printf("Telefono fijo: ");
			scanf("%u", &(entrada.telFijo));             
			printf("Celular: ");
			scanf("%u", &(entrada.telCel));
			fflush(stdin);
			printf("Sexo: ");
			scanf("%[^\n]%*c", &entrada.sexo);
			fflush(stdin);
			printf("Agrege su fecha de nacimiento:\n");
			printf("Dia: ");
			scanf("%d", &entrada.cumpleanios.dia);
			printf("Mes: ");
			scanf("%d", &entrada.cumpleanios.mes);
			printf("Anio: ");
			scanf("%d", &entrada.cumpleanios.anio);
			printf("Contacto agregado");	
			agregaEntradaAlFinal(archivoBinario, entrada);
			break;
		
		case 2:
			system("cls");
			printf("\t\t1)Modificar un campo del contacto\n"
					"\t\t2)Modificar un contacto\n"
					"\t\tSeleccione una opcion: ");
			scanf("%d", &mod);
			if(mod==1)
			{
    			printf("\t\tModificar un campo del contacto");
    			total=mostrar(archivoBinario);
    			if(total==0)
    			{
    				printf("\nNo hay contactos aun");
    				return 0;
    			} 
    			printf("\nSeleccione el numero del contacto que se modificara: ");
    			scanf("%d",&l);
    			if(l<1 || l>total)
    			{
    				system("cls");
    				printf("Opcion no valida");
    				return 0;
    			}
    			system("cls");
    			printf("\t\t\tCampos del contacto\n"
    					"\t\t1)Nombre\n"
    					"\t\t2)Apellido paterno\n"
    					"\t\t3)Apellido materno\n"
    					"\t\t4)lada\n"
    					"\t\t5)Telefono fijo\n"
    					"\t\t6)Telefeno celular\n"
    					"\t\t7)Cumpleanios\n"
    					"\t\t8)Sexo"
    					"\nDigite el numero de la opcion que busca:");
    			scanf("%d",&z);
    			modificarcampo(archivoBinario, z, l, total);
   			}
   			if(mod==2)
   			{
   			    total=mostrar(archivoBinario);
    			if(total==0)
    			{
    				printf("\nNo hay contactos aun");
    				return 0;
    			} 
   				printf("\nSeleccione el numero del contacto que se modificara: ");
   				scanf("%d", &eleccion);
   				modificarcont(archivoBinario, eleccion, total);
			}
			break;
		
		case 3:
			system("cls");
			printf("\t\t\tBorrar Contacto");
			total=mostrar(archivoBinario);
			printf("\nEliga el numero del contacto que se elmininara: ");
			scanf("%d",&v1);
			borrar(archivoBinario, v1, total);
			printf("Contacto borrado exitosamente");
			break;
			
		case 4:
			system("cls");
			printf("\t\t\tDesea borrar todos los contactos del directorio?"
					"\n1)Si"
					"\n2)No"
					"\nInserte la opcion desdeada: ");
			scanf("%d",&v2);
			if(v2==2)
			{
				printf("Directorio intacto");
				return 0;
			}
			if(v2==1)
			{
				printf("Contactos eliminados de manera exitosa");
				altf4(archivoBinario);
			}
			break;
			
		case 5:
			system("cls");
			printf("\t\t\tDirectorio\n");
			fseek(archivoBinario, 0, SEEK_SET);
			for (i=0; !feof(archivoBinario); i++)
			{
				printf("\n\n______________________________________________________________");
	    		if (obtenEntrada(archivoBinario, &entrada)<0) break;
	    		printf("\n\n\tNombre: %s %s %s",                    
	          	entrada.nombre, entrada.apellidoPaterno, entrada.apellidoMaterno);
	    		printf("\n\tTelefono fijo: ");                                           
	    		if (entrada.telFijo!=0) printf("(%u) %u", entrada.lada, entrada.telFijo);
	    		else printf("sin numero telefonico");                                    
	    		printf("\n\tTelefono celular: ");                                        
	    		if (entrada.telCel!=0) printf("(%u) %u", entrada.lada, entrada.telCel);  
	    		else printf("\nsin numero de telefonia celular");
	    		printf("\n\tSexo: %c", entrada.sexo);
	    		printf("\n\tCumpleanios: %d/%d/%d", entrada.cumpleanios.dia, entrada.cumpleanios.mes, entrada.cumpleanios.anio);
	    		printf("\n\tLa direccion de memoria de una variable es: %p", &entrada.pPuntero);
			}
			break;
    }	
    printf("\nPresiona 1 para continuar o 0 para terminar: ");
    scanf("%d", &cicle);
    }while(cicle==1);
  fclose(archivoBinario);
  return 0;
}

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
			fflush(stdin);
			printf("\nNuevo nombre: ");
			scanf("%[^\n]%*c", mc[ncnt-1].nombre);
			fflush(stdin);
			break;
		case 2:
			printf("\nNuevo apellido paterno: ");
			scanf("%s", mc[ncnt-1].apellidoPaterno);
			break;
		case 3:
			printf("\nNuevo apellido materno: ");
			scanf("%s", mc[ncnt-1].apellidoMaterno);
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
		case 7:
			printf("\nNueva fecha de cumpleanios(d m a): ");
			scanf("%d %d %d", &mc[ncnt-1].cumpleanios.dia,
				&mc[ncnt-1].cumpleanios.mes,
				&mc[ncnt-1].cumpleanios.anio);
		case 8:
			printf("\nsexo: ");
			scanf("%[^\n]%*c", &mc[ncnt-1].sexo);
			break;
	}
	printf("Campo modificado");
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

  if (ret < 0)
  {
    printf("Error al ir al final del archivo\n");
    return -1;
  }
  	for (i=0; i<=t; i++)
	  {
    	if (obtenEntrada(directorio, &mc[i])<0) break;
      }
		fflush(stdin);
		printf("\nNuevo nombre: ");
		scanf("%[^\n]%*c", mc[ncnt-1].nombre);
		fflush(stdin);
		printf("\nNuevo apellido paterno: ");
		scanf("%s", mc[ncnt-1].apellidoPaterno);
		printf("\nNuevo apellido materno: ");
		scanf("%s", mc[ncnt-1].apellidoMaterno);
		printf("\nNueva lada: ");
		scanf("%u", &mc[ncnt-1].lada);
		printf("\nNuevo telefono fijo: ");
		scanf("%d", &mc[ncnt-1].telFijo);
		printf("\nNuevo telefono celular: ");
		scanf("%d", &mc[ncnt-1].telCel);
		fflush(stdin);
		printf("\nNuevo sexo: ");
		scanf("%c", &mc[ncnt-1].sexo);
		fflush(stdin);
		printf("\nNuevo cumpleanios(d m a): ");
		scanf("%d %d %d", &mc[ncnt-1].cumpleanios.dia, &mc[ncnt-1].cumpleanios.mes, &mc[ncnt-1].cumpleanios.anio);
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
  	if (ret < 0)
	{
    printf("Error al ir al final del archivo\n");
    return -1;
	}
  	fclose(directorio);
  	return 0;
}