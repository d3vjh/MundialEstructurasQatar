/**
 * \structs.h
 * \author Jhonatan Moreno - Santiago Avila - Hanna Sarmiento
 * \date Diciembre - 2022
 */


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

struct tarjeta{
	
	string idNomPais;
	string idNumJugador;
	string idNombreJugador;
	string color;
	string fecha;
	string motivo;
	string contrincante;	
};

struct jugador{
	
	int numero;
	string nombre;
	string nacionalidad;
	string fechaDeNacimiento;
	int estatura;
	int edad;
	string club;
	string posicion;
	int golesAnotados;
	int fechasSancion; //Se almacena N fechas Fifa
	List<tarjeta> tarjetas;
};




struct equipo{
	string nombre;
	string entrenador;
	string confederacion;
	
	List<jugador> futbolistas;
};

struct programacion{
	estadio estadio1;
	equipo equipo1;
	equipo equipo2;
	string hora;
		
};



//


struct primeraFase{
	char grupo;
	List<equipo> e;
	List<programacion> p;
};

//Arbol

struct nodoArbol{
	
	equipo Equipo1; 
	bool esGanador;	
	
};




#endif
