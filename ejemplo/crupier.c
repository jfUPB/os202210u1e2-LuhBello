#include "crupier.h"

static void _destroyC(Crupier* this)
{
	this->subject->destroy(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}
static void _lanzar(Crupier* this)
{
    printf("%s\n","BIENVENIDOS AL CASINO LUNA");
    printf("%s\n","Mi nombre es ");
    printf("%s\n",this->name);
    printf("%s\n","El juego ha empezado.");
    int N=9;
    int M= 1;
    int numero = rand () % (N-M+1) + M; //nuúmero aleatorio entre M y N

    switch (numero)
    {
    case 1:
        this->event=NUM1;
        this->subject->notifyObservers(this->subject);
        break;
    case 2:
        this->event=NUM2;
        this->subject->notifyObservers(this->subject);
        break;
    case 3:
        this->event=NUM3;
        this->subject->notifyObservers(this->subject);
        break;
    case 4:
        this->event=NUM4;
        this->subject->notifyObservers(this->subject);
        break;
    case 5:
        this->event=NUM5;
        this->subject->notifyObservers(this->subject);
        break;
    case 6:
        this->event=NUM6;
        this->subject->notifyObservers(this->subject);
        break;
    case 7:
        this->event=NUM7;
        this->subject->notifyObservers(this->subject);
        break;
    case 8:
        this->event=NUM8;
        this->subject->notifyObservers(this->subject);
        break;
    case 9:
        this->event=NUM9;
        this->subject->notifyObservers(this->subject);
        break;
    default:
        printf("UUPS");
        break;
    }
}

static AciertoEvent _getEvent(Crupier* this){ return this->event;}

//Subject

static int _registerObserver(Crupier* this, Observer* observer) {
  return this->subject->registerObserver(this->subject, observer);
}

static int _unregisterObserver(Crupier * this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}

Crupier* CRUPIER_create(char* name){
    Crupier* this=(Crupier *) malloc(sizeof(*this));
    this->name=name;
    this->destroy= _destroyC;
    this->getEvent= _getEvent;
    this->lanzar= _lanzar;

	this->subject = subjectNew(this);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

    return this;

}
