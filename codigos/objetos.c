#include <stdio.h>
#include <stdlib.h>

int cuadrado[4][2];

void coordenadas_de_cuadrado (int x, int y){
    //primer cuadrante
    cuadrado[0][0]=x;//cordenada x                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    cuadrado[0][1]=y;//cordenada y
    //segundo cuadrante
    cuadrado[1][0]=x+1;
    cuadrado[1][1]=y;
    //tercer cuadrante
    cuadrado[2][0]=x;
    cuadrado[2][1]=y+1;
    //cuarto cuadrante
    cuadrado[3][0]=x+1;
    cuadrado[3][1]=y+1;

}