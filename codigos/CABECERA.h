#ifndef CABECERA_H
#define CABECERA_H

//se definen las funciones de tiempo
int conv_seg_min(int segundos,int minutos, int operacion);

//se define la funcion para recargar la pantalla
void draw();

// se define las coordenadas de el cuadrado
void coordenadas_de_cuadrado (int x, int y);

//se define el cuadrado 
extern int cuadrado[4][2];

//se define el palo
extern int palo[4][2];

//se define la u
extern int u[5][2];

//se define a "l"
extern int l[5][2];

//se define a "t"
extern int t[4][2];

//se define Las coordenadas de la T
void coordenadas_de_t(int y, int x, int rotacion);

//se define las coordenadas de la L
void coordenadas_de_L(int y, int x, int rotacion);

//se define las ccordenadas de la L
void coordenadas_de_u (int y, int x, int rotacion);

//se define las coordenadas del palo
void coordenadas_de_palo (int y, int x, int rotacion);

//se define la tabla
extern char tabla[22][22];

//se define la funcion ocultar_cursor
void ocultar_cursor();

//se define la funcion mover_cursor
void mover_cursor(int x, int y);

//se define la funcion colicion
int colicion();


// Estructura para almacenar punteros a las figuras
typedef struct Nodo {
    void* ptr;           // Puntero a la memoria asignada
    struct Nodo* siguiente; // Puntero al siguiente nodo
} Nodo;

// Estructura de recolector de basura
typedef struct {
    Nodo* head; // Puntero al primer nodo de la lista
} RecolectorBasura;

// Funciones del recolector de basura
RecolectorBasura* inicializar_recolector();
void registrar_puntero(RecolectorBasura* recolector, void* ptr);
void recolectar_basura(RecolectorBasura* recolector);
void liberar_recolector(RecolectorBasura* recolector);

void mover_figura();

#endif // CABECERA_H
