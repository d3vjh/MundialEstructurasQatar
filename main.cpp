#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
/*----------------Integrantes-----------------
Sebastian Morales Tarapues 20182020039
Sergio Andres Vega 20191020
Juan Velazques 20191020 */


#include <iomanip>
#include <unistd.h>
#include <string>
#include <sstream>
//Librerias que se importan
#include "Lectura.h"
#include "Crud.h"
#include "Menus.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::string;
using namespace std;


/* programas guias */
void menu(); //Metodo menu local
void cargarArchivos();//Metodo cargarArchivos local


int main(int argc, char** argv) {
	system("color 4F"); // Permite cambiar el color de la fuente y del fondo de la consola de ejecución
	cargarArchivos(); //Llama a la funcion cargarArchivos de la libreria Lectura
	menu();//Llama a la funcion menu de la libreria de Menus
	
	return 0;
}




