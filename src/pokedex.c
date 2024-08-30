#include "pokedex.h"
#include <string.h>

struct pokedex {
	int no_idea_che;
};

struct pokedex *pokedex_crear()
{
	return NULL;
}

bool pokedex_agregar_pokemon(struct pokedex *pokedex, struct pokemon pokemon)
{
	return false;
}

size_t pokedex_cantidad_pokemones(struct pokedex *pokedex)
{
	return 0;
}

const struct pokemon *pokedex_buscar_pokemon(struct pokedex *pokedex,
					     const char *nombre)
{
	return NULL;
}


size_t pokedex_iterar_pokemones(struct pokedex *pokedex,
				bool (*funcion)(struct pokemon *, void *),
				void *ctx)
{
	return 0;
}

void pokedex_destruir(struct pokedex *pokedex)
{
}
