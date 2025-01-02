#include <stdio.h>
#include <stdlib.h>

char tabla[22][22];

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