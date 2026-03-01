#ifndef TABLE_H
#define TABLE_H
#define HIGHT 22
#define WIDTH 22

typedef struct 
{
    int hight;
    int width;
    int table[HIGHT][WIDTH];
}TABLE;

void init_table(TABLE* t);

#endif