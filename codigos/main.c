#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CABECERA.h"
#include <windows.h>


int main() {
     // Inicialización
    RecolectorBasura* recolector = inicializar_recolector();

    ocultar_cursor();//se oculta el cursor
    coordenadas_de_cuadrado(1,8);//se iniciazalizan las cordenadas del cuadrado
    registrar_puntero(recolector, cuadrado);

    coordenadas_de_el_palo(8,1,1);//se inicializan las cordenadas del palo
    registrar_puntero(recolector, palo);

    for(int i=0;i<25;i++){
        mover_cursor(0, 0);
        draw();
        Sleep(600);
    }
    //while (game_over()==false);

    // Liberar memoria y recolectar basura
    recolectar_basura(recolector);
    liberar_recolector(recolector);
    
    return 0;
}
