#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CABECERA.h"
#include <windows.h>

int main() {
    ocultar_cursor();//se oculta el cursor
    coordenadas_de_cuadrado(0,10);//se iniciazalizan las cordenadas del cuadrado
    for(int i=0;i<25;i++){
        mover_cursor(0, 0);
        draw();
        Sleep(1000);
    }
    //while (game_over()==false);
    
    system("pause");
    return 0;
}
