#include <stdio.h>
#include <string.h>
#include "servicio.h"
#include "inputs.h"

/*********************************************************************/

void inicializarListaServicios(Servicio listaServicios[])
{
	Servicio auxiliar[4] = {{20000, "Limpieza", 30}, {20001, "Parche", 400}, {20002, "Centrado", 500}, {20003,"Cadena", 450}};

		for(int i=0; i<4; i++)
		{
			listaServicios[i] = auxiliar[i];
		}
}

/*********************************************************************/

void mostrarListaServicios(Servicio listaServicios[])
{
	SeparadorConGuionesCorto();
	for(int i=0; i<4; i++)
	{
		printf("\nID: %d     Descripcion: %s     Precio: %.2f", listaServicios[i].id, listaServicios[i].descripcion, listaServicios[i].precio);
	}
	SeparadorConGuionesCorto();
}

/*********************************************************************/
