#include "subject.h"


/*
*Método para liberar el espacio en memoria usado por el Subject
*
*/
static void _destroy(Subject* this)
{
	if (this != NULL) {																																				   //Verifica que el observador no sea nulo																
		free(this);																																							//Libera el espacio en memoria usado por el observador.
		this = NULL;																																					//Vuelve nulo el observador	
	}
}
/*
*Método para añadir al observer a la lista del subject
*
*/
static int _registerObserver(Subject* this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {																												//Recorre la lista de observadores, cuando encuentre el primer espacio nulo																																													
		if (this->observers[i] == NULL) {																												//lo llena con el observador en cuestión y retorna un EXIT_SUCCES
			this->observers[i] = observer;

			return OK;
		}
	}

	printf("[INF] [SUBJECT] we have rush the max number of observers\n");									//Sino encuentra algún nulo en la lista, infiere que está llena y retorna un EXIT_FAIL
	return KO;
}
/*
*Método para eliminar al observer a la lista del subject
*
*/
static int _unregisterObserver(Subject *this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {																											//Recorre la lista de los observadores y mediante recorre la lista, 
		void* pObserver = this->observers[i];																								 // deja al observador seleccionado en el puntero pObserver

		if (observer == pObserver) {																												  //Si observador a eliminar es igual al pObserver, la dirección la hace nula.
			pObserver = NULL;
			return OK;																																			    //Retorna EXIT_SUCCES
		}
	}

	return KO;																																						//Si no hay coincidencias, retorna FAIL_EXIT
}
/*
*Método para notificar a todos los observadores sobre el evento
*
*/
static void _notifyObservers(Subject* this)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {																											//Después mientras recorre la lista de observadores, va ejecutando el método
		if (this->observers[i] != NULL) {																											 //notify en cada uno de ellos.
			this->observers[i]->notify(this->observers[i], this->impl);
		}
	}
}
/*
*Método Constructor de Subject
*
*/
Subject * subjectNew(void* impl)
{
	Subject* this = (Subject *) malloc(sizeof(*this));																				//Reserva el espacio en memoria usado por el subject

	this->destroy = _destroy;																														 //el puntero apunta al método destroy.
	this->impl = impl;																																		 //el puntero apunta al método subject en concreto.
	this->registerObserver = _registerObserver;                     															 //el puntero apunta al método registerObserver.
	this->unregisterObserver = _unregisterObserver;															               //el puntero apunta al método unregisterObserver.
	this->notifyObservers = _notifyObservers;                           														  //el puntero apunta al método notifyObservers.

	return this;
}
