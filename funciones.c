#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char String[100];

struct S_fecha {
    int dia;
    int mes;
    int anio;
};

int conv_seg_horas(int segundos,int horas, int operacion){
    
    switch (operacion)
    {
    case 1:
        segundos=horas*60;
        return segundos;//retorna las horas en segundos
        break;
    case 2:
        horas=segundos/60;
        return horas;//reetorna los segundos en horas
        break;
    default:
    printf("Operacion no valida");//mensaje de errr
        break;
    }
    
}

int conv_seg_min(int segundos,int minutos, int operacion){
    
    switch (operacion)
    {
    case 1:
        segundos=minutos*60;
        return segundos;//retorna los minutos en segundos
        break;
    case 2:
        minutos=segundos/60;
        return minutos;//retorna los segundos en minutos
        break;
    default:
    printf("Operacion no valida");//mensaje de error
        break;
    }
    
}

int conv_min_horas(int minutos,int horas, int operacion){
    
    switch (operacion)
    {
    case 1:
        minutos=horas*60;
        return minutos;//retorna las horas en minutos
        break;
    case 2:
        horas=minutos/60;
        return horas;//retorna los minutos en horas
        break;
    default:
    printf("Operacion no valida");//mensaje de error
        break;
    }
    
}

void frame( void (*draw)()){

        system("cls");
        draw();

}//funciona para actualizar la pantalla


