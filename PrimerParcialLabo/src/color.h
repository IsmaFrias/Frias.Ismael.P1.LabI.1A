#ifndef COLOR_H_
#define COLOR_H_

typedef struct
{
	int id;
	char nombreColor[20];
}Color;

/*
 * inicializa la lista de colores hardcodeados
 * Parametro: lista de colores
 */
void inicializarListaColores(Color listaColor[]);

/*
 * muestra la lista de colores
 * Parametro: lista de colores
 */
void mostrarListaColores(Color listaColor[]);

#endif /* COLOR_H_ */
