#include "observer.h"


/*
*Método para liberar el espacio en memoria usado por el Observer
*
*/
static void _destroy(Observer* this)
{
	if (this != NULL) {        																																//Verifica que el observador no sea nulo
		free(this);        																																		//Libera el espacio en memoria usado por el observador.
		this = NULL;           																																 //Vuelve nulo el observador																	
	}
}
/*
 *Es un método usado por los subject para que sea más fácil el uso su lista de observadores
 * no tiene otro uso realmente.
*/
static void _notify(Observer *this, void * subject)
{
	this->notifyImpl(this->impl, subject);                         																		//implementa la notificación dada por el suject en cuenstión
}
	/*
	 * Constructor, reserva en la memoria e inicializa las credenciales
	 */
Observer* observerNew(void* impl, void (*notifyImpl)(void*,void*))
{
	Observer* this = (Observer *) malloc(sizeof(*this));																//Primero se debe reservar el espacio en memoria que contendrá al observador.

	this->destroy = _destroy;																												  //el puntero apunta al método destroy.
	this->notify = _notify;																												  		  //el puntero apunta al método notify.
	this->impl = impl;																												                  //el puntero apunta al método observador en concreto.
	this->notifyImpl = (void (*)(void*, void*)) notifyImpl;															     //se hizo primero un casteo para que no halla fallos, ya que
																																									// no hay un método llamado notifyImpl incializado

	return this;
}
