#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#define T 5
#define P 50


int main(void) {

	setbuf(stdout, NULL);

	    Tipo tipos[T];
	    Color colores[T];
	    Servicio servicios[T];
	    Bicicleta bicis[P];
	    Trabajo trabajos[P];

	    int opcion;
	    int retorno;
	    int opcionModificar;
	    int flagAlta = -1;
	    int flagModificar = -1;

	    inicializarBicisLibres(bicis, P);
	    inicializarListaTipo(tipos);
	    inicializarListaColores(colores);
	    inicializarListaServicios(servicios);
	    inicializarTrabajosLibres(trabajos, P);

	        do{
				if(utn_getNumero(&opcion, "\n1-Alta bicicleta\n2-Modificar bicicleta\n3-Baja bicicleta\n4-Listar bicicletas\n5"
						"-Listar tipos\n6-Listar colores\n7-Listar servicios\n8-Alta trabajo\n9-Listar trabajos\n10-Salir\n\nIngrese una opcion: ",
						"\nError ingrese una opcion valida\n", 1, 10, 50) == 0){}

					switch(opcion)
					{
						case 1:
							retorno = altaBicicleta(bicis, P, tipos, colores);
							if(retorno != -1)
							{
								SeparadorConGuionesCorto();
								printf("\nSe dio de alta exitosamente!!!\n\n");
								SeparadorConGuionesCorto();
								flagAlta = 1;
							}
							else
							{
								printf("\nNo hay mas espacio");
							}
						break;
						case 2:
							if(flagAlta == 1)
							{

								if(utn_getNumero(&opcionModificar, "\nQue desea modficar?\n1-Modificar tipo\n2-Modificar material\n\nIngrese opcion: ",
											"\nError ingrese una opcion valida\n", 1, 2, 50) == 0){}

									if(opcionModificar == 1)
									{
										retorno = modificarTipo(bicis, P, tipos);
										if(retorno == 1)
										{
											printf("\nSe modifico el tipo exitosamente!!!");
											flagModificar = 1;
										}
										else
										{
											printf("\nNo se pudo realizar la modificacion\n");
										}
									}
									else
									{
										retorno = modificarMaterial(bicis, P, tipos);
										if(retorno == 1)
										{
											printf("\nSe modifico el material exitosamente!!!\n");
											flagModificar = 1;
										}
										else
										{
											printf("\nNo se pudo realizar la modificacion\n");
										}
									}
							}
							else
							{
								printf("\nDebe dar de alta antes de poder hacer una modificacion\n");
							}
						break;
						case 3:
							if(flagModificar == 1)
							{
								retorno = bajaBicicleta(bicis, P, tipos);
								if(retorno == 1)
								{
									printf("\nSe dio de baja la bicicleta exitosamente!!!");
								}
								else
								{
									printf("\nNo se pudo realizar la baja");
								}
							}
							else
							{
								printf("\nDebe dar de alta antes de poder dar de baja\n");
							}
						break;
						case 4:
							if(flagAlta == 14)
							{
								SeparadorConGuionesCorto();
								mostrarListaBicicletas(bicis, P, tipos);
								SeparadorConGuionesCorto();
							}
							else
							{
								printf("\nDebe dar de alta antes de mostrar este listado\n");
							}
						break;
						case 5:
							mostrarListaTipos(tipos);
						break;
						case 6:
							mostrarListaColores(colores);
						break;
						case 7:
							mostrarListaServicios(servicios);
						break;
						case 8:
							retorno = altaTrabajo(trabajos, P, bicis, P, servicios, tipos);
							if(retorno == -1)
							{
								printf("\nNo se pudo realizar el trabajo\n");
							}
							else
							{
								printf("\nSe dio de alta el trabajo exitosamente!!!\n");
							}
						break;
						case 9:
							listarTrabajos(trabajos, P, bicis, P);
						break;
					}


	        }while(opcion != 10);

	return EXIT_SUCCESS;
}
