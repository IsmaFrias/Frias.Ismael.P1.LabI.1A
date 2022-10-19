#include <stdio.h>
#include <string.h>
#include "color.h"
#include "inputs.h"

/*********************************************************************/

void inicializarListaColores(Color listaColor[])
{
	Color auxiliar[5] = {{5000, "Gris"}, {5001, "Blanco"}, {5002, "Azul"}, {5003,"Negro"}, {5004,"Rojo"}};

		for(int i=0; i<5; i++)
		{
			listaColor[i] = auxiliar[i];
		}
}

/*********************************************************************/

void mostrarListaColores(Color listaColor[])
{
	SeparadorConGuionesCorto();
	for(int i=0; i<5; i++)
	{
		printf("\nID: %d     Color: %s", listaColor[i].id, listaColor[i].nombreColor);
	}
	SeparadorConGuionesCorto();
}

/*********************************************************************/
