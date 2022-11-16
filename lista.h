/**
 * \mainpage ListsSort
 * \author Jhonatan Moreno - Santiago Avila
 * \date Octubre - 2022
 */


#ifndef LISTA_H
#define LISTA_H
# import "structs.h"

template <class T>
struct Nodo{T info;
	Nodo<T> *sig;
};

using namespace std;

template <class T>
class Lista{Nodo<T>*cab = new Nodo<T>;
			int tam;
	public: Lista (){
			cab=NULL;
			tam=0;}
			bool isEmptyList();
			int sizeList();
			bool insertOnList(T dato, int pos); 
			bool deleteFromList(int pos);
			T printList(int pos);
			void sortList();
			T getDato(int pos);
//			~Lista();

	};
	
	
/** \fn bool Lista<T>::isEmptyList()
 * \brief Indica si la lista est? vacia mediante un booleano
 * \param 
 * \return Devuelve un booleano, si esta vac?a, o no.
 *
 * 
 */
template <class T>
bool Lista<T>::isEmptyList(){
	return (tam==0);
}


/** \fn int Lista<T>::sizeList()
 * \brief Indica el tama?o actual de la lista
 * \param 
 * \return Devuelve un entero.
 *
 * 
 */
template <class T>
int Lista<T>::sizeList(){
	return tam;
}


/** \fn bool Lista<T>::insertOnList(T dato, int pos)
 * \brief Inserta el elemento en la posicion indicada
 * \param T dato -> Elemento a ingresar; int pos -> Posicion a sustituir
 * \return Devuelve un booleano, si fue posible el insertar, o no.
 *
 * 
 */
template <class T>
bool Lista<T>::insertOnList(T dato, int pos){

	if(pos>tam+1){
		return false;
	}
	Nodo<T> *nn = new Nodo<T>;
	Nodo<T> *aux = new Nodo<T>;
	Nodo<T> *aux2 = new Nodo<T>;
	nn->info =dato;

	if(pos==1){													
		nn->sig = cab;										
		cab = nn;											
		tam++;
	}else{
		if(pos==tam+1){	 									
			aux=cab;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=nn;
			nn->sig=NULL;
			tam++;
			}
			else if(pos==2){
				aux=cab; 
				for(int i=1; i<pos; i++){
					nn->sig=aux->sig;
					aux->sig=nn;
				}
				tam++;
				}
			else{
				aux=cab;
				for(int i=1; i<pos-1; i++){
					aux = aux->sig;
					aux2 = aux-> sig;
					nn->sig=aux2;}
				aux->sig=nn;
				tam++;
				}	
		}
	//Imprime el paso a paso del ingreso a la lista		
//	Nodo<T> *aux3 = new Nodo<T>;
//	aux3=cab;
//	for(int i=1; i<=tam; i++){
//		cout<<aux3->info<<"-";
//		aux3=aux3->sig;
//	}
	
	return true;
}



/** \fn bool Lista<T>::deleteFromList(int pos)
 * \brief Elimina el dato que se encuentre en la posicion indicada
 * \param T dato -> int pos -> Posicion a eliminar
 * \return Devuelve un booleano, si fue posible el eliminar, o no.
 *
 * 
 */

template <class T>
bool Lista<T>::deleteFromList(int pos){
	Nodo<T> *aux = new Nodo<T>;
	Nodo<T> *aux2 = new Nodo<T>;
	aux = cab;
	
	if(pos==1){
		cab=aux->sig;
		tam--;
	}else if(pos>tam+1){
		return false;
	}
	else if(pos==2){
		aux = aux->sig;
		cab->sig=aux->sig;
		tam--;
		return true;
	}
	else{
		for(int i=1; i<pos-1; i++){
			aux = aux->sig;
			aux2 = aux-> sig;
		}
		aux2=aux2->sig;
		aux->sig=aux2;
		tam--;
	}
}



/** \fn T Lista<T>::printList()
 * \brief Imprime por consola, la lista separada por un gui?n
 * \param 
 * \return Devuelve los elementos tipo T.
 *
 * 
 */
template <class T>
T Lista<T>::printList(int pos){
	Nodo<T> *aux = new Nodo<T>;
	aux=cab;
	if(pos==1){
		return aux->info;
		
	}else if(pos>1){
				for(int i=1; i<pos; i++){
			aux = aux->sig;
		}	
	
		return aux->info;
	}
	//Si se sale del rango de pos. Pero no esta funcionando
//	else {
//		
//		cout<<"\n[!] Se está saliendo del rango \n"<<endl;
//		return NULL;
//		
//	}	
}

/** \fn void Lista<T>::sortList()
 * \brief Organiza los elementos de la lista
 * \param 
 * \return 
 *
 * 
 */
template <class T>
void Lista<T>::sortList(){
	Nodo<T> *aux = new Nodo<T>;
	Nodo<T> *aux2 = new Nodo<T>;
	
	int i, j;
    T actual;
 	aux=cab;
 	aux2=cab;
 	T arr[tam];
 	
 	for(i=1; i<=tam; i++){      //Guarda los info dentro del arreglo
 		arr[i]=aux->info;
 		aux=aux->sig;
	}
    for (i = 1; i <= tam; i++) { //Ordena el arreglo
        actual = arr[i];
        for (j = i; j > 1 && arr[j - 1] > actual; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = actual;
    }
    cout<<endl;
    // Asignar a los nodos los respectivos info
    for(i=1; i<=tam; i++){
    	aux2->info=arr[i];
    	aux2=aux2->sig;
	}
}


template <class T>
T Lista<T>::getDato(int pos){
	
	Nodo<T> *aux = new Nodo<T>;
	aux = cab;	
	
	if(pos==1){
		return aux->info;
		
	}
//else if(pos > tam || pos < 0){
//		
//		//cout<<"\n[!] Se está saliendo del rango \n"<<endl;
//		return NULL;
//		
//	}
	else{

		for(int i=1; i<pos; i++){
			aux = aux->sig;
		}	
	
		return aux->info;
	}


	
	
	
	
}

#endif


