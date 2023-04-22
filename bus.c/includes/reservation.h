typedef struct bus Bus;
typedef struct tickets Tickets;
typedef struct ticket Ticket;

Ticket *start();
void makeReservation(Ticket *l, char *name, char *origin, char *destination);
void writePassenger(char *name, char *origin, char *destination);
