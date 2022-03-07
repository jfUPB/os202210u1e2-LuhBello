#include "apostador.h"
 #include "stddef.h"

static void _destroy(Apostador* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

static void _apostar(Apostador* this, int fichas, Crupier* crup){
    crup->registerObserver(crup, this->observer);
    printf("El jugador %s apuesta %d fichas en la ruleta del Crupier %s\n", this->name, fichas, crup->name);
}

static void _handleAciertoEvent(Apostador* this, Crupier* crup){
    printf("%s\n", "Escuchó");
    int N=9;
    int M= 1;
    int i=0;
    int numero = rand () % (N-M+1) + M; 
    char cuadro[8]= "NUM";
    for(;i<8;i++){
    	if(cuadro[i]=='\0'){
    		cuadro[i]=numero+'0';
    		break;
    	}
    }
    if(strcmp(cuadro,(char *) crup->getEvent) == 0){
        printf("El jugador %s ha ganado con %s",this->name, cuadro);
    }

}

static void _notify(Apostador* this, void* subject){
    _handleAciertoEvent(this, (Crupier*)subject);
}

Apostador* APOSTADOR_create(char* nombreC){
    Apostador* this= (Apostador*) malloc(sizeof(*this));
    this->name= nombreC;
    this->apostar=_apostar;
    this->destroy=_destroy;
    this->observer= observerNew(this,(void(*)(void*,void*))_notify);

    return this;
}
