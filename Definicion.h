/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */

#ifndef DEFINICION_H
#define DEFINICION_H
#include<iostream>
//Librerias importadas
#include "structs.h"
#include "lista.h"

using namespace std;
//Lista de tipo estadio para guardar los estadios junto con su estructura auxiliar de tipo estadio
List<estadio> listaEstadios;
estadio Estadios_;

//Lista de tipo equipo para guardar los equipos junto con su estructura auxiliar de tipo equipo
List<equipo> listaEquipos;
equipo Equipos_;

//Listas de tipo juagdor para guardar los jugadores convocados y los once que jugaran un partido junto con su estructura auxiliar de tipo jugador
List<jugador> listaJugadores;
List<jugador> losOnce;
jugador Jugadores_;

//Lista de tipo tarjeta para guardar los tarjetas junto con su estructura auxiliar de tipo tarjeta
List<tarjeta> listaTarjetasIndv;
tarjeta Tarjetas_;

//Lista de tipo tecnico para guardar los directores tecnicos junto con su estructura auxiliar de tipo tecnico
List<tecnico> listaTecnicos;
tecnico Tecnicos_;

//Lista de tipo programacion para guardar el itinerario de partidos junto con su estructura auxiliar de tipo programa
List<programacion> listaPartidos;
programacion Partidos_;

//Lista de tipo primera fase para guardar grupos de la primera fase junto con su estructura auxiliar de tipo primera fase
List<primeraFase> listaFase1;
primeraFase Fase1_;
#endif
