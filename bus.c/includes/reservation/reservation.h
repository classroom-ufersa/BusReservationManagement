#include "../bus/bus.h"
typedef struct tickets Tickets;

Tickets *start();
Tickets *makeReservation(Tickets *l, Bus *b, int number, char *name);
Tickets *deleteReservation(Tickets *t, Bus *b, char *name);
void showReservation(Tickets *t, int number);
void searchReservation(Tickets *t, char *name);
Tickets *editReservation(Bus *b, Tickets *t, char *name, int num);
void writeFile(Tickets *t);
void editFile(char *name, char *origin, char *destination, int num);
Tickets *readFile();
void freeTickets(Tickets *t);