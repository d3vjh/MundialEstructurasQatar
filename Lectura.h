/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */
#ifndef LECTURA_H
#define LECTURA_H

#include<iostream>
//Libreria importada

#include "Definicion.h"
#include "Crud.h"

using namespace std;
void enteroACadena();//define el metodo local

//Metodo que permite la lectura del archivo plano de los estadios
void lecturaEstadios(){	
	ifstream archivo;//Variable de tipo ifstream para el archivo
	string textEstadios;//String para ir guardando la informacion leida

	archivo.open("Estadios.txt", ios::in);//Funcion que permite abrir el archivo plano en modo lectura
	//If para validar en caso de que no se pueda abrir el archivo o no exista
	if(archivo.fail()){
		cout<<"ERROR ARCHIVO PLANO :( !!!!!!!!!!!!";//Impresion para notificar el error
	}	
	int i=0;//Int que nos permite controlar el ingreso de los datos a la lista
	
	while(!archivo.eof()){//While que valida que el archivo tenga informacion que leer
		/*Metodo que permite leer la  informacion del archivo plano hasta encontrar el caracter ';'
		y pasar esta informacion al string que guarda la informacion */		
		getline(archivo,textEstadios,';');
		textEstadios.replace(0, 1,"",0);//Metodo que reemplaza el primer carácter de la cadena textEstadios por una cadena vacía.
		Estadios_.nombreEstadio = textEstadios;	//Asignamos a la estructura auxiliar de tipo estadio en su campo para el nombre del estadio
		i++;//Aumentamos en uno el contador de control
		/*Metodo que permite leer la  informacion del archivo plano hasta encontrar el caracter ';'
		y pasar esta informacion al string que guarda la informacion */		
		getline(archivo,textEstadios,';');
		int aux = atoi(textEstadios.c_str());//Declaramos un Int auxiliar y convertimos la cadena textEstadios en entero para poder asignarsela
		Estadios_.capacidad = aux;	//Asignamos a la estructura auxiliar de tipo estadio en su campo para la capacidad del estadio
		i++;
			/*Metodo que permite leer la  informacion del archivo plano hasta encontrar el caracter ';'
		y pasar esta informacion al string que guarda la informacion */		
		getline(archivo,textEstadios,';');
		Estadios_.ciudad = textEstadios;	//Asignamos a la estructura auxiliar de tipo estadios en su campo para el nombre del estadio	
		i++;
		//If que valida el contador para la insercion en la lista
		if(i%3==0 && i>0){
			listaEstadios.insertOnList(Estadios_, listaEstadios.sizeList()+1);//Insertamos en la lista de estadios la estructura auxiliar en la posicion 1
		}		
	}

	archivo.close();	//Cerramos el archivo plano 
}

//Metodo que permite la lectura de los jugadores
void lecturaJugadores(){
	/*Metodos y varibles necesarias para la lectura del archivo plano e insercion a la lista de jugadores*/
	ifstream archivo;
	string text;

	archivo.open("Jugadores.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	int contador=0;
	
	while(!archivo.eof()){
				
		getline(archivo,text,';');
		text.replace(0, 1,"",0);
		Jugadores_.nombre = text;	
		i++;
		
		getline(archivo,text,';');
		Jugadores_.nacionalidad = text;	
		i++;
		
		getline(archivo,text,';');
		Jugadores_.fechaDeNacimiento = text;	
		i++;
		
		getline(archivo,text,';');
		int aux = atoi(text.c_str());
		Jugadores_.estatura = aux;	
		i++;
		
		getline(archivo,text,';');
		aux = atoi(text.c_str());
		Jugadores_.edad = aux;	
		i++;
		
		getline(archivo,text,';');
		Jugadores_.club = text;	
		i++;
		
		getline(archivo,text,';');
		Jugadores_.posicion = text;	
		i++;
		
		getline(archivo,text,';');
		aux = atoi(text.c_str());
		Jugadores_.golesAnotados = aux;	
		i++;
		
		getline(archivo,text,';');
		aux = atoi(text.c_str());
		Jugadores_.fechasSancion = aux;	
		i++;
		
		if(i%9==0 && i>0){	
			listaJugadores.insertOnList(Jugadores_, (listaJugadores.sizeList()+1)); 	
		}
		
	listaJugadores.sizeList();
		if(i%26==0){
			//Seccion de codigo que limpia la lista de equipos para la proxima insercion de jugadores para su respectivo equipo
			contador++;
			Equipos_ = listaEquipos.getData(contador);//Toma el equipo en la estructura auxiliar de la lista de equipos en la posicion contador
  			Equipos_.futbolistas = listaJugadores; //Le asigna a la estructura en su campo futbolista la lista de jugadores
			
			//Limpia las listas
			for(int m=1; m<27; m++){
				listaJugadores.deleteFromList(1);	
			}  		
  			listaEquipos.deleteFromList(contador);
  			listaEquipos.insertOnList(Equipos_, contador);//Inserta equipo en la lista de equipos
			}
				
	}

	archivo.close();
}
//Metodo que permite la lectura de los paises y llena la lista de equipos
void lecturaPaises(){
	
	ifstream archivoPaises,archivoTecnicos;
	
	string textoPaises;
	archivoPaises.open("Paises.txt", ios::in);
	archivoTecnicos.open("Tecnicos.txt", ios::in);
	
	if(archivoPaises.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;

	while(!archivoPaises.eof()){
		
		getline(archivoPaises,textoPaises,';');
		textoPaises.replace(0, 1,"",0);
		Equipos_.nombre = textoPaises;	
		i++; 
		
		getline(archivoPaises,textoPaises,';');
		Equipos_.confederacion = textoPaises; 
		i++; 
		
		getline(archivoTecnicos,textoPaises,';');
		textoPaises.replace(0, 1,"",0);
		Equipos_.entrenador.nombre = textoPaises; 
		i++;
		getline(archivoTecnicos,textoPaises,';');
		Equipos_.entrenador.nacionalidad = textoPaises; 
		i++;
		getline(archivoTecnicos,textoPaises,';');
		Equipos_.entrenador.equipo = textoPaises; 
		i++; 
		
		if(i%5==0 && i>0){
			listaEquipos.insertOnList(Equipos_, listaEquipos.sizeList()+1);
		}	
		
	}
	archivoPaises.close();
	archivoTecnicos.close();
	

			
}
//Metodo que permite la asigancion del tecnico a la lista de equipos y llena la lista de directores tecnicos
void lecturaTecnicos(){
	ifstream archivo;
	string textTecnicos;
	
	archivo.open("Tecnicos.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	while(!archivo.eof()){
		
		getline(archivo,textTecnicos,';');
		textTecnicos.replace(0, 1,"",0);
		Tecnicos_.nombre = textTecnicos;
		
		i++; 
		
		getline(archivo,textTecnicos,';');
		Tecnicos_.nacionalidad = textTecnicos;	
		
		i++; 
		
		getline(archivo,textTecnicos,';');
		Tecnicos_.equipo = textTecnicos;	
	
		i++; 
		
		
		if(i%3==0 && i>0){
			listaTecnicos.insertOnList(Tecnicos_, listaTecnicos.sizeList()+1);
		}		
	}

	archivo.close();
	
}
//Metodo que permite la lectura del programa y llena la lista de partidos programados
void lecturaPrograma(){
	
	fstream archivo;
	string textPrograma;

	archivo.open("Programa.txt", ios::in|ios::out);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	int j=0;
   					
	while(!archivo.eof()){
				
		getline(archivo,textPrograma,';');
		textPrograma.replace(0, 1,"",0);
		Partidos_.estadio1 = textPrograma;	
		i++;
		getline(archivo,textPrograma,';');
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(textPrograma == Equipos_.nombre){
				Partidos_.equipo1 = Equipos_;
				
				break;
			}
		}			
		i++;
		getline(archivo,textPrograma,';');
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(textPrograma == Equipos_.nombre){
				Partidos_.equipo2 = Equipos_;
			
				break;
			}
		}	
		i++;
		getline(archivo,textPrograma,';');
		Partidos_.hora = textPrograma;
		i++;
		
		getline(archivo,textPrograma,';');
		Partidos_.fecha = textPrograma;
		i++;
		
		getline(archivo,textPrograma,';');
		int gol1 = atoi(textPrograma.c_str());
		Partidos_.goles1 = gol1;
		i++;
		
		getline(archivo,textPrograma,';');
		int gol2 = atoi(textPrograma.c_str());
		Partidos_.goles2 = gol2;
		i++;
		
		if(i%7==0 && i>0){
			listaPartidos.insertOnList(Partidos_, listaPartidos.sizeList()+1);
			
		}	

	}
		 

	archivo.close();	

}
//Metodo que permite la lectura y la actualizacion de los grupos con sus respectivos puntos a partir de la lectura del programa
void lecturaGrupos(){
	lecturaPrograma();
	fstream archivo;
	string textGrupos;
	
	archivo.open("grupos2.txt", ios::in|ios::out);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}
	
	int i=0;
	int j=0;
   	string textGuardar ="";		
	while(!archivo.eof()){
				
		getline(archivo,textGrupos,';');
		textGrupos.replace(0, 1,"",0);
		Fase1_.grupo = textGrupos;	
		i++;
		
		getline(archivo,textGrupos,';');
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(textGrupos == Equipos_.nombre){
				Fase1_.equips = Equipos_;
				break;
			}
		}			
		i++;
			
		for(int i=2; i<=listaPartidos.sizeList(); i++){
			Partidos_ = listaPartidos.getData(i);
			if(Fase1_.equips.nombre == Partidos_.equipo1.nombre){
				if(Partidos_.goles1 > Partidos_.goles2){
					Fase1_.Puntaje += 3;
					Fase1_.goles += Partidos_.goles1;
				
		
				}else if(Partidos_.goles1 == Partidos_.goles2){
					Fase1_.Puntaje += 1;
					Fase1_.goles += Partidos_.goles1;
			
				}
			
			}else if(Fase1_.equips.nombre == Partidos_.equipo2.nombre){
				if(Partidos_.goles1 < Partidos_.goles2){
					Fase1_.Puntaje += 3;
					Fase1_.goles += Partidos_.goles2;
				
				}else if(Partidos_.goles1 == Partidos_.goles2){
					Fase1_.Puntaje += 1;
					Fase1_.goles += Partidos_.goles2;
		
				}
				
			}
				
		}

		i++;
		if(i%3==0 && i>0){
			listaFase1.insertOnList(Fase1_, listaFase1.sizeList()+1);
			Fase1_.Puntaje=0;
			Fase1_.goles=0;
			}
		}
		//Iteradores que recorresn la lista de la fase 1 y escribe el mensaje que actualizara el archivo plano de los grupos
		int ultimo;
		for(int m=1;m<listaFase1.sizeList();m++){
			Fase1_ = listaFase1.getData(m);
			textGuardar += Fase1_.grupo;
			textGuardar += ';';
			textGuardar += Fase1_.equips.nombre;
			textGuardar += ';';
			textGuardar +=  enteroACadena(Fase1_.Puntaje);
			textGuardar += ';';
			textGuardar +=  enteroACadena(Fase1_.goles);
			textGuardar += ';';
			textGuardar += '\n';
			ultimo = m;
		}
		Fase1_ = listaFase1.getData(ultimo+1);
			textGuardar += Fase1_.grupo;
			textGuardar += ';';
			textGuardar += Fase1_.equips.nombre;
			textGuardar += ';';
			textGuardar +=  enteroACadena(Fase1_.Puntaje);
			textGuardar += ';';
			textGuardar +=  enteroACadena(Fase1_.goles);
			
			
		
		//Secuencia de codigo que permite crear un respaldo de los grupos y llena un archivo temporal de grupos para despues sobreescribir el archivo original de grupos
		system("copy grupos.txt grupos.txt.backup");
		ofstream archivoGrupos;	
  		archivoGrupos.open("gruposTemp.txt", ios::out);
  	
  		if(archivoGrupos.fail()){
  			cout<<"Hemos fallado";
		}
		
		archivoGrupos<<textGuardar;
		archivoGrupos.close();
		archivo.close();
		system("move gruposTemp.txt grupos.txt");
		 

	archivo.close();	

	
}

//Metodo que realiza la lectura de todos los archivos planos y llena las lista en la memoria principal
void cargarArchivos(){
	lecturaEstadios();
	lecturaPaises();
	lecturaJugadores();
	lecturaTecnicos();
	lecturaGrupos();
}
#endif

