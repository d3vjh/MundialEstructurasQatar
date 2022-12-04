#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string.h>


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
void exit();

int main(int argc, char** argv) {
	
	menu();

	return 0;
}




void menu(){
	int option;
//	system("cls");
	cout<<"[+] = = = = = = MENU = = = = = = [+]"<<endl;
	string options[] = {"Ingresar", "Mostrar", "Modificar", "Volver al menu principal", "Salir y guardar"};
  	int size = sizeof(options) / sizeof(*options);
	for (int i = 0; i < size; i++)	
    	cout << i + 1 << "." << options[i] << "\n";
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
	
//	 ifstream archEntrada("Estadios.txt", ios::in);
//	 
//	 if (!archEntrada.good()){
//	 	cerr<<"No se pudo abrir el archivo de estadios"<<endl;
//		 }
//		 
//	List<estadio> Estadio;
//	estadio estadioAux;
//	string nombre;
//	int	cap;
//	string ciud;
//	getch();
//	
//	
//	
//	while(!archEntrada.eof()){
//			cout<<"Hola22";
//    archEntrada >> nombre;
//    estadioAux.nombreEstadio = nombre;
//    archEntrada >> cap;
//    estadioAux.capacidad = cap;
//    archEntrada >> ciud;
//    estadioAux.ciudad=ciud;
//    cout<<ciud;
//	Estadio.insertOnList(estadioAux, 1);
//   }


	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
	
  	menu();
}


void show(){
	ifstream archivo;
	string texto;
	
	estadio EstadioAux;
	List<estadio> listaEstadios;
	archivo.open("Estadios.txt", ios::in);
	
	if(archivo.fail()){
		cout<<"Hemos fallado con exito";
	}	
	int i=0;
	
	while(!archivo.eof()){
		if(i%3==0 && i>0){
			listaEstadios.insertOnList(EstadioAux, listaEstadios.sizeList()+1);
		}
			
		getline(archivo,texto,'\t');
		texto.replace(0, 0,"",1);
		EstadioAux.nombreEstadio = texto;	
//		cout<<texto<<"(Nombre)-> "<<i;
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

		
	
		
	}
	
	archivo.close();
	
	for(int j=1; j<=listaEstadios.sizeList(); j++){
		EstadioAux = listaEstadios.getData(j);
		cout<<"[+]"<<endl;
		cout<<"Nombre del estadio "<<j<<": "<<EstadioAux.nombreEstadio<<endl;	
		cout<<"Capacidad del estadio "<<j<<": "<<EstadioAux.capacidad<<endl;	
		cout<<"Ciudad del estadio del estadio "<<j<<": "<<EstadioAux.ciudad<<endl;	
		cout<<"--- --- --- ---"<<endl<<endl;
	}
		

	menu();
}
	
void exit(){
	
	cout<<"[+] Guardado con exito"<<endl; 
	
	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
	
	exit(0); 
	

	

}




