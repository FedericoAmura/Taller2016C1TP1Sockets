#ifndef LISTA_H
#define LISTA_H
#include <stdbool.h>
#include <stddef.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS
 * *****************************************************************/

/* La lista está planteada como una lista que guarda void* enlazados */

typedef struct lista lista_t;
typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/


/* Primitivas basicas */

// Crea una lista.
// Post: devuelve una nueva lista vacía.
lista_t *lista_crear();

// Devuelve verdadero o falso, según si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista);

// Inserta un elemento al final de la lista
// Pre: la lista fue creada.
// Post: se agrega el elemento al final de la lista.
int lista_insertar_ultimo(lista_t *lista, void *dato);

// Saca el primer elemento de la lista y lo devuelve
// Pre: la lista fue creada.
// Post: se devolvió el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacía.
void *lista_borrar_primero(lista_t *lista);

// Destruye la lista
// Pre: la lista fue creada
// Post: se destruye la lista
void lista_destruir(lista_t *lista);

/* Primitivas de iterador externo */

// Crea un iterador externo asociado a una lista.
// Pre: La lista fue creada.
// Post: Se devuelve un iterador apuntando al primer elemento de la lista.
// Si la lista estuviese vacia, se devuelve NULL.
lista_iter_t *lista_iter_crear(const lista_t *lista);

// Mueve el iterador al siguiente elemento de la lista.
// Pre: El iterador y la lista correspondiente fueron creados.
// Post: Se devuelve 0 y el iterador apunta al siguiente elemento
// o 1 en caso de estar en el final de la lista.
int lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el valor al que esta apuntando el iterador.
// Pre: El iterador y la lista correspondiente fueron creados.
// Post: Se devuelve el dato al que se encontraba apuntando el iterador.
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Destruye el iterador.
// Pre: El iterador fue creado.
// Post: Se libera la memoria del iterador.
void lista_iter_destruir(lista_iter_t *iter);

#endif // LISTA_H
