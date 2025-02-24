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
int palo[4][2];

void coordenadas_de_palo (int y, int x, int rotacion){
    if(rotacion==0){
    //primer cuadrante
    palo[0][0]=y;//cordenada y
    palo[0][1]=x;//cordenada x
    //segundo cuadrante
    palo[1][0]=y+1;//cordenada y
    palo[1][1]=x;//cordenada x
    //tercer cuadrante
    palo[2][0]=y+2;//cordenada y
    palo[2][1]=x;//cordenada x
    //cuarto cuadrante
    palo[3][0]=y+3;//cordenada y
    palo[3][1]=x;//cordenada x
    }
    else{
    //primer cuadrante
    palo[0][0]=y;//cordenada y  
    palo[0][1]=x;//cordenada x
    //segundo cuadrante
    palo[1][0]=y;//cordenada y
    palo[1][1]=x+1;//cordenada x
    //tercer cuadrante
    palo[2][0]=y;//cordenada y
    palo[2][1]=x+2;//cordenada x
    //cuarto cuadrante
    palo[3][0]=y;//cordenada y
    palo[3][1]=x+3;//cordenada x
    }
}
//se termina la estructura del palo

//se declare la estructura de la u
int u[5][2];

void coordenadas_de_u (int y, int x, int rotacion){
    if(rotacion==0){
    //primer cuadrante
    u[0][0]=y;//cordenada y
    u[0][1]=x;//cordenada x
    //segundo cuadrante
    u[1][0]=y+1;//cordenada y
    u[1][1]=x;//cordenada x
    //tercer cuadrante
    u[2][0]=y+2;//cordenada y
    u[2][1]=x;//cordenada x
    //cuarto cuadrante
    u[3][0]=y+2;//cordenada y
    u[3][1]=x+1;//cordenada x
    //quinto cuadrante
    u[4][0]=y+2;//cordenada y
    u[4][1]=x+2;//cordenada x
    }
    else if(rotacion==1){
    //primer cuadrante
    u[0][0]=y;//cordenada y
    u[0][1]=x;//cordenada x
    //segundo cuadrante
    u[1][0]=y+1;//cordenada y
    u[1][1]=x;//cordenada x
    //tercer cuadrante
    u[2][0]=y+1;//cordenada y
    u[2][1]=x+1;//cordenada x
    //cuarto cuadrante
    u[3][0]=y+1;//cordenada y
    u[3][1]=x+2;//cordenada x
    //quinto cuadrante
    u[4][0]=y;//cordenada y
    u[4][1]=x+2;//cordenada x
    }
    else if(rotacion==2){
    //primer cuadrante
    u[0][0]=y;//cordenada y
    u[0][1]=x;//cordenada x
    //segundo cuadrante
    u[1][0]=y;//cordenada y
    u[1][1]=x+1;//cordenada x
    //tercer cuadrante
    u[2][0]=y+1;//cordenada y
    u[2][1]=x;//cordenada x
    //cuarto cuadrante
    u[3][0]=y+2;//cordenada y
    u[3][1]=x;//cordenada x
    //quinto cuadrante
    u[4][0]=y+2;//cordenada y
    u[4][1]=x+1;//cordenada x
    }
    else{
    //primer cuadrante
    u[0][0]=y;//cordenada y
    u[0][1]=x+2;//cordenada x
    //segundo cuadrante
    u[1][0]=y+1;//cordenada y
    u[1][1]=x;//cordenada x
    //tercer cuadrante
    u[2][0]=y+1;//cordenada y
    u[2][1]=x+1;//cordenada x
    //cuarto cuadrante
    u[3][0]=y+1;//cordenada y
    u[3][1]=x+2;//cordenada x
    //quinto cuadrante
    u[4][0]=y;//cordenada y
    u[4][1]=x;//cordenada x
    }
}
//se termina la estructura de la u

//se delara la estructura de la l
int l[5][2];

void coordenadas_de_L(int y, int x, int rotacion){
    if(rotacion==0){
    //primer cuadrante
    l[0][0]=y;//cordenada y
    l[0][1]=x;//cordenada x
    //segundo cuadrante
    l[1][0]=y+1;//cordenada y
    l[1][1]=x;//cordenada x
    //tercer cuadrante
    l[2][0]=y+2;//cordenada y
    l[2][1]=x;//cordenada x
    //cuarto cuadrante
    l[3][0]=y+3;//cordenada y
    l[3][1]=x;//cordenada x
    //quinto cuadrante
    l[4][0]=y+3;//cordenada y
    l[4][1]=x-1;//cordenada x
    }
    else if(rotacion==1){
    //primer cuadrante
    l[0][0]=y;//cordenada y
    l[0][1]=x;//cordenada x
    //segundo cuadrante
    l[1][0]=y;//cordenada y
    l[1][1]=x+1;//cordenada x
    //tercer cuadrante
    l[2][0]=y;//cordenada y
    l[2][1]=x+2;//cordenada x
    //cuarto cuadrante
    l[3][0]=y;//cordenada y
    l[3][1]=x+3;//cordenada x
    //quinto cuadrante
    l[4][0]=y+1;//cordenada y
    l[4][1]=x+3;//cordenada x
    }
    else if(rotacion==2){
    //primer cuadrante
    l[0][0]=y;//cordenada y
    l[0][1]=x;//cordenada x
    //segundo cuadrante
    l[1][0]=y+1;//cordenada y
    l[1][1]=x;//cordenada x
    //tercer cuadrante
    l[2][0]=y+2;//cordenada y
    l[2][1]=x;//cordenada x
    //cuarto cuadrante
    l[3][0]=y+3;//cordenada y
    l[3][1]=x;//cordenada x
    //quinto cuadrante
    l[4][0]=y;//cordenada y
    l[4][1]=x+1;//cordenada x
    }
    else{
    //primer cuadrante
    l[0][0]=y;//cordenada y
    l[0][1]=x;//cordenada x
    //segundo cuadrante
    l[1][0]=y;//cordenada y
    l[1][1]=x+1;//cordenada x
    //tercer cuadrante
    l[2][0]=y;//cordenada y
    l[2][1]=x+2;//cordenada x
    //cuarto cuadrante
    l[3][0]=y;//cordenada y
    l[3][1]=x+3;//cordenada x
    //quinto cuadrante
    l[4][0]=y-1;//cordenada y
    l[4][1]=x;//cordenada x
    }
}
//se termina la estructura de la l

//se declara la estructura de t
int t[4][2];

void coordenadas_de_t(int y, int x, int rotacion){
    if(rotacion==0){
    //primer cuadrante
    t[0][0]=y;//cordenada y
    t[0][1]=x;//cordenada x
    //segundo cuadrante
    t[1][0]=y;//cordenada y
    t[1][1]=x+1;//cordenada x
    //tercer cuadrante
    t[2][0]=y;//cordenada y
    t[2][1]=x+2;//cordenada x
    //cuarto cuadrante
    t[3][0]=y+1;//cordenada y
    t[3][1]=x+1;//cordenada x
    }
    else if(rotacion==1){
    //primer cuadrante
    t[0][0]=y;//cordenada y
    t[0][1]=x;//cordenada x
    //segundo cuadrante
    t[1][0]=y+1;//cordenada y
    t[1][1]=x;//cordenada x
    //tercer cuadrante
    t[2][0]=y+2;//cordenada y
    t[2][1]=x;//cordenada x
    //cuarto cuadrante
    t[3][0]=y+1;//cordenada y
    t[3][1]=x-1;//cordenada x
    }
    else if(rotacion==2){
    //primer cuadrante
    t[0][0]=y;//cordenada y
    t[0][1]=x;//cordenada x
    //segundo cuadrante
    t[1][0]=y;//cordenada y
    t[1][1]=x+1;//cordenada x
    //tercer cuadrante
    t[2][0]=y;//cordenada y
    t[2][1]=x+2;//cordenada x
    //cuarto cuadrante
    t[3][0]=y-1;//cordenada y
    t[3][1]=x+1;//cordenada x
    }
    else{
    //primer cuadrante
    t[0][0]=y;//cordenada y
    t[0][1]=x;//cordenada x
    //segundo cuadrante
    t[1][0]=y+1;//cordenada y
    t[1][1]=x;//cordenada x
    //tercer cuadrante
    t[2][0]=y+2;//cordenada y
    t[2][1]=x;//cordenada x
    //cuarto cuadrante
    t[3][0]=y+1;//cordenada y
    t[3][1]=x+1;//cordenada x
    }
}
//se termina la estructura de t