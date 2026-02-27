#ifndef UNIT_H
#define UNIT_H

typedef struct {
    int x;
    int y;
} unit;

int get_x(unit* u);
int get_y(unit* u);
int set_x(unit* u, int x);
int set_y(unit* u, int y);

#endif