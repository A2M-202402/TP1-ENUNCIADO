#include "src/csv.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool leer_int(const char *str, void *ctx)
{
	return sscanf(str, "%d", (int *)ctx) == 1;
}

bool crear_string_nuevo(const char *str, void *ctx)
{
	char *nuevo = malloc(strlen(str) + 1);
	if (nuevo == NULL)
		return false;
	strcpy(nuevo, str);
	*(char **)ctx = nuevo;
	return true;
}

bool leer_caracter(const char *str, void *ctx)
{
	*(char *)ctx = *(char *)str;
	return true;
}

int main(int argc, char const *argv[])
{
	struct archivo_csv *archivo =
		abrir_archivo_csv("ejemplos/ejemplo.csv", ';');

	bool (*funciones[3])(const char *, void *) = { crear_string_nuevo,
						       leer_caracter,
						       leer_int };
	int entero;
	char caracter;
	char *string = NULL;
	void *punteros[3] = { &string, &caracter, &entero };

	printf("Leyendo lineas...\n");

	while (leer_linea_csv(archivo, 3, funciones, punteros) == 3) {
		printf("Entero: %d, String: %s, Caracter: %c\n", entero, string,
		       caracter);
		free(string);
	}

	printf("Fin de archivo\n");

	cerrar_archivo_csv(archivo);

	return 0;
}
