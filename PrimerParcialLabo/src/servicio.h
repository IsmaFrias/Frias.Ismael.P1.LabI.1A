#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}Servicio;

/*
 * muestra la lista de servicios hardcodeados
 * Parametro: lista de servicios
 */
void inicializarListaServicios(Servicio listaServicios[]);

/*
 * muestra la lista de servicios
 * Parametro: lista de servicios
 */
void mostrarListaServicios(Servicio listaServicios[]);

#endif /* SERVICIO_H_ */
