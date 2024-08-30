#ifndef POKEDEX_H
#define POKEDEX_H

#include <stdlib.h>
#include <stdbool.h>

#define TIPO_AGUA 'A'
#define TIPO_FUEGO 'F'
#define TIPO_PLANTA 'P'
#define TIPO_ROCA 'R'
#define TIPO_ELECTRICO 'E'
#define TIPO_NORMAL 'N'
#define TIPO_LUCHA 'L'

struct pokemon {
	char *nombre;
	char tipo;
	int fuerza;
	int destreza;
	int resistencia;
};

struct pokedex;

/**
 * Crea una nueva pokedex.
*/
struct pokedex *pokedex_crear();

/**
 * Agrega un pokemon a la pokedex.
 * 
 * Devuelve true si el pokemon fue agregado correctamente, o false en caso contrario.
*/
bool pokedex_agregar_pokemon(struct pokedex *pokedex, struct pokemon pokemon);

/**
 * Devuelve la cantidad de pokemones en la pokedex.
*/
size_t pokedex_cantidad_pokemones(struct pokedex *pokedex);

/**
 * Busca un pokemon con el nombre especificado en la pokedex.
 * 
 * Devuelve un puntero al pokemon si se encontró, o NULL en caso contrario.
*/
const struct pokemon *pokedex_buscar_pokemon(struct pokedex *pokedex,
					     const char *nombre);

/**
 * Invoca la función especificada para cada pokemon en la pokedex.
 * 
 * La función se debe invocar a los pokemon ordenados por nombre de manera creciente.
 * 
 * La función de iteración recibe un puntero al pokemon y un puntero al contexto y devuelve 
 * true si se debe seguir iterando, o false en caso contrario.
 * 
 * Devuelve la cantidad de pokemones iterados.
*/
size_t pokedex_iterar_pokemones(struct pokedex *pokedex,
				bool (*funcion)(struct pokemon *, void *),
				void *ctx);

/**
 * Destruye la pokedex.
*/
void pokedex_destruir(struct pokedex *pokedex);

#endif // POKEDEX_H
