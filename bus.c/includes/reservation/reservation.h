#include "../bus/bus.h"
typedef struct tickets Tickets;

Tickets *start();
Tickets *makeReservation(Tickets *l, Bus *b, int number);