#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "tipo.h"

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	int id;
	int idBicicleta; //Debe existir, validar
	int idServicio; //Debe existir, validar
	Fecha fecha;
}Trabajo;

/*
 * inicializa la lista de trabajos en 0 por defecto
 * Parametro: lista de trabajos, tamaño de la lista
 */
void inicializarTrabajosLibres(Trabajo trabajos[], int sizeTrabajos);

/*
 * busca lugar libre en la lista
 * Parametro: lista de trabajos, tamaño de la lista
 */
int buscarLugarLibreTrabajo(Trabajo trabajos[], int sizeTrabajos);

/*
 * da de alta un trabajo
 * Parametro: lista de trabajos, lista de bicicleta, lista de servicios, tamaños de las listas
 */
int altaTrabajo(Trabajo trabajos[], int sizeTrabajos, Bicicleta bicis[], int sizeBicis, Servicio listaServicios[], Tipo listaTipos[]);

/*
 * muestra una lista de trabajos
 * Parametro: lista de trabajos, lista de bicicletas, tamaño de la lista
 */
void listarTrabajos(Trabajo trabajos[], int sizeTrabajos, Bicicleta bicis[], int sizeBicis);

#endif /* TRABAJO_H_ */
