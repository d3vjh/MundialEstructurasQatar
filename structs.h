#ifndef STRUCTS_H
#define STRUCTS_H
#include <cstring>
#include "lista.h"

using namespace std;

struct estadio{
	string nombreEstadio;
	int capacidad;
	string ciudad;
};

struct equipo{
	string nombre;
	string entrenador;
	string confederacion;
	
//	Lista<jugador> j;
};

struct programacion{
	estadio estadio1;
	equipo equipo1;
	equipo equipo2;
	string hora;
		
};

struct jugador{
	string nombre;
	string nacionalidad;
	string fechaDeNacimiento;
	int estatura;
	float edad;
	string club;
	string posicion;
	int golesAnotados;
	int fechasSancion; //Se almacena N fechas Fifa
};


//


struct primeraFase{
	char grupo;
	List<equipo> e;
	List<programacion> p;
};

struct segundaFase{
	programacion pr;
	List<equipo> e; //Solo dos equipos
	
};




#endif
