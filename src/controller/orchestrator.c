#include "../../include/ORCHESTRATOR.h"
#include "../../include/TABLE.h"
#include "../../include/PIECE.h"

int check_colision(TABLE* t, PIECE* p){
    int colision = FALSE;
    for(int i = 0; i < p ->size; i++){
        if(p->blocks[i].x <= 0 || p->blocks[i].x >= t->width || p->blocks[i].y <= 0 || p->blocks[i].y >= t->hight){
            return TRUE;
        }
    }

    for (int i = 0; i < p -> size; i++) {
        int x = p->blocks[i].x;
        int y = p->blocks[i].y;
        if (t->table[x][y] != 0) {
            colision = TRUE;
            break;
        }
    }
    return colision;
}

int move_simple(PIECE* p, int add_or_subs, TABLE* t, int cardinality){
    PIECE temp = *p;

    // 1. Movemos el clon (este for tuyo está perfecto)
    for(int i = 0; i < p ->size;i++){
        if(cardinality == HORIZONTAL){
            temp.blocks[i].x += add_or_subs;
        }else{
            temp.blocks[i].y += add_or_subs;
        }
    }

    // 2. Checamos si el clon chocó
    if(check_colision(t, &temp) == TRUE){
        return FALSE; // Chocó, abortamos misión
    } else {
        *p = temp;    // ¡Magia! Pisamos la pieza vieja con el clon validado
    }
    
    return TRUE; // Éxito
}

int move_piece_in_table(PIECE* p, int direction, TABLE* t){
    switch (direction){
    case UP:
        return move_simple(p, -1, t, VERTICAL);
        break;
    case DOWN:
        return move_simple(p, 1, t, VERTICAL);
        break;
    case LEFT:
        return move_simple(p, -1, t, HORIZONTAL);
        break;
    case RIGHT:
        return move_simple(p, 1, t, HORIZONTAL);
        break;
    default:
    return -1;
        break;
    }
}

int rotate_piece_with_verification(PIECE* p, int direction, TABLE* t){
    PIECE temp = *p;

    switch (direction)
    {
    case ROTATE_RIGHT:
        rotate_piece(&temp, ROTATE_RIGHT);
        if(check_colision(t, &temp) == TRUE){return FALSE;}
        else{
            rotate_piece(p, ROTATE_RIGHT);
            return TRUE;
        }
        break;
    case ROTATE_LEFT:
        rotate_piece(&temp, ROTATE_LEFT);
        if(check_colision(t, &temp) == TRUE){return FALSE;}
        else{
            rotate_piece(p, ROTATE_LEFT);
            return TRUE;
        }
        break;
    default:
    return -1;
        break;
    }
}

void delete_rows(TABLE* t){
    for(int i = 1; i < t->hight - 1; i++){
        int full_row = TRUE;
        for(int j = 1; j < t->width - 1; j++){
            if(t->table[i][j] == 0){
                full_row = FALSE;
                break;
            }
        }
        if(full_row == TRUE){
            for(int k = i; k > 0; k--){
                for(int l = 0; l < t->width; l++){
                    t->table[k][l] = t->table[k-1][l];
                }
            }
            for(int l = 0; l < t->width; l++){
                t->table[0][l] = 0;
            }
        }
    }
}

void lock_piece(TABLE* t, PIECE* p){
    for(int i = 0; i < p->size; i++){
        int x = p->blocks[i].y;
        int y = p->blocks[i].x;
        t->table[x][y] = 1;
    }
    delete_rows(t);
}

void set_piece_position(PIECE* p, int x, int rotacion){
    for(int i = 0; i < p->size; i++){
        p->blocks[i].x = p->blocks[i].x + x;
        p->blocks[i].y = p->blocks[i].y + 1;
    }
    for(int i = 0; i < rotacion; i++){
        rotate_piece(p, ROTATE_RIGHT);
    }
}