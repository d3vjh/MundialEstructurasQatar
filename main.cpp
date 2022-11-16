#include <iostream>
#include <cstdlib>
#include <ctime>
#include "structs.h"
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

Lista<tarjeta> createListCard(int n){
	
		
		Lista<tarjeta> lt;
		string tarjetasMotivos[3] = {"Codazo", "pelear", "Insultar"};
		string tarjetasColor[3] = {"Amarrilla", "Roja", "Azul"};
		srand((unsigned) time(NULL));
	
		for(int i=1; i<=n; i++){
		tarjeta tarjetasAux;
		
		tarjetasAux.color = tarjetasColor[rand() % 3];
		tarjetasAux.motivo = tarjetasMotivos[rand() % 3];
		tarjetasAux.dia = (int)(1 + rand() % 30);
		tarjetasAux.mes = (11);
		tarjetasAux.anio = 2022;
		cout<<"[!]"<<tarjetasAux.mes;
		lt.insertOnList(tarjetasAux, lt.sizeList()+1);	
		
		
	}
	return lt;
}



int main(int argc, char** argv) {
	

	

//	int random = (rand() % 3);
	
//	equipo equipoAux;
	jugador jugadorAux;
	tarjeta tarjetasAux;
	Lista<jugador> lj;
	Lista<tarjeta> lt;


//Inserta Tarjetas



	
//	
	jugadorAux.nombre = "James Rodriguez";
	jugadorAux.edad = 25;
	jugadorAux.posicion = "Delantero";
	jugadorAux.talla = "M";
	jugadorAux.t = createListCard(5); //Se le asigna la lista de tarjetas
	lj.insertOnList(jugadorAux, lj.sizeList()+1) ;
	
	int tamJugadores = lj.sizeList();
	for(int i=1; i<=tamJugadores; i++){
		jugadorAux=lj.getDato(i);
		cout<<"----------------------Nombre: "<<jugadorAux.nombre<<" --------------------"<<endl;
		cout<<"Edad: "<<jugadorAux.edad<<endl;
		cout<<"Posición: "<<jugadorAux.posicion<<endl;
		cout<<"Talla: "<<jugadorAux.talla<<endl;
		for(int j=1; j<=jugadorAux.t.sizeList(); j++){
			tarjetasAux=jugadorAux.t.getDato(j);
			cout<<"===========[+]Tarjeta "<<j<<"[+]============ "<<endl;
			cout<<"Motivo: "<<tarjetasAux.motivo<<endl;
			cout<<"Contrincante: "<<tarjetasAux.contrincante<<endl;
			cout<<"Dia: "<<tarjetasAux.dia<<endl;
			cout<<"Mes: "<<tarjetasAux.mes<<endl;
			cout<<"Anio: "<<tarjetasAux.anio<<endl;
			cout<<"Color: "<<tarjetasAux.color<<endl;
			
		}
	}
//	
//	jugadorAux = lj.printList(1);
//	cout<<jugadorAux.nombre<<endl;
//	
//	
//	
//	tarjetasAux = jugadorAux.t.printList(1);
//	cout<<tarjetasAux.dia<<endl;
////	
//	tarjetasAux = jugadorAux.t.getDato(2);
//	cout<<tarjetasAux.color<<endl;
////	
////	cout<<tarjetasAux.motivo<<endl;
////	
////	
	
	
//	
//	equipoAux.nombre = "Colombia";
//	equipoAux.entrenador = "Carlos Queiroz";
//	equipoAux.confederacion = "CONMEBOL";
//	equipoAux.j.insertOnList(jugadorAux, 1);
//	
//	
//	
	
	
	return 0;
}




