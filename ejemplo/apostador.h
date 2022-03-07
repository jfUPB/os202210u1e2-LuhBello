#ifndef APOSTADOR_H
	#define APOSTADOR_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../observer/observer.h"
	#include "crupier.h"


	typedef struct __apostador
	{
		char* name;
		void (*lanzar)(struct __apostador*);
		void (*destroy)(struct __apostador*);
		void (*apostar)(struct __apostador*, int,Crupier*);

		Observer* observer;
	}Apostador;

	Apostador* APOSTADOR_create(char *);
#endif