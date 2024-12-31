#ifndef CABECERA_H
#define CABECERA_H

//se definen las funciones de tiempo
int conv_seg_horas(int segundos,int horas, int operacion);
int conv_seg_min(int segundos,int minutos, int operacion);
int conv_min_horas(int minutos,int horas, int operacion);

//se define la funcion para recargar la pantalla
void draw();

// se define las coordenadas de el cuadrado
void coordenadas_de_cuadrado (int x, int y);

//se define el cuadrado 
extern int cuadrado[4][2];

#endif // CABECERA_H