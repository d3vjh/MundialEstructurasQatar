#ifndef STRUCTS_H
#define STRUCTS_H
#include <cstring>
#include "lista.h"

using namespace std;
struct tarjeta{
	
	string color;
	int dia;
	int mes;
	int anio;
	string motivo;
	string contrincante;	
};

struct jugador{
	string nombre;
	string posicion;
	int edad;
	string talla;
	Lista <tarjeta> t;
};


//
//struct equipo{
//	string nombre;
//	 string entrenador;
//	 string confederacion;
//	 Lista<jugador> j;
//};



#endif
