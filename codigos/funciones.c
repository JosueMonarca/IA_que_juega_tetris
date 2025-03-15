#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CABECERA.h"
#include <windows.h>


int colision(int figura[][2], int filas) {

    // Verificar si las posiciones inferiores del c están en contacto con un borde ('*')
    for (int k = 2; k < filas; k++) { // Solo revisamos la parte inferior del c
        int y = figura[k][0] + 1; // Próxima posición en Y
        int x = figura[k][1];     // Posición actual en X
        
        // Verificar colisiones con los bordes laterales
        if (tabla[figura[k][0]][figura[k][1] + 1] == '*' || tabla[figura[k][0]][figura[k][1] - 1] == '*') {
            return 2; // Colisión con los bordes laterales
        }
        
        // Verificar si la próxima posición está fuera del área del figura actual
        bool es_parte_de_la_figura = false;
        for (int i = 0; i < 4; i++) {
            if (figura[i][0] == y && figura[i][1] == x) {
                es_parte_de_la_figura = true;
                break;
            }
        }
        
        // Si no es parte de la figura y encuentra '*' o '#', hay colisión
        if (!es_parte_de_la_figura && (tabla[y][x] == '*' || tabla[y][x] == '#')) {
            return 1; // Hay colisión
        }
    }
    
    return 0; // No hay colisión
}

// Función para mover el cursor a una posición específica
void mover_cursor(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion;
    posicion.X = y;
    posicion.Y = x;
    SetConsoleCursorPosition(hConsole, posicion);
}

// Función para ocultar el cursor
void ocultar_cursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Ocultar el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int conv_seg_min(int segundos,int minutos, int operacion){
    
    switch (operacion)
    {
    case 1:
        segundos=minutos*60;
        return segundos;//retorna los minutos en segundos
        break;
    case 2:
        minutos=segundos/60;
        return minutos;//retorna los segundos en minutos
        break;
    default:
    printf("Operacion no valida");//mensaje de error
        break;
    }
    
}

void gravity(){
    int i;
    int x;
    int y; // Declare y outside the loop
    //se mueve el c hacia abajo
    if (colision(c,sizeof(c)/sizeof(c[0]))==0)
    {
    coordenadas_de_c(c[0][0]+1,c[0][1],0); 
    //el primer parametro es la cordenada 'y' y el segundo la cordenada 'x
/*
    //se mueve el p hacia abajo
    coordenadas_de_p(p[0][0]+1,p[0][1],0);

    //se mueve la U hacia abajo
    //coordenadas_de_u(u[0][0]+1,u[0][1],1);

    //se mueve la L hacia abajo
    //coordenadas_de_L(l[0][0]+1,l[0][1],0);

    //se mueve la T hacia abajo
    //coordenadas_de_t(t[0][0]+1,t[0][1],0);
*/
    }
    else{
        coordenadas_de_c(c[0][0],c[0][1],0);
    }
}


void draw() {
    // Se llama a la funcion gravity para determinar la posicion de las figuras
    gravity();
    // Recorrer el tablero
    for (int x = 0; x < 22; x++) {
        for (int y = 0; y < 22; y++) {
            // Bordes del tablero
            if (x == 0 || x == 21 || y == 0 || y == 21) {
                tabla[x][y] = '*';//borde del tablero
            } else {
                // Revisar si el punto (i, j) coincide con alguna coordenada del c
                tabla[x][y] = ' '; // Inicialmente vacío

                for (int k = 0; k < 4; k++) {
                    if (x == c[k][0] && y == c[k][1]) {
                        tabla[x][y] = '#'; // Parte del c
                    }
                }
/*
                // Revisar si el punto (i, j) coincide con alguna coordenada del p
                for (int k = 0; k < 5; k++) {
                    if (x == p[k][0] && y == p[k][1]) {
                        tabla[x][y] = '#'; // Parte del p
                    }
                }

                // Revisar si el punto (i, j) coincide con alguna coordenada de la U
                for (int k = 0; k < 5; k++) {
                    if (x == u[k][0] && y == u[k][1]) {
                        tabla[x][y] = '#'; // Parte de la u
                    }
                }

                // Revisar si el punto (i, j) coincide con alguna coordenada de la L
                for (int k = 0; k < 5; k++) {
                    if (x == l[k][0] && y == l[k][1]) {
                        tabla[x][y] = '#'; // Parte de la L
                    }
                }

                // Revisar si el punto (i, j) coincide con alguna coordenada de la T
                for (int k = 0; k < 4; k++) {
                    if (x == t[k][0] && y == t[k][1]) {
                        tabla[x][y] = '#'; // Parte de la T
                    }
                }
*/
                }
            // Imprimir el contenido del tablero
            printf("%c", tabla[x][y]);
        }
        printf("\n");
    }
}
