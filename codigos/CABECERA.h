#ifndef CABECERA_H
#define CABECERA_H

//se definen las funciones de tiempo
int conv_seg_horas(int segundos,int horas, int operacion);
int conv_seg_min(int segundos,int minutos, int operacion);
int conv_min_horas(int minutos,int horas, int operacion);

//se define la funcion para recargar la pantalla
void frame(char ***TABLA);

// se define la constante de el cuadrado
// Definición de la estructura S_Cuadrado
struct S_Cuadrado {
    const char forma[4][4];  // Matriz para representar la forma del cuadrado
    int x_1, y_1;
    int x_2, y_2;
    int x_3, y_3;
    int x_4, y_4;
    int x_5, y_5;
    int x_6, y_6;
    int x_7, y_7;
    int x_8, y_8;
    int x_9, y_9;
    int x_10, y_10;
    int x_11, y_11;
    int x_12, y_12;
};

// Declaración de la instancia de la estructura (cuadrado)
extern struct S_Cuadrado cuadrado;

#endif // CABECERA_H