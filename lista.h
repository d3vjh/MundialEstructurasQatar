/**
 * \mainpage pilasEjercicio2
 * \author Jhonatan Moreno - Santiago Avila
 * \date Octubre - 2022
 */


#ifndef LIST_H
#define LIST_H

template <class T>
struct NodoL{T info;
	NodoL<T> *sig;
};

using namespace std;

template <class T>
class List{NodoL<T>*cab = new NodoL<T>;
			int tam;
	public: List (){
			cab=NULL;
			tam=0;}
			bool isEmptyList();
			int sizeList();
			bool insertOnList(T dato, int pos); 
			bool deleteFromList(int pos);
			T printList();
			void sortList();
			void sortDescendingList();
			T getData(int pos);
			void replaceInList(T nuevo, T antiguo);


	};

//Se comenta, porque al momento de inicializar una variable de tipo List, se queda pensando y finaliza el programa

/** \fn List<T>::List<T>::~List()
 * \brief Es el destructor, sirve para liberar memoria
 * \param 
 * \return 
 *
 * 
 */
//template <class T>	
//List<T>::~List(){
//	NodoL<T> *aux;
//	aux = cab; 
//	while(aux->sig){
//	delete aux;
//	}
//}
//	
	
/** \fn bool List<T>::isEmptyList()
 * \brief Indica si la lista esta vacia mediante un booleano
 * \param 
 * \return Devuelve un booleano, si esta vacia, o no.
 *
 * 
 */
template <class T>
bool List<T>::isEmptyList(){
	return (tam==0);
}


/** \fn int List<T>::sizeList()
 * \brief Indica el tama?o actual de la lista
 * \param 
 * \return Devuelve un entero.
 *
 * 
 */
template <class T>
int List<T>::sizeList(){
	return tam;
}


/** \fn bool List<T>::insertOnList(T dato, int pos)
 * \brief Inserta el elemento en la posicion indicada
 * \param T dato -> Elemento a ingresar; int pos -> Posicion a sustituir
 * \return Devuelve un booleano, si fue posible el insertar, o no.
 *
 * 
 */
template <class T>
bool List<T>::insertOnList(T dato, int pos){

	if(pos>tam+1){
		return false;
	}
	NodoL<T> *nn = new NodoL<T>;
	NodoL<T> *aux = new NodoL<T>;
	NodoL<T> *aux2 = new NodoL<T>;
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

/*
Imprime el paso a paso del ingreso a la lista		
	NodoL<T> *aux3 = new NodoL<T>;
	aux3=cab;
	for(int i=1; i<=tam; i++){
		cout<<aux3->info<<"-";
		aux3=aux3->sig;
	}
*/
	return true;
}



/** \fn bool List<T>::deleteFromList(int pos)
 * \brief Elimina el dato que se encuentre en la posicion indicada
 * \param T dato -> int pos -> Posicion a eliminar
 * \return Devuelve un booleano, si fue posible el eliminar, o no.
 *
 * 
 */
template <class T>
bool List<T>::deleteFromList(int pos){
	NodoL<T> *aux = new NodoL<T>;
	NodoL<T> *aux2 = new NodoL<T>;
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



/** \fn T List<T>::printList()
 * \brief Imprime por consola, la lista separada por un gui?n
 * \param 
 * \return Devuelve los elementos tipo T.
 *
 * 
 */
template <class T>
T List<T>::printList(){
	NodoL<T> *aux = new NodoL<T>;
	aux=cab;
	cout<<">> ";
	for(int i=1; i<=tam; i++){
		cout<<aux->info<<"-";
		aux=aux->sig;
	}
	cout<<"  "<<endl;		
}

/** \fn void List<T>::sortList()
 * \brief Organiza los elementos de la lista
 * \param 
 * \return 
 *
 * 
 */
template <class T>
void List<T>::sortList(){
	NodoL<T> *aux = new NodoL<T>;
	NodoL<T> *aux2 = new NodoL<T>;
	
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
T List<T>::getData(int pos){
	
	NodoL<T> *aux = new NodoL<T>;
	aux = cab;	
	
	if(pos==1){
		return aux->info;
		
	}
//	else if(pos > tam || pos < 0){
//		
//		cout<<"[!] Pide un dato inválido"<<endl;
//		return NULL;		
//	}
	else{
		for(int i=1; i<pos; i++){
			aux = aux->sig;
		}	
		return aux->info;
	}
}


template <class T>
void List<T>::sortDescendingList(){
	NodoL<T> *aux = new NodoL<T>;
	NodoL<T> *aux2 = new NodoL<T>;
	
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
        for (j = i; j > 1 && arr[j - 1] < actual; j--) {
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
	

/** \fn void List<T>::replaceInList(T nuevo, T antiguo)
 * \brief Reemplaza un valor, por otro, de la lista
 * \param T nuevo, T antiguo
 * \return 
 *
 * 
 */
template <class T>
void List<T>::replaceInList(T nuevo, T antiguo){
	NodoL<T> *aux = new NodoL<T>;
	NodoL<T> *aux2 = new NodoL<T>;
	int i, j;
	aux=cab;
	aux2=cab;
 	T arr[tam];
 	
 	for(i=1; i<=tam; i++){      //Guarda los info dentro del arreglo
 		arr[i]=aux->info;
 		aux=aux->sig;
	}
	for(i=1; i<=tam; i++){	
	//Verificar si está en la lista, y si está reemplazar
		if(arr[i]==antiguo){
			arr[i]=nuevo;			
		}	
	}
	
	for(j=1; j<=tam; j++){
    	aux2->info=arr[j];
    	aux2=aux2->sig;
	}
}


#endif


