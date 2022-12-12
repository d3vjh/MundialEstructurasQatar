

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


void ingresarTarjeta();
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

void exit();

// Funciones Auxiliares
string enteroACadena(int);
bool isSeleccion(string);
bool isJugador(string);



int posicionAbsoluta;


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
			ingresarTarjeta();
		}else{
			cout<<"\n[!] Información del jugador equivocada\nPresione cualquier tecla..."; 
			getch();		
			enter();
		}		
	
		TarjetaAux = JugadorAux.tarjetas.getData(1);
  		break;
  	}

  		
  		default:
  			break;
  		
  }
  	
  
	
	//Fin del m?todo
	cout<<"Presione cualquier tecla..."; getch();
  	menu();
}

void ingresarTarjeta(){
	
		string Color;
		string Motivo;
		equipo Contrincante; //Buscar equipo por nombre
		string Fecha;

		
		cout<<"Ingrese el color de la tarjeta: ";
		getline(cin, Color);
		
		cout<<"\nIngrese el motivo de la amonestación: ";
		getline(cin, Motivo);
		
		cout<<"\nIngrese el día de la amonestación: ";
		getline(cin, Fecha);

	
			cout<<"ENCONTRADO"<<endl;
			TarjetaAux.color = Color;
			TarjetaAux.motivo = Motivo;
			TarjetaAux.contrincante = "España";
			TarjetaAux.fecha = Fecha;

		
	
		
	//	listaTarjetasIndv.insertOnList(TarjetaAux, 1);
		cout<<"ANTES"<<JugadorAux.tarjetas.sizeList()<<endl;
		JugadorAux.tarjetas.insertOnList(TarjetaAux, (JugadorAux.tarjetas.sizeList()+1));
		cout<<"Despues"<<JugadorAux.tarjetas.sizeList()<<endl;
		cout<<"[!] Amonestación asignada a: "<<JugadorAux.nombre<<endl;
		
		EquipoAux.futbolistas.deleteFromList(posicionAbsoluta);
  		EquipoAux.futbolistas.insertOnList(JugadorAux, posicionAbsoluta);			
		
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
			"", 
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
		listarJugadores();
		cout<<"Presione cualquier tecla...";
		getch();cout<<endl;
		break;
	}
	case 3:{
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

void listarJugadores(){
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
	
void exit(){
	
	
	string ent;
	
	cout<<"\n[+] Guardado con exito"<<endl; 
		
		string textGuardar ="";
	
		system("cls");
 
		for(int j=1; j<=listaEquipos.sizeList(); j++){
		EquipoAux = listaEquipos.getData(j);
		for(int k=1; k<=EquipoAux.futbolistas.sizeList(); k++){
			
			JugadorAux = EquipoAux.futbolistas.getData(k);
			
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
			
		//	cout<<textGuardar;
					
		}
	}
	
	system("copy Jugadores.txt Jugadores.txt.backup");
	
	
	ofstream archivoJugador;
	
  	archivoJugador.open("jugadorTemp.txt", ios::out);
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
	}
	
	
	
	archivoJugador<<textGuardar;
	
	
	archivoJugador.close();
	
	system("move jugadorTemp.txt Jugadores.txt");

	//Fin del m?todo
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
	
	ifstream archivo;
	string texto;

	archivo.open("Jugadores.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	int contador=0;
	
	while(!archivo.eof()){
				
		getline(archivo,texto,'\t');
		texto.replace(0, 1,"",0);
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
		int aux = atoi(texto.c_str());
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
	listaJugadores.sizeList();
		if(i%26==0){
				
			contador++;
			EquipoAux = listaEquipos.getData(contador);
  			EquipoAux.futbolistas = listaJugadores;

			//Debería borrar acá, ya que se asigna a un equipo ya.
			
//			for(int j=1; j<=listaJugadores.sizeList(); j++){
//			JugadorAux = listaJugadores.getData(j);
//			cout<<"[+] ------------------------- [+]"<<endl;
//			cout<<JugadorAux.nombre<<endl;
//			cout<<JugadorAux.nacionalidad<<endl;
//			cout<<JugadorAux.fechaDeNacimiento<<endl;
//			cout<<JugadorAux.estatura<<endl;
//			cout<<JugadorAux.edad<<endl;
//			cout<<JugadorAux.club<<endl;
//			cout<<JugadorAux.posicion<<endl;
//			cout<<"--------------------"<<endl;
//		
//		}
			
			for(int m=1; m<27; m++){
				listaJugadores.deleteFromList(1);	
			}  		
			
			
			
  			listaEquipos.deleteFromList(contador);
  			listaEquipos.insertOnList(EquipoAux, contador);		
			}
		

					
	}

	archivo.close();
	
	//Imprime en el load

	

	
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



