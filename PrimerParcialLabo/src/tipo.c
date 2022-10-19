#include <stdio.h>
#include <string.h>
#include "tipo.h"
#include "inputs.h"

/*********************************************************************/

void inicializarListaTipo(Tipo listaTipo[])
{
	Tipo auxiliar[4] = {{1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"}, {1003,"BMX"}};

		for(int i=0; i<4; i++)
		{
				listaTipo[i] = auxiliar[i];
		}
}

/*********************************************************************/

void mostrarListaTipos(Tipo listaTipos[])
{
	SeparadorConGuionesCorto();
	for(int i=0; i<4; i++)
	{
		printf("\nID: %d     Descripcion: %s", listaTipos[i].id, listaTipos[i].descripcion);
	}
	SeparadorConGuionesCorto();
}

/*********************************************************************/
