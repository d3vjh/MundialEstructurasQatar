/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */

#include <iostream>
#ifndef MENUS_H
#define MENUS_H

#include "Crud.h"
#include "Lectura.h"

using namespace std;
//Metodos locales de crud
void enter();
void show();
void modify();
void Consultar();
void exit();
void cargarArchivos();

//Impresion del menu principal 

void menu(){
	
	int option;
	system("cls");
	cout<< setw(80) << setfill(' ')<<"      ...                           s                                                                                          "<<endl;
	cout<< setw(80) << setfill(' ')<<"   xH88\"`~ .x8X                    :8                               .--~*teu.        .n~~%x.       .--~*teu.      .--~*teu.    "<<endl;
	cout<< setw(80) << setfill(' ')<<" :8888   .f\"8888Hf                .88                   .u    .    dF     988Nx    x88X   888.    dF     988Nx   dF     988Nx  "<<endl;
	cout<< setw(80) << setfill(' ')<<"':8888>  X8L  ^""`        u       :888ooo       u      .d88B :@8c  d888b   `8888>  X888X   8888L  d888b   `8888> d888b   `8888> "<<endl;
	cout<< setw(79) << setfill(' ')<<" X8888  X888h         us888u.  -*8888888    us888u.  =\"8888f8888r ?8888>  98888F X8888X   88888  ?8888>  98888F ?8888>  98888F "<<endl;
	cout<< setw(80) << setfill(' ')<<"88888  !88888.     .@88 \"8888\"   8888    .@88 \"8888\"   4888>'88\"   \"**\"  x88888~ 88888X   88888X  \"**\"  x88888~  \"**\"  x88888~ "<<endl;
	cout<< setw(80) << setfill(' ')<<"88888   %88888     9888  9888    8888    9888  9888    4888> '          d8888*`  88888X   88888X       d8888*`        d8888*`  "<<endl;	
	cout<< setw(80) << setfill(' ')<<"88888 '> `8888>    9888  9888    8888    9888  9888    4888>          z8**\"`   : 88888X   88888f     z8**\"`   :     z8**\"`   : "<<endl;	
	cout<< setw(80) << setfill(' ')<<"`8888L %  ?888   ! 9888  9888   .8888Lu= 9888  9888   .d888L .+     :?.....  ..F 48888X   88888    :?.....  ..F   :?.....  ..F "<<endl;
	cout<< setw(80) << setfill(' ')<<" `8888  `-*\"\"   /  9888  9888   ^%888*   9888  9888   ^\"8888*\"     <\"\"888888888~  ?888X   8888\"   <\"\"888888888~  <\"\"888888888~ "<<endl;
	cout<< setw(80) << setfill(' ')<<"   \"888.      :\"   \"888*\"\"888\"    'Y\"    \"888*\"\"888\"     \"Y\"       8:  \"888888*    \"88X   88*`    8:  \"888888*   8:  \"888888*  "<<endl;
	cout<< setw(80) << setfill(' ')<<"     `\"\"***~\"`      ^Y\"   ^Y'             ^Y\"   ^Y'                \"\"    \"**\"`       ^\"===\"`      \"\"    \"**\"`    \"\"    \"**\"` "<<endl;
	cout<< setw(120) << setfill('-')<<"";
	cout<<endl<<endl;
	cout<<"-_-_-_-_-_-_-_-_-_-_-_-_-_- MENU -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	string options[] = {"Ingresar", "Mostrar", "Modificar","Consultas", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << ". " << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  	cin >> option;
  	//Casos para cada opcion del menu
  switch (option){
  case 1:
  	//Implementacion de Ingresar de la libreria crud
    enter();
    break;
  case 2:
	//Mostrar
   show();

    break;
  case 3:
  	//Implementacion de Modificar de la libreria crud
    modify();
    break;
  case 4:
  	//Implementacion de Consutar de la libreria crud
    Consultar();	
	break;
  case 5:
  	//Implementacion de Salir de la libreria crud
  		exit();
 	break;
  default:
    menu();
    break;
  }
  	
}
//Este metodo imprime y ejecuta el menu de mostrar
void show(){

	int option;
	system("cls");
do{
	system("cls");
	
	cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_ SHOW  -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
	string options[] = {"Estadios", "Paises", "Entrenadores", "Programa","Tabla de grupos", "Volver al menu principal"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << "." << options[i] << "\n";
  	cout << "Ingresa una opcion: ";
  cin >> option;
  
  
  switch (option){
  	//Este caso muestra la lista de estadios y sus datos
  	case 1:
  		system("cls");
  		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_ESTADIOS -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
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
		//Este caso muestra la lista de Equipos y sus datos
		system("cls");
  		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_PAISES Y CONFEDERACIONES -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
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
		//Este caso muestra la lista de tecnicos y sus datos
		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_TECNICO -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
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
			//Este caso muestra la lista de partidos programados y sus datos
		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_PARTIDOS PROGRAMADOS -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
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
			//Este caso muestra la lista de grupos y sus datos
		system("cls");
		cout<<" -_-_-_-_-_-_-_-_-_-_-_-_-_-_TABLA DE GRUPOS -_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl<<endl;
		cout << setw(7) << setfill(' ') << "Grupo"<< "   | ";
		cout << setw(5) << setfill(' ') << "Equipo "<< " | "<<endl;
	
	
    	for(int m=1;m<=listaFase1.sizeList();m++){

	    		Fase1_ = listaFase1.getData(m);

	    		cout << setw(7) << setfill(' ') << Fase1_.grupo<< "   | ";
	    		cout << setw(5) << setfill(' ') << Fase1_.equips.nombre<< " | "<<endl;
	    		

		}
			
		cout<<endl;
		
		cout<<"Presione cualquier tecla..."; getch();cout<<endl;
		break;
		
	case 6:
  	//Menu
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

