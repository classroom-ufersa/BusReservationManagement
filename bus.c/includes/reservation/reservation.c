#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reservation.h" // inclui a definição das estruturas e protótipos das funções
#include "../bus/bus.c"

struct tickets // definindo a estrutura de bilhetes
{
    char passengerName[50];
    char origin[50];
    char destination[50];
    int busNum;

    Tickets *next;
};

Tickets *start() // função para criar uma nova instância da estrutura ticket e inicializar o primeiro ponteiro com NULL
{
    return NULL;
}

Tickets *makeReservation(Tickets *l, Bus *b, int number) // função para criar um novo bilhete e adicioná-lo à lista encadeada de bilhetes
{
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
    Bus *bus = (Bus *)malloc(sizeof(Bus));
    if (ticket == NULL || bus == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }

    for (bus = b; bus != NULL; bus = bus->next)
    {
        if (number == bus->number) // verifica se o numero do onibus é existe e atribui os valores à passagem
        {
            strcpy(ticket->origin, bus->origin);
            strcpy(ticket->destination, bus->destination);
            ticket->busNum = bus->number;

            bus->vacancies--; // diminui a quantidade de vagas

            ticket->next = l;
            return ticket;
        }
    }

    return NULL;
}
