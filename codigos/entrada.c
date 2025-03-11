// Autor: Josué Monarca Pérez
// Fecha: 10/03/2025
// Descripción: Este código es un ejemplo de cómo se puede detectar la entrada del teclado en C.
// Para ello, se utiliza la función GetAsyncKeyState de la biblioteca Windows.h.
#include <stdbool.h>
#include "CABECERA.h"
#include <stdio.h>
#include <windows.h>

int rota;

// Función para mover la figura
void mover_figura() {
    // Si se presiona la flecha arriba
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        // Lógica para rotar la figura
        rota++;
        if (rota>2){
            rota=0;
        }
        coordenadas_de_p(p[0][0],p[0][1],rota);
    }
    // Si se presiona la flecha abajo
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        // Lógica para mover la figura hacia abajo
        coordenadas_de_p(p[0][0]+1,p[0][1],rota);
    }
    // Si se presiona la flecha izquierda
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        // Lógica para mover la figura a la izquierda
        coordenadas_de_p(p[0][0],p[0][1]-1,rota);
    }
    // Si se presiona la flecha derecha
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        // Lógica para mover la figura a la derecha
        coordenadas_de_p(p[0][0],p[0][1]+1,rota);
    }
};