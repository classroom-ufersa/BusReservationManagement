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

Tickets *makeReservation(Tickets *l, Bus *b, int number, char *name) // função para criar um novo bilhete e adicioná-lo à lista encadeada de bilhetes
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
            strcpy(ticket->passengerName, name);
            ticket->busNum = bus->number;

            bus->vacancies--; // diminui a quantidade de vagas

            ticket->next = l;
            return ticket;
        }
    }

    return NULL;
}

void showReservation(Tickets *t, int number)
{
    Tickets *ticket = (Tickets *)malloc(sizeof(Tickets));
    for (ticket = t; ticket != NULL; ticket = ticket->next)
    {
        if (number == ticket->busNum)
        {
            printf("Nome: %s\n", ticket->passengerName);
        }
    }
}

Tickets *deleteReservation(Tickets *t, char *name)
{
    Tickets *prev = NULL;
    Tickets *ticket = t;

    while ((strcmp(ticket->passengerName, name)))
    {
        if (ticket == NULL)
        {
            return ticket; // não achou a reserva
        }
        
        prev = ticket;
        ticket = ticket->next;
    }

    if (prev == NULL)
    {
        t = ticket->next;
    }
    else {
        prev->next = ticket->next;
    }

    free(ticket);
    return t;
}