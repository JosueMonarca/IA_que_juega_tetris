#include <stdio.h>
#include <stdlib.h>

struct S_Cuadrado {
    const char forma[4][4];
    int x_1,y_1;
    int x_2,y_2;
    int x_3,y_3;
    int x_4,y_4;
    int x_5,y_5;
    int x_6,y_6;
    int x_7,y_7;
    int x_8,y_8;
    int x_9,y_9;
    int x_10,y_10;
    int x_11,y_11;
    int x_12,y_12;
};

struct S_Cuadrado cuadrado =
{
    {
        {'#','#','#','#'},
        {'#',' ',' ','#'},
        {'#',' ',' ','#'},
        {'#','#','#','#'}
    },
    1,1,
    1,2,
    1,3,
    1,4,
    2,1,
    2,4,
    3,1,
    3,4,
    4,1,
    4,2,
    4,3,
    4,4
};

