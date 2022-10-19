#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"
#include "tipo.h"


/****************************************************************************/

void inicializarTrabajosLibres(Trabajo trabajos[], int sizeTrabajos)
{
		for(int i=0; i<sizeTrabajos; i++)
		{
			trabajos[i].id = 0;
		}
}

/****************************************************************************/

int buscarLugarLibreTrabajo(Trabajo trabajos[], int sizeTrabajos)
{
	int index;
	index = -1;

	for(int i=0; i<sizeTrabajos; i++)
	{
		if(trabajos[i].id == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

/****************************************************************************/

int altaTrabajo(Trabajo trabajos[], int sizeTrabajos, Bicicleta bicis[], int sizeBicis, Servicio listaServicios[], Tipo listaTipos[])
{
	int index;
	int idIngresado;

		index = buscarLugarLibreTrabajo(trabajos, sizeTrabajos);

		if(index != -1)
		{
			if(utn_getNumero(&trabajos[index].id, "\nIngrese ID del trabajo:  ",
								"\nError ingrese un id valido", 0, 100000, 500)==0){}

			SeparadorConGuionesCorto();
			mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta:  ",
								"\nError ingrese un id valido", 0, 100000, 500)==0){}

				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id == idIngresado)
					{
							trabajos[i].idBicicleta = idIngresado;
							mostrarListaServicios(listaServicios);

							if(utn_getNumero(&trabajos[index].idServicio, "\nIngrese ID del servicio:  ",
												"\nError ingrese un id valido", 20000, 20003, 500)==0){}


							if(utn_getNumero(&trabajos[index].fecha.dia, "\nIngrese dia:  ",
												"\nError ingrese un dia valido", 1, 31, 500)==0){}
							if(utn_getNumero(&trabajos[index].fecha.mes, "\nIngrese mes:  ",
												"\nError ingrese un mes valido", 1, 12, 500)==0){}
							if(utn_getNumero(&trabajos[index].fecha.anio, "\nIngrese año:  ",
												"\nError ingrese un anio valido", 2000, 2050, 500)==0){}
							break;
					}
					else
					{
						printf("\nNo se encontro el ID\n");
						break;
					}
				}

		}

	return index;
}

/****************************************************************************/

void listarTrabajos(Trabajo trabajos[], int sizeTrabajos, Bicicleta bicis[], int sizeBicis)
{
	for(int i=0; i<sizeTrabajos-1; i++)
	{
		for(int j=i+1; j<sizeTrabajos; j++)
		{
			if(trabajos[i].idBicicleta == bicis[j].id && bicis[j].id != 0)
			{
				printf("\nID trabajo: %d     Material: %s      Marca: %s     Fecha: %d/%d/%d", trabajos[i].id, bicis[i].material, bicis[j].marca,
																							  trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
			}
		}
	}
}
