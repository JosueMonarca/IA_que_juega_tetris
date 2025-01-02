#ifndef CABECERA_H
#define CABECERA_H

//se definen las funciones de tiempo
int conv_seg_min(int segundos,int minutos, int operacion);

//se define la funcion para recargar la pantalla
void draw();

// se define las coordenadas de el cuadrado
void coordenadas_de_cuadrado (int x, int y);

//se define el cuadrado 
extern int cuadrado[4][2];

//se define la tabla
extern char tabla[22][22];

//se define la funcion ocultar_cursor
void ocultar_cursor();

//se define la funcion mover_cursor
void mover_cursor(int x, int y);

//se define la funcion colicion
int colicion();

#endif // CABECERA_H