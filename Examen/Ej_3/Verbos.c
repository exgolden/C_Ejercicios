#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples}; 
enum tiemposComp {ANTEPRESENTE, ANTEPRETERITO, ANTEFUTURO, ANTECOPRETERITO, ANTEPOSTPRETERITO, TotalTiemposComp};        
enum tiemposSimSub {PRESENTESub, PRETERITOSub, FUTUROSub, TotalTiemposSimSub}; 
enum tiemposCompSub {ANTEPRESENTESub, ANTEPRETERITOSub, ANTEFUTUROSub, TotalTiemposCompSub};                                                      

#define LONGMAX 128

typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];

enBasePronombres Pronombres = {"yo", "t�", "�l", "nosotros", "ustedes", "ellos"}; 

char *ModoIndicativoSimple[]={"Presente", "Pret�rito", "Futuro",
                             "Copret�rito", "Postpret�rito"};  
enBasePronombres DesidenciaSimpleAR = {"o        ","as       ","a        ","amos     ","an       ","an       ",
									   "e        ","aste     ","o        ","amos     ","aron     ","aron     ",
									   "are      ","aras     ","ara      ","aremos   ","aran     ","aran     ",
									   "aba      ","abas     ","aba      ","abamos   ","aban     ","aban     ",
									   "aria     ","arias    ","aria     ","ariamos  ","arian    ","arian    "};
				
enBasePronombres DesidenciaSimpleER = {"o        ","es       ","e        ","emos     ","en       ","en       ",
									   "i        ","iste     ","io       ","imos     ","ieron     ","ieron     ",
									   "ere      ","er�s     ","er�      ","eremos   ","er�n     ","er�n     ",
									   "�a       ","�as      ","�a       ","�amos    ","�an      ","�an      ",
									   "er�a     ","er�as    ","er�a     ","er�amos  ","er�an    ","erian    "};

enBasePronombres DesidenciaSimpleIR = {"o        ","es       ","e        ","imos     ","en       ","en       ",
									   "i        ","iste     ","io       ","imos     ","ieron    ","ieron    ",
									   "ir�      ","ir�s     ","ir�      ","iremos   ","ir�n     ","ir�n     ",
									   "�a       ","�as      ","�a       ","�amos    ","�an      ","�an      ",
									   "ir�a     ","ir�as    ","ir�a     ","ir�amos  ","ir�an    ","ir�an    "};
									   
enBasePronombres SimpleCaber = {"quepo    ", "cabes    ", "cabe     ", "cabemos  ", "caben    ", "caben    ",
						  		"cupe     ", "cupiste  ", "cupo     ", "cupimos  ", "cupieron ", "cupieron ",
						 		"cabr�    ", "cabr�s   ", "cabr�    ", "cabremos ", "cabr�n   ", "cabr�n   ",
						 		"cab�a    ", "cab�as   ", "cab�a    ", "cab�amos ", "cab�an   ", "cab�an   ",
						 		"cabr�a   ", "cabr�as  ", "cabr�a   ", "cabr�amos", "cabe�an  ", "cabr�an  "};
						
enBasePronombres SimpleJugar = {"juego     ", "juegas    ", "juega     ", "jugamos   ", "juegan    ", "juegan    ",
								"jugu�     ", "jugaste   ", "jug�      ", "jugamos   ", "jugaron   ", "jugaron   ",
								"jugar�    ", "jugar�s   ", "jugar�    ", "jugaremos ", "jugar�n   ", "jugar�n   ",
								"jugaba    ", "jugabas   ", "jugaba    ", "jugabamos ", "jugaban   ", "jugaban   ",
								"jugar�a   ", "jugar�as  ", "jugar�a   ", "jugar�amos", "jugar�an  ", "jugar�an  "};

enBasePronombres SimpleDecir = {"digo    ", "dices   ", "dice    ", "decimos ", "dicen   ", "dicen   ",
								"dije    ", "dijiste ", "dijo    ", "dijimos ", "dijeron ", "dijeron ",
								"dir�    ", "dir�s   ", "dir�    ", "diremos ", "dir�n   ", "dir�n   ",
								"dec�a   ", "dec�as  ", "dec�a   ", "dec�amos", "dec�an  ", "dec�an  ",
								"dir�a   ", "dir�as  ", "dir�a   ", "dir�amos", "dir�an  ", "dir�an  "};

enBasePronombres SimpleOrder = {"uerdo     ", "uerdes    ", "uerde     ", "ordemos   ", "uerden    ", "uerden    ",
								"ord�      ", "ordiste   ", "ordi�     ", "ordimos   ", "ordieron  ", "ordieron  ",
								"order�    ", "order�s   ", "order�    ", "orderemos ", "order�n   ", "order�n   ",
								"ord�a     ", "ord�as    ", "ord�a     ", "ord�amos  ", "ord�an    ", "ord�an    ",
								"order�a   ", "order�as  ", "order�a   ", "order�amos", "order�an  ", "order�an  ",};

enBasePronombres SimpleMorir = {"muero     ", "mueres    ", "muere     ", "morimos   ", "mueren    ", "mueren    ",
								"mor�      ", "moriste   ", "muri�     ", "morimos   ", "murieron  ", "murieron  ",
								"morir�    ", "morir�s   ", "morir�    ", "moriremos ", "morir�n   ", "morir�n   ",
								"mor�a     ", "mor�as    ", "mor�a     ", "mor�amos  ", "mor�an    ", "mor�an    ",
								"morir�a   ", "morir�as  ", "morir�a   ", "morir�amos", "morir�an  ", "morir�an  "};

enBasePronombres SimpleReir = {"r�o      ", "r�es     ", "r�e      ", "re�mos   ", "r�en     ", "r�en     ",
								"re�      ", "re�ste   ", "rio      ", "re�mos   ", "rieron   ", "rieron   ",
								"reir�    ", "reir�s   ", "reir�    ", "reiremos ", "reir�n   ", "reir�n   ",
								"re�a     ", "re�as    ", "re�a     ", "re�amos  ", "re�an    ", "re�an    ",
								"reir�a   ", "reir�as  ", "reir�a   ", "reir�amos", "reir�an  ", "reir�an  "};

enBasePronombres SimpleRodar = {"ruedo     ", "ruedas    ", "rueda     ", "rodamos   ", "ruedan    ", "ruedan    ",
								"rod�      ", "rodaste   ", "rod�      ", "rodamos   ", "rodaron   ", "rodaron   ",
								"rodar�    ", "rodar�s   ", "rodar�    ", "rodaremos ", "rodar�n   ", "rodar�n   ",
								"rodaba    ", "rodabas   ", "rodaba    ", "rod�bamos ", "rodaban   ", "rodaban   ",
								"rodar�a   ", "rodar�as  ", "rodar�a   ", "rodar�amos", "rodar�an  ", "rodar�an  "};

char *ModoIndicativoComp[]={"Antepresente", "Antepret�rito", "Antefuturo",
                             "Antecopret�rito", "Antepostpret�rito"};  

enBasePronombres HabiaComp = {  "       he", "      has", "       ha", "    hemos", "      han", "      han",
								"     hube", "  hubiste", "     hubo", "  hubimos", " hubieron", " hubieron",
								"    habre", "   habras", "    habra", " habremos", "   habran", "   habran",
								"    habia", "   habias", "    habia", " habiamos", "   habian", "   habian",
								"   habria", "  habrias", "   habria", "habriamos", "  habrian", "  habrian"};
								
char *ModoSubSimp[]={"Presente", "Pret�rito", "Futuro"};

enBasePronombres DesiSubSimAR = {"e        ","es       ","e        ","emos     ","en       ","en       ",
								 "ara      ","aras     ","ara      ","aramos   ","aran     ","aran     ",
								 "are      ","ares     ","are      ","aremos   ","aren     ","aren     "};

enBasePronombres DesiSubSimER = {"a        ","as       ","a        ","amos     ","an       ","an       ",
								 "iera     ","ieras    ","iera     ","ieramos  ","ieran    ","ieran    ",
								 "iere     ","ieres    ","iere     ","ieremos  ","ieren    ","ieren    "};

enBasePronombres DesiSubSimIR = {"a        ","as       ","a        ","amos     ","an       ","an       ",
								 "iera     ","ieras    ","iera     ","ieramos  ","ieran    ","ieran    ",
								 "iere     ","ieres    ","iere     ","ieremos  ","ieren    ","ieren    "};

enBasePronombres DesiSubCaber = {"quepa     ", "quepas    ", "quepa     ", "quepamos  ", "quepan    ", "quepan    ",
								 "cupiera   ", "cupieras  ", "cupiera   ", "cupieramos", "cupieran  ", "cupieran  ",
								 "cupiere   ", "cupieres  ", "cupiere   ", "cupi�remos", "cupieren  ", "cupieren  "};
								 
enBasePronombres DesiSubJugar = {"juegue   ", "juegues  ", "juegue   ", "juguemos ", "jueguen  ", "jueguen  ",
								 "jugara   ", "jugaras  ", "jugara   ", "jug�ramos", "jugaran  ", "jugaran  ",
								 "jugare   ", "jugares  ", "jugare   ", "jug�remos", "jugaren  ", "jugaren  "};

enBasePronombres DesiSubRodar = {"ruede    ", "ruedes   ", "ruede    ", "rodemos  ", "rueden   ", "rueden   ",
								 "rodara   ", "rodaras  ", "rodara   ", "rod�ramos", "rodaran  ", "rodaran  ",
								 "rodare   ", "rodares  ", "rodare   ", "rod�remos", "rodaren  ", "rodaren  "};

enBasePronombres DesiSubDecir = {"diga     ", "digas    ", "diga     ", "digamos  ", "digan    ", "digan    ",
								 "dijera   ", "dijeras  ", "dijera   ", "dijeramos", "dijeran  ", "dijeran  ",
								 "dijere   ", "dijeres  ", "dijere   ", "dij�remos", "dijeren  ", "dijeren  "};

enBasePronombres DesiSubOrder = {"uerda     ", "uerdas    ", "uerda     ", "ordamos   ", "uerdan    ", "muerdan    ",
								 "ordiera   ", "ordieras  ", "ordiera   ", "ordi�ramos", "ordieran  ", "ordieran  ",
								 "ordiere   ", "ordieres  ", "ordiere   ", "ordi�remos", "ordieren  ", "ordieren  "};

enBasePronombres DesiSubReir = {"r�a     ", "r�as    ", "r�a     ", "riamos  ", "r�an    ", "r�an    ",
								"riera   ", "rieras  ", "riera   ", "ri�ramos", "rieran  ", "rieran  ",
								"riere   ", "rieres  ", "riere   ", "ri�remos", "rieren  ", "rieren  "};

enBasePronombres DesiSubMorir = {"muera     ", "mueras    ", "muera     ", "moramos   ", "mueran    ", "mueran    ",
								 "muriera   ", "murieras  ", "muriera   ", "muri�ramos", "murieran  ", "murieran  ",
								 "muriere   ", "murieres  ", "muriere   ", "muri�remos", "murieren  ", "murieren  "};
								 
								 
char *ModoSubComp[]={"Antepresente", "Antepr�terito", "Antefuturo"};

enBasePronombres HabiaSubComp = {"      haya", "     hayas", "      haya", "   hayamos", "     hayan", "     hayan",
								 "   hubiera", "  hubieras", "   hubiera", "hubieramos", "  hubieran", "  hubieran",
								 "   hubiere", "  hubieres", "   hubiere", "hubieremos", "  hubieren", "  hubieren"};

int conjugacionAR(FILE *archivo, char raizVerbo[]);   
int conjugacionER(FILE *archivo, char raizVerbo[]); 
int conjugacionIR(FILE *archivo, char raizVerbo[]);
int conjugaCaber(FILE *archivo, char raizVerbo[]);
int conjugaDecir(FILE *archivo, char raizVerbo[]);
int conjugaJugar(FILE *archivo, char raizVerbo[]);
int conjugaOrder(FILE *archivo, char raizVerbo[]);
int conjugaRodar(FILE *archivo, char raizVerbo[]);
int conjugaMorir(FILE *archivo, char raizVerbo[]);
int conjugaReir(FILE *archivo, char raizVerbo[]);
int Definicion(FILE *archivo, char Verbo[]);                                                                        

int main(int argc, char *argv[])
{                               
  FILE *miArchivo;              
  char buffer[128], auxb1[128], auxb2[128], auxb3[128]; 
  char a[]="a", e[]="e", i[]="i", virr1[]="caber", virr7[]="reir", virr6[]="morir", virr5[]="rodar", virr4[]="order", virr3[]="jugar", virr2[]="decir";           
  int lbuffer, lauxb1, lauxb2, lauxb3, compara1, compara2, compara3, compara4, compara5, compara6, compara7;                  

  miArchivo = fopen("misVerbos.txt", "a");

  if (miArchivo == NULL){
    fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
    return 0;                                                          
  }
  printf("Escriba el verbo a conjugar.\nPuede ingresar cualquier verbo regular, pero de irregulares solo puede ingresar las siguientes familias:\nCaber\nRodar Enrodar\nDecir Entredecir Redecir\nJugar\nMorder\nMorir Entremorir\nReir Fre�r\n"); 

  scanf("%s", buffer);
  lbuffer = strlen(buffer);
  strcpy(auxb1, buffer);
  lauxb1 = strlen(auxb1);
  strcpy(auxb2, buffer);
  lauxb2 = strlen(auxb2);
  strcpy(auxb3, buffer);
  lauxb3 = strlen(auxb3);  
  
  const char *ultimos5 = &buffer[lbuffer-5];
  const char *ultimos4 = &buffer[lbuffer-4];
  char fin = buffer[lbuffer-2];
  auxb1[lauxb1-2] = '\0';
  auxb2[lauxb2-5] = '\0';
  auxb3[lauxb3-4] = '\0';

  printf("Por conjugar verbo\n");
    
    Definicion(miArchivo, buffer);
    if(strncmp(ultimos5, "caber", 5)==0)
		conjugaCaber(miArchivo, auxb2);	
    else if(strncmp(ultimos5, "decir", 5)==0)
    	conjugaDecir(miArchivo, auxb2);
    else if(strncmp(ultimos5, "jugar", 5)==0)
    	conjugaJugar(miArchivo, auxb2);
    else if(strncmp(ultimos5, "order", 5)==0)
    	conjugaOrder(miArchivo, auxb2);
    else if(strncmp(ultimos5, "rodar", 5)==0)
    	conjugaRodar(miArchivo, auxb2);
    else if(strncmp(ultimos5, "morir", 5)==0)
    	conjugaMorir(miArchivo, auxb2);
    else if(strncmp(ultimos4, "reir", 4)==0)
			conjugaReir(miArchivo, auxb3);
	else if(fin=='a')
		conjugacionAR(miArchivo, auxb1);
	else if(fin=='e')
		conjugacionER(miArchivo, auxb1);
	else if(fin=='i')
		conjugacionIR(miArchivo, auxb1);
	else
		printf("La palabra ingresada no es un verbo. Reingrese una palabra adecuada.");


  printf("Verbo Conjugado\n");                    

  fclose(miArchivo);

  printf("FIN\n");

  return 0;
}          

int conjugacionAR(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleAR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sado", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubSimAR[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}            

int conjugacionER(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+2, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleER[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sido", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubSimER[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}            

int conjugacionIR(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesidenciaSimpleIR[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sido", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubSimIR[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}            

int conjugaCaber(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleCaber[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %scabido", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%2", Pronombres[persona], 
    		        raizVerbo, DesiSubCaber[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %scabido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaJugar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleJugar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sjugado", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubJugar[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sjugado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaRodar(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleRodar[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %srodado", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubRodar[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %srodado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaDecir(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleDecir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sdicho", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubDecir[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sdicho", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaOrder(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleOrder[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %smordido", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubOrder[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %smordido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaReir(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleReir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %sre�do", Pronombres[persona], 
    		        HabiaComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubReir[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %sre�do", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int conjugaMorir(FILE *archivo, char raizVerbo[])                                                                           
{                                                                               
  int  lpronombre=8, ldesidencia=4,tiempo, lverbo, persona, centrado, titulo;           
  char formato[1024];                                                           
  
  lverbo = strlen(raizVerbo)+3;

 fprintf(archivo, "           Modo Indicativo\n\n");
//Indicativo Simple
  for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoSimple[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoIndicativoSimple[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n ");
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, SimpleMorir[tiempo]); 
        fprintf(archivo, "\n");
   }                                                           

  fprintf(archivo, "\n");
//Indicativo Comp
    for(tiempo=0;tiempo<=4;tiempo++)
   {
  		titulo = strlen(ModoIndicativoComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoIndicativoComp[tiempo]," ");
	    
   }
	  fprintf(archivo,"\n\n");
	  
  for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<5*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%12s %s %smuerto", Pronombres[persona], 
    		        HabiaComp[tiempo]), raizVerbo; 
        fprintf(archivo, "\n");
   }                                   
   	  fprintf(archivo,"\n\n");    

  fprintf(archivo, "           Modo Subjuntivo\n\n");
//Subjuntivo Simple
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubSimp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado, centrado+2);
	    fprintf(archivo, formato, " ", ModoSubSimp[tiempo]," ");
   }
	  fprintf(archivo,"\n\n ");
	  
   for (persona=0; persona<TotalPronombres; persona++)
   {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%8s %s%s", Pronombres[persona], 
    		        raizVerbo, DesiSubMorir[tiempo]); 
        fprintf(archivo, "\n");
   }                      

  fprintf(archivo, "\n");
  
//Subjuntivo Complejo
    for(tiempo=0;tiempo<=2;tiempo++)
   {
  		titulo = strlen(ModoSubComp[tiempo])/2;
	    centrado = (lverbo+lpronombre+ldesidencia+1)/2;
	    if (centrado<=titulo) centrado=0;
  			else centrado -= titulo;         
		sprintf(formato, "%%%ds%%s%%%ds", centrado+6, centrado+4);
	    fprintf(archivo, formato, " ", ModoSubComp[tiempo]," ");
   }
   	  fprintf(archivo,"\n\n ");
	  
  for (persona=0; persona<TotalPronombres; persona++)
  {
		for(tiempo=persona;tiempo<3*TotalPronombres;tiempo+=6) 
	  		fprintf(archivo, "%10s %s %smuerto", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

int Definicion(FILE *archivo, char Verbo[])
{
    if(strncmp(Verbo, "caber", 5)==0)
    	printf("Caber: Poder contenerse dentro de algo.\n");
    else if(strncmp(Verbo, "rodar", 5)==0)
    	printf("Rodar: Moverse por medio de ruedas. \n");
    else if(strncmp(Verbo, "enrodar", 7)==0)
    	printf("Enrodar: Imponer el suplicio que consist�a en despedazar al reo sujet�ndole a una rueda en movimiento.\n");
    else if(strncmp(Verbo, "morder", 6)==0)
    	printf("Morder: Clavar los dientes en algo.\n");
    else if(strncmp(Verbo, "jugar", 5)==0)
    	printf("Jugar: Hacer algo con alegr�a con el fin de entretenerse, divertirse o desarrollar determinadas capacidades.\n");
    else if(strncmp(Verbo, "decir", 5)==0)
    	printf("Decir: Manifestar con palabras el pensamiento.\n");
    else if(strncmp(Verbo, "entredecir", 10)==0)
    	printf("Entredecir: Prohibir la comunicaci�n y trato con alguien o algo.\n");
    else if(strncmp(Verbo, "redecir", 7)==0)
    	printf("Redecir: Volver a decir.\n");
    else if(strncmp(Verbo, "reir", 4)==0)
    	printf("Reir: Celebrar con risa algo.\n");
    else if(strncmp(Verbo, "freir", 5)==0)
    	printf("Freir: Hacer que un alimento crudo llegue a estar en disposici�n de poderse comer, teni�ndolo el tiempo necesario en aceite o grasa hirviendo.\n");
    else if(strncmp(Verbo, "morir", 5)==0)
    	printf("Morir: Llegar al t�rmino de la vida.\n");
    else if(strncmp(Verbo, "entremorir", 10)==0)
    	printf("Entremorir: Estarse apagando o extinguiendo.\n");
	else return 0;   
}
