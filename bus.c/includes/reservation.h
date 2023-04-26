typedef struct bus Bus;
typedef struct tickets Tickets;
typedef struct ticket Ticket;

Ticket *start();
Ticket *capturePassenger(Ticket *l);
void makeReservation(Ticket *l, char *name, char *origin, char *destination);
void writePassenger(char *name, char *origin, char *destination);
void deleteReservation(Ticket *t, char *nome);
void showReservation(Ticket *t);
void seekReservation(Ticket *t, char *nome);
