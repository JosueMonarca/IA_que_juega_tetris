#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CABECERA.h"
#include <windows.h>

int colision() {
        if(tabla[cuadrado[2][0]+1][cuadrado[2][1]]=='*'||tabla[cuadrado[3][0]+1][cuadrado[3][1]]=='*'){
            return 0 ;
        }
        else{
            return 1;
        }
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
    //se mueve el cuadrado hacia abajo
    if (colision()==1)
    {
    coordenadas_de_cuadrado(cuadrado[0][0]+1,cuadrado[0][1]); 
    //el primer parametro es la cordenada 'y' y el segundo la cordenada 'x
    }
    else{
        coordenadas_de_cuadrado(cuadrado[0][0],cuadrado[0][1]);
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
                // Revisar si el punto (i, j) coincide con alguna coordenada del cuadrado
                tabla[x][y] = ' '; // Inicialmente vacío
                for (int k = 0; k < 4; k++) {
                    if (x == cuadrado[k][0] && y == cuadrado[k][1]) {
                        tabla[x][y] = '#'; // Parte del cuadrado
                    }
                }
            }
            // Imprimir el contenido del tablero
            printf("%c", tabla[x][y]);
        }
        printf("\n");
    }
}

