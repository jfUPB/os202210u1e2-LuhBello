#ifndef CRUPIER_H
#define CRUPIER_H
#include <stdio.h>
#include <stdlib.h>
#include "../observer/observer.h"
#include "../observer/subject.h"

typedef enum __acierto_event
{
    NUM1,
        NUM2,
            NUM3,
                NUM4,
                    NUM5,
                        NUM6,
                            NUM7,
                                NUM8,
                                    NUM9
} AciertoEvent;

typedef struct __crupier
{
    char *name;
    void (*destroy)(struct __crupier *);

    AciertoEvent event;
    AciertoEvent (*getEvent)(struct __crupier *);

    void (*lanzar)(struct __crupier *);

    Subject *subject;
    int (*registerObserver)(struct __crupier *, Observer *);
    int (*unregisterObserver)(struct __crupier *, Observer *);
} Crupier;

Crupier *CRUPIER_create(char *);

#endif