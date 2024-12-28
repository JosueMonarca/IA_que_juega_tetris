#include <stdio.h>
#include <stdlib.h>

typedef char String[100];

struct S_fecha {
    int dia;
    int mes;
    int anio;
};

typedef struct S_fecha Fecha;

int division_entera(int num_1, int num_2){
    int residuo, resultado;
    residuo=num_1%num_2;
    resultado=(num_1-residuo)/num_2;
    return resultado;
}

int main() {
    int i,j,z;
    int dia,mes,ano_1,ano_2;
    Fecha fecha;

    printf("Introduzca un número: ");
    scanf("%d", &i);

    for (j = 1; j < i+1; j++) {
        for (z = 0; z < j; z++) {
            printf("*");
        }
        printf("\n");
    }

    
    printf("Introduzca el dia de su cumpleaños:");
    scanf("%d",&fecha.dia);

    printf("Introduzca el mes de su cumpleaños(ejemplo /01/):");
    scanf("%d",&fecha.mes);

    printf("Introduzca el ano de su cumpleaños:");
    scanf("%d",&fecha.anio);

    if(fecha.mes<=2){
        fecha.anio=fecha.anio-1;
        fecha.mes=fecha.mes+12;
    }
    else{
        fecha.mes=fecha.mes-2;
    }
    ano_1=fecha.anio%100;
    ano_2=division_entera(fecha.anio,100);
    dia=(700+(fecha.mes*26-2)/10+fecha.dia+ano_1+division_entera(ano_1,4)+division_entera(ano_2,4)-2*ano_2)%7;

    switch(dia){
        case 0:
            printf("Domingo");
            break;
        case 1:
            printf("Lunes");
            break;
        case 2:
            printf("Martes");
            break;
        case 3:
            printf("Miercoles");
            break;
        case 4:
            printf("Jueves");
            break;
        case 5:
            printf("Viernes");
            break;
        case 6:
            printf("Sabado");
            break;
        default:
            printf("Error");
            break;
    }
    return 0;
}