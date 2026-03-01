#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/TETRIS.h"
#include <windows.h>
#include "../include/orchestrator.h"
#include "../include/PIECE.h"
#include "../include/TABLE.h"
#include "../include/INTERFAZ_API.h"
#include <stdbool.h>

int main() {
    int score = 0;
    
    TABLE tabla_main = {HIGHT, WIDTH, {{0}}};
    init_table(&tabla_main);

    PIECE piece_main = generate_piece();

    init_gamePlay(&piece_main);

    while (!game_over(&tabla_main))
    {
        mover_cursor(1,0);
        if(delete_rows(&tabla_main)){score++;}
        draw_gamePlay(&tabla_main, &piece_main);
        mover_figura(&piece_main, &tabla_main);
        Sleep(100);
    }

    end_gamePlay(score);
    
    return 0;
}
