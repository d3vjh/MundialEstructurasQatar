#ifndef ORDENAMIENTO_H
#define ORDENAMIETNO_H

#include <iostream>
#include "Definicion.h"
using namespace std;


void intercambioS(goleador a[], int actual, int menor){
	int aux;
	string auxn;

	aux = a[actual].goles;
	auxn = a[actual].nombre;



	a[actual].goles=a[menor].goles;
	a[actual].nombre=a[menor].nombre;
	
	a[menor].goles=aux;
	a[menor].nombre=auxn;

}
void orden(goleador gol[],int tam)
{		
	int longitud;

	for(int m=0;m<tam;m++){
		
	  	longitud = m;
	  	if(gol[m].nombre==""){
				break;
			}
	}
	int min;

	for(int i=0;i<longitud;i++){//Iterador que ordena los numeros del arreglo
		min = i;

		for(int j=i+1;j<longitud;j++)
//		
			if(gol[j].goles>gol[min].goles)
				min = j;
			intercambioS(gol,i,min);
						
	}	


}


#endif
