#ifndef PIECE_H
#define PIECE_H
#include "UNIT.h"

typedef struct {
    char type; // Tipo de pieza (C, P, U, L, T, Z, S)
    int size;
    unit blocks[6];
}PIECE;

#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4
#define ROTATE_RIGHT 5
#define ROTATE_LEFT 6

extern const PIECE piece_C;
extern const PIECE piece_P;
extern const PIECE piece_U;
extern const PIECE piece_L;
extern const PIECE piece_T;
extern const PIECE piece_Z;
extern const PIECE piece_S;

extern int get_size(PIECE* p);
extern char get_type(PIECE* p);
extern void move_piece(PIECE* p, int direction);
extern void set_type(PIECE* p, char type);
extern void rotate_piece(PIECE* p, int direction);

#endif