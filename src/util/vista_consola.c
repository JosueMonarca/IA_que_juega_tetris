#include "../../include/INTERFAZ_API.h"
#include "../../include/TETRIS.h"
#include "../../include/PIECE.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

void gravity(TABLE* t, PIECE* p){
    //se mueve el c hacia abajo
    if (move_piece_in_table(p, DOWN, t) == FALSE){
        lock_piece(t, p);
        *p = generate_piece();
        set_piece_position(p,generate_random_number(4, t->width - 4), 0);
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

void draw_gamePlay(TABLE* t, PIECE* p) {
    mover_cursor(1,0);
    gravity(t, p);
    draw(t, p);
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

void init_gamePlay(PIECE* piece_main) {
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    system("cls"); 
    set_piece_position(piece_main, 1, 0);
    ocultar_cursor();//se oculta el cursor
}

void end_gamePlay(int score) {
    //system("cls");
    printf("Game Over! Your score: %d\n", score);
}