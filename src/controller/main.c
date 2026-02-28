#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/TETRIS.h"
#include <windows.h>
#include "../../include/orchestrator.h"
#include "../../include/PIECE.h"
#include "../../include/TABLE.h"
#include <stdbool.h>

int main() {

    TABLE tabla_main = {HIGHT, WIDTH, {{0}}};
    init_table(&tabla_main);

    PIECE piece_main = generate_piece();
    set_piece_position(&piece_main, 1, 0);
    ocultar_cursor();//se oculta el cursor


    for(int i=0;i<90;i++){
        mover_cursor(1,0);
        gravity(&tabla_main, &piece_main);
        draw(&tabla_main, &piece_main);
        mover_figura(&piece_main, &tabla_main);
        Sleep(150);
    }
    
    return 0;
}
