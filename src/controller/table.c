#include "../../include/TABLE.h"

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