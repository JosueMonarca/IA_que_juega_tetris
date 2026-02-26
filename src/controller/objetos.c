#include <stdio.h>
#include <stdlib.h>

#define c_SIZE 4
#define p_SIZE 4
#define U_SIZE 5
#define L_SIZE 5
#define T_SIZE 4
#define Z_SIZE 4
#define S_SIZE 4

char tabla[22][22];

int c[c_SIZE][2];
int p[p_SIZE][2];
int u[U_SIZE][2];
int l[L_SIZE][2];
int t[T_SIZE][2];
int z[Z_SIZE][2];
int s[S_SIZE][2];

/**
 * Esta función toma un array de enteros y su tamaño como entrada,
 * y devuelve la suma de todos los elementos en el array.
 *
 * @param arr Un array de enteros.
 * @param size El número de elementos en el array.
 * @return La suma de los elementos en el array.
 */
void set_coordinates(int shape[][2], int size, int coords[][2]) {
    for (int i = 0; i < size; i++) {
        shape[i][0] = coords[i][0];
        shape[i][1] = coords[i][1];
    }
}
//nota el parametro rotacion no se usa 
//solo se puso para que el puntero a la funcion sea igual en todas las funciones
void coordenadas_de_c(int x, int y, int rotacion) {
    int coords[c_SIZE][2] = {
        {x, y}, {x + 1, y}, {x, y + 1}, {x + 1, y + 1}
    };
    set_coordinates(c, c_SIZE, coords);
}

void coordenadas_de_p(int y, int x, int rotacion) {
    int coords[p_SIZE][2];
    if (rotacion == 0) {
        int temp[p_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 3, x}
        };
        set_coordinates(coords, p_SIZE, temp);
    } else {
        int temp[p_SIZE][2] = {
            {y, x}, {y, x + 1}, {y, x + 2}, {y, x + 3}
        };
        set_coordinates(coords, p_SIZE, temp);
    }
    set_coordinates(p, p_SIZE, coords);
}

void coordenadas_de_u(int y, int x, int rotacion) {
    int coords[U_SIZE][2];
    if (rotacion == 0) {
        int temp[U_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 2, x + 1}, {y + 2, x + 2}
        };
        set_coordinates(coords, U_SIZE, temp);
    } else if (rotacion == 1) {
        int temp[U_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 1, x + 1}, {y + 1, x + 2}, {y, x + 2}
        };
        set_coordinates(coords, U_SIZE, temp);
    } else if (rotacion == 2) {
        int temp[U_SIZE][2] = {
            {y, x}, {y, x + 1}, {y + 1, x}, {y + 2, x}, {y + 2, x + 1}
        };
        set_coordinates(coords, U_SIZE, temp);
    } else {
        int temp[U_SIZE][2] = {
            {y, x + 2}, {y + 1, x}, {y + 1, x + 1}, {y + 1, x + 2}, {y, x}
        };
        set_coordinates(coords, U_SIZE, temp);
    }
    set_coordinates(u, U_SIZE, coords);
}

void coordenadas_de_L(int y, int x, int rotacion) {
    int coords[L_SIZE][2];
    if (rotacion == 0) {
        int temp[L_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 3, x}, {y + 3, x - 1}
        };
        set_coordinates(coords, L_SIZE, temp);
    } else if (rotacion == 1) {
        int temp[L_SIZE][2] = {
            {y, x}, {y, x + 1}, {y, x + 2}, {y, x + 3}, {y + 1, x + 3}
        };
        set_coordinates(coords, L_SIZE, temp);
    } else if (rotacion == 2) {
        int temp[L_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 3, x}, {y, x + 1}
        };
        set_coordinates(coords, L_SIZE, temp);
    } else {
        int temp[L_SIZE][2] = {
            {y, x}, {y, x + 1}, {y, x + 2}, {y, x + 3}, {y - 1, x}
        };
        set_coordinates(coords, L_SIZE, temp);
    }
    set_coordinates(l, L_SIZE, coords);
}

void coordenadas_de_t(int y, int x, int rotacion) {
    int coords[T_SIZE][2];
    if (rotacion == 0) {
        int temp[T_SIZE][2] = {
            {y, x}, {y, x + 1}, {y, x + 2}, {y + 1, x + 1}
        };
        set_coordinates(coords, T_SIZE, temp);
    } else if (rotacion == 1) {
        int temp[T_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 1, x - 1}
        };
        set_coordinates(coords, T_SIZE, temp);
    } else if (rotacion == 2) {
        int temp[T_SIZE][2] = {
            {y, x}, {y, x + 1}, {y, x + 2}, {y - 1, x + 1}
        };
        set_coordinates(coords, T_SIZE, temp);
    } else {
        int temp[T_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 2, x}, {y + 1, x + 1}
        };
        set_coordinates(coords, T_SIZE, temp);
    }
    set_coordinates(t, T_SIZE, coords);
}

void coordenadas_de_z(int y, int x, int rotacion) {
    int coords[Z_SIZE][2];
    if (rotacion == 0) {
        int temp[Z_SIZE][2] = {
            {y, x}, {y, x + 1}, {y + 1, x + 1}, {y + 1, x + 2}
        };
        set_coordinates(coords, Z_SIZE, temp);
    } else {
        int temp[Z_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 1, x - 1}, {y + 2, x - 1}
        };
        set_coordinates(coords, Z_SIZE, temp);
    }
    set_coordinates(z, Z_SIZE, coords);
}

void coordenadas_de_s(int y, int x, int rotacion) {
    int coords[S_SIZE][2];
    if (rotacion == 0) {
        int temp[S_SIZE][2] = {
            {y, x}, {y, x + 1}, {y + 1, x}, {y + 1, x - 1}
        };
        set_coordinates(coords, S_SIZE, temp);
    } else {
        int temp[S_SIZE][2] = {
            {y, x}, {y + 1, x}, {y + 1, x + 1}, {y + 2, x + 1}
        };
        set_coordinates(coords, S_SIZE, temp);
    }
    set_coordinates(s, S_SIZE, coords);
}
