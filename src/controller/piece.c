#include "../../include/PIECE.h"
#include "../../include/UNIT.h"

unit unit_basic = {
    .x = 0,
    .y = 0
};

const PIECE piece_C = {
    .type = 'C',
    .size = 4,
    .blocks = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0}
    }
};

const PIECE piece_P = {
    .type = 'P',
    .size = 5,
    .blocks = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {3, 1}
    }
};

const PIECE piece_U = {
    .type = 'U',
    .size = 5,
    .blocks = {
        {0, 0},
        {1, 0},
        {2, 0},
        {2, 1},
        {2, 2}
    }
};

const PIECE piece_L = {
    .type = 'L',
    .size = 5,
    .blocks = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {3, -1}
    }
};

const PIECE piece_T = {
    .type = 'T',
    .size = 4,
    .blocks = {
        {0, 0},
        {1, 0},
        {2, 0},
        {1, 1}
    }
};

const PIECE piece_Z = {
    .type = 'Z',
    .size = 4,
    .blocks = {
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 2}
    }
};

const PIECE piece_S = {
    .type = 'S',
    .size = 4,
    .blocks = {
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 1}
    }
};

int get_size(PIECE* p){
    return p->size;
}

char get_type(PIECE* p){
    return p->type;
}

void set_type(PIECE* p, char type){
    p->type = type;
}

void move_piece(PIECE* P, int direction){
    for(int i = 0; i < P->size; i++){
        if(direction == RIGHT){
            P->blocks[i].y += 1;
        } else if(direction == LEFT){
            P->blocks[i].y -= 1;
        } else if(direction == DOWN){
            P->blocks[i].x += 1;
        } else if(direction == UP){
            P->blocks[i].x -= 1;
        }
    }
}

void rotate_piece(PIECE* P, int direction){
    if(P->type == 'O') return; // La pieza O no rota

    int center_x = P->blocks[0].x;
    int center_y = P->blocks[0].y;

    for(int i = 0; i < P->size; i++){
        int x = P->blocks[i].x - center_x;
        int y = P->blocks[i].y - center_y;

        if(direction == ROTATE_RIGHT){
            P->blocks[i].x = center_x - y;
            P->blocks[i].y = center_y + x;
        } else if(direction == ROTATE_LEFT){
            P->blocks[i].x = center_x + y;
            P->blocks[i].y = center_y - x;
        }
    }
}

