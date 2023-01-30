//2) Bendecir: problemas con el simple indicativo y simple subjuntivo
//7) Corregir: problemas con el simple indicativo y simple subjuntivo

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
enBasePronombres SimpleMaldecir={"maldigo    ", "maldices   ", "maldice    ", "maldecimos ", "maldicen   ", "maldicen   ",
								"maldije    ", "maldijiste ", "maldijo    ", "maldijimos ", "maldijeron ", "maldijeron ",
								"maldecire    ", "maldeciras   ", "maldecira    ", "maldeciremos ", "maldeciran   ", "maldeciran   ",
								"maldecia   ", "maldecias  ", "maldecia   ", "maldeciamos", "maldecian  ", "maldecian  ",
								"maldeciria   ", "maldecirias  ", "maldeciria   ", "maldeciriamos", "maldecirian  ", "maldecirian  "};
//DONE:
enBasePronombres SimpleComer={"como     ", "comes    ", "come     ", "comemos   ", "comen    ", "comen    ",
								"comi      ", "comiste   ", "comio     ", "comimos   ", "comieron  ", "comieron  ",
								"comere    ", "comeras   ", "comera    ", "comeremos ", "comeran   ", "comeran   ",
								"comia     ", "comias    ", "comia     ", "comiamos  ", "comian    ", "comian    ",
								"comeria   ", "comerias  ", "comeria   ", "comeriamos", "comerian  ", "comerian  "};
enBasePronombres SimpleCometer={"cometo     ", "cometes    ", "comete     ", "cometemos   ", "cometen    ", "cometen    ",
								"cometi      ", "cometiste   ", "cometio     ", "cometimos   ", "cometieron  ", "cometieron  ",
								"cometere    ", "cometeras   ", "cometera    ", "cometeremos ", "cometeran   ", "cometeran   ",
								"cometia     ", "cometias    ", "cometia     ", "cometiamos  ", "cometian    ", "cometian    ",
								"cometeria   ", "cometerias  ", "cometeria   ", "cometeriamos", "cometerian  ", "cometerian  ",};								
enBasePronombres SimpleCoser={"coso     ", "coses    ", "cose     ", "cosemos   ", "cosen    ", "cosen    ",
								"cosi      ", "cosiste   ", "cosio     ", "cosimos   ", "cosieron  ", "cosieron  ",
								"cosere    ", "coseras   ", "cosera    ", "coseremos ", "coseran   ", "coseran   ",
								"cosia     ", "cosias    ", "cosia     ", "cosiamos  ", "cosian    ", "cosian    ",
								"coseria   ", "coserias  ", "coseria   ", "coseriamos", "coserian  ", "coserian  "};
enBasePronombres SimpleMeter={"meto     ", "metes    ", "mete     ", "metemos   ", "meten    ", "meten    ",
								"meti      ", "metiste   ", "metio     ", "metimos   ", "metieron  ", "metieron  ",
								"metere    ", "meteras   ", "metera    ", "meteremos ", "meteran   ", "meteran   ",
								"metia     ", "metias    ", "metia     ", "metiamos  ", "metian    ", "metian    ",
								"meteria   ", "meterias  ", "meteria   ", "meteriamos", "meterian  ", "meterian  "};
//DONE:
enBasePronombres SimpleNegar={"niego     ", "niegas    ", "niega     ", "negamos   ", "niegan    ", "niegan    ",
								"negue     ", "negaste   ", "nego      ", "negamos   ", "negaron   ", "negaron   ",
								"negare    ", "negaras   ", "negara    ", "negaremos ", "negaran   ", "negaran   ",
								"negaba    ", "negabas   ", "negaba    ", "negabamos ", "negaban   ", "negaban   ",
								"negaria   ", "negarias  ", "negaria   ", "negariamos", "negarian  ", "negarian  "};
enBasePronombres SimpleRegar={"riego     ", "riegas    ", "riega     ", "regamos   ", "riegan    ", "riegan    ",
								"regue     ", "regaste   ", "rego      ", "regamos   ", "regaron   ", "regaron   ",
								"regare    ", "regaras   ", "regara    ", "regaremos ", "regaran   ", "regaran   ",
								"regaba    ", "regabas   ", "regaba    ", "regabamos ", "regaban   ", "regaban   ",
								"regaria   ", "regarias  ", "regaria   ", "regariamos", "regarian  ", "regarian  "};
enBasePronombres SimpleCegar={"ciego     ", "ciegas    ", "ciega     ", "cegamos   ", "ciegan    ", "ciegan    ",
								"cegue     ", "cegaste   ", "cego      ", "cegamos   ", "cegaron   ", "cegaron   ",
								"cegare    ", "cegaras   ", "cegara    ", "cegaremos ", "cegaran   ", "cegaran   ",
								"cegaba    ", "cegabas   ", "cegaba    ", "cegabamos ", "cegaban   ", "cegaban   ",
								"cegaria   ", "cegarias  ", "cegaria   ", "cegariamos", "cegarian  ", "cegarian  "};
enBasePronombres SimpleRenegar={"reniego     ", "reniegas    ", "reniega     ", "renegamos   ", "reniegan    ", "reniegan    ",
								"renegue     ", "renegaste   ", "renego      ", "renegamos   ", "renegaron   ", "renegaron   ",
								"renegare    ", "renegaras   ", "renegara    ", "renegaremos ", "renegaran   ", "renegaran   ",
								"renegaba    ", "renegabas   ", "renegaba    ", "renegabamos ", "renegaban   ", "renegaban   ",
								"renegaria   ", "renegarias  ", "renegaria   ", "renegariamos", "renegarian  ", "renegarian  "};
//DONE:
enBasePronombres SimpleTocar={"toco     ", "tocas    ", "toca     ", "tocamos   ", "tocan    ", "tocan    ",
								"toque      ", "tocaste   ", "toco      ", "tocamos   ", "tocaron   ", "tocaron   ",
								"tocare    ", "tocaras   ", "tocara    ", "tocaremos ", "tocaran   ", "tocaran   ",
								"tocaba      ", "tocaba   ", "tocaba      ", "tocabamos   ", "tocaban   ", "tocaba   ",
								"tocaria   ", "tocarias  ", "tocaria   ", "tocariamos", "tocarian  ", "tocarian  "};
enBasePronombres SimpleOpacar={"opaco     ", "opacas    ", "opaca     ", "opacamos   ", "opacan    ", "opacan    ",
								"opaque      ", "opacaste   ", "opaco      ", "opacamos   ", "opacaron   ", "opacaron   ",
								"tocare    ", "tocaras   ", "tocara    ", "tocaremos ", "tocaran   ", "tocaran   ",
								"tocaba      ", "tocaba   ", "tocaba      ", "tocabamos   ", "tocaban   ", "tocaba   ",
								"tocaria   ", "tocarias  ", "tocaria   ", "tocariamos", "tocarian  ", "tocarian  "};
enBasePronombres SimpleEducar={"educo     ", "educas    ", "educa     ", "educamos   ", "educan    ", "educan    ",
								"eduque      ", "educaste   ", "educo      ", "educamos   ", "educaron   ", "educaron   ",
								"educare    ", "educaras   ", "educara    ", "educaremos ", "educaran   ", "educaran   ",
								"educaba      ", "educaba   ", "educaba      ", "educabamos   ", "educaban   ", "educaba   ",
								"educaria   ", "educarias  ", "educaria   ", "educariamos", "educarian  ", "educarian  "};
enBasePronombres SimpleSuperar={"supero     ", "superas    ", "supera     ", "superamos   ", "superan    ", "superan    ",
								"supere      ", "superaste   ", "supero      ", "superamos   ", "superaron   ", "superaron   ",
								"superare    ", "superaras   ", "superara    ", "superaremos ", "superaran   ", "superaran   ",
								"superaba      ", "superaba   ", "superaba      ", "superabamos   ", "superaban   ", "superaba   ",
								"superaria   ", "superarias  ", "superaria   ", "superariamos", "superarian  ", "superarian  "};
//DONE:
enBasePronombres SimpleAbrir={"abro     ", "abres    ", "abre     ", "abrimos   ", "abren    ", "abren    ",
								"abri      ", "abriste   ", "abrio     ", "abrimos   ", "abrieron  ", "abrieron  ",
								"abrire    ", "abriras   ", "abrira    ", "abriremos ", "abriran   ", "abriran   ",
								"abria     ", "abrias    ", "abria     ", "abriamos  ", "abrian    ", "abrian    ",
								"abriria   ", "abririas  ", "abriria   ", "abririamos", "abririan  ", "abririan  "};
enBasePronombres SimpleReabrir={"reabro     ", "reabres    ", "reabre     ", "reabrimos   ", "reabren    ", "reabren    ",
								"reabri      ", "reabriste   ", "reabrio     ", "reabrimos   ", "reabrieron  ", "reabrieron  ",
								"reabrire    ", "reabriras   ", "reabrira    ", "reabriremos ", "reabriran   ", "reabriran   ",
								"reabria     ", "reabrias    ", "reabria     ", "reabriamos  ", "reabrian    ", "reabrian    ",
								"reabriria   ", "reabririas  ", "reabriria   ", "reabririamos", "reabririan  ", "reabririan  "};
enBasePronombres SimpleEntreabrir={"entreabro     ", "entreabres    ", "entreabre     ", "entreabrimos   ", "entreabren    ", "entreabren    ",
								"entreabri      ", "entreabriste   ", "entreabrio     ", "entreabrimos   ", "entreabrieron  ", "entreabrieron  ",
								"entreabrire    ", "entreabriras   ", "entreabrira    ", "entreabriremos ", "abriran   ", "abriran   ",
								"abria     ", "abrias    ", "abria     ", "abriamos  ", "abrian    ", "abrian    ",
								"abrriria   ", "abririas  ", "abriria   ", "abririamos", "abririan  ", "abririan  "};
enBasePronombres SimpleEncubrir={"encubro     ", "encubres    ", "encubre     ", "encubrimos   ", "encubren    ", "encubren    ",
								"encubri      ", "encubriste   ", "encubrio     ", "encubrimos   ", "encubrieron  ", "encubrieron  ",
								"encubrire    ", "encubriras   ", "encubrira    ", "encubriremos ", "encubriran   ", "encubriran   ",
								"encubria     ", "encubrias    ", "encubria     ", "encubriamos  ", "encubrian    ", "encubrian    ",
								"encubriria   ", "encubririas  ", "encubriria   ", "encubririamos", "encubririan  ", "encubririan  "};
//DONE:
enBasePronombres SimpleCorregir={"corrigo     ", "corriges     ", "corrige      ", "corregimos   ", "corrigen     ", "corrigen     ",
								"corregia      ", "corregias   ", "corregia      ", "corregiamos   ", "corrigieron   ", "corrigieron   ",
								"corregiria    ", "corregirias   ", "corregiria    ", "corregiriamos ", "corregirian   ", "corregirian   ",
								"corregia     ", "corregias    ", "corregia     ", "corregiamos  ", "corregian    ", "corregian    ",
								"corregiria    ", "corregirias   ", "corregiria    ", "corregiriamos ", "corregirian   ", "corregirian   "};
enBasePronombres SimpleElegir={"eliijo      ", "eliiges     ", "elije      ", "elejimos   ", "eligen     ", "eligen     ",
								"elegia      ", "elegias   ", "elegia      ", "elegiamos   ", "eligieron   ", "eligieron   ",
								"elegiria    ", "elegirias   ", "elegiria    ", "elegiriamos ", "elegirian   ", "elegirian   ",
								"elegia     ", "elegias    ", "elegia     ", "elegiamos  ", "elegian    ", "elegian    ",
								"elegiria    ", "elegirias   ", "elegiria    ", "elegiriamos ", "elegirian   ", "elegirian   "};
enBasePronombres SimpleReelegir={"reelijo      ", "reeliges     ", "reelige      ", "reelegimos   ", "reeligen     ", "reeligen     ",
								"reelegia      ", "reelegias   ", "reelegia      ", "reelegiamos   ", "reeligieron   ", "reeligieron   ",
								"reelegiria    ", "reelegirias   ", "reelegiria    ", "reelegiriamos ", "reelegirian   ", "reelegirian   ",
								"reelegia     ", "reelegias    ", "reelegia     ", "reelegiamos  ", "reelegian    ", "reelegian    ",
								"reelegiria    ", "reelegirias   ", "reelegiria    ", "reelegiriamos ", "reelegirian   ", "reelegirian   "};
enBasePronombres SimpleRegir={"rijoo      ", "riges     ", "rige      ", "regimos   ", "rigen     ", "rigen     ",
								"regia      ", "regias   ", "regia      ", "regiamos   ", "regian   ", "regiann   ",
								"regiria    ", "regirias   ", "regiria    ", "regiriamos ", "regirian   ", "regirian   ",
								"regia     ", "regias    ", "regia     ", "regiamos  ", "regian    ", "regian    ",
								"regiria    ", "regirias   ", "regiria    ", "rigiriamos ", "regirian   ", "regirian   "};

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
//DONE:
enBasePronombres DesiSubSaber={"sepa     ", "sepas    ", "sepa     ", "sepamos  ", "sepan    ", "sepan    ",
								 "supiera   ", "supieras  ", "supiera   ", "supieramos", "supieran  ", "supieran  ",
								 "supiere   ", "supieres  ", "supiere   ", "supieremos", "supieren  ", "supieren  "};
//FAIL:
enBasePronombres DesiSubBendecir={"bendiga     ", "bendigas    ", "bendiga     ", "bendigamos  ", "bendigan    ", "bendigan    ",
								 "bendijera   ", "bendijeras  ", "bendijera   ", "bendijeramos", "bendijeran  ", "bendijeran  ",
								 "bendijere   ", "bendijeres  ", "bendijere   ", "bendijeremos", "bendijeren  ", "bendijeren  "};
enBasePronombres DesiSubMaldecir={"maldiga     ", "maldigas    ", "maldiga     ", "maldigamos  ", "maldigan    ", "maldigan    ",
								 "maldijera   ", "maldijeras  ", "maldijera   ", "maldijeramos", "maldijeran  ", "maldijeran  ",
								 "bendijere   ", "maldijeres  ", "maldijere   ", "maldijereemos", "maldijeren  ", "maldijeren  "};
//DONE:			 
enBasePronombres DesiSubNegar={"niegue   ", "niegues  ", "niegue   ", "neguemos ", "nieguen  ", "nieguen  ",
								 "negara   ", "negaras  ", "negara   ", "negaramos", "negaran  ", "negaran  ",
								 "negara   ", "negares  ", "negare   ", "negaremos", "negaren  ", "negaren  "};
enBasePronombres DesiSubRegar={"riegue   ", "riegues  ", "riegue   ", "reguemos ", "rieguen  ", "rieguen  ",
								 "regara   ", "regaras  ", "regara   ", "regaramos", "regaran  ", "regaran  ",
								 "regara   ", "regares  ", "regare   ", "regaremos", "regaren  ", "regaren  "};
enBasePronombres DesiSubCegar={"ciegue   ", "ciegues  ", "ciegue   ", "ceguemos ", "cieguen  ", "cieguen  ",
								 "cegara   ", "cegaras  ", "cegara   ", "cegaramos", "cegaran  ", "cegaran  ",
								 "cegara   ", "cegares  ", "cegare   ", "cegaremos", "cegaren  ", "cegaren  "};
enBasePronombres DesiSubRenegar={"reniegue   ", "reniegues  ", "reniegue   ", "reneguemos ", "renieguen  ", "renieguen  ",
								 "renegara   ", "renegaras  ", "renegara   ", "renegaramos", "renegaran  ", "renegaran  ",
								 "renegara   ", "renegares  ", "renegare   ", "renegaremos", "renegaren  ", "renegaren  "};
//FAIL:
enBasePronombres DesiSubCorregir={"corrija     ", "corrijas    ", "corrija     ", "corrijamos  ", "corrijan    ", "corrijan    ",
								"corrigiera   ", "corrigieras  ", "corrigiera   ", "corrigieramos", "corrigieran  ", "corrigieran  ",
								"corrigiere   ", "corrigieres  ", "corrigiere   ", "corrigieremos", "corrigieren  ", "corrigieren  "};
enBasePronombres DesiSubElegir={"elija     ", "elijas    ", "elija     ", "elijamos  ", "elijan    ", "elijan    ",
								"eligiera   ", "eligieras  ", "eligiera   ", "eligieramos", "eligieran  ", "eligieran  ",
								"eligiere   ", "eligieres  ", "eligiere   ", "eligieremos", "eligieren  ", "eligieren  "};
enBasePronombres DesiSubRegir={"rija     ", "rijas    ", "rija     ", "rijamos  ", "rijan    ", "rijan    ",
								"rigiera   ", "rigieras  ", "rigiera   ", "rigieramos", "rigieran  ", "rigieran  ",
								"rigiere   ", "rigieres  ", "rigiere   ", "rigieremos", "rigieren  ", "rigieren  "};
enBasePronombres DesiSubReelegir={"reelija     ", "reelijas    ", "reelija     ", "reelijamos  ", "reelijan    ", "reelijan    ",
								"reeligiera   ", "reeligieras  ", "reeligiera   ", "reeligieramos", "reeligieran  ", "reeligieran  ",
								"reeligiere   ", "reeligieres  ", "reeligiere   ", "reeligieremos", "reeligieren  ", "reeligieren  "};
//DONE:
enBasePronombres DesiSubComer={"coma     ", "comas    ", "coma     ", "comamos   ", "coman    ", "coman    ",
								"comiera   ", "comieras  ", "comiera   ", "comieramos", "comieran  ", "comieran  ",
								"comiere   ", "comieres  ", "comiere   ", "comieremos", "comieren  ", "comieren  "};
enBasePronombres DesiSubCoser={"cosa     ", "cosas    ", "cosa     ", "cosamos   ", "cosan    ", "cosan    ",
								"cosiera   ", "cosieras  ", "cosiera   ", "cosieramos", "cosieran  ", "cosieran  ",
								"cosiere   ", "cosieres  ", "cosiere   ", "cosieremos", "cosieren  ", "cosieren  "};
enBasePronombres DesiSubMeter={"meta     ", "metas    ", "meta     ", "metamos   ", "metan    ", "metan    ",
								"metiera   ", "metieras  ", "metiera   ", "metieramos", "metieran  ", "metaieran  ",
								"metaiere   ", "metieres  ", "metaiere   ", "metaieremos", "metaieren  ", "metaieren  "};
enBasePronombres DesiSubCometer={"cometa     ", "cometas    ", "cometa     ", "cometamos   ", "cometan    ", "cometan    ",
								"cometiera   ", "cometieras  ", "cometiera   ", "cometieramos", "cometieran  ", "cometieran  ",
								"cometiere   ", "cometieres  ", "cometiere   ", "cometieremos", "cometieren  ", "cometieren  "};
//DONE:
enBasePronombres DesiSubTocar={"toque    ", "toques   ", "toque    ", "toquemos  ", "toquen   ", "toquen   ",
								 "tocare   ", "tocaras  ", "tocara   ", "tocaremos", "tocaran  ", "tocaran  ",
								 "tocare   ", "tocares  ", "tocare   ", "tocaremos", "tocaran  ", "tocare  "};
enBasePronombres DesiSubOpacar={"opaque    ", "opaques   ", "opaque    ", "opaquemos  ", "opaquen   ", "opaquen   ",
								 "opacase   ", "opacases  ", "opacase   ", "opacasemos", "opacaran  ", "tocaran  ",
								 "opacare   ", "opacares  ", "opacare   ", "opacaremos", "opacaran  ", "opacare  "};
enBasePronombres DesiSubSuperar={"supere    ", "superes   ", "supere    ", "superemos  ", "superen   ", "superen   ",
								 "superase   ", "superases  ", "superase   ", "superasemos", "superasen  ", "superasen  ",
								 "superare   ", "superareres  ", "superare   ", "superaremos", "superaren  ", "superaren  "};
enBasePronombres DesiSubEducar={"eduque    ", "eduques   ", "eduque    ", "eduquemos  ", "eduquen   ", "eduquen   ",
								 "educase   ", "educases  ", "educase   ", "educasemos", "educasen  ", "educasen  ",
								 "educare   ", "educares  ", "educare   ", "educaremos", "educaren  ", "educaren  "};
//DONE:
enBasePronombres DesiSubAbrir={"abra     ", "abras    ", "abra     ", "abramos   ", "abran    ", "abran    ",
								 "abriera   ", "abrieras  ", "abriera   ", "abrieramos", "abrieran  ", "abrieran  ",
								 "abriere   ", "abrieres  ", "abriere   ", "abriremos", "abrieren  ", "abrieren  "};
enBasePronombres DesiSubReabrir={"reabra     ", "reabras    ", "reabra     ", "reabramos   ", "reabran    ", "reabran    ",
								 "reabriera   ", "reabrieras  ", "reabriera   ", "reabrieramos", "reabrieran  ", "reabrieran  ",
								 "reabriere   ", "reabrieres  ", "reabriere   ", "reabriremos", "reabrieren  ", "reabrieren  "};
enBasePronombres DesiSubEntreabrir={"entreabra     ", "entreabras    ", "entreabra     ", "entreabramos   ", "entreabran    ", "entreabran    ",
								 "entreabriera   ", "entreabrieras  ", "entreabriera   ", "entreabrieramos", "entreabrieran  ", "entreabrieran  ",
								 "entreabriere   ", "entreabrieres  ", "entreabriere   ", "entreabriremos", "entreabrieren  ", "entreabrieren  "};
enBasePronombres DesiSubEncubrir={"encubra     ", "encubras    ", "encubra     ", "encubramos   ", "encubran    ", "encubran    ",
								 "encubriera   ", "encubrieras  ", "encubriera   ", "encubrieramos", "encubrieran  ", "encubrieran  ",
								 "encubriere   ", "encubrieres  ", "encubriere   ", "encubriremos", "encubrieren  ", "encubrieren  "};

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
//CHECK:
int conjugaMaldecir(FILE *archivo, char raizVerbo[]);
int conjugaMeter(FILE *archivo, char raizVerbo[]);
int conjugaCoser(FILE *archivo, char raizVerbo[]);
int conjugaCometer(FILE *archivo, char raizVerbo[]);		
int conjugaRegar(FILE *archivo, char raizVerbo[]);
int conjugaCegar(FILE *archivo, char raizVerbo[]);
int conjugaRenegar(FILE *archivo, char raizVerbo[]);
int conjugaOpacar(FILE *archivo, char raizVerbo[]);
int conjugaEducar(FILE *archivo, char raizVerbo[]);
int conjugaSuperar(FILE *archivo, char raizVerbo[]);
int conjugaEntreabrir(FILE *archivo, char raizVerbo[]);
int conjugaReabrir(FILE *archivo, char raizVerbo[]);
int conjugaEncubrir(FILE *archivo, char raizVerbo[]);

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
int conjugaMaldecir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleMaldecir[tiempo]); 
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
    		        raizVerbo, DesiSubMaldecir[tiempo]); 
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
//DONE:
int conjugaRegar(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleRegar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sregado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubRegar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sregado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaCegar(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleCegar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %scegado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubCegar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %scegado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaRenegar(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleRenegar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %srenegado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubRenegar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %srenegado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE:
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
int conjugaCometer(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleCometer[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %scometido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubCometer[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %scometido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaCoser(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleCoser[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %scosido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubCoser[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %scosido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaMeter(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleMeter[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %smetido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubMeter[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %smetido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE:
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
int conjugaOpacar(FILE *archivo, char raizVerbo[])                                                                   
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
    		        raizVerbo, SimpleOpacar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sOpacado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubOpacar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sOpacado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaEducar(FILE *archivo, char raizVerbo[])                                                                   
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
    		        raizVerbo, SimpleEducar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %seducado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubEducar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %seducado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaSuperar(FILE *archivo, char raizVerbo[])                                                                   
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
    		        raizVerbo, SimpleSuperar[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %ssuperado", Pronombres[persona], 
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
    		        raizVerbo, DesiSubSuperar[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %ssuperado", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
//DONE:
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
int conjugaReabrir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleReabrir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sareabierto", Pronombres[persona], 
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
    		        raizVerbo, DesiSubReabrir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sreabierto", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaEntreabrir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleEntreabrir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sentreabierto", Pronombres[persona], 
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
    		        raizVerbo, DesiSubEntreabrir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sentreabierto", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaEncubrir(FILE *archivo, char raizVerbo[])                                                                           
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
    		        raizVerbo, SimpleEncubrir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sencubierto", Pronombres[persona], 
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
    		        raizVerbo, DesiSubEncubrir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sencubierto", Pronombres[persona], 
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
int conjugaRegir(FILE *archivo, char raizVerbo[])
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
    		        raizVerbo, SimpleRegir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sregido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubRegir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sregido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaReelegir(FILE *archivo, char raizVerbo[])
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
    		        raizVerbo, SimpleReelegir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %sreelegido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubReelegir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %sreelegido", Pronombres[persona], 
    		        HabiaSubComp[tiempo], raizVerbo); 
        fprintf(archivo, "\n");
   }                              
   	  fprintf(archivo, "\n");    
  
}
int conjugaElegir(FILE *archivo, char raizVerbo[])
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
    		        raizVerbo, SimpleElegir[tiempo]); 
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
	  		fprintf(archivo, "%12s %s %selegido", Pronombres[persona], 
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
    		        raizVerbo, DesiSubElegir[tiempo]); 
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
	  		fprintf(archivo, "%10s %s %selegido", Pronombres[persona], 
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
    else if(strncmp(Verbo, "maldecir", 5)==0)
    	printf("Maldecir: Decir maldiciones contra una persona o una cosa.\n");
	//DONE:
    else if(strncmp(Verbo, "negar", 5)==0)
    	printf("Negar: Decir que una cosa no es verdad, no existe o no es como se afirma.\n");
    else if(strncmp(Verbo, "regar", 5)==0)
    	printf("Regar: Esparcir agua sobre la tierra o sobre una planta para beneficiarlas.\n");
	else if(strncmp(Verbo, "cegar", 5)==0)
    	printf("Cegar: Perder el sentido de la vista.\n");
	else if(strncmp(Verbo, "renegar", 5)==0)
    	printf("Renegar: bandonar [una persona] sus ideales o su religión para seguir otros diferentes.\n");
	//DONE:
	//corregir, elegir, regir, reelegir
    else if(strncmp(Verbo, "corregir", 4)==0)
		printf("Corregir: Enmendar lo errado.\n");
    else if(strncmp(Verbo, "regir", 4)==0)
		printf("Regir: Dirigir un asunto o administrar una gobernacion.\n");
    else if(strncmp(Verbo, "reelegir", 4)==0)
		printf("Reelegir: Elegir de nuevo por votación a una persona para un cargo, un premio o una distinción.\n");
	else if(strncmp(Verbo, "elegir", 4)==0)
		printf("Elegir: Elegir por votación a una persona para un cargo, un premio o una distinción.\n");
	//DONE:
    else if(strncmp(Verbo, "comer", 6)==0)
    	printf("Comer: Tomar alimento por la boca.\n");
    else if(strncmp(Verbo, "cometer", 6)==0)
    	printf("Cometer: Realizar una acción que constituye un error, una falta o un delito.\n");
    else if(strncmp(Verbo, "coser", 6)==0)
    	printf("Coser: Unir con hilo enhebrado en una aguja pedazos o partes de una tela, de cuero o de otro material semejante.\n");
    else if(strncmp(Verbo, "meter", 6)==0)
    	printf("Meter: Hacer que algo o alguien pase a estar en el interior de una cosa o un lugar.\n");
	//DONE:
    else if(strncmp(Verbo, "abrir", 5)==0)
    	printf("Abrir: Hacer que algo deje de estar cerrado.\n");
    else if(strncmp(Verbo, "reabrir", 5)==0)
    	printf("Reabrir: Abrir o hacer que empiece de nuevo una cosa.\n");
    else if(strncmp(Verbo, "entreabrir", 5)==0)
    	printf("Entreabrir: Abrir una cosa un poco o a medias.\n");
	else if(strncmp(Verbo, "encubrir", 5)==0)
    	printf("Encubrir: Ocultar una cosa impidiendo que se manifieste.\n");
	//DONE:
    else if(strncmp(Verbo, "tocar", 5)==0)
    	printf("Tocar: Alcanzar algun objeto mediante un instrumento. \n");
    else if(strncmp(Verbo, "opacar", 5)==0)
    	printf("Opacar: Superar [algo o alguien] a un equivalente en alguna cualidad. \n");
    else if(strncmp(Verbo, "educar", 5)==0)
    	printf("Educar: Desarrollar las facultades intelectuales, morales y afectivas de una persona. \n");
    else if(strncmp(Verbo, "pescar", 5)==0)
    	printf("Pescar: Atrapar peces y otros animales que viven en el mar o en aguas dulces con redes, cañas u otros instrumentos. \n");
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
		"\tSaber\n"
		"\topacar, educar, pescar, tocar\n"
		"\tBendecir, maldecir\n"
		"\tNegar, regar, cegar, reneger\n"
		"\tcometer, comer, coser, meter\n"
		"\treabrir, entreabir, abrir, encubrir\n"
		"\tregir, corregir, reelegir, elegir\n");
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
	//DONE:
	if(strncmp(ultimos5, "saber", 5)==0)
		conjugaSaber(miArchivo, auxb2);	
	//DONE:
	else if(strncmp(ultimos5, "bendecir", 5)==0)
		conjugaBendecir(miArchivo, auxb2);
	else if(strncmp(ultimos5, "maldecir", 5)==0)
		conjugaMaldecir(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos5, "negar", 5)==0)
		conjugaNegar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "regar", 5)==0)
		conjugaRegar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "cegar", 5)==0)
		conjugaCegar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "renegar", 5)==0)
		conjugaRenegar(miArchivo, auxb2);
	//DONE:
	else if(strncmp(ultimos5, "comer", 5)==0)
		conjugaComer(miArchivo, auxb2);
	else if(strncmp(ultimos5, "meter", 5)==0)
		conjugaMeter(miArchivo, auxb2);
	else if(strncmp(ultimos5, "coser", 5)==0)
		conjugaCoser(miArchivo, auxb2);
	else if(strncmp(ultimos5, "cometer", 5)==0)
		conjugaCometer(miArchivo, auxb2);		
	//DONE:
	else if(strncmp(ultimos5, "tocar", 5)==0)
		conjugaTocar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "opacar", 5)==0)
		conjugaOpacar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "educar", 5)==0)
		conjugaEducar(miArchivo, auxb2);
	else if(strncmp(ultimos5, "superar", 5)==0)
		conjugaSuperar(miArchivo, auxb2);
	//DONE:		
	else if(strncmp(ultimos5, "abrir", 5)==0)
		conjugaAbrir(miArchivo, auxb2);
	else if(strncmp(ultimos5, "reabrir", 5)==0)
		conjugaReabrir(miArchivo, auxb2);
	else if(strncmp(ultimos5, "entreabrir", 5)==0)
		conjugaEntreabrir(miArchivo, auxb2);
	else if(strncmp(ultimos5, "encubrir", 5)==0)
		conjugaEncubrir(miArchivo, auxb2);
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