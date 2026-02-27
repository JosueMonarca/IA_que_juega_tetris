#include "../../include/UNIT.h";

int get_x(unit* u){
    return u->x;
}

int get_y(unit* u){
    return u->y;
}

int set_x(unit* u, int x){
    u->x = x;
    return 0;
}

int set_y(unit* u, int y){
    u->y = y;
    return 0;
}