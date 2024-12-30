#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CABECERA.h"
const int FILAS=42;
const int COLUMNAS=42;

char TABLA[82][42]; //se declara la tabla

int main() {
    int i;
    int j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            TABLA[i][j] = ' ';
        }
    }
    
    for (i=0;i<FILAS;i++){
        for(j=0;j<COLUMNAS;j++){
            if(i==0||i==FILAS-1){
                TABLA[i][j]='#';
            }
            if(j==0||j==COLUMNAS-1){
                TABLA[i][j]='_';
            }
        printf("%c",TABLA[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}