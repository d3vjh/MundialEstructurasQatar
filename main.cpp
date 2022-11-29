#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "structs.h"
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


/* programas guias */
void enter();
void show();
void modify();
void promedio();
void exit();


menu(){
	int option;
	system("cls");
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
   // show();
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
	
	 ifstream archEntrada("Estadios.txt", ios::in);
	 
	 if (!archEntrada.good()){
	 	cerr<<"No se pudo abrir el archivo trios"<<endl;
		 }
		 
	List<estadio> Estadio;
	estadio estadioAux;
	string nombre;
	int	cap;
	string ciud;
	cout<<archEntrada.eof();
	getch();
	
	while(!archEntrada.eof()){
			cout<<"Hola22";
    archEntrada >> nombre;
    estadioAux.nombreEstadio = nombre;
    archEntrada >> cap;
    estadioAux.capacidad = cap;
    archEntrada >> ciud;
    estadioAux.ciudad=ciud;
    cout<<ciud;
	Estadio.insertOnList(estadioAux, 1);
   }


	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
	
  	menu();
}

void exit(){
	
	cout<<"[+] Guardado con exito"<<endl; 
	
	//Fin del método
	cout<<"Presione cualquier tecla..."; getch();
	
	exit(0); 
	

	

}

int main(int argc, char** argv) {

	menu();

	return 0;
}




