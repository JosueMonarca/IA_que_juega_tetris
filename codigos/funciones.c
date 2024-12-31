#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CABECERA.h"

typedef char String[100];

struct S_fecha {
    int dia;
    int mes;
    int anio;
};

int tabla[42][42];



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

int colicion() {
        // Dummy implementation, replace with actual logic
        return 0;
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

void draw() {
    // Establecer las coordenadas del cuadrado
    coordenadas_de_cuadrado(2,2);

    // Recorrer el tablero
    for (int x = 0; x < 42; x++) {
        for (int y = 0; y < 42; y++) {
            // Bordes del tablero
            if (x == 0 || x == 41 || y == 0 || y == 41) {
                tabla[x][y] = 1;
            } else {
                // Revisar si el punto (i, j) coincide con alguna coordenada del cuadrado
                tabla[x][y] = 0; // Inicialmente vacío
                for (int k = 0; k < 4; k++) {
                    if (x == cuadrado[k][0] && y == cuadrado[k][1]) {
                        tabla[x][y] = 1; // Parte del cuadrado
                    }
                }
            }
            // Imprimir el contenido del tablero
            printf("%d", tabla[x][y]);
        }
        printf("\n");
    }
}
            
        