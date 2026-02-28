#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../../include/TETRIS.h"
#include <windows.h>
#include "../../include/PIECE.h"
#include "../../include/TABLE.h"
#include "../../include/orchestrator.h"
#define MAX 7
#define MIN 1

int generate_random_number() {
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    return (rand() % (MAX - MIN + 1)) + MIN; // Generar un número entre MIN y MAX
}

PIECE generate_piece(){
    switch (generate_random_number())
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

void init_table(TABLE* t){
    for(int i = 0; i < HIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(i == 0 || i == HIGHT - 1 || j == 0 || j == WIDTH - 1){
                t->table[i][j] = 1; // Bordes del tablero
            } else {
                t->table[i][j] = 0; // Espacios vacíos
            }
        }
    }
}

// Función para mover el cursor a una posición específica
void mover_cursor(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion;
    posicion.X = y;
    posicion.Y = x;
    SetConsoleCursorPosition(hConsole, posicion);
}

// Función para ocultar el cursor
void ocultar_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Ocultar el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
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

void gravity(TABLE* t, PIECE* p){
    //se mueve el c hacia abajo
    if (move_piece_in_table(p, DOWN, t) == FALSE){
        lock_piece(t, p);
        delete_rows(t);
        *p = generate_piece();
        set_piece_position(p,generate_random_number(), 0);
    }
}


void draw(TABLE* t, PIECE* p) {
    // Se llama a la funcion gravity para determinar la posicion de las figuras
    // Recorrer el tablero
    for (int i = 0; i < t->hight;i++){
        for(int j = 0; j < t->width; j++){
            // Verificar si la posición actual es parte de la figura
            bool es_parte_de_la_figura = false;
            for (int k = 0; k < p->size; k++) {
                if (p->blocks[k].x == j && p->blocks[k].y == i) {
                    es_parte_de_la_figura = true;
                    break;
                }
            }
            
            // Imprimir el carácter correspondiente
            if (es_parte_de_la_figura) {
                printf("#"); // Parte de la figura
            } else if (t->table[i][j] == 1) {
                printf("*"); // Parte bloqueada del tablero
            } else {
                printf(" "); // Espacio vacío
            }
        }printf("\n");
    }printf("\n");
}