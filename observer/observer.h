#ifndef OBSERVER_H
	#define OBSERVER_H
	#include "common.h"
	/**
	 * Definición del Patrón Observer
	 */

	typedef struct __observer {
		/**
		 * Método para liberar el espacio en memoria usado por el Observer
		 */
		void (*destroy)(struct __observer *);
		/**
		 * Hace referencia al observador en concreto
		 */
		void* impl;     //una variable que almacena la dirección de un objeto cualquiera, en este caso de tipo Observer
		/**
		 *Es un método usado por los subject para que sea más fácil el uso su lista de observadores
		 * no tiene otro uso realmente.
		 */
		void (*notify)(struct __observer*, void *); //es la dirección de las notificaciones (realmente no se està usando
		/**
		 * The notify implementation (es la función actual que va a ser activada), es decir, es la implementación de la notificación
		 * que hace el Subject, en este caso, el Crupier(quien lanza la bola).
		 */
		void (*notifyImpl)(void*,void*);      //es una dirección que apunta a metodo que tiene dichos parametro
	} Observer;


	/**
	 * Constructor, reserva en la memoria e inicializa las credenciales
	 * @param impl  (es el primer parámetro) este se refiere al observer en sí, en este caso sería al "apostardor" 
	 * @param serial (segundo parámetro) es el método "notifyImpl"
	 * @return la instancia del nuevo Observador
	 */
	Observer * observerNew(void*, void (*)(void*,  void*));  

#endif