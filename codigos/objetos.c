#include <stdio.h>
#include <stdlib.h>

//Se declara la tabla
char tabla[22][22];

//Se declara el cuadrado{
int cuadrado[4][2];

void coordenadas_de_cuadrado (int x, int y){
    //primer cuadrante
    cuadrado[0][0]=x;//cordenada y                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    cuadrado[0][1]=y;//cordenada x
    //segundo cuadrante
    cuadrado[1][0]=x+1;//cordenada y
    cuadrado[1][1]=y;//cordenada x
    //tercer cuadrante
    cuadrado[2][0]=x;//cordenada y
    cuadrado[2][1]=y+1;//cordenada x
    //cuarto cuadrante
    cuadrado[3][0]=x+1;//cordenada y
    cuadrado[3][1]=y+1;//cordenada x

}
//}se termina le estructura del cuadrado

// Se declara la estructura del palo
int palo[22][22];

void coordenadas_de_el_palo(int x, int y, int rotacion) {
    int coordenada_x;
    int coordenada_y;

    for (coordenada_y = 0; coordenada_y < 22; coordenada_y++) {
        for (coordenada_x = 0; coordenada_x < 22; coordenada_x++) {
            if (rotacion == 0) {
                if (coordenada_x == x && coordenada_y > y - 1 && coordenada_y < y + 4) {
                    palo[coordenada_y][coordenada_x] = 1;
                } else {
                    palo[coordenada_y][coordenada_x] = 0;
                }
            } else {
                if (coordenada_y == y && coordenada_x > x - 1 && coordenada_x < x + 4) {
                    palo[coordenada_y][coordenada_x] = 1;
                } else {
                    palo[coordenada_y][coordenada_x] = 0;
                }
            }
        }
    }
}
