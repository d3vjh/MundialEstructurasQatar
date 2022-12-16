/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */


#ifndef STRUCTS_H
#define STRUCTS_H
#include <cstring>
//Libreria importada
#include "lista.h"

using namespace std;

//Estrutura de tipo Estadio
struct estadio{
	string nombreEstadio;//String para el nombre del estadio
	int capacidad;//Entero para la capacidad del estadio
	string ciudad;//String para la ciudad donde esta ubicado el estadio
};
//Estructura de tipo tarjeta
struct tarjeta{
	string color;//String para el color de la tarjeta
	int dia;//Int para el dia
	int mes;//Int para el mes
	int anio;//Int para el año
	string motivo;//String para registrar el motivo
	string contrincante;//String para el equipo contrincante
};
//Estructura de tipo jugador
struct jugador{
	string nombre;//String para el nombre completo del jugador
	string nacionalidad;//String para la nacionalidad del jugador
	string fechaDeNacimiento;//String para la fecha de nacimiento del jugador
	int estatura;//Entero para la estatura en cm del jugador
	int edad;//Entero para la edad del jugador
	string club;//String para el club en el que juega el jugador
	string posicion;//String para la posicion que tomara el jugador
	int golesAnotados;//Entero para los goles anotados
	int fechasSancion; //Entero para registrar las fechas de sancion
	List<tarjeta> tarjetas;//Estructura de datos lista de tipo tarjetas para registra las diferentes tarjetas
};
//Estructura de tipo tecnico
struct tecnico{
	string nombre;//String para el nombre completo del tecnico
	string nacionalidad;//String para la nacionalidad del tecnico
	string equipo;//String para el equipo que dirige del tecnico
};
//Estructura de tipo goleador
struct goleador{
	string nombre;//String del nombre completo del jugardor con goles
	int goles;//Int para el numero de goles
};
//Estructura de tipo equipo
struct equipo{
	string nombre;//String para el nombre del pais
	tecnico entrenador;//Dato de tipo tecnico para registrar el tecnico correspondiente
	string confederacion;//String para la confederacion a la que pertenece el pais
	
	List<jugador> futbolistas;//Estructura de datos lista de tipo jugador para registra las jugadore convocados
};
//Estructura de tipo Programacion
struct programacion{
	string estadio1;//String para el nombre del estadio del encuentro
	equipo equipo1;//Dato tipo equipo para el primer equipo  
	equipo equipo2;//Dato tipo equipo para el segundo equipo contrincante
	string hora;//String para el registro de la hora del encuentro
	string fecha;//String para establecer la fecha del encuentro
	int goles1;//Int para los goles del primer equipo
	int goles2;//Int para los goles del segundo equipo
		
};
//Estructura de tipo Primera fase
struct primeraFase{
	string grupo;//String para el registro del grupo
	equipo equips;//Dato tipo equipo para registrar los equipos del dicho grupo
	int Puntaje;//Int para registrar los puntos del equipo
	int goles;//Int para mostrar los goles antodados durante la primera fase del equipo
};
//Estructura de tipo Segunda Fase
struct segundaFase{
	programacion pr;//Dato tipo pogramacion para registrar los datos den encuentro
	List<equipo> e; //Lista de los equipos que se enfrentaran
	
};




#endif
