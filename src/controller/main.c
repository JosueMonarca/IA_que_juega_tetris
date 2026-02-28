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
     // Inicialización
    RecolectorBasura* recolector = inicializar_recolector();

    TABLE tabla_main = {HIGHT, WIDTH, {{0}}};
    init_table(&tabla_main);

    PIECE piece_main = generate_piece();
    set_piece_position(&piece_main, 1, 0);
    ocultar_cursor();//se oculta el cursor


    for(int i=0;i<25;i++){
        mover_cursor(1,0);
        draw(&tabla_main, &piece_main);
        mover_figura(&piece_main, &tabla_main);
        Sleep(150);
    }
    //while (game_over()==false);

    // Liberar memoria y recolectar basura
    recolectar_basura(recolector);
    liberar_recolector(recolector);
    
    return 0;
}

