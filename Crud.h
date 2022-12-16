/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */

#ifndef CRUD_H
#define CRUD_H

#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>
#include "Menus.h"
#include "Ordenamiento.h"


using namespace std;

void menu();
void Orden();
//Metodo que recibe como parametro un entero y realiza la conversion a String de dicho entero
string enteroACadena(int entero)
{
    std::string numeroComoCadena = "";
    std::stringstream ss;
    ss << entero;
    ss >> numeroComoCadena;
    return numeroComoCadena;
}

//Metodo que despliega el menu de inserciones y realiza las inserciones
void enter(){	
	int pos;
	int option;
	system("cls");
	//Menu de opciones
	cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_INGRESAR -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	string options[] = {"Jugador a Seleccion", "Tarjeta a jugador", "Partido", "Iniciar partido","Volver al menu principal", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
	  
	  bool seguir = false;
  //Bloque de codigo para cada caso del menu
  switch(option){
  	//Este caso permite la insercion de un nuevo jugador a una seleccion y que este sea guardado en un archivo temporal
  case 1:
  	{
   	string seleNuevo;
  	
  	string jugaNuevo;

  	ofstream archivoJugador;
  	
  	archivoJugador.open("jugadorTemp.txt", ios::out);
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
  		

	}
	//Seccion de codigo que recibe los datos del jugador y lo guarda en la estructura auxiliar de jugadores
	system("cls");
	cout<<"Ingrese el nombre: ";
	cin.ignore();
	getline(cin, seleNuevo);
	Jugadores_.nombre = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la nacionalidad: ";

	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	Jugadores_.nacionalidad = seleNuevo;
	cout<<Jugadores_.nacionalidad;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la fecha de nacimiento: (dd-mm-aaaa)";

	getline(cin, seleNuevo);
	Jugadores_.fechaDeNacimiento = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la estatura: (cm)";

	getline(cin, seleNuevo);
	int aux = atoi(seleNuevo.c_str());
	Jugadores_.estatura = aux;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la edad: ";

	getline(cin, seleNuevo);
	aux = atoi(seleNuevo.c_str());
	Jugadores_.edad = aux;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese el club en el que juega: ";

	getline(cin, seleNuevo);
	Jugadores_.club = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese posicion en la que juega: (AAA)";

	getline(cin, seleNuevo);
	Jugadores_.posicion = seleNuevo;
	jugaNuevo += seleNuevo + ";";

	//Escribimos y cerramos el archivo temporal

  	archivoJugador<<jugaNuevo;
  	
  	archivoJugador.close();

  	break;
  }
 	//Caso que permite el registro de tarjetas para un jugador
  case 2:
  	{
  	
  		string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin>>nombreSeleccion;
		//Se crea un metodo para buscar al equipo
		//Iterador que busca el equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Siiii es el mismo"<<endl;
				break;
			}
		}
		//Iterador que recorre y busca el jugador en los jugadores del equipo respectivo
		cout<<"El nombre de la seleccion es: "<<Equipos_.nombre<<endl;
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
  		cin.ignore();
		getline(cin, nombreJugador);
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){
			
			Jugadores_ = Equipos_.futbolistas.getData(i);
			cout<<Jugadores_.nombre<<endl;
			//Seccion de codigo que asigna valores quemados de los campos de la tarjera
			if(nombreJugador == Jugadores_.nombre){
				cout<<"ENCONTRADO"<<endl;
				
				Tarjetas_.color = "Roja";
				Tarjetas_.motivo = "Pelea";
				Tarjetas_.contrincante = "España";
				Tarjetas_.dia = 25;
				Tarjetas_.mes = 12;
				Tarjetas_.anio = 2022;
				break;
			}	
		}
		
		//inserta la tarjeta en la lista de tarjetas
		Jugadores_.tarjetas.insertOnList(Tarjetas_, (Jugadores_.tarjetas.sizeList()+1));
		Tarjetas_ = Jugadores_.tarjetas.getData(1);
		
		cout<<"Tarjeta Motivo: "<<Tarjetas_.motivo;
		
		  
  		break;
  	}

  		case 3:
  			{
  		system("cls");
  		//Permite abrir el archivo plano de Pograma con los atributos de escritura y lectura
  		fstream archivoPrograma;
  		archivoPrograma.open("Programa.txt", ios::in|ios::out);
  		
			if(archivoPrograma.fail()){
  			cout<<"Hemos fallado";
		}
		
  		int eleccion;
		string textGuardar ="";
		//A traves del metodo tellp encontramos la posicion disponible de escritura
		pos = archivoPrograma.tellp();
		//Con el metodo seekp ubicamos el curson en dicha posicion
		archivoPrograma.seekp(pos, ios::end);
	
		//String para los datos del programa
 		string Estadio, equipo1, equipo2, hora,fecha,sgol1,sgol2;
 		int goles_1,goles_2,opcion;
 		cout<<"En que estadio va realizar el partido? :"<<endl;
		for(int j=1; j<=listaEstadios.sizeList(); j++){
			Estadios_ = listaEstadios.getData(j);
			cout<<"Opcion "<<j<< " "<<Estadios_.nombreEstadio<<endl;
		}
		
		cin>>eleccion;
		//Switch que permite la seleccion del estadio donde se realizara el partido
		switch(eleccion){
			case 1:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 2:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 3:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 4:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 5:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 6:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 7:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			case 8:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					Partidos_.estadio1 = Estadios_.nombreEstadio;
					break;
				}
			default:
				break;
		}
//			
//		
	
		cout<<"Ingrese el equipo 1: ";
		cin>>equipo1;
		//Busqueda del primer equipo que juega
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(equipo1 == Equipos_.nombre){
				cout<<"Equipo encontrado"<<endl;
				break;
			}
		}
		Partidos_.equipo1 = Equipos_;
		
		cout<<"Ingrese el equipo 2: ";
		cin>>equipo2;
		//Busqueda del segundo equipo que juega
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(equipo2 == Equipos_.nombre){
				cout<<"Equipo encontrado"<<endl;
				break;
			}
		}
		Partidos_.equipo2 = Equipos_;
		//Ingresamos la hora para el encuentro
		cout<<"Ingrese la hora (00:00)";
		cin>>hora;
		Partidos_.hora = hora;
		
		//Ingresamos la fecha para el encuentro
		cout<<"Ingrese la fecha (DD/MM)";
		cin>>fecha;
		Partidos_.fecha = fecha;
		
		
		//Seccion que permite el elegir el marcador de forma manual o aleatoria
		cout<<"Desea ingresar el marcador de manera Manual o Aleatorio?"<<endl;
		cout<<"1.Manual"<<endl<<"2.Aleatorio"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Cuando goles marco "<<Partidos_.equipo1.nombre<<" :";
				cin>>goles_1;
				Partidos_.goles1 = goles_1;
				cout<<"Cuando goles marco "<<Partidos_.equipo2.nombre<<" :";
				cin>>goles_2;
				Partidos_.goles2 = goles_2;
				break;
			case 2:
				srand((unsigned) time(NULL));
				goles_1 = rand() % 5 ;
				Partidos_.goles1 = goles_1;
				cout<<"El equipo "<<Partidos_.equipo1.nombre<<" marco: "<<goles_1<<endl;
				goles_2 = rand() % 5 ;
				Partidos_.goles2 = goles_2;
				cout<<"El equipo "<<Partidos_.equipo2.nombre<<" marco: "<<goles_2<<endl;
				
		}
		//Insertamos el programa en la lista de partidos programados
		listaPartidos.insertOnList(Partidos_, listaPartidos.sizeList()+1);
		
		
		//Seccion de codigo para escribir el registro que se actualizara al archivo plano
		textGuardar +=';';
		textGuardar += '\n';
		

		
		textGuardar += Partidos_.estadio1;
		textGuardar += ';';
		textGuardar += Partidos_.equipo1.nombre;
		textGuardar += ';';
		textGuardar += Partidos_.equipo2.nombre;
		textGuardar += ';';
		textGuardar += Partidos_.hora;
		textGuardar += ';';
		textGuardar += Partidos_.fecha;
		sgol1 = enteroACadena(Partidos_.goles1);
		textGuardar += ';';
		textGuardar += sgol1;
		sgol2 = enteroACadena(Partidos_.goles2);
		textGuardar += ';';
		textGuardar += sgol2;
		
		


		//Escribimos y cerramos el archivo plano
		
		archivoPrograma<<textGuardar;
		archivoPrograma.close();
		break;
		}
	//Metodo que permite la eleccion de los once titulares	
  	case 4:{
  		string portero="POR";
  		string defensa="DEF";
  		string medio="MED";
  		string delantero="DEL";
  		
	do{
		//Imprimimos los partidos programados
		string seguiremos;
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_PARTIDOS PROGRAMADOS -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
			cout << setw(10) << setfill(' ') << "Indice"<< " | ";
    		cout << setw(10) << setfill(' ') << "Estadio"<<"\t"<< " | ";
			cout << setw(10) << setfill(' ') << "Equipo 1"<< " | ";
    		cout << setw(5) << setfill(' ') << "Equipo 2"<< " | ";
    		cout << setw(5) << setfill(' ') << "Hora"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=2;m<=listaPartidos.sizeList();m++){
    		Partidos_ = listaPartidos.getData(m);
    		cout<<setw(5) << setfill(' ') << m-1 <<" | ";
    		cout << setw(5) << setfill(' ') << Partidos_.estadio1<< " | ";
	    	cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " | ";
	    	cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< " | ";
	    	cout << setw(5) << setfill(' ') << Partidos_.hora<<endl;	   	

		}
		int simular;
		cout<<"Por favor indique el indice del partido que desa simular: ";
		cin>>simular;
		//Incia la simulacion del partido seleccionado
		Partidos_= listaPartidos.getData(simular+1);
  		cout<<"Esta a punto de iniciar el partido "<<Partidos_.equipo1.nombre<<" VS "<<Partidos_.equipo2.nombre<<" ..."<<endl;
  		cout<<"Presione cualquier tecla para continuar.....";
		  getch();
  		system("cls");
  		//Busqueda del primer equipo que se enfrentara
  		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(Partidos_.equipo1.nombre == Equipos_.nombre){

				break;
			}
		}
		//Imprimimos el entredador de dicho equipo
  		cout<<"Entrenador del equipo "<<Equipos_.nombre<<" : "<<Equipos_.entrenador.nombre<<endl;
  		int seleccionados = 1;
  		int cont =1;
  		int contPOR=0;
		int contDEF=0;
		int contMED=0;

  		int escogido;
  		//PORTEROS FOR
  		while(seleccionados != 12){
  			for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
			Jugadores_ = Equipos_.futbolistas.getData(k);
			if(Jugadores_.posicion==portero){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
				contPOR++;
			}
			
		}
		//Seleccionamos e insertamos 
		cout<<"Seleccione uno de los indices de los anteriores porteros:";
		cin>>escogido;
		Jugadores_ = Equipos_.futbolistas.getData(escogido);
		cout<<"El seleccionado "<<Jugadores_.nombre<<endl<<endl;
		seleccionados++;
		
		losOnce.insertOnList(Jugadores_,(losOnce.sizeList()+1));

	
		//FOR Para el resto
		cont=1;
		for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
			Jugadores_ = Equipos_.futbolistas.getData(k);
			if(Jugadores_.posicion==defensa){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			if(Jugadores_.posicion==medio){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			if(Jugadores_.posicion==delantero){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			
		}
			while(seleccionados!=12){
			cout<<"Seleccione el indice para el siguiente jugador:";
				//Seleccionamos e insertamos 
			cin>>escogido;
			escogido += contPOR;
			Jugadores_ = Equipos_.futbolistas.getData(escogido);
			cout<<"El seleccionado "<<Jugadores_.nombre<<endl<<endl;
			seleccionados++;
	  		losOnce.insertOnList(Jugadores_,(losOnce.sizeList()+1));
			}
			
		cout<<"Equipo completo..."<<endl;
		
		  }
		system("cls");
		//Busqueda del segundo equipo que se enfrentara
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(Partidos_.equipo2.nombre == Equipos_.nombre){

				break;
			}
		}
		//Imprimimos el entredador de dicho equipo
  		cout<<"Entrenador del equipo "<<Equipos_.nombre<<" : "<<Equipos_.entrenador.nombre<<endl;;
  		seleccionados = 1;
  		cont =1;
		contPOR = 0;  

  		//PORTEROS FOR
  		while(seleccionados != 12){
  			for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
			Jugadores_ = Equipos_.futbolistas.getData(k);
			if(Jugadores_.posicion==portero){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
				contPOR++;
			}
			
		}
			//Seleccionamos e insertamos 
		cout<<"Seleccione uno de los indices de los anteriores porteros:";
		cin>>escogido;
		Jugadores_ = Equipos_.futbolistas.getData(escogido);
		cout<<"el seleccionado "<<Jugadores_.nombre<<endl<<endl;
		seleccionados++;
		losOnce.insertOnList(Jugadores_,(losOnce.sizeList()+1));
	
	//FOR Para el resto
		cont=1;
		for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
			Jugadores_ = Equipos_.futbolistas.getData(k);
			if(Jugadores_.posicion==defensa){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			if(Jugadores_.posicion==medio){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			if(Jugadores_.posicion==delantero){
				cout<<cont<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
				cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;
				cont++;
			}
			
		}
			while(seleccionados!=12){
			cout<<"Seleccione el indice para el siguiente jugador:";
			//Seleccionamos e insertamos 
			cin>>escogido;
			escogido += contPOR;
			Jugadores_ = Equipos_.futbolistas.getData(escogido);
			cout<<"el seleccionado "<<Jugadores_.nombre<<endl<<endl;
			seleccionados++;
			losOnce.insertOnList(Jugadores_,(losOnce.sizeList()+1));
	  			
			}
			
		cout<<"Equipo completo..."<<endl;
		
		  }
  		  		//Mensaje que permite seguir o detener la ejecucion 
  		cout<<"Desea continuar con el siguiente partido (Y/N)"<<endl;
  		cin>>seguiremos;
  		if(seguiremos=="N"||seguiremos=="n"){
  			seguir = true;
		  }
	}while(seguir == false);
		
  		break;
	  }
		//Caso que permite volver al menu principal
		case 5:{
			menu();
			break;
		}
		default:
  			break;
  		
  }
  	
  
	
	//Fin del metodo
	cout<<"Presione cualquier tecla..."; getch();
	menu();

}

	//Metodo que permite la modificacion de los datos de los jugadores
void modify(){	

	int option;
	system("cls");
	cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_MODIFICAR MUNIDAL -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	string options[] = {"Goles Anotados", "Fechas de Sancion", "---", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  switch (option){
  case 1:
  	{
	  //Este caso permite actualizar en la lista de jugadores de un equipo la cantidad de goles
  	system("cls");
  	string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin.ignore();
		getline(cin, nombreSeleccion);
		
		//Se crea un bucle para buscar al equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
		
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
		getline(cin, nombreJugador);
		//Busca el jugador en dicho equipo
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){	
			Jugadores_ = Equipos_.futbolistas.getData(i);
			if(nombreJugador == Jugadores_.nombre){
				//Asiganmos la cantidad de goles
				cout<<"ENCONTRADO EN LA POSICION: "<<i<<endl;
				int golesPartido;
				cout<<"Cuantos goles metio: "<<endl;
				cin>>golesPartido;
				Jugadores_.golesAnotados = golesPartido;
				
				Equipos_.futbolistas.deleteFromList(i);
  				Equipos_.futbolistas.insertOnList(Jugadores_, i);	
				break;
				
				}
			}
			break;
		}
		case 2:{
			//Este caso permite actualizar en la lista de jugadores de un equipo la cantidad de fechas de sancion
			string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin.ignore();
		getline(cin, nombreSeleccion);
		
		//Se crea un bucle para buscar al equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
		cout<<"El nombre de la seleccion es: "<<Equipos_.nombre<<endl;
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;

		getline(cin, nombreJugador);
		//Busca el jugador en dicho equipo
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){
			
			Jugadores_ = Equipos_.futbolistas.getData(i);

			if(nombreJugador == Jugadores_.nombre){
				//Asiganmos la cantidad de fechas de sancion
				cout<<"ENCONTRADO EN LA POSICION: "<<i<<endl;
		
				int faltas;
				cout<<"Cuantos fechas de sancion: 5"<<endl;
				cin>>faltas;
				Jugadores_.fechasSancion = faltas;
				
				Equipos_.futbolistas.deleteFromList(i);
  				Equipos_.futbolistas.insertOnList(Jugadores_, i);	
				break;
			}
		}
			
			break;
		}
		default:
			menu();
  }
		
  		
	//Nos regresa al menu principal
	getch();
	menu();

}

	//Este metodo permite la actualizacion de los jugadores en el archivo plano de jugadores a la hora de terminar la ejecucion del programa
void exit(){

	string ent;
	
	cout<<"\n[+] Guardado con exito"<<endl; 
		
		string textGuardar ="";
	
		system("cls");
 
		for(int j=1; j<=listaEquipos.sizeList(); j++){
		Equipos_ = listaEquipos.getData(j);
		for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
			
			Jugadores_ = Equipos_.futbolistas.getData(k);
			
			textGuardar += Jugadores_.nombre;
			textGuardar += ';';
			textGuardar += Jugadores_.nacionalidad;
			textGuardar += ';';
			textGuardar += Jugadores_.fechaDeNacimiento;
			textGuardar += ';';
			
			ent = enteroACadena(Jugadores_.estatura);
			textGuardar += ent;
			textGuardar += ';';
			
			ent = enteroACadena(Jugadores_.edad);
			textGuardar += ent;
			textGuardar += ';';

			textGuardar += Jugadores_.club;
			textGuardar += ';';
			textGuardar += Jugadores_.posicion;
			textGuardar += ';';
		
			ent = enteroACadena(Jugadores_.golesAnotados);
			textGuardar += ent;
			textGuardar += ';';
				
			ent = enteroACadena(Jugadores_.fechasSancion);
			textGuardar += ent;
			textGuardar += ';';
		
			textGuardar += '\n';
			
					
		}
	}
//Secuencia de codigo que permite crear un respaldo de los jugadores y llena un archivo temporal de jugadores para despues sobreescribir el archivo original de jugadores
	system("copy Jugadores.txt Jugadores.txt.backup");
	ofstream archivoJugador;	
  	archivoJugador.open("jugadorTemp.txt", ios::out);
  	
  	if(archivoJugador.fail()){
  		cout<<"Hemos fallado";
	}
	
	archivoJugador<<textGuardar;
	archivoJugador.close();
	system("move jugadorTemp.txt Jugadores.txt");
	
	cout<<"Presione cualquier tecla..."; getch();
	exit(0);
	

}
//Metodo que despliega el menu de consultas y realiza las consultas
void Consultar(){
	//Menu de consultas
	int option;
	system("cls");
	cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_CONSULTAS -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	string options[] = {"Pais-> Entrenador y equipo ", "Goleadores", "Programa de estadio","Partido en fecha","Resultado pais","Resultados grupo","Alineacion equipo", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  	cin >> option;
  	switch(option){
	
  	case 1:
  	{	
  	//Para este caso mostramos el entrenador y jugadores por posicion del equipo
  		string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin.ignore();
		getline(cin, nombreSeleccion);
		
		//Se crea un bucle para buscar al equipo
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
  		system("cls");
		//Impresion de los datos
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_TECNICO -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
		cout << setw(10) << setfill(' ') << "Nombre del tecnico"<<"   | ";
		cout << setw(5) << setfill(' ') << "Nacionalidad"<< " | ";
		cout << setw(8) << setfill(' ') << "Seleccion" << endl;
		cout << setw(60) << setfill('-') << "" << endl;
		cout << setw(10) << setfill(' ') <<Equipos_.entrenador.nombre<<"\t \t";
		cout << setw(10) << setfill(' ') << Equipos_.entrenador.nacionalidad<<"\t";
		cout << setw(8) << setfill(' ') << Equipos_.entrenador.equipo << endl;
    	cout << setw(60) << setfill('-') << "" << endl;
    	cout<<""<<endl;	
		cout<<"Jugadores: "<<endl;
		cout<<""<<endl;	
		cout << setw(60) << setfill('-') << "" << endl;
		cout << setw(10) << setfill(' ') << "Nombre "<<"  | ";

    	cout << setw(5) << setfill(' ') << "Posicion"<< " | ";

    	cout << setw(60) << setfill('-') << "" << endl;
    	
  		for(int j=1; j<=Equipos_.futbolistas.sizeList(); j++){
		Jugadores_ = Equipos_.futbolistas.getData(j);
			cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | "<<endl;

	}

	
		break;

	}
	case 2:{
		//Para este caso guardamos en un arreglo de tipo goleadores con los 50 con mas goles
		goleador Goles[50];
		int pos=0;
		//Buscamos los goleadores 
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			for(int p=1; p<=Equipos_.futbolistas.sizeList(); p++){
			Jugadores_ = Equipos_.futbolistas.getData(p);
		
			if(Jugadores_.golesAnotados>0){
					if(pos==50){
						break;
					}
					
					Goles[pos].nombre = Jugadores_.nombre;
					Goles[pos].goles = Jugadores_.golesAnotados;
					pos++;
					
				}
				
				}
			}
			//Encontramos el tamaño del arreglo y ordenamos 
			int size = sizeof(Goles) / sizeof(*Goles);
			orden(Goles,size);
			//Impresion de la lista de goleadores
			cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_TABLA DE GOLEADORES -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
  			cout << setw(10) << setfill(' ') << "Nombre del jugador"<< "   | ";
    		cout << setw(5) << setfill(' ') << "Cantidad de goles"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
			for(int j=0;j<size;j++){
				if(Goles[j].nombre==""){
					break;
				}
						cout<<setw(10) << setfill(' ')<<Goles[j].nombre;
						cout<<setw(20) << setfill(' ')<<Goles[j].goles<<endl;
			}
		
			cout << setw(42) << setfill('-') << "" << endl;
		cout<<"Presione cualquier tecla..."; getch(); menu();
	break;
}
	case 3:{
		//Este caso permite consultar un estadio y mostrar todos los partidos que se haran en dicho estadio
		int eleccion;
		system("cls");
 		cout<<"De que estadio desea ver la programacion? :"<<endl;
		for(int j=1; j<=listaEstadios.sizeList(); j++){
			Estadios_ = listaEstadios.getData(j);
			cout<<"Opcion "<<j<< " "<<Estadios_.nombreEstadio<<endl;
		}
		//Switch para la eleccion del estadio
		cin>>eleccion;
		switch(eleccion){
			case 1:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			case 2:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			case 3:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			case 4:
				{
					Estadios_ = listaEstadios.getData(eleccion);
				
					break;
				}
			case 5:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			case 6:
				{
					Estadios_ = listaEstadios.getData(eleccion);
				
					break;
				}
			case 7:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			case 8:
				{
					Estadios_ = listaEstadios.getData(eleccion);
					
					break;
				}
			default:
				break;
		}
		//Impresion y busqueda de datos del programa en dicho estadio
		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_PARTIDOS PROGRAMADOS EN EL "<<Estadios_.nombreEstadio<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
    		cout << setw(10) << setfill(' ') << "Equipo 1"<< " | ";
    		cout << setw(5) << setfill(' ') << "Equipo 2"<< " | ";
    		cout << setw(5) << setfill(' ') << "Hora"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=2;m<=listaPartidos.sizeList();m++){
    		Partidos_ = listaPartidos.getData(m);
    		if(Estadios_.nombreEstadio == Partidos_.estadio1 ){
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.hora<<endl;
			}	   	

		}
		
		break;
	}
		
	case 4:{
		//Caso que permite consultar los partidos en una fecha
		string fecha_;
		system("cls");
 		cout<<"De cual fecha desea ver la programacion? (DD/MM): ";
 		cin>>fecha_;
		system("cls");
		//Impresion y busqueda de los partido
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_PARTIDOS PROGRAMADOS PARA EL DIA "<<fecha_<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
    		cout << setw(10) << setfill(' ') << "Estadio"<< "   | ";
			cout << setw(10) << setfill(' ') << "Equipo 1"<< " | ";
    		cout << setw(5) << setfill(' ') << "Equipo 2"<< " | ";
    		cout << setw(5) << setfill(' ') << "Hora"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=2;m<=listaPartidos.sizeList();m++){
    		Partidos_ = listaPartidos.getData(m);
    		if(fecha_ == Partidos_.fecha ){
    			cout << setw(10) << setfill(' ') << Partidos_.estadio1<< "   | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.hora<<endl;
			}	   	

		}
		break;
	}
	
	case 5:{
		//Caso que permite mostra los partidos y resultados de un equipo
		string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin>>nombreSeleccion;
		//Se crea un metodo para buscar al equipo
		
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				break;
			}
		}
		system("cls");
		//Impresion y busqueda de los partidos
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_HISTORIAL PARA EL EQUIPO "<<Equipos_.nombre<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
    		cout << setw(10) << setfill(' ') << "Partido"<< "   | ";
			cout << setw(15) << setfill(' ') << "Marcador"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=2;m<=listaPartidos.sizeList();m++){
    		Partidos_ = listaPartidos.getData(m);
    		if(Equipos_.nombre == Partidos_.equipo1.nombre ){
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " VS ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< "  ";
	    		cout << setw(5) << setfill(' ') << Partidos_.goles1<<"-"<<Partidos_.goles2<<endl;
			}else if(Equipos_.nombre == Partidos_.equipo2.nombre){
				cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " VS ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< "  ";
	    		cout << setw(5) << setfill(' ') << Partidos_.goles1<<"-"<<Partidos_.goles2<<endl;
			}	   	

		}

		break;
	}
	case 6:{
		//Caso que permite mostrar la tabla de puntajes y goles de un grupo
		string nombregrupo;
  		cout<<"Ingrese el grupo a buscar: "<<endl;
		cin>>nombregrupo;

		//Se crea un metodo para buscar al equipo

		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_RESULTADOS PARA EL EQUIPO "<<nombregrupo<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
    		cout << setw(10) << setfill(' ') << "Equipo"<< "   | ";
			cout << setw(5) << setfill(' ') << "Puntaje"<< " | ";
			cout << setw(15) << setfill(' ') << "Diferencia de goles"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=1;m<=listaFase1.sizeList();m++){
    		Fase1_ = listaFase1.getData(m);
  
    		if(nombregrupo == Fase1_.grupo ){
	    		cout << setw(5) << setfill(' ') << Fase1_.equips.nombre<< "   | ";
	    		cout << setw(5) << setfill(' ') << Fase1_.Puntaje<< "   | ";
	    		cout << setw(5) << setfill(' ') << Fase1_.goles<< "   | "<<endl;
			}
		}
		
		break;
	}
	case 7:{
		//Caso que muestra los jugadores alineados por equipo
		string nombrequipo;
  		cout<<"Ingrese el equipo a buscar: "<<endl;
		cin>>nombrequipo;
		for(int m=1;m<=listaEquipos.sizeList();m++){
    		Jugadores_ = losOnce.getData(m);
  
    		if(nombrequipo == Equipos_.nombre ){
    			cout<<"Lo encontre";
	    		break;
			}
		}
		//Se crea un metodo para buscar al equipo

		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_JUGADORES ALINEADOS PARA EL EQUIPO "<<Equipos_.nombre<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
    		cout << setw(10) << setfill(' ') << "Equipo"<< "   | ";
			cout << setw(5) << setfill(' ') << "Puntaje"<< " | ";
			cout << setw(15) << setfill(' ') << "Diferencia de goles"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int k=1; k<=losOnce.sizeList(); k++){
			Jugadores_ = Equipos_.futbolistas.getData(k);
			cout << setw(5) << setfill(' ') << Jugadores_.nombre<<"  | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.nacionalidad<< " | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.fechaDeNacimiento<< " | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.estatura<< " | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.edad<< " | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.club<< " | ";
    		cout << setw(5) << setfill(' ') << Jugadores_.posicion<< " | ";
    		cout << setw(2) << setfill(' ') << Jugadores_.golesAnotados<< " | ";
			cout << setw(2) << setfill(' ')<< Jugadores_.fechasSancion<< " | "<<endl;
		}
		

		
		break;
	}
	//Caso que regresa
		case 8:{
			menu();
			break;
		}
		default:
	break;
}	
//Volvemos al menu
	cout<<"Presione cualquier tecla..."; getch();
	menu();
	
}

#endif
