#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int id;
	char descripcion[20];
}Tipo;

/*
 * inicializa la lista de tipos con los tipos harcodeados
 * Parametro: lista de tipos
 */
void inicializarListaTipo(Tipo listaTipo[]);

/*
 * muestra la lista de tipos
 * Parametro: lista de tipos
 */
void mostrarListaTipos(Tipo listaTipos[]);

#endif /* TIPO_H_ */
