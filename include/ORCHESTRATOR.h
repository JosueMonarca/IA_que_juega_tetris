#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H
#include "TABLE.h"
#include "PIECE.h"

#define FALSE 0
#define TRUE 1
#define HORIZONTAL 0
#define VERTICAL 1

extern int check_colision(TABLE* t, PIECE* p);
extern int move_piece_in_table(PIECE* p, int direction, TABLE* t);
extern int rotate_piece_with_verification(PIECE* p, int direction, TABLE* t);
extern void delete_rows(TABLE* t);
extern void lock_piece(TABLE* t, PIECE* p);
extern void set_piece_position(PIECE* p, int x, int rotation);

#endif