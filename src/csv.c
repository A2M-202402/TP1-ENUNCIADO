#include "csv.h"
#include <stdio.h>
#include <string.h>

struct archivo_csv {
	int no_se_que_va_acá;
};

struct archivo_csv *abrir_archivo_csv(const char *nombre_archivo,
				      char separador)
{
	return NULL;
}

size_t leer_linea_csv(struct archivo_csv *archivo, size_t columnas,
		      bool (*funciones[])(const char *, void *), void *ctx[])
{
	return 0;
}

void cerrar_archivo_csv(struct archivo_csv *archivo)
{

}
