
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

string enteroACadena(int entero)
{
    std::string numeroComoCadena = "";
    std::stringstream ss;
    ss << entero;
    ss >> numeroComoCadena;
    return numeroComoCadena;
}


void enter(){
	int pos;
	int option;
	system("cls");
	cout<<"[+] = = = = = = INGRESAR = = = = = = [+]"<<endl;
	string options[] = {"Jugador a Seleccion", "Tarjeta a jugador", "Partido", "Volver al menu principal", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  
  
  switch(option){
  	
  case 1:
  	{
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
	Jugadores_.nombre = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la nacionalidad: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	cout<<seleNuevo<<endl;
	Jugadores_.nacionalidad = seleNuevo;
	cout<<Jugadores_.nacionalidad;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la fecha de nacimiento: (dd-mm-aaaa)";
//	cin.ignore();
	getline(cin, seleNuevo);
	Jugadores_.fechaDeNacimiento = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la estatura: (cm)";
//	cin.ignore();
	getline(cin, seleNuevo);
	int aux = atoi(seleNuevo.c_str());
	Jugadores_.estatura = aux;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese la edad: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	aux = atoi(seleNuevo.c_str());
	Jugadores_.edad = aux;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese el club en el que juega: ";
//	cin.ignore();
	getline(cin, seleNuevo);
	Jugadores_.club = seleNuevo;
	jugaNuevo += seleNuevo + ";";
	
	cout<<"Ingrese posicion en la que juega: (AAA)";
//	cin.ignore();
	getline(cin, seleNuevo);
	Jugadores_.posicion = seleNuevo;
	jugaNuevo += seleNuevo + ";";

	

  	archivoJugador<<jugaNuevo;
  	
  	archivoJugador.close();

  	break;
  }
  case 2:
  	{
  	
  		string nombreSeleccion;
  		cout<<"Ingrese la seleccion a buscar: "<<endl;
		cin>>nombreSeleccion;
		//Se crea un metodo para buscar al equipo
		
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Siiii es el mismo"<<endl;
				break;
			}
		}
		
		cout<<"El nombre de la seleccion es: "<<Equipos_.nombre<<endl;
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
  		cin.ignore();
		getline(cin, nombreJugador);
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){
			
			Jugadores_ = Equipos_.futbolistas.getData(i);
			cout<<Jugadores_.nombre<<endl;
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
		
	//	listaTarjetasIndv.insertOnList(Tarjetas_, 1);
		Jugadores_.tarjetas.insertOnList(Tarjetas_, (Jugadores_.tarjetas.sizeList()+1));
		Tarjetas_ = Jugadores_.tarjetas.getData(1);
		
		cout<<"Tarjeta Motivo: "<<Tarjetas_.motivo;
		
		  
  		break;
  	}

  		case 3:
  			{
  		system("cls");
  		fstream archivoPrograma;
  		archivoPrograma.open("Programa.txt", ios::in|ios::out);
  		
			if(archivoPrograma.fail()){
  			cout<<"Hemos fallado";
		}
	
  		int eleccion;
		string textGuardar ="";
		pos = archivoPrograma.tellp();
		archivoPrograma.seekp(pos, ios::end);
	
	
 		string Estadio, equipo1, equipo2, hora,fecha,sgol1,sgol2;
 		int goles_1,goles_2,opcion;
 		cout<<"En que estadio va realizar el partido? :"<<endl;
		for(int j=1; j<=listaEstadios.sizeList(); j++){
			Estadios_ = listaEstadios.getData(j);
			cout<<"Opcion "<<j<< " "<<Estadios_.nombreEstadio<<endl;
		}
		
		cin>>eleccion;
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
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			if(equipo2 == Equipos_.nombre){
				cout<<"Equipo encontrado"<<endl;
				break;
			}
		}
		Partidos_.equipo2 = Equipos_;
		
		cout<<"Ingrese la hora (00:00)";
		cin>>hora;
		Partidos_.hora = hora;
		
		cout<<"Ingrese la fecha (DD/MM)";
		cin>>fecha;
		Partidos_.fecha = fecha;
		
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
				goles_1 = rand() % 10 + 1;
				Partidos_.goles1 = goles_1;
				cout<<"El equipo "<<Partidos_.equipo1.nombre<<" marco: "<<goles_1<<endl;
				goles_2 = rand() % 10 + 1;
				Partidos_.goles2 = goles_2;
				cout<<"El equipo "<<Partidos_.equipo2.nombre<<" marco: "<<goles_2<<endl;
				
		}
		
		listaPartidos.insertOnList(Partidos_, listaPartidos.sizeList()+1);
		
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
		
		


		
		
		archivoPrograma<<textGuardar;
		
	
	
		
		
		
		
		archivoPrograma.close();
		

//	
//	archivoJugador<<textGuardar;
//	archivoJugador.close();
//	system("move jugadorTemp.txt Jugadores.txt");
//	
//			  }
//  		
		}
		
  		
			
		default:
  			break;
  		
  }
  	
  
	
	//Fin del m?todo
	cout<<"Presione cualquier tecla..."; getch();
	menu();

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
			Equipos_ = listaEquipos.getData(i);
			if(nombreSeleccion == Equipos_.nombre){
				cout<<"Equipo Encontrado con éxito..."<<endl;
				break;
			}
		}
		
		
  		string nombreJugador;
  		cout<<"Ingrese el jugador a buscar: "<<endl;
		getline(cin, nombreJugador);
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){	
			Jugadores_ = Equipos_.futbolistas.getData(i);
			if(nombreJugador == Jugadores_.nombre){
				
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
  		//cin.ignore();
		getline(cin, nombreJugador);
		for(int i=1; i<=Equipos_.futbolistas.sizeList(); i++){
			
			Jugadores_ = Equipos_.futbolistas.getData(i);

			if(nombreJugador == Jugadores_.nombre){
				
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
		
  		
				
	getch();
	menu();

}


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

void Consultar(){
	int option;
	system("cls");
	cout<<"[+] = = = = = = CONSULTAS = = = = = = [+]"<<endl;
	string options[] = {"Pais-> Entrenador y equipo ", "Goleadores", "Programa de estadio","Partido en fecha","Resultado pais", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  	cin >> option;
  	switch(option){
	//Editar consulta programa ****************************************************************
  	case 1:
  	{	
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

		cout<<"-----------------TECNICO--------------------------"<<endl<<endl;
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
	cout<<"Presione cualquier tecla..."; getch(); menu();
	
		break;

	}
	case 2:{
		goleador Goles[50];
		int pos=0;
		for(int i=1; i<=listaEquipos.sizeList(); i++){
			Equipos_ = listaEquipos.getData(i);
			for(int p=1; p<=Equipos_.futbolistas.sizeList(); p++){
			Jugadores_ = Equipos_.futbolistas.getData(p);
		
			if(Jugadores_.golesAnotados>0){
					if(pos==50){
						break;
					}
					
//				cout<<"Yo "<<Jugadores_.nombre<<" meti "<<Jugadores_.golesAnotados<<endl;
					Goles[pos].nombre = Jugadores_.nombre;
					Goles[pos].goles = Jugadores_.golesAnotados;
					pos++;
					
				}
				
				}
			}
			
			int size = sizeof(Goles) / sizeof(*Goles);
			orden(Goles,size);
			cout<<"-----------------TABLA DE GOLEADORES------------------------"<<endl<<endl;
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
		int eleccion;
		system("cls");
 		cout<<"De que estadio desea ver la programacion? :"<<endl;
		for(int j=1; j<=listaEstadios.sizeList(); j++){
			Estadios_ = listaEstadios.getData(j);
			cout<<"Opcion "<<j<< " "<<Estadios_.nombreEstadio<<endl;
		}
		
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
		
		system("cls");
		cout<<"--------------PARTIDOS PROGRAMADOS EN EL "<<Estadios_.nombreEstadio<<"----------------------"<<endl<<endl;
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
		cout<<"Presione cualquier tecla..."; getch();cout<<endl;
		menu();
	
		
		break;
	}
		
	case 4:{
		string fecha_;
		system("cls");
 		cout<<"De cual fecha desea ver la programacion? (DD/MM): ";
 		cin>>fecha_;
		system("cls");
		cout<<"--------------PARTIDOS PROGRAMADOS PARA EL DIA "<<fecha_<<"----------------------"<<endl<<endl;
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
		cout<<"Presione cualquier tecla..."; getch();cout<<endl;
		menu();
		
		break;
	}
	
	case 5:{
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
		cout<<"--------------RESULTADOS PARA EL EQUIPO "<<Equipos_.nombre<<"----------------------"<<endl<<endl;
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
		cout<<"Presione cualquier tecla..."; getch();cout<<endl;
		menu();
		
		break;
	}
		
		default:
	break;
}	
}

#endif
