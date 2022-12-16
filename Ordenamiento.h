/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */

#ifndef ORDENAMIENTO_H
#define ORDENAMIETNO_H

#include <iostream>
#include "Definicion.h"
using namespace std;
//Esta libreria realiza el ordenamiento de los jugadores por el algoritmo de seleccion

//Metodo que recibe como parametros un arreglo de tipo goleado, una posicion actual, y la posicion menor

void intercambioS(goleador a[], int actual, int menor){
	
	//Bloque de codigo que realiza el intercambio 
	int aux;
	string auxn;

	aux = a[actual].goles;
	auxn = a[actual].nombre;



	a[actual].goles=a[menor].goles;
	a[actual].nombre=a[menor].nombre;
	
	a[menor].goles=aux;
	a[menor].nombre=auxn;

}

//Metodo que recibe un arreglo de tipo goleador y el tamaño del arreglo
void orden(goleador gol[],int tam)
{		
	int longitud;
	//Iterador que permite controlar los espacios vacios y no imprimir datos erroneos
	for(int m=0;m<tam;m++){
		
	  	longitud = m;
	  	//Condicional que detiene el iterador tan pronto no encuentre mas goleadores
	  	if(gol[m].nombre==""){
				break;
			}
	}
	int min;

	for(int i=0;i<longitud;i++){//Iterador que recorre el arreglo y realiza las comparaciones, llama al metodo intercambio para ordenar
		min = i;

		for(int j=i+1;j<longitud;j++)
//		
			if(gol[j].goles>gol[min].goles)
				min = j;
			intercambioS(gol,i,min);
						
	}	


}





#endif
