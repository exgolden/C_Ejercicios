#include <stdio.h>

int main(){
    int Mes, DiaMes, DiaSemana;
    printf("Meses del año: \n"
            "Enero:1\n"
            "Febrero:2\n"
            "Marzo:3\n"
            "Abril:4\n"
            "Mayo:5\n"
            "Junio:6\n"
            "Julio:7\n"
            "Agosto:9\n"
            "Septiembre:10\n"
            "Octubre:10\n"
            "Noviembre:11\n"
            "Diciembre:12\n");
    printf("Ingrese un mes: ");
    scanf("%d", &Mes);
        //Para corregir el input del usuario por si acaso, el usuario nunca tiene la culpa, baboso
    if (Mes=0 || Mes>12)
    {
        Mes=1;
    }
    //Separamos los meses del año dependiendo de cuantos dias tienen
    switch (Mes)
    {
    case 2: DiaMes=28; break;
    //Podemos agrupar distintos casos
    case 4: case 6: case 9: case 11: DiaMes=30; break;
    //Si no se cumple ninguno de los casos anteriores se usa por defecto este
    default: DiaMes=31; break;
    }
    printf("Dias de la semana:\n"
            "Lunes:0\n"
            "Martes:1\n"
            "Miercoles:2\n"
            "Jueves:3\n"
            "Viernes:4\n"
            "Sabado:5\n"
            "Domingo:6\n");
    scanf("%d", &DiaSemana);
    //Para corregir el input del usuario por si acaso, el usuario nunca tiene la culpa, baboso
    if (DiaSemana<0 || DiaSemana>6)
    {
        DiaSemana=0;
    }
    //El 19s nos imprime 19 caracteres, si se tienen menos letras entonces imrpime espacios
    printf("%19s\n", "Mes Selecto");
    printf("Dom Lun Mar Mie Jue Vie Sab\n");
    for (int i=0; i<DiaSemana; i++)
    {
        printf("    ");
    }
    for (DiaMes=1; DiaMes<=DiaMes; DiaMes++)
    {
        printf(" %2d ", DiaMes);
    }
    if ((DiaMes+1)%7==0)
    {
        printf("\n");
    }
    printf("\n");
    return 0;        
}
//El codigo de la profesora no frunciona y el mio tampoco, supongo que quiso imprimir un calendario pero imprime infinitamente, luego lo checo jejeje