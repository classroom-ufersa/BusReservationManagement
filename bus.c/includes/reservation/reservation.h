#include "../bus/bus.h"
typedef struct tickets Tickets;

//Inicia a lista de reservas
Tickets *start();

//Função para verificar se há espaço desnecesário
void hasDuplicateSpace(char *name);

//Função para formatar texto
void formatText(char *name);

//Função para criar a reserva
Tickets *makeReservation(Tickets *l, Bus *b, int number, char *name);

//Função para excluir reserva
Tickets *deleteReservation(Tickets *t, Bus *b, char *name);

//Função para mostrar a reserva
void showReservation(Tickets *t, int number);

//Função para buscar uma reserva
void searchReservation(Tickets *t, char *name);

//Função para editar reserva
void editReservation(Tickets *t, Bus *b, int number);

//Função para escrever a reserva no arquivo
void writeFile(Tickets *t);

//Função para ler o arquivo
Tickets *readFile(Tickets *t, Bus *b);

//Função para liberar o espaço de memoria que foi alocado
void freeTickets(Tickets *t);