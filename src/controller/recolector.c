#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../../include/TETRIS.h"
#include <windows.h>

// Inicializa el recolector de basura
RecolectorBasura* inicializar_recolector() {
    RecolectorBasura* recolector = (RecolectorBasura*)malloc(sizeof(RecolectorBasura));
    recolector->head = NULL;
    return recolector;
}

// Registra un puntero en el recolector de basura
void registrar_puntero(RecolectorBasura* recolector, void* ptr) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->ptr = ptr;
    nuevoNodo->siguiente = recolector->head;
    recolector->head = nuevoNodo;
}

// Libera todos los punteros registrados
void recolectar_basura(RecolectorBasura* recolector) {
    Nodo* actual = recolector->head;
    while (actual != NULL) {
        Nodo* temp = actual;
        free(actual->ptr); // Liberar la memoria asignada
        actual = actual->siguiente;
        free(temp); // Liberar el nodo
    }
    recolector->head = NULL;
}

// Libera el propio recolector de basura
void liberar_recolector(RecolectorBasura* recolector) {
    recolectar_basura(recolector); // Asegúrate de liberar todo
    free(recolector);
}
