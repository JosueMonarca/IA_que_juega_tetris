#ifndef INTERFAZ_API_H
#define INTERFAZ_API_H
#include "orchestrator.h"

void draw_gamePlay(TABLE* t, PIECE* p);
void init_gamePlay(PIECE* piece_main);
void end_gamePlay(int score);

#endif // INTERFAZ_API_H