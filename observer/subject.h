#ifndef SUBJECT_H
	#define SUBJECT_H
	#include "observer.h"

	/**
	 * Es una interfaz para los Subjects
	 */

	typedef struct __subject
	{
		int type;
		/**
		 * Desctructor para el subject
		 */
		void (*destroy)(struct __subject *);
		/**
		 *Referencia al subject en concreto
		 */
		void * impl;
		/**
		 *Es la lista de los observadores que se han suscrito al subject en concreto.
		 */
		Observer * observers[MAX_OBSERVERS];  //MAX_OBSERVERS  es el número 20
			/**
		 * Es el método que usará para suscrbir observadores a su lista y así asociarlos
		 */
		int (*registerObserver)(struct __subject*, Observer*);
		/**
		 * Es para desuscribir los observadores
		 */
		int (*unregisterObserver)(struct __subject *, Observer*);
		/**
		 * Cuando haya un evento, se llama este método para notificarselos a los observadores
		 */
		void (*notifyObservers)(struct __subject*);
	} Subject;

	/**
	 * Constructor del Subject, este tiene como parámetro una variable que apunta a un dirección de cualquier cosa,
	 * en este caso, es el Crupier.
	 */
	Subject * subjectNew(void*);

#endif
