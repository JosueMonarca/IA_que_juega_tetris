#ifndef CABECERA_H
#define CABECERA_H

//se definen las funciones de tiempo
int conv_seg_min(int segundos,int minutos, int operacion);

//se define la funcion para recargar la pantalla
void draw();

// se define las coordenadas de el cuadrado
void coordenadas_de_cuadrado (int x, int y);

//se definen la funcion para las coordenadas de el palo
void coordenadas_de_el_palo(int x, int y, int rotacion);

//se define el cuadrado 
extern int cuadrado[4][2];

//se define la estructura para la figura palo
extern int palo[22][22];

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

#endif // CABECERA_H