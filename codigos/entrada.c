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
void mover_figura(char figura) {
    switch (figura) {
        case 'c':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_c(c[0][0], c[0][1]);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_c(c[0][0] + 1, c[0][1]);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[c[0][0]][c[0][1] - 1] == '*') {
                    coordenadas_de_c(c[0][0], c[0][1]);
                } else {
                    coordenadas_de_c(c[0][0], c[0][1] - 1);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[c[2][0]][c[2][1] + 1] == '*') {
                    coordenadas_de_c(c[0][0], c[0][1]);
                } else {
                    coordenadas_de_c(c[0][0], c[0][1] + 1);
                }
            }
            break;

        case 'p':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_p(p[0][0], p[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_p(p[0][0] + 1, p[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[p[0][0]][p[0][1] - 1] == '*') {
                    coordenadas_de_p(p[0][0], p[0][1], rota);
                } else {
                    coordenadas_de_p(p[0][0], p[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[p[2][0]][p[2][1] + 1] == '*') {
                    coordenadas_de_p(p[0][0], p[0][1], rota);
                } else {
                    coordenadas_de_p(p[0][0], p[0][1] + 1, rota);
                }
            }
            break;

        case 'u':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_u(u[0][0], u[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_u(u[0][0] + 1, u[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[u[0][0]][u[0][1] - 1] == '*') {
                    coordenadas_de_u(u[0][0], u[0][1], rota);
                } else {
                    coordenadas_de_u(u[0][0], u[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[u[2][0]][u[2][1] + 1] == '*') {
                    coordenadas_de_u(u[0][0], u[0][1], rota);
                } else {
                    coordenadas_de_u(u[0][0], u[0][1] + 1, rota);
                }
            }
            break;

        case 'l':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_L(l[0][0], l[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_L(l[0][0] + 1, l[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[l[0][0]][l[0][1] - 1] == '*') {
                    coordenadas_de_L(l[0][0], l[0][1], rota);
                } else {
                    coordenadas_de_L(l[0][0], l[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[l[2][0]][l[2][1] + 1] == '*') {
                    coordenadas_de_L(l[0][0], l[0][1], rota);
                } else {
                    coordenadas_de_L(l[0][0], l[0][1] + 1, rota);
                }
            }
            break;

        case 't':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_t(t[0][0], t[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_t(t[0][0] + 1, t[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[t[0][0]][t[0][1] - 1] == '*') {
                    coordenadas_de_t(t[0][0], t[0][1], rota);
                } else {
                    coordenadas_de_t(t[0][0], t[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[t[2][0]][t[2][1] + 1] == '*') {
                    coordenadas_de_t(t[0][0], t[0][1], rota);
                } else {
                    coordenadas_de_t(t[0][0], t[0][1] + 1, rota);
                }
            }
            break;

        case 'z':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_z(z[0][0], z[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_z(z[0][0] + 1, z[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[z[0][0]][z[0][1] - 1] == '*') {
                    coordenadas_de_z(z[0][0], z[0][1], rota);
                } else {
                    coordenadas_de_z(z[0][0], z[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[z[2][0]][z[2][1] + 1] == '*') {
                    coordenadas_de_z(z[0][0], z[0][1], rota);
                } else {
                    coordenadas_de_z(z[0][0], z[0][1] + 1, rota);
                }
            }
            break;

        case 's':
            // Si se presiona la flecha arriba
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                coordenadas_de_s(s[0][0], s[0][1], rota);
            }
            // Si se presiona la flecha abajo
            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                coordenadas_de_s(s[0][0] + 1, s[0][1], rota);
            }
            // Si se presiona la flecha izquierda
            if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                if (tabla[s[0][0]][s[0][1] - 1] == '*') {
                    coordenadas_de_s(s[0][0], s[0][1], rota);
                } else {
                    coordenadas_de_s(s[0][0], s[0][1] - 1, rota);
                }
            }
            // Si se presiona la flecha derecha
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                if (tabla[s[2][0]][s[2][1] + 1] == '*') {
                    coordenadas_de_s(s[0][0], s[0][1], rota);
                } else {
                    coordenadas_de_s(s[0][0], s[0][1] + 1, rota);
                }
            }
            break;

        default:
            
            break;
    }
    
};