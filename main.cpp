/**
 * \mainpage 
 * \author Jhonatan Moreno - Santiago Avila - Hanna Sarmiento
 * \date Diciembre - 2022
 */


#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <sstream>

#include "structs.h"
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::string;
using namespace std;


/* programas guias */
void menu();

void enter();


void ingresarTarjeta(int, string, string, string, string);
void ingresarGoles(equipo, int);

void show();
void listarEstadios();
void listarPaises();
void listarJugadores();
void listarTarjetas();

void modify();

void promedio();

void load();
void loadEstadios();
void loadPaises();
void loadJugadores();
void loadTarjetas();

void exit();

// Funciones Auxiliares
string enteroACadena(int);
bool isSeleccion(string);
bool isJugador(string);

string variableEquipoNombre;

int posicionAbsoluta;
string textTarjetaGuardar="";


List<estadio> listaEstadios;
estadio EstadioAux;

List<equipo> listaEquipos;
equipo EquipoAux;

List<jugador> listaJugadores;
jugador JugadorAux;

List<tarjeta> listaTarjetasIndv;
tarjeta TarjetaAux;


int main(int argc, char** argv) {


	load();
	menu();
	cout<<"\a"<<endl;
	
	return 0;
}

//Menú


void menu(){
	int option;
	system("cls");
	cout<<"[+] = = = = = = MENU = = = = = = [+]"<<endl;
	
	string options[] = {
		"Ingresar", 
		"Mostrar", 
		"Modificar", 
		"Volver al menu principal", 
		"Salir y guardar"};
		
		
	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
    	
    	
  	cout << "Ingresa una opcion: ";
  	cin >> option;
  	switch (option){
  		case 1:
    		enter();
    		break;
  		case 2:
   			show();
			break;
  		case 3:
    		modify();
   			break;
  		case 4:
   			//promedio();
			break;
  		case 5:
  			exit();
  			break;
  		default:
    		menu();
    		break;
  }
  	
}


void enter(){
	
	int option;
	system("cls");
	cout<<"[+] = = = = = = INGRESAR = = = = = = [+]"<<endl;
	string options[] = {"Jugador a Seleccion", "Tarjeta a jugador", "Modificar", "Volver al menu principal", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  
  
  switch(option){
  	
  case 1:
  	break;
  case 2:
  	{
		system("cls");
		cout<<"[+]==============TARJETA===============[+]\n";
  		string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
  		cin.ignore();
		getline(cin, nombreSeleccion);		
		if(isSeleccion(nombreSeleccion)){
			cout<<"Se encontro\t"<<EquipoAux.nombre<<endl;
			
			
		}else{
			cout<<"\n[!] Información de la seleccion equivocada\nPresione cualquier tecla..."; 
			getch();		
			enter();
		}		
		
		
		string nombreJugador;
		cout<<"Ingrese el jugador a buscar: ";
		getline(cin, nombreJugador);
		cout<<nombreJugador;
		if(isJugador(nombreJugador) ){
			cout<<"Se encontro\t"<<JugadorAux.nombre<<endl;
			string Color;
			string Motivo;
			string Contrincante; //Buscar equipo por nombre
			string Fecha;
	
			
			cout<<"\nIngrese el color de la tarjeta: ";
			getline(cin, Color);
			
			cout<<"\nIngrese el motivo de la amonestación: ";
			getline(cin, Motivo);
			
			cout<<"\nIngrese el contrincante: ";
			getline(cin, Contrincante);
					
			cout<<"\nIngrese el día de la amonestación: ";
			getline(cin, Fecha);
			cout<<JugadorAux.nombre;
	
			cout<<"posicion Absoluta:  "<<posicionAbsoluta<<endl;

			
			ingresarTarjeta(posicionAbsoluta, Color, Motivo, Contrincante, Fecha);
	
		}else{
			cout<<"\n[!] Información del jugador equivocada\nPresione cualquier tecla..."; 
			getch();		
			enter();
		}		
	
		
  		break;
  	}

  		
  		default:
  			break;
  		
  }
  	
  
	
	//Fin del m?todo
	cout<<"Presione cualquier tecla..."; getch();
  	menu();
}

void ingresarTarjeta(int posicionAbs, string Color, string Motivo, string Contrincante, string Fecha){
		
			TarjetaAux.color = Color;
			TarjetaAux.motivo = Motivo;
			TarjetaAux.contrincante = Contrincante;
			TarjetaAux.fecha = Fecha;

	//	listaTarjetasIndv.insertOnList(TarjetaAux, 1);
		
		JugadorAux.tarjetas.insertOnList(TarjetaAux, (JugadorAux.tarjetas.sizeList()+1));
		
	
		
		EquipoAux.futbolistas.deleteFromList(posicionAbs);
  		EquipoAux.futbolistas.insertOnList(JugadorAux, posicionAbs);
		  
		  	
		cout<<"\n[!] Amonestación asignada a: "<<JugadorAux.nombre<<endl;
		cout<<"Jugador N. "<<posicionAbs<<endl;
		cout<<"Pertenece al equipo"<<EquipoAux.nombre<<endl;
			
		
}

void show(){
	int option;
	system("cls");
	do{
		system("cls");
		cout<<"[+] = = = = = = SHOW = = = = = = [+]"<<endl;
		string options[] = {
			"Estadios", 
			"Paises", 
			"TODOS los jugadores", 
			"Tarjetas", 
			"", 
			"Volver al menu principal"};
			
  		int size = sizeof(options) / sizeof(*options);
		for(int i = 0; i < size; i++)	
    		cout << i + 1 << "." << options[i] << "\n";
  		cout << "Ingresa una opcion: ";
  		cin >> option;
  
  
  switch (option){
  	case 1:{
  		listarEstadios();
		cout<<"Presione cualquier tecla..."; 
		getch();
		
		break;
	  }
		
	case 2:{
		//De una sola seleccion
		system("cls");
		string nombreSeleccion;
		cout<<"Ingrese la seleccion a consultar: ";
		cin>>nombreSeleccion;
		if(isSeleccion(nombreSeleccion)){
			listarJugadores();	
		}else{
			cout<<"\n[!] Información de la seleccion equivocada\nPresione cualquier tecla..."; 
			getch();		
			enter();
		}
		cout<<"Presione cualquier tecla...";
		getch();cout<<endl;
		break;
	}
	case 3:{
		//absolutamente todos los jugadores
		listarPaises();
		cout<<"Presione cualquier tecla...";
		getch();cout<<endl;
		break;
	}
	case 4:{
		system("cls");
		string nombreSeleccion;
		cout<<"Ingrese la seleccion a consultar las tarjetas: ";
		cin>>nombreSeleccion;
		if(isSeleccion(nombreSeleccion)){
			listarTarjetas();	
		}else{
			cout<<"\n[!] Información de la seleccion equivocada\nPresione cualquier tecla..."; 
			getch();		
			enter();
		}
		
		getch();
		break;	
	}	
  		
	
	
  }
}while(option!=6);	

	system("cls");
	cout<<"[!] Regresando al menu "<<endl;
	system("timeout 1");
	
	menu();
}

void listarEstadios(){
	  	system("cls");
  		cout<<"ESTADIOS"<<endl<<endl;
  		for(int j=1; j<=listaEstadios.sizeList(); j++){
			EstadioAux = listaEstadios.getData(j);
			cout<<"Nombre del estadio "<<j<<": "<<EstadioAux.nombreEstadio<<endl;	
			cout<<"Capacidad del estadio "<<j<<": "<<EstadioAux.capacidad<<endl;	
			cout<<"Ciudad del estadio "<<j<<": "<<EstadioAux.ciudad<<endl;			
			cout<<endl;
	}
}

void listarPaises(){
		system("cls");
  		cout<<"PAISES Y CONFEDERACIONES"<<endl<<endl;
		for(int j=1; j<=listaEquipos.sizeList(); j++){
			EquipoAux = listaEquipos.getData(j);
			cout<<"[+] ---------------------------------- [+]"<<endl;
			cout<<"Nombre "<<j<<": "<<EquipoAux.nombre<<endl;	
			cout<<"Confederacion "<<j<<": "<<EquipoAux.confederacion<<endl;	
			cout<<"Jugadores: "<<endl;
		for(int k=1; k<=EquipoAux.futbolistas.sizeList(); k++){
			JugadorAux = EquipoAux.futbolistas.getData(k);
			cout<<"=> Jugador "<<k<<"<="<<endl;
			cout<<"Numero: "<<JugadorAux.numero<<endl;
			cout<<"Nombre: "<<JugadorAux.nombre<<endl;
			cout<<"Nacionalidad: "<<JugadorAux.nacionalidad<<endl;			
			cout<<"Fecha: "<<JugadorAux.fechaDeNacimiento<<endl;
			cout<<"Estatura: "<<JugadorAux.estatura<<endl;
			cout<<"Edad: "<<JugadorAux.edad<<endl;
			cout<<"Club: "<<JugadorAux.club<<endl;
			cout<<"Posicion: "<<JugadorAux.posicion<<endl;
			cout<<"Goles: "<<JugadorAux.golesAnotados<<endl;
			cout<<"Fechas Sancion: "<<JugadorAux.fechasSancion<<endl;
		}
	}
}

void listarTarjetas(){
	
	cout<<"Este es el equipo:  "<<EquipoAux.nombre;
	
	for(int i=0; i<=EquipoAux.futbolistas.sizeList(); i++ ){
		JugadorAux = EquipoAux.futbolistas.getData(i);
		cout<<"Este es el jugadooor1 :"<<JugadorAux.nombre<<" "<<JugadorAux.tarjetas.sizeList()<<endl;	
		
		if(JugadorAux.tarjetas.sizeList() !=0 ){
			cout<<"Entro"<<endl;
			//Un ciclo hasta tarjetas.sizeList();
			TarjetaAux = JugadorAux.tarjetas.getData(1);
			cout<<TarjetaAux.color<<"\n";
			cout<<TarjetaAux.motivo<<"\n";
			cout<<TarjetaAux.contrincante<<"\n";
			cout<<TarjetaAux.fecha<<"\n";
			
		}
	}
	
}

//Lista lo de un solo pais;
void listarJugadores(){
	
	
		system("cls");
  		cout<<"Jugadores de: "<<EquipoAux.nombre<<endl<<endl;

		cout<<"[+] ---------------------------------- [+]"<<endl;
		cout<<"Nombre : "<<EquipoAux.nombre<<endl;	
		cout<<"Confederacion: "<<EquipoAux.confederacion<<endl;	
		cout<<"Jugadores: "<<endl;
		for(int k=1; k<=EquipoAux.futbolistas.sizeList(); k++){
			JugadorAux = EquipoAux.futbolistas.getData(k);
			cout<<"=> Jugador"<<k<<"<="<<endl;
			cout<<"Nombre: "<<JugadorAux.nombre<<endl;
			cout<<"Nacionalidad: "<<JugadorAux.nacionalidad<<endl;			
			cout<<"Fecha: "<<JugadorAux.fechaDeNacimiento<<endl;
			cout<<"Estatura: "<<JugadorAux.estatura<<endl;
			cout<<"Edad: "<<JugadorAux.edad<<endl;
			cout<<"Club: "<<JugadorAux.club<<endl;
			cout<<"Posicion: "<<JugadorAux.posicion<<endl;
			cout<<"Goles: "<<JugadorAux.golesAnotados<<endl;
			cout<<"Fechas Sancion: "<<JugadorAux.fechasSancion<<endl;
			cout<<"Cantidad de tarjetas: "<<JugadorAux.tarjetas.sizeList()<<endl;
			cout<<"Numero: "<<JugadorAux.numero<<endl<<endl;
		}
	
}



void modify(){	

	int option;
	system("cls");
	cout<<"[+] = = = = = = MODIFICAR MUNIDAL = = = = = = [+]"<<endl;
	string options[] = {"Goles Anotados", "Fechas de Sancion", "---", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  switch (option){
  case 1:
  	{
	  
  	system("cls");
  	string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin.ignore();
		getline(cin, nombreSeleccion);
		
		//Se crea un bucle para buscar al equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			EquipoAux = listaEquipos.getData(i);
			if(nombreSeleccion == EquipoAux.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
		
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
  		//cin.ignore();
		getline(cin, nombreJugador);
		for(int i=1; i<=EquipoAux.futbolistas.sizeList(); i++){
			
			JugadorAux = EquipoAux.futbolistas.getData(i);

			if(nombreJugador == JugadorAux.nombre){
				
				cout<<"ENCONTRADO EN LA POSICION: "<<i<<endl;
				int golesPartido;
				cout<<"Cuantos goles metio: "<<endl;
				cin>>golesPartido;
				JugadorAux.golesAnotados = golesPartido;
				
				EquipoAux.futbolistas.deleteFromList(i);
  				EquipoAux.futbolistas.insertOnList(JugadorAux, i);	
				break;
				}
			}
			break;
		}
		case 2:{
			
			string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin.ignore();
		getline(cin, nombreSeleccion);
		
		//Se crea un bucle para buscar al equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			EquipoAux = listaEquipos.getData(i);
			if(nombreSeleccion == EquipoAux.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
		cout<<"El nombre de la seleccion es: "<<EquipoAux.nombre<<endl;
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
  		//cin.ignore();
		getline(cin, nombreJugador);
		for(int i=1; i<=EquipoAux.futbolistas.sizeList(); i++){
			
			JugadorAux = EquipoAux.futbolistas.getData(i);

			if(nombreJugador == JugadorAux.nombre){
				
				cout<<"ENCONTRADO EN LA POSICION: "<<i<<endl;
		
				int faltas;
				cout<<"Cuantos fechas de sancion: 5"<<endl;
				cin>>faltas;
				JugadorAux.fechasSancion = faltas;
				
				EquipoAux.futbolistas.deleteFromList(i);
  				EquipoAux.futbolistas.insertOnList(JugadorAux, i);	
				break;
			}
		}
			
			break;
		}
		default:
			menu();
  }
		
  		
				
	getch();
	menu();
}
	

void loadPaises(){
	
	ifstream archivoPaises;
	string textoPaises;

	archivoPaises.open("Paises.txt", ios::in);
	
	if(archivoPaises.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	
	while(!archivoPaises.eof()){
				
		getline(archivoPaises,textoPaises,'\t');
		textoPaises.replace(0, 1,"",0);
		EquipoAux.nombre = textoPaises;	
//		cout<<textoPaises<<"(Nombre)-> "<<i<<endl;
		i++; //1
		
		getline(archivoPaises,textoPaises,'\t');
		EquipoAux.confederacion = textoPaises; 
//		cout<<textoPaises<<"(Confederacion)-> "<<i<<endl;
		i++; //2
		
		
		if(i%2==0 && i>0){
			listaEquipos.insertOnList(EquipoAux, listaEquipos.sizeList()+1);
		}		
	}

	archivoPaises.close();
	
	
	
//	for(int j=1; j<=listaEquipos.sizeList(); j++){
//		EquipoAux = listaEquipos.getData(j);
//		cout<<"[+] --- --- --- --- [+]"<<endl;
//		cout<<"Nombre "<<j<<": "<<EquipoAux.nombre<<endl;	
//		cout<<"Confederacion "<<j<<": "<<EquipoAux.confederacion<<endl;				
//	}
	
	
}

void loadEstadios(){
	
	ifstream archivo;
	string texto;

	archivo.open("Estadios.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	
	while(!archivo.eof()){
				
		getline(archivo,texto,'\t');
		texto.replace(0, 1,"",0);
		EstadioAux.nombreEstadio = texto;	
//		cout<<texto<<"(Nombre)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		int aux = atoi(texto.c_str());
		EstadioAux.capacidad = aux;	
//		cout<<texto<<"(Capacidad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		EstadioAux.ciudad = texto;	
//		cout<<texto<<"(Ciudad)-> "<<i<<endl;
		i++;
		
		if(i%3==0 && i>0){
			listaEstadios.insertOnList(EstadioAux, listaEstadios.sizeList()+1);
		}		
	}

	archivo.close();
	
	for(int j=1; j<=listaEstadios.sizeList(); j++){
		EstadioAux = listaEstadios.getData(j);
		cout<<"[+] --- --- --- --- [+]"<<endl;
		cout<<"Nombre del estadio "<<j<<": "<<EstadioAux.nombreEstadio<<endl;	
		cout<<"Capacidad del estadio "<<j<<": "<<EstadioAux.capacidad<<endl;	
		cout<<"Ciudad del estadio del estadio "<<j<<": "<<EstadioAux.ciudad<<endl;			
	}
	
	
}

void loadJugadores(){
	
	int posicionPuntero =0;

	ifstream archivo;
	string texto;

	fstream archivoTarjetas;
	archivoTarjetas.open("JugadorTarjeta.txt", ios::in | ios::out);
			
	archivo.open("Jugadores.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}else{
		
		
	int i=0;
	int contador=0;
	
	
	while(!archivo.eof()){
		
		
				
		getline(archivo, texto, '\t');
		texto.replace(0, 1,"",0);
		int aux = atoi(texto.c_str());
		JugadorAux.numero = aux;
				
		getline(archivo,texto,'\t');
//		texto.replace(0, 1,"",0);
		JugadorAux.nombre = texto;	
//		cout<<texto<<"(Nombre)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		//texto.replace(0, 1,"",0);
		JugadorAux.nacionalidad = texto;	
//		cout<<texto<<"(Nombre)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		//texto.replace(0, 1,"",0);
		JugadorAux.fechaDeNacimiento = texto;	
//		cout<<texto<<"(Nombre)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		aux = atoi(texto.c_str());
		JugadorAux.estatura = aux;	
//		cout<<texto<<"(Capacidad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		aux = atoi(texto.c_str());
		JugadorAux.edad = aux;	
//		cout<<texto<<"(Capacidad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		JugadorAux.club = texto;	
//		cout<<texto<<"(Ciudad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		JugadorAux.posicion = texto;	
//		cout<<texto<<"(Ciudad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		aux = atoi(texto.c_str());
		JugadorAux.golesAnotados = aux;	
//		cout<<texto<<"(Capacidad)-> "<<i<<endl;
		i++;
		
		getline(archivo,texto,'\t');
		aux = atoi(texto.c_str());
		JugadorAux.fechasSancion = aux;	
//		cout<<texto<<"(Capacidad)-> "<<i<<endl;
		i++;
		
		if(i%9==0 && i>0){
			

			
			
			//Error acá
			listaJugadores.insertOnList(JugadorAux, (listaJugadores.sizeList()+1)); 
				

		}
		if(i%26==0){
				
			contador++;
			EquipoAux = listaEquipos.getData(contador);
  			EquipoAux.futbolistas = listaJugadores;
  		
  	
  			/*
			  Lee el archivo de las tarjetas, y lo agrega en la casilla correspondiente			  
			  */	
			string tarAux;
			
			archivoTarjetas.seekg(0, ios::beg);
			
			while(!archivoTarjetas.eof()){
				
				archivoTarjetas.seekg(posicionPuntero, ios::beg);
			

				getline(archivoTarjetas, tarAux, '\t');
				tarAux.replace(0, 1,"",0);
				TarjetaAux.idNomPais = tarAux;
				cout<<"\n\nEsto recibe de primeras: "<<tarAux;
				
				
				if(tarAux==""){
					cout<<"tarAux ta vacio"<<endl;
					break;
					
				}else{
					variableEquipoNombre = tarAux;	
				}
				
				
	
				
				if(EquipoAux.nombre == variableEquipoNombre){
				
								
				
				string numeroString;
				getline(archivoTarjetas,numeroString,'\t');
				int numberJugador = atoi(numeroString.c_str());
				cout<<"Numero del jugador: "<<numberJugador<<endl;
				TarjetaAux.idNombreJugador = numberJugador;
				
				string NombJuga;
				getline(archivoTarjetas, NombJuga, '\t');
				cout<<"Nombre del man"<<NombJuga<<endl;
				TarjetaAux.idNombreJugador = NombJuga;
				
				string col;
				getline(archivoTarjetas, col, '\t');
				cout<<"color de la tarjeta"<<col<<endl;
				TarjetaAux.color = col;
				
				string mot;
				getline(archivoTarjetas, mot, '\t');
				cout<<"Motivo"<<mot<<endl;
				TarjetaAux.motivo= mot;
				
				string fecha;
				getline(archivoTarjetas, fecha, '\t');
				cout<<"Fechaaaa"<<fecha<<endl;
				TarjetaAux.fecha = fecha;
				
				string cont;
				getline(archivoTarjetas, cont, '\t');
				cout<<"Contrincante: "<<cont<<endl;
				TarjetaAux.contrincante = cont;
				
				posicionPuntero = archivoTarjetas.tellp();
				cout<<archivoTarjetas.tellp()<<"<<<---------POSICION"<<endl;
				getch();
				
				JugadorAux = EquipoAux.futbolistas.getData(numberJugador);
				cout<<"Antes de ingresarlo al pais: "<<EquipoAux.nombre;
				cout<<JugadorAux.nombre<<"Mi nombre";
				ingresarTarjeta(numberJugador, col, mot, cont, fecha);
				
				
				getch();
			
					
				}else{
					
						
					cout<<"No es el mismo nombre del equipo"<<endl;
						
					break;
					
				}		
				//	
				
			}
			
getch();

//  	
  			
//  			JugadorAux= EquipoAux.futbolistas.getData(/*De donde lee el archivo*/) 
			
	
			
			for(int m=1; m<27; m++){
				listaJugadores.deleteFromList(1);	
			}  		
			
			
			
  			listaEquipos.deleteFromList(contador);
  			listaEquipos.insertOnList(EquipoAux, contador);		
			}
		

					
	}
}
	archivo.close();
	
	//Imprime en el load

	archivoTarjetas.close();

	
}



void load(){
	loadEstadios();
	loadPaises();
	loadJugadores();
	
}


string enteroACadena(int entero){
    std::string numeroComoCadena = "";
    std::stringstream ss;
    ss << entero;
    ss >> numeroComoCadena;
    return numeroComoCadena;
}


bool isSeleccion(string nombreSeleccion){
	for(int i=1; i<=listaEquipos.sizeList(); i++){
			EquipoAux = listaEquipos.getData(i);
			if(nombreSeleccion == EquipoAux.nombre){
				return true;
			}				
		}
		return false;
}

bool isJugador(string nombreJugador){

	for(int i=1; i<=EquipoAux.futbolistas.sizeList(); i++){	
		JugadorAux = EquipoAux.futbolistas.getData(i);
		if(nombreJugador == JugadorAux.nombre){
			posicionAbsoluta = i;
			return true;
		}	
	}
	return false;
	
}




void guardarTarjetas(){
	
	
	for(int i=1; i<=JugadorAux.tarjetas.sizeList(); i++){
		
		cout<<"Jugador a guardar tarjetas:: "<<JugadorAux.nombre<<endl;
		TarjetaAux = JugadorAux.tarjetas.getData(i);
		cout<<TarjetaAux.motivo<<endl;
		cout<<TarjetaAux.idNombreJugador<<endl;
		
		
		textTarjetaGuardar += '\n';
		textTarjetaGuardar += EquipoAux.nombre;
		textTarjetaGuardar += '\t';
		
		string entero = enteroACadena(JugadorAux.numero);
		textTarjetaGuardar += entero;
		textTarjetaGuardar += '\t';
		
		textTarjetaGuardar += JugadorAux.nombre;
		textTarjetaGuardar += '\t';
		
		textTarjetaGuardar += TarjetaAux.color;
		textTarjetaGuardar += '\t';
		
		textTarjetaGuardar += TarjetaAux.motivo;
		textTarjetaGuardar += '\t';
		
		textTarjetaGuardar += TarjetaAux.fecha;
		textTarjetaGuardar += '\t';
		
		textTarjetaGuardar += TarjetaAux.contrincante;
		textTarjetaGuardar += '\t';
		
		
		
	}
	
	
	
		
	
	ofstream archivoJugador;
	
  	archivoJugador.open("JugadorTarjeta.txt", ios::out);
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
	}

	archivoJugador<<textTarjetaGuardar;
	
	
	archivoJugador.close();
	
	
	
	
}

// Guarda los jugadores en el archivo plano de texto
void guardarJugadores(){
	
	
	string ent;
		
	string textGuardar ="\n";

	system("cls");

	for(int j=1; j<=listaEquipos.sizeList(); j++){
		EquipoAux = listaEquipos.getData(j);
		for(int k=1; k<=EquipoAux.futbolistas.sizeList(); k++){
		
			JugadorAux = EquipoAux.futbolistas.getData(k);
			cout<<JugadorAux.tarjetas.sizeList()<<endl;
			getch();
			
			if(JugadorAux.tarjetas.sizeList() > 0){
				
				cout<<"El jugador a guardar tarjetas es: "<<JugadorAux.nombre<<endl;
				cout<<"El tamano de la lista es: "<<JugadorAux.tarjetas.sizeList()<<endl;
				getch();
				guardarTarjetas();
			
			}
			
			string ent = enteroACadena(k);
			textGuardar += ent;
			textGuardar += '\t';
			
			textGuardar += JugadorAux.nombre;
			textGuardar += '\t';
			
			
			textGuardar += JugadorAux.nacionalidad;
			textGuardar += '\t';
			
			textGuardar += JugadorAux.fechaDeNacimiento;
			textGuardar += '\t';
			
			ent = enteroACadena(JugadorAux.estatura);
			textGuardar += ent;
			textGuardar += '\t';
			
			ent = enteroACadena(JugadorAux.edad);
			textGuardar += ent;
			textGuardar += '\t';

			textGuardar += JugadorAux.club;
			textGuardar += '\t';
			
			textGuardar += JugadorAux.posicion;
			textGuardar += '\t';
		
			ent = enteroACadena(JugadorAux.golesAnotados);
			textGuardar += ent;
			textGuardar += '\t';
		//	
			ent = enteroACadena(JugadorAux.fechasSancion);
			textGuardar += ent;
			textGuardar += '\t';
		
			textGuardar += '\n';
			
//			

								
	}
}
	
	system("copy Jugadores.txt JugadoresBKCP2.txt");
	
	
	ofstream archivoJugador;
	
  	archivoJugador.open("jugadorTemp.txt", ios::out);
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
	}
	
	
	
	archivoJugador<<textGuardar;
	
	
	archivoJugador.close();
	
	system("move jugadorTemp.txt Jugadores.txt");	
	
	
	cout<<"\a [+] Jugadores guardados correctamente";
}



void exit(){

	system("timeout 1");
	guardarJugadores();
	system("timeout 1");
	//Fin del m?todo
	cout<<"Hasta luego...";
	exit(0);
	

}

