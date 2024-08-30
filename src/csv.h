#ifndef CSV_H
#define CSV_H

#include <stdlib.h>
#include <stdbool.h>

struct archivo_csv;

/**
 * Intenta abrir un archivo CSV para su posterior lectura. 
 * El separador indica el caracter que separa las columnas dentro del archivo.
 * 
 * Devuelve un puntero a un archivo_csv en caso de éxito, o NULL en caso de error.
 */
struct archivo_csv *abrir_archivo_csv(const char *nombre_archivo,
				      char separador);

/**
 * Lee una línea del archivo CSV.
 * 
 * Se debe especificar la cantidad de columnas que se esperan leer.
 * Por cada columna se debe especificar una función que se encargará de convertir
 * el valor leído a un tipo específico. Adicionalmente, se debe especificar un puntero
 * a un contexto que será pasado a cada una de las funciones.
 * 
 * Las funciones de parseo reciben el string leído y un puntero al contexto. Devuelven true si
 * el valor pudo ser parseado correctamente, o false en caso contrario.
 * 
 * Devuelve la cantidad de columnas leídas correctamente.
 */
size_t leer_linea_csv(struct archivo_csv *archivo, size_t columnas,
		      bool (*funciones[])(const char *, void *), void *ctx[]);

/**
 * Cierra un archivo CSV previamente abierto.
 */
void cerrar_archivo_csv(struct archivo_csv *archivo);

#endif // CSV_H
