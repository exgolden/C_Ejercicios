#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> 

typedef struct _entradaDirectorio_{
  char nombre[32], apellidoPaterno[32], apellidoMaterno[32];
  unsigned short lada;                                      
  unsigned int telFijo, telCel;                             
  char anotacion[64];                                       
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
  int i,n,m,z,total,l, v1,v2;
                          
  EntradaDirectorio entrada;    


  archivoBinario = fopen("directorio.bin", "ab+");
        
if (archivoBinario == NULL){
    int errAuxiliar;          
    errAuxiliar = errno;      
    fprintf(stderr, "No se pudo abrir el archivo \"directorio.bin\" (%d:%s)\n", 
errAuxiliar, strerror(errAuxiliar));                                            
    return 0;                                                                   
  }      
	printf("\t\t\tMENU\n\t\t1)Agregar contacto\n\t\t2)Modificar contacto\n\t\t3)Borrar contacto\n\t\t4)Borrar directorio\n\t\t5)Mostrar directorio");
	printf("\nDigita el numero de la opcion que busca:");
	scanf("%d",&n);
	if(n<1 || n>5)
	{
		////system("cls");
		printf("Opcion no valida");
		return 0;
	}
	if(n==1)
	{
		////system("cls");
		printf("\t\t\tPor agregar un elemento al directorio:\n");
  printf("nombre: "); gets(entrada.nombre);   
  printf("apellido paterno: "); scanf("%s", entrada.apellidoPaterno);
  printf("apellido materno: "); scanf("%s", entrada.apellidoMaterno);
  printf("lada: "); scanf("%u", &(entrada.lada));                    
  printf("tel fijo: "); scanf("%u", &(entrada.telFijo));             
  printf("cel: "); scanf("%u", &(entrada.telCel));
  printf("Contacto agregado");
  agregaEntradaAlFinal(archivoBinario, entrada);
	}
    if(n==2)
	{
		////system("cls");
		printf("\t\t1)Modificar un campo del contacto\n\t\t2)Modificar el contacto");
		printf("\nDigita el numero de la opcion que busca:");
		scanf("%d",&m);
		if(m<1 || m>2)
		{
			////system("cls");
			printf("Opcion no valida");
			return 0;
		}
		if(m==1)
		{
			////system("cls");
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
				////system("cls");
				printf("Opcion no valida");
				return 0;
			}
			////system("cls");
			printf("\t\t\tCampos del contacto\n\t\t1)Nombre\n\t\t2)Apellido paterno\n\t\t3)Apellido materno\n\t\t4)lada\n\t\t5)Telefono fijo\n\t\t6)Telefno celular");
			printf("\nDigite el numero de la opcion que busca:");
			scanf("%d",&z);
			modificarcampo(archivoBinario, z, l, total);
			printf("Campo modificado");
		}
		
	}
	if(n==3)
	{
		////system("cls");
		printf("\t\t\tBorrar Contacto");
		total=mostrar(archivoBinario);
		printf("\nEliga el numero del contacto que se elmininara: ");
		scanf("%d",&v1);
		borrar(archivoBinario, v1, total);
		printf("Contacto borrado exitosamente");
	}                    
	if(n==4)
	{
		////system("cls");
		printf("\t\t\tDesea borrar todos los contactos del directorio?");
		printf("\n1)Si\t\t\t\t2)No\nInserte la opci�n desdeada:");
		scanf("%d",&v2);
		if(v2==2)
		{
			printf("Los contactos permaneces intactos en el directorio");
			return 0;
		}
		if(v2==1)
		{
			printf("Contactos eliminados de manera exitosa");
			altf4(archivoBinario);
		}
		
	}
	if(n==5)
	{
		
		////system("cls");
		printf("\t\t\tDirectorio");
		for (i=0; !feof(archivoBinario); i++)
		{
			printf("\n\n------------------------------------------------------------");
    		if (obtenEntrada(archivoBinario, &entrada)<0) break;
    		printf("\n\n\tnombre: %s %s %s",                    
           entrada.nombre, entrada.apellidoPaterno, entrada.apellidoMaterno);
    		printf("\n\ttelefono fijo: ");                                           
    		if (entrada.telFijo!=0) printf("(%u) %u", entrada.lada, entrada.telFijo);
    		else printf("sin numero telefonico");                                    
    		printf("\n\ttelefono celular: ");                                        
    		if (entrada.telCel!=0) printf("(%u) %u", entrada.lada, entrada.telCel);  
    		else printf("sin numero de telefonia celular");
		} 
		printf("\n\n\nFin\n\n");
	}
	                   
  fclose(archivoBinario); //Q: racionales, H: cuaterniones, G:gaussiano, Gq:gaussiano racionales, Zp: enteros modulo p, C: complejos

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


















