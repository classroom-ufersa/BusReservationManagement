typedef struct bus Bus;
typedef struct tickets Tickets;

Tickets *makeReservation(char *name, char *origin, char *destination);
void writePassenger(char *name, char *origin, char *destination);
