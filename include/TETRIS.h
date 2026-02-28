#ifndef TETRIS_H
#define TETRIS_H
#include "PIECE.h"
#include "TABLE.h"

//se definen las funciones de tiempo
int conv_seg_min(int segundos,int minutos, int operacion);

//se define la funcion para recargar la pantalla
void draw(TABLE* t, PIECE* p);

// se define una funcion para numeros aleatoris
int generate_random_number();

// se define la funcion para generar piezas aleatorias
PIECE generate_piece();

// se define la funcion mover las figuras por teclado
void mover_figura(PIECE* p, TABLE* t);

void gravity(TABLE* t, PIECE* p);

//se define la tabla
extern char tabla[22][22];

//se define la funcion ocultar_cursor
void ocultar_cursor();

//se define la funcion mover_cursor
void mover_cursor(int x, int y);

extern int rota;

#endif // TETRIS_H
