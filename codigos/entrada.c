// Autor: Josué Monarca Pérez
// Fecha: 10/03/2025
// Descripción: Este código es un ejemplo de cómo se puede detectar la entrada del teclado en C.
// Para ello, se utiliza la función GetAsyncKeyState de la biblioteca Windows.h.
#include <stdbool.h>
#include "CABECERA.h"
#include <stdio.h>
#include <windows.h>

int rota;

static bool tecla_presionada = false;

// Función para mover la figura
void mover_figura(char figura) {
    void (*coordenadas_func)(int, int, int) = NULL;
    int (*figura_coords)[][2] = NULL;

    switch (figura) {
        case 'c': coordenadas_func = coordenadas_de_c; figura_coords = &c; break;
        case 'p': coordenadas_func = coordenadas_de_p; figura_coords = &p; break;
        case 'u': coordenadas_func = coordenadas_de_u; figura_coords = &u; break;
        case 'l': coordenadas_func = coordenadas_de_L; figura_coords = &l; break;
        case 't': coordenadas_func = coordenadas_de_t; figura_coords = &t; break;
        case 'z': coordenadas_func = coordenadas_de_z; figura_coords = &z; break;
        case 's': coordenadas_func = coordenadas_de_s; figura_coords = &s; break;
        default: return;
    }

    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if(!tecla_presionada){
            coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1], rota);
            tecla_presionada = true;
        }else {
            tecla_presionada = false;
        }
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if(!tecla_presionada){
            if(tabla[(*figura_coords)[2][0] + 1][(*figura_coords)[2][1]] == '*'){
                coordenadas_func((*figura_coords)[0][0] + 1, (*figura_coords)[0][1], rota);
                tecla_presionada = true;
            }else{
                coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1], rota);
                tecla_presionada = true;
            }
        }else {
            tecla_presionada = false;
        }
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            if (tabla[(*figura_coords)[0][0]][(*figura_coords)[0][1] - 1] == '*') {
                coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1], rota);
            } else {
                coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1] - 1, rota);
            }
        }else {
            tecla_presionada = false;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if(!tecla_presionada){
            tecla_presionada = true;
            if (tabla[(*figura_coords)[2][0]][(*figura_coords)[2][1] + 1] == '*') {
                coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1], rota);
            } else {
                coordenadas_func((*figura_coords)[0][0], (*figura_coords)[0][1] + 1, rota);
            }
        }else{
            tecla_presionada = false;
        }
    }
}
