#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/CABECERA.h"
#include <windows.h>

int main() {
     // Inicialización
    RecolectorBasura* recolector = inicializar_recolector();

    rota = 0;
    ocultar_cursor();//se oculta el cursor
    coordenadas_de_c(1,3,0);//se iniciazalizan las cordenadas del c
    //coordenadas_de_p(1,14,0);//se inicializan las cordenadas del p
    //coordenadas_de_u(1,7,1);//se inicializan las cordenadas de la U
    //coordenadas_de_L(1,11,0);//se inicializan las cordenadas de la L
    //coordenadas_de_t(1,18,0);//se inicializan las cordenadas de la T
    registrar_puntero(recolector, c);
    //registrar_puntero(recolector, p);
    //registrar_puntero(recolector,tabla);
    //registrar_puntero(recolector, u);
    //registrar_puntero(recolector, l);
    //registrar_puntero(recolector, t);


    for(int i=0;i<25;i++){
        mover_cursor(0, 0);
        draw();
        mover_figura('c');
        Sleep(150);
    }
    //while (game_over()==false);

    // Liberar memoria y recolectar basura
    recolectar_basura(recolector);
    liberar_recolector(recolector);
    
    return 0;
}
