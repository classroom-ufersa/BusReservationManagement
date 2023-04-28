#include "../bus/bus.h"
typedef struct tickets Tickets;

Tickets *start();
Tickets *makeReservation(Tickets *l, Bus *b, int number, char *name);
void showReservation(Tickets *t, int number);
Tickets *deleteReservation(Tickets *t, char *name);