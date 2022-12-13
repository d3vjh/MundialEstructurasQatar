
#ifndef LECTURA_H
#define LECTURA_H

#include<iostream>


#include "Definicion.h"
using namespace std;

void lecturaEstadios(){	
	ifstream archivo;
	string textEstadios;

	archivo.open("Estadios.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	
	while(!archivo.eof()){
				
		getline(archivo,textEstadios,';');
		textEstadios.replace(0, 1,"",0);
		Estadios_.nombreEstadio = textEstadios;	
		i++;
		
		getline(archivo,textEstadios,';');
		int aux = atoi(textEstadios.c_str());
		Estadios_.capacidad = aux;	
		i++;
		
		getline(archivo,textEstadios,';');
		Estadios_.ciudad = textEstadios;	
		i++;
		
		if(i%3==0 && i>0){
			listaEstadios.insertOnList(Estadios_, listaEstadios.sizeList()+1);
		}		
	}

	archivo.close();	
}
void lecturaJugadores(){
	
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
				
			contador++;
			Equipos_ = listaEquipos.getData(contador);
  			Equipos_.futbolistas = listaJugadores;
			
			for(int m=1; m<27; m++){
				listaJugadores.deleteFromList(1);	
			}  		
  			listaEquipos.deleteFromList(contador);
  			listaEquipos.insertOnList(Equipos_, contador);		
			}
				
	}

	archivo.close();
}

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
		//cout<<"ACA -----> "<<textPrograma<<endl;
		Partidos_.hora = textPrograma;
		//getch();
		i++;
		
		if(i%4==0 && i>0){
			listaPartidos.insertOnList(Partidos_, listaPartidos.sizeList()+1);
			
		}	

	}
		 

	archivo.close();	

}
void cargarArchivos(){
	lecturaEstadios();
	lecturaPaises();
	lecturaJugadores();
	lecturaTecnicos();
	lecturaPrograma();
}
#endif

