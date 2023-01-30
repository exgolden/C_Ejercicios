//1) Saber:falta el modo subjuntivo,
//2) Bendecir: problemas con el simple indicativo y subjuntivo
//7) Corregir: No funciona bien el modulo de subjuntivo

#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>

//Estructuras
enum pronombres {YO, TU, EL, NOSOTROS, USTEDES, ELLOS, TotalPronombres};
enum tiemposSimples {PRESENTE, PRETERITO, FUTURO, COPRETERITO, POSTPRETERITO, TotalTiemposSimples}; 
enum tiemposComp {ANTEPRESENTE, ANTEPRETERITO, ANTEFUTURO, ANTECOPRETERITO, ANTEPOSTPRETERITO, TotalTiemposComp};        
enum tiemposSimSub {PRESENTESub, PRETERITOSub, FUTUROSub, TotalTiemposSimSub}; 
enum tiemposCompSub {ANTEPRESENTESub, ANTEPRETERITOSub, ANTEFUTUROSub, TotalTiemposCompSub};                                                      
#define LONGMAX 128
typedef char enBasePronombres[TotalPronombres*TotalTiemposSimples][LONGMAX];
enBasePronombres Pronombres = {"Yo", "Tu", "El", "Nosotros", "Ustedes", "Ellos"}; 
char *ModoIndicativoSimple[]={"Presente", "Preterito", "Futuro", "Copreterito", "Postpreterito"};  

//Modulos de terminaciones para verboes regulares
enBasePronombres DesidenciaSimpleAR = {"o        ","as       ","a        ","amos     ","an       ","an       ",
									   "e        ","aste     ","o        ","amos     ","aron     ","aron     ",
									   "are      ","aras     ","ara      ","aremos   ","aran     ","aran     ",
									   "aba      ","abas     ","aba      ","abamos   ","aban     ","aban     ",
									   "aria     ","arias    ","aria     ","ariamos  ","arian    ","arian    "};				
enBasePronombres DesidenciaSimpleER = {"o        ","es       ","e        ","emos     ","en       ","en       ",
									   "i        ","iste     ","io       ","imos     ","ieron     ","ieron     ",
									   "ere      ","eras     ","era      ","eremos   ","eran     ","eran     ",
									   "ia       ","ias      ","ia       ","iamos    ","ian      ","an      ",
									   "eria     ","erias    ","eria     ","eriamos  ","erian    ","erian    "};
enBasePronombres DesidenciaSimpleIR = {"o        ","es       ","e        ","imos     ","en       ","en       ",
									   "i        ","iste     ","io       ","imos     ","ieron    ","ieron    ",
									   "ire      ","iras     ","ira      ","iremos   ","iran     ","iran     ",
									   "ia       ","ias      ","ia       ","iamos    ","ian      ","ian      ",
									   "iria     ","irias    ","iria     ","iriamos  ","irian    ","irian    "};
									   
//Verbos irregulares simples
//DONE:
enBasePronombres SimpleSaber={"se    ", "sabes    ", "sabe     ", "sabemos  ", "saben    ", "saben    ",
						  		"supe     ", "supiste  ", "supo     ", "supimos  ", "supieron ", "supieron ",
						 		"sabre    ", "sabras   ", "sabra    ", "sabremos ", "sabran   ", "sabran   ",
						 		"sabia    ", "sabias   ", "sabia    ", "sabiamos ", "sabian   ", "sab�ian   ",
						 		"sabria   ", "sabrias  ", "sabria   ", "sabriamos", "sabrian  ", "sabrian  "};
//DONE:
enBasePronombres SimpleBendecir={"bendigo    ", "bendices   ", "bendice    ", "bendecimos ", "bendicen   ", "bendicen   ",
								"bendije    ", "bendijiste ", "bendijo    ", "bendijimos ", "bendijeron ", "bendijeron ",
								"bendecire    ", "bendeciras   ", "bendecira    ", "bendeciremos ", "bendeciran   ", "bendeciran   ",
								"bendecia   ", "bendecias  ", "bendecia   ", "bendeciamos", "bendecian  ", "bendecian  ",
								"bendiciria   ", "bendicirias  ", "bendiciria   ", "bendiciriamos", "bendicirian  ", "bendcirian  "};
//DONE:
enBasePronombres SimpleComer={"como     ", "comes    ", "come     ", "comemos   ", "comen    ", "comen    ",
								"comi      ", "comiste   ", "comio     ", "comimos   ", "comieron  ", "comieron  ",
								"comere    ", "comeras   ", "comera    ", "comeremos ", "comeran   ", "comeran   ",
								"comia     ", "comias    ", "comia     ", "comiamos  ", "comian    ", "comian    ",
								"comeria   ", "comerias  ", "comeria   ", "comeriamos", "comerian  ", "comerian  ",};
//DONE:
enBasePronombres SimpleNegar={"niego     ", "niegas    ", "niega     ", "negamos   ", "niegan    ", "niegan    ",
								"negue     ", "negaste   ", "nego      ", "negamos   ", "negaron   ", "negaron   ",
								"negare    ", "negaras   ", "negara    ", "negaremos ", "negaran   ", "negaran   ",
								"negaba    ", "negabas   ", "negaba    ", "negabamos ", "negaban   ", "negaban   ",
								"negaria   ", "negarias  ", "negaria   ", "negariamos", "negarian  ", "negarian  "};
//DONE:
enBasePronombres SimpleTocar={"toco     ", "tocas    ", "toca     ", "tocamos   ", "tocan    ", "tocan    ",
								"toque      ", "tocaste   ", "toco      ", "tocamos   ", "tocaron   ", "tocaron   ",
								"tocare    ", "tocaras   ", "tocara    ", "tocaremos ", "tocaran   ", "tocaran   ",
								"tocaba      ", "tocaba   ", "tocaba      ", "tocabamos   ", "tocaban   ", "tocaba   ",
								"tocaria   ", "tocarias  ", "tocaria   ", "tocariamos", "tocarian  ", "tocarian  "};
//DONE:
enBasePronombres SimpleAbrir={"abro     ", "abres    ", "abrre     ", "abrimos   ", "abren    ", "abren    ",
								"abri      ", "abriste   ", "abrio     ", "abrimos   ", "abrieron  ", "abrieron  ",
								"abrire    ", "abriras   ", "abrira    ", "abriremos ", "abriran   ", "abriran   ",
								"abria     ", "abrias    ", "abria     ", "abriamos  ", "abrian    ", "abrian    ",
								"abrriria   ", "abririas  ", "abriria   ", "abririamos", "abririan  ", "abririan  "};
//DONE:
enBasePronombres SimpleCorregir={"corrigo      ", "corriges     ", "corrige      ", "corregimos   ", "corrigen     ", "corrigen     ",
								"corregia      ", "corregias   ", "corregia      ", "corregiamos   ", "corrigieron   ", "corrigieron   ",
								"corregiria    ", "corregirias   ", "corregiria    ", "corrigiriamos ", "corregirian   ", "corregirian   ",
								"corregia     ", "corregias    ", "corregia     ", "corregiamos  ", "corregian    ", "corregian    ",
								"corregiria    ", "corregirias   ", "corregiria    ", "corrigiriamos ", "corregirian   ", "corregirian   "};

//Modos
char *ModoIndicativoComp[]={"Antepresente", "Antepreterito", "Antefuturo", "Antecopreterito", "Antepostpreterito"};  
char *ModoSubSimp[]={"Presente", "Preterito", "Futuro"};
char *ModoSubComp[]={"Antepresente", "Antepreterito", "Antefuturo"};

enBasePronombres HabiaComp = {  "       he", "      has", "       ha", "    hemos", "      han", "      han",
								"     hube", "  hubiste", "     hubo", "  hubimos", " hubieron", " hubieron",
								"    habre", "   habras", "    habra", " habremos", "   habran", "   habran",
								"    habia", "   habias", "    habia", " habiamos", "   habian", "   habian",
								"   habria", "  habrias", "   habria", "habriamos", "  habrian", "  habrian"};
								
//Modulos subjuntivo regulares
enBasePronombres DesiSubSimAR = {"e        ","es       ","e        ","emos     ","en       ","en       ",
								 "ara      ","aras     ","ara      ","aramos   ","aran     ","aran     ",
								 "are      ","ares     ","are      ","aremos   ","aren     ","aren     "};
enBasePronombres DesiSubSimER={"a        ","as       ","a        ","amos     ","an       ","an       ",
								 "iera     ","ieras    ","iera     ","ieramos  ","ieran    ","ieran    ",
								 "iere     ","ieres    ","iere     ","ieremos  ","ieren    ","ieren    "};
enBasePronombres DesiSubSimIR = {"a        ","as       ","a        ","amos     ","an       ","an       ",
								 "iera     ","ieras    ","iera     ","ieramos  ","ieran    ","ieran    ",
								 "iere     ","ieres    ","iere     ","ieremos  ","ieren    ","ieren    "};

//Modulos subjuntivo irregulares
//FAIL:
enBasePronombres DesiSubSaber={"sepa     ", "sepas    ", "sepa     ", "sepamos  ", "sepan    ", "sepan    ",
								 "supiera   ", "supieras  ", "supiera   ", "supieramos", "supieran  ", "supieran  ",
								 "supiere   ", "supieres  ", "supiere   ", "supieremos", "supieren  ", "supieren  "};
//DONE:
enBasePronombres DesiSubTocar={"toque    ", "toques   ", "toque    ", "toquemos  ", "toquen   ", "toquen   ",
								 "tocare   ", "tocaras  ", "tocara   ", "tocaremos", "tocaran  ", "tocaran  ",
								 "tocare   ", "tocares  ", "tocare   ", "tocaremos", "tocaran  ", "tocare  "};
//DONE:			 
enBasePronombres DesiSubNegar={"niegue   ", "niegues  ", "niegue   ", "neguemos ", "nieguen  ", "nieguen  ",
								 "negara   ", "negaras  ", "negara   ", "negaramos", "negaran  ", "negaran  ",
								 "negara   ", "negares  ", "negare   ", "negaremos", "negaren  ", "negaren  "};
//DONE:
enBasePronombres DesiSubComer={"coma     ", "comas    ", "coma     ", "comamos   ", "coman    ", "coman    ",
								"comiera   ", "comieras  ", "comiera   ", "comieramos", "comieran  ", "comieran  ",
								"comiere   ", "comieres  ", "comiere   ", "comieremos", "comieren  ", "comieren  "};
//DONE:
enBasePronombres DesiSubAbrir={"abra     ", "abras    ", "abra     ", "abramos   ", "abran    ", "abran    ",
								 "abriera   ", "abrieras  ", "abriera   ", "abrieramos", "abrieran  ", "abrieran  ",
								 "abriere   ", "abrieres  ", "abriere   ", "abriremos", "abrieren  ", "abrieren  "};






//CHECK:
enBasePronombres DesiSubBendecir={"bendiga     ", "bendigas    ", "bendiga     ", "bendigamos  ", "bendigan    ", "bendigan    ",
								 "bendijera   ", "bendijeras  ", "bendijera   ", "bendijeramos", "bendijeran  ", "bendijeran  ",
								 "bendijere   ", "bendijeres  ", "bendijere   ", "bendij�remos", "bendijeren  ", "bendijeren  "};


//FAIL:
enBasePronombres DesiSubCorregir={"corrija     ", "corrijas    ", "corrija     ", "corrijamos  ", "corrijan    ", "corrijan    ",
								"corrigiera   ", "corrigieras  ", "corrigiera   ", "corrigieramos", "corrigieran  ", "corrigieran  ",
								"corrigiere   ", "corrigieres  ", "corrigiere   ", "corrigieremos", "corrigieren  ", "corrigieren  "};


// //FAIL:
// enBasePronombres DesiSubBendecir = {"diga     ", "digas    ", "diga     ", "digamos  ", "digan    ", "digan    ",
// 								 "dijera   ", "dijeras  ", "dijera   ", "dijeramos", "dijeran  ", "dijeran  ",
// 								 "dijere   ", "dijeres  ", "dijere   ", "dij�remos", "dijeren  ", "dijeren  "};













								 
								 


enBasePronombres HabiaSubComp = {"      haya", "     hayas", "      haya", "   hayamos", "     hayan", "     hayan",
								 "   hubiera", "  hubieras", "   hubiera", "hubieramos", "  hubieran", "  hubieran",
								 "   hubiere", "  hubieres", "   hubiere", "hubieremos", "  hubieren", "  hubieren"};

//Declaracion de funciones auxiliares
int conjugacionAR(FILE *archivo, char raizVerbo[]);   
int conjugacionER(FILE *archivo, char raizVerbo[]); 
int conjugacionIR(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaSaber(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaBendecir(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaNegar(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaComer(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaTocar(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaAbrir(FILE *archivo, char raizVerbo[]);
//DONE:
int conjugaCorregir(FILE *archivo, char raizVerbo[]);
//DONE:
int Definicion(FILE *archivo, char Verbo[]);                                                                        

//Modulso de conjugacion de verbos regulares
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

//Modulos de conjugaciones de irregulares
//DONE:
int conjugaSaber(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleSaber[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %ssabido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubSaber[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %ssabido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE:
int conjugaBendecir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleBendecir[tiempo]); 
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
    		        raizVerbo, DesiSubBendecir[tiempo]); 
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
//DONE: DONE:
int conjugaNegar(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleNegar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %snegado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubNegar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %snegado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE: DONE:
int conjugaComer(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleComer[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %scomido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubComer[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %scomido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE: DONE:
int conjugaTocar(FILE *archivo, char raizVerbo[])                                                                   
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
    		        raizVerbo, SimpleTocar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %stocado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubTocar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %stocado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE: DONE:
int conjugaAbrir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleAbrir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sabierto", Pronombres[persona], 
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
    		        raizVerbo, DesiSubAbrir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sabierto", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE:
int conjugaCorregir(FILE *archivo, char raizVerbo[])
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
    		        raizVerbo, SimpleCorregir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sreido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubCorregir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sreido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}

//Modulo de definiciones DONE:
int Definicion(FILE *archivo, char Verbo[])
{
	//DONE:
    if(strncmp(Verbo, "saber", 5)==0)
    	printf("Saber: Tener noticia o conocimiento de algo.\n");
	//DONE:
    else if(strncmp(Verbo, "bendecir", 5)==0)
    	printf("Bendecir: Consagrar una persona, lugar o un objeto a Dios.\n");
	//DONE:
    else if(strncmp(Verbo, "negar", 5)==0)
    	printf("Negar: Decir que una cosa no es verdad, no existe o no es como se afirma.\n");
	//DONE:
    else if(strncmp(Verbo, "corregir", 4)==0)
		printf("Corregir: Enmendar lo errado.\n");
	//DONE:
    else if(strncmp(Verbo, "comer", 6)==0)
    	printf("Comer: Tomar alimento por la boca.\n");
	//DONE:
    else if(strncmp(Verbo, "abrir", 5)==0)
    	printf("Abrir: Hacer que algo deje de estar cerrado.\n");
	//DONE:
    else if(strncmp(Verbo, "tocar", 5)==0)
    	printf("Tocar: Alcanzar algun objeto mediante un instrumento. \n");
	else return 0;   
}

//Funcion principal
int main(){
	//Declaracion de variables e inicializacion del archivo                        
	FILE *miArchivo=fopen("Verbos.txt", "a"); 
	char buffer[128], auxb1[128], auxb2[128], auxb3[128]; 
	char a[]="a", e[]="e", i[]="i", virr1[]="saber", virr2[]="bendecir", virr3[]="negar", virr4[]="comer", virr5[]="tocar", virr6[]="abrir", virr7[]="corregir";   
	int lbuffer, lauxb1, lauxb2, lauxb3, compara1, compara2, compara3, compara4, compara5, compara6, compara7;                  
	if (miArchivo == NULL){
	fprintf(stderr, "No se pudo abrir el archivo \"misVerbos.txt\"\n");
	return 0;                                                          
	}
	//Propio conjugador
	printf("//// CONJUGADOR DE VERBOS ////\n");
	printf("Puede ingresar cualquier verbo regular, pero de irregulares solo puede ingresar alguno de los sigientes:\n"
		"\tSaber\n\tTocar\n\tBendecir\n\tNegar\n\tComer\n\tAbrir\n\tCorregir\n");
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

	//Eleccion de verbos irregulares
	printf("Por conjugar verbo\n");
	Definicion(miArchivo, buffer);
	//DONE:
	if(strncmp(ultimos5, "saber", 5)==0)
		conjugaSaber(miArchivo, auxb2);	
	//DONE:
	else if(strncmp(ultimos5, "bendecir", 5)==0)
		conjugaBendecir(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos5, "negar", 5)==0)
		conjugaNegar(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos5, "comer", 5)==0)
		conjugaComer(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos5, "tocar", 5)==0)
		conjugaTocar(miArchivo, auxb2);
	//DONE:		
	else if(strncmp(ultimos5, "abrir", 5)==0)
		conjugaAbrir(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos4, "corregir", 4)==0)
		conjugaCorregir(miArchivo, auxb3);
	//Conjugacion de verbos regulares terminados en vocal CHECK:
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