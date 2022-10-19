#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "bicicleta.h"
#include "color.h"

/****************************************************************************/

void inicializarBicisLibres(Bicicleta bicis[], int sizeBicis)
{
		for(int i=0; i<sizeBicis; i++)
		{
			bicis[i].id = 0;
		}
}

/****************************************************************************/

int buscarLugarLibre(Bicicleta bicis[], int sizeBicis)
{
	int index;
	index = -1;

	for(int i=0; i<sizeBicis; i++)
	{
		if(bicis[i].id == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

/****************************************************************************/

int altaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[])
{
	int index;

		index = buscarLugarLibre(bicis, sizeBicis);

		if(index != -1)
		{
			if(utn_getNumero(&bicis[index].id, "\nIngrese ID de bicicleta:  ",
								"\nError ingrese un id valido", 0, 100000, 500)==0){}
			PedirCadena(bicis[index].marca, "\nIngrese marca de la bicicleta: ");

			mostrarListaTipos(listaTipos);
			if(utn_getNumero(&bicis[index].idTipo, "\nIngrese ID de tipo:  ",
								"\nError ingrese un id valido", 1000, 1003, 500)==0){}
			mostrarListaColores(listaColor);
			if(utn_getNumero(&bicis[index].idColor, "\nIngrese ID del color:  ",
								"\nError ingrese un id valido", 5000, 5004, 500)==0){}
			PedirCadena(bicis[index].material, "\nIngrese material (c -> carbono / a -> aluminio: ");
		}

	return index;
}

/****************************************************************************/

void mostrarListaBicicletas(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	for(int i=0; i<sizeBicis-1; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(bicis[i].id != 0 && bicis[i].idTipo == listaTipos[j].id)
			{
				printf("\nID Bici: %d     Material: %s      Tipo: %s", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
			}
		}
	}
}

/****************************************************************************/

int modificarTipo(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idIngresado;
	int idNuevoTipo;
	int retorno = -1;

	    SeparadorConGuionesCorto();
	    mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
		SeparadorConGuionesCorto();
		if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta: ",
						"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

			for(int i=0; i<sizeBicis; i++)
			{
				if(bicis[i].id == idIngresado)
				{
					mostrarListaTipos(listaTipos);
					if(utn_getNumero(&idNuevoTipo, "\nIngrese el nuevo ID del tipo: ",
									"\nError ingrese un ID valido: \n", 1000, 1003, 50) == 0){}
					bicis[i].idTipo = idNuevoTipo;
					retorno = 1;
					break;
				}
				else
				{
					printf("\nNo se econtro el ID ingresado\n");
					break;
				}
			}

	return retorno;
}

/****************************************************************************/

int modificarMaterial(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idIngresado;
	int retorno = -1;

		    SeparadorConGuionesCorto();
		    mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta: ",
							"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id == idIngresado)
					{
						PedirCadena(bicis[i].material, "\nIngrese nuevo material (c -> carbono / a -> aluminio: ");
						retorno = 1;
						break;
					}
					else
					{
						printf("\nNo se econtro el ID ingresado\n");
						break;
					}
				}

		return retorno;
}

/****************************************************************************/

int bajaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int retorno = -1;
	int idIngresado;

			SeparadorConGuionesCorto();
			mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta a dar de baja: ",
								"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

			for(int i=0; i<sizeBicis; i++)
			{
				if(bicis[i].id == idIngresado)
			    {
					bicis[i].id = 0;
					retorno = 1;
					break;
				}
				else
				{
					printf("\nNo se econtro el ID ingresado");
				}
			}

	return retorno;
}
