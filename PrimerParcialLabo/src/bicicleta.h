#ifndef BICICLETA_H_
#define BICICLETA_H_
#include "tipo.h"
#include "color.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material[20]; // “c” carbono, “a” aluminio
}Bicicleta;

/*
 * Inicializa la lista de bicicletas en 0
 * Parametro: lista de bicicletas
 */
void inicializarBicisLibres(Bicicleta bicis[], int sizeBicis);

/*
 * busca un lugar libre en el array de bicicletas
 * Parametro: lista de bicicletas
 */
int buscarLugarLibre(Bicicleta bicis[], int sizeBicis);

/*
 * muestra lista de bicicletas dadas de alta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarListaBicicletas(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * da de alta una bicicleta
 * Parametro: lista de bicicletas, lista de tipos, lista de color, tamaño de la lista
 */
int altaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[]);

/*
 * modifica el tipo de bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int modificarTipo(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * modifica el material de bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int modificarMaterial(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * da de baja una bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int bajaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

#endif /* BICICLETA_H_ */
