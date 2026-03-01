#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../../include/TETRIS.h"
#include <windows.h>
#include "../../include/PIECE.h"
#include "../../include/TABLE.h"
#include "../../include/orchestrator.h"
#include "../../include/INTERFAZ_API.h"
#define MAX 7
#define MIN 1

int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min; // Generar un número entre min y max
}

PIECE generate_piece(){
    switch (generate_random_number(MIN, MAX))
    {
    case 1: return piece_C; break;
    case 2: return piece_P; break;
    case 3: return piece_U; break;
    case 4: return piece_L; break;
    case 5: return piece_T; break;
    case 6: return piece_Z; break;
    case 7: return piece_S; break;
    default:
        return piece_C; // Valor por defecto
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
