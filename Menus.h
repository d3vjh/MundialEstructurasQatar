#include <iostream>
#ifndef MENUS_H
#define MENUS_H

#include "Crud.h"

using namespace std;

void enter();
void show();
void modify();
void Consultar();
void exit();
void cargarArchivos();


void menu(){

	int option;
	system("cls");
	cout<<"[+] = = = = = = MENU = = = = = = [+]"<<endl;
	string options[] = {"Ingresar", "Mostrar", "Modificar","Consultas", "Volver al menu principal", "Salir y guardar"};
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
    Consultar();	
	break;
  case 5:
 	break;
	case 6:
		exit();
	break;
  default:
    menu();
    break;
  }
  	
}

void show(){

	int option;
	system("cls");
do{
	system("cls");
	cout<<"=///// = = = = = = SHOW = = = = = = =\\\\\\\\"<<endl;
	string options[] = {"Estadios", "Paises", "Entrenadores", "Programa", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << "." << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  
  
  switch (option){
  	case 1:
  		system("cls");
  		cout<<"-----------------ESTADIOS--------------------------"<<endl<<endl;
  		cout << setw(10) << setfill(' ') << "Nombre del estadio"<<"\t\t" <<"   | ";
    	cout << setw(5) << setfill(' ') <<"\t"<< "Capacidad"<<"\t"<< " | ";
    	cout << setw(8) << setfill(' ') << "Ubicacion" << endl;
    	cout << setw(100) << setfill('-') << "" << endl;
  		for(int j=1; j<=listaEstadios.sizeList(); j++){
		Estadios_ = listaEstadios.getData(j);
		if(Estadios_.nombreEstadio=="Estadio Internacional Khalifa"){
			cout << setw(10) << setfill(' ') << Estadios_.nombreEstadio<<"\t";
			cout << setw(25) << setfill(' ') << Estadios_.capacidad<<"\t";
    		cout << setw(18) << setfill(' ') << Estadios_.ciudad << endl;
		}else{
			cout << setw(10) << setfill(' ') << Estadios_.nombreEstadio<<"\t";
    		cout << setw(35) << setfill(' ') << Estadios_.capacidad<<"\t";
    		cout << setw(20) << setfill(' ') << Estadios_.ciudad << endl;
		}		
		cout<<endl;
	}
	cout<<"Presione cualquier tecla..."; getch();cout<<endl;
	
	break;
  	
	case 2:
		system("cls");
  		cout<<"PAISES Y CONFEDERACIONES"<<endl<<endl;
		for(int j=1; j<=listaEquipos.sizeList(); j++){
		Equipos_ = listaEquipos.getData(j);
		cout << setw(50) << setfill('-') << "" << endl;
		cout << setw(10) << setfill(' ') << "Nombre "<<"\t "<<"  | ";
    	cout << setw(5) << setfill(' ') <<"\t"<< "Confederacion"<< " | "<<endl;
    	cout << setw(50) << setfill('-') << "" << endl;
    	cout << setw(10) << setfill(' ') << Equipos_.nombre<<"\t";
    	cout << setw(20) << setfill(' ') << Equipos_.confederacion<<endl;

		cout<<""<<endl;	
		cout<<"Jugadores: "<<endl;
		cout<<""<<endl;	
		cout << setw(105) << setfill('-') << "" << endl;
		cout << setw(10) << setfill(' ') << "Nombre "<<"  | ";
    	cout << setw(5) << setfill(' ') << "Pais de origen"<< " | ";
    	cout << setw(5) << setfill(' ') << "Fecha"<< " | ";
    	cout << setw(5) << setfill(' ') << "Estatura"<< " | ";
    	cout << setw(5) << setfill(' ') << "Edad"<< " | ";
    	cout << setw(5) << setfill(' ') << "Club"<< " | ";
    	cout << setw(5) << setfill(' ') << "Posicion"<< " | ";
    	cout << setw(5) << setfill(' ') << "Goles"<< " | ";
		cout << setw(5) << setfill(' ')<< "Fechas de sancion"<< " | "<<endl;
    	cout << setw(105) << setfill('-') << "" << endl;
		for(int k=1; k<=Equipos_.futbolistas.sizeList(); k++){
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
		
	}
	
	cout<<"Presione cualquier tecla..."; getch();cout<<endl;
	break;
	
	case 3:
		system("cls");
		cout<<"-----------------TECNICO--------------------------"<<endl<<endl;
  			cout << setw(10) << setfill(' ') << "Nombre del tecnico"<<"\t" <<"   | ";
    		cout << setw(5) << setfill(' ') << "Nacionalidad"<< " | ";
    		cout << setw(8) << setfill(' ') << "Seleccion" << endl;
    		cout << setw(20) << setfill('-') << "" << endl;
		for(int k = 1; k<=listaTecnicos.sizeList();k++){
  			Tecnicos_ = listaTecnicos.getData(k);
		    	cout << setw(10) << setfill(' ') <<Tecnicos_.nombre;
				cout << setw(25) << setfill(' ') << Tecnicos_.nacionalidad;
	    		cout << setw(15) << setfill(' ') << Tecnicos_.equipo << endl;
			}
			
  	cout<<"Presione cualquier tecla..."; getch();cout<<endl;
	
	break;
	case 4:
		system("cls");
		cout<<"-----------------PARTIDOS PROGRAMADOS------------------------"<<endl<<endl;
  			cout << setw(10) << setfill(' ') << "Estadio"<< "   | ";
    		cout << setw(10) << setfill(' ') << "Equipo 1"<< " | ";
    		cout << setw(5) << setfill(' ') << "Equipo 2"<< " | ";
    		cout << setw(5) << setfill(' ') << "Hora"<< " | ";
    		cout << setw(5) << setfill(' ') << "Fecha"<< " | ";
    		cout << setw(5) << setfill(' ') << "Marcador"<< " | "<<endl;
    		cout << setw(42) << setfill('-') << "" << endl;
    	for(int m=2;m<=listaPartidos.sizeList();m++){

	    		Partidos_ = listaPartidos.getData(m);

	    		cout << setw(10) << setfill(' ') << Partidos_.estadio1<< "   | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo1.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.equipo2.nombre<< " | ";
	    		cout << setw(5) << setfill(' ') << Partidos_.hora<<" | ";;
	    		cout << setw(5) << setfill(' ') << Partidos_.fecha<<" | ";	
	    		cout << setw(5) << setfill(' ') << Partidos_.goles1<<"-"<<Partidos_.goles2<<endl;

		}
		cout<<"Presione cualquier tecla..."; getch();cout<<endl;
		break;
		
	case 5:
  	
	  menu();	
	  break;	
		
  }
  
  
  
  
}while(option!=6);	

	system("cls");
	cout<<"[!] Regresando al menu "<<endl;
	system("timeout 1");
	
	menu();
}

#endif

