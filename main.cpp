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

#include "Lectura.h"
#include "Crud.h"
#include "Menus.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using std::string;
using namespace std;


/* programas guias */
void menu();

void cargarArchivos();


int main(int argc, char** argv) {

	cargarArchivos();
	menu();

	return 0;
}




