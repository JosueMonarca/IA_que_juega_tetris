#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "CABECERA.h"
#include <windows.h>
#include "ENTRADA.H"


int colision() {
    // Verificar si las posiciones inferiores del cuadrado están en contacto con un borde ('*')
    for (int k = 2; k < 4; k++) { // Solo revisamos la parte inferior del cuadrado
        int y = cuadrado[k][0] + 1; // Próxima posición en Y
        int x = cuadrado[k][1];     // Posición actual en X
        
        if (cuadrado[k][1]+1=='*'||cuadrado[k][1]-1=='*'){//se corroboran las coliciones con los bordes
            return 2;
        }
        
          // Verificar si la próxima posición está fuera del área del cuadrado actual
        bool es_parte_del_cuadrado = false;
        for (int i = 0; i < 4; i++) {
            if (cuadrado[i][0] == y && cuadrado[i][1] == x) {
                es_parte_del_cuadrado = true;
                break;
            }
        }
        
        // Si no es parte del cuadrado y encuentra '*' o '#', hay colisión
        if (!es_parte_del_cuadrado && (tabla[y][x] == '*' || tabla[y][x] == '#')) {
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
    //se mueve el cuadrado hacia abajo
    if (colision()==0||colision()==2)
    {
    coordenadas_de_cuadrado(cuadrado[0][0]+1,cuadrado[0][1]); 
    //el primer parametro es la cordenada 'y' y el segundo la cordenada 'x
/*
    //se mueve el palo hacia abajo
    coordenadas_de_palo(palo[0][0]+1,palo[0][1],0);

    //se mueve la U hacia abajo
    coordenadas_de_u(u[0][0]+1,u[0][1],1);

    //se mueve la L hacia abajo
    coordenadas_de_L(l[0][0]+1,l[0][1],0);

    //se mueve la T hacia abajo
    coordenadas_de_t(t[0][0]+1,t[0][1],0);
*/
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
/*
                // Revisar si el punto (i, j) coincide con alguna coordenada del palo
                for (int k = 0; k < 5; k++) {
                    if (x == palo[k][0] && y == palo[k][1]) {
                        tabla[x][y] = '#'; // Parte del palo
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
