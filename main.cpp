#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <unistd.h>

#include "structs.h"
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


/* programas guias */
void menu();
void enter();
void show();
void modify();
void promedio();
void load();
void loadEstadios();
void loadPaises();
void exit();

List<estadio> listaEstadios;
estadio EstadioAux;

List<equipo> listaEquipos;
equipo EquipoAux;


jugador JugadorAux;


int main(int argc, char** argv) {

	load();
	menu();

	return 0;
}




void menu(){
	int option;
	system("cls");
	cout<<"[+] = = = = = = MENU = = = = = = [+]"<<endl;
	string options[] = {"Ingresar", "Mostrar", "Modificar", "Volver al menu principal", "Salir y guardar"};
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
    //modify();
    break;
  case 4:
    //promedio();
	break;
  case 5:
  	exit();
  default:
    menu();
    break;
  }
  	
}


void enter(){
	
	int option;
	system("cls");
	cout<<"[+] = = = = = = INGRESAR = = = = = = [+]"<<endl;
	string options[] = {"Jugador a Seleccion", "Mostrar", "Modificar", "Volver al menu principal", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  switch (option){
  case 1:
  	
  	string seleNuevo;
  	
  	string jugaNuevo;
  	
  	
  	
  	ofstream archivoJugador;
  	archivoJugador.open("jugadorTemp.txt", ios::out);
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
	}
	
	system("cls");
	cout<<"Ingrese el nombre: ";
	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	JugadorAux.nombre = seleNuevo;
	cout<<JugadorAux.nombre;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese la nacionalidad: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	JugadorAux.nacionalidad = seleNuevo;
	cout<<JugadorAux.nacionalidad;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese la fecha de nacimiento: (dd-mm-aaaa)";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	JugadorAux.fechaDeNacimiento = seleNuevo;
	cout<<JugadorAux.fechaDeNacimiento;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese la estatura: (cm)";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	int aux = atoi(seleNuevo.c_str());
	JugadorAux.estatura = aux;
	cout<<JugadorAux.estatura;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese la edad: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	aux = atoi(seleNuevo.c_str());
	JugadorAux.edad = aux;
	cout<<JugadorAux.edad;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese el club en el que juega: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	JugadorAux.club = seleNuevo;
	cout<<JugadorAux.club;
	jugaNuevo += seleNuevo + "\t";
	
	cout<<"Ingrese posicion en la que juega: (AAA)";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	JugadorAux.posicion = seleNuevo;
	cout<<JugadorAux.posicion;
	jugaNuevo += seleNuevo + "\t";

	

  	archivoJugador<<jugaNuevo;
  	
  	archivoJugador.close();
  	
  
  	EquipoAux = listaEquipos.getData(1);
  	EquipoAux.futbolistas.insertOnList(JugadorAux, 1);
  	listaEquipos.deleteFromList(1);
  	listaEquipos.insertOnList(EquipoAux, 1);
  	


  	break;
  
  }
	
	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
  	menu();
}



	
void exit(){
	
	cout<<"\n[+] Guardado con exito"<<endl; 
	
	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
	exit(0);
	

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
		i++;
		
		getline(archivoPaises,textoPaises,'\t');
		EquipoAux.confederacion = textoPaises; 
//		cout<<textoPaises<<"(Confederacion)-> "<<i<<endl;
		i++;
		
		
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

void load(){
	loadEstadios();
	loadPaises();
}


void show(){
	int option;
	system("cls");
do{
	system("cls");
	cout<<"[+] = = = = = = SHOW = = = = = = [+]"<<endl;
	string options[] = {"Estadios", "Paises", "Modificar", "", "", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << "." << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  
  
  switch (option){
  	case 1:
  		system("cls");
  		cout<<"ESTADIOS"<<endl<<endl;
  		for(int j=1; j<=listaEstadios.sizeList(); j++){
		EstadioAux = listaEstadios.getData(j);
		cout<<"Nombre del estadio "<<j<<": "<<EstadioAux.nombreEstadio<<endl;	
		cout<<"Capacidad del estadio "<<j<<": "<<EstadioAux.capacidad<<endl;	
		cout<<"Ciudad del estadio "<<j<<": "<<EstadioAux.ciudad<<endl;			
		cout<<endl;
	}
	cout<<"Presione cualquier tecla..."; getch();cout<<endl;
	
	break;
  	
	case 2:
		system("cls");
  		cout<<"PAISES Y CONFEDERACIONES"<<endl<<endl;
		for(int j=1; j<=listaEquipos.sizeList(); j++){
		EquipoAux = listaEquipos.getData(j);
		cout<<"[+] ---------------------------------- [+]"<<endl;
		cout<<"Nombre "<<j<<": "<<EquipoAux.nombre<<endl;	
		cout<<"Confederacion "<<j<<": "<<EquipoAux.confederacion<<endl;	
		cout<<"Jugadores: "<<endl;
		for(int k=1; k<2; k++){
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
		}
	}
	
  	cout<<"Presione cualquier tecla..."; getch();cout<<endl;
	
	break;
  }
}while(option!=6);	

	system("cls");
	cout<<"[!] Regresando al menu "<<endl;
	system("timeout 1");
	
	menu();
}
