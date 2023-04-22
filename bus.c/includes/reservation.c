#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reservation.h"

struct bus {
    int number;
    int vacancies;
    char origin[50];
    char destination[50];
};

struct tickets {
    char passengerName[50];
    char origin[50];
    char destination[50];
    char busName[50];
};

Tickets *makeReservation(char name[50], char origin[50], char destination[50])
{
    Tickets *t = (Tickets *)malloc(sizeof(Tickets));
    strcpy(t->passengerName, name);
    strcpy(t->origin, origin);
    strcpy(t->destination, destination);

    return t;
}