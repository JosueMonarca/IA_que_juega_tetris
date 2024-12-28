#include <stdio.h>
#include <stdlib.h>

typedef char String[100];

struct S_fecha {
    int dia;
    int mes;
    int anio;
};

int conversor(int segundos,int horas, int operacion){
    int minutos;
    if(operacion==1){
        minutos=segundos/60;
        return minutos;
    }
    else{
        minutos=horas*60;
        return minutos;
    }
}