// Autor: Josué Monarca Pérez
// Fecha: 10/03/2025
// Descripción: Este código es un ejemplo de cómo se puede detectar la entrada del teclado en C.
// Para ello, se utiliza la función GetAsyncKeyState de la biblioteca Windows.h.
#include <stdbool.h>
#include "../../include/TETRIS.h"
#include <stdio.h>
#include <windows.h>
#include "../../include/orchestrator.h"
#include "../../include/PIECE.h"
#include "../../include/TABLE.h"

int rota;

static bool tecla_presionada = false;

// Función para mover la figura
void mover_figura(PIECE* p, TABLE* t) {
    

    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            rotate_piece_with_verification(p, ROTATE_RIGHT, t);
        }
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            move_piece_in_table(p, DOWN, t);
        }else{
            tecla_presionada = false;
        }
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            move_piece_in_table(p, LEFT, t);
        }
        else{
            tecla_presionada = false;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            move_piece_in_table(p, RIGHT, t);
        }else{
            tecla_presionada = false;
        }
    }
}
