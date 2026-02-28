#ifndef TETRIS_H
#define TETRIS_H
#include "PIECE.h"
#include "TABLE.h"

//se definen las funciones de tiempo
int conv_seg_min(int segundos,int minutos, int operacion);

//se define la funcion para recargar la pantalla
void draw(TABLE* t, PIECE* p);

// se define las coordenadas de el c
void coordenadas_de_c (int x, int y,int rotacion);

// se define una funcion para numeros aleatoris
int generate_random_number();

// se define la funcion para generar piezas aleatorias
PIECE generate_piece();

// se define la funcion mover las figuras por teclado
void mover_figura(PIECE* p, TABLE* t);

//se define el c 
extern int c[4][2];

//se define el p
extern int p[4][2];

//se define la u
extern int u[5][2];

//se define a "l"
extern int l[5][2];

//se define a "t"
extern int t[4][2];

//se define a "z"
extern int z[4][2];

//se define a "s"
extern int s[4][2];

//se define Las coordenadas de la T
void coordenadas_de_t(int y, int x, int rotacion);

//se define las coordenadas de la L
void coordenadas_de_L(int y, int x, int rotacion);

//se define las ccordenadas de la L
void coordenadas_de_u (int y, int x, int rotacion);

//se define las coordenadas del p
void coordenadas_de_p (int y, int x, int rotacion);

//se define las coordenadas de la z
void coordenadas_de_z (int y, int x, int rotacion);

//se define las coordenadas de la s
void coordenadas_de_s (int y, int x, int rotacion);

//se define la tabla
extern char tabla[22][22];

//se define la funcion ocultar_cursor
void ocultar_cursor();

//se define la funcion mover_cursor
void mover_cursor(int x, int y);

//se define la funcion colicion
int colicion();


// Estructura para almacenar punteros a las figuras
typedef struct Nodo {
    void* ptr;           // Puntero a la memoria asignada
    struct Nodo* siguiente; // Puntero al siguiente nodo
} Nodo;

// Estructura de recolector de basura
typedef struct {
    Nodo* head; // Puntero al primer nodo de la lista
} RecolectorBasura;

// Funciones del recolector de basura
RecolectorBasura* inicializar_recolector();
void registrar_puntero(RecolectorBasura* recolector, void* ptr);
void recolectar_basura(RecolectorBasura* recolector);
void liberar_recolector(RecolectorBasura* recolector);

extern int rota;

#endif // TETRIS_H
