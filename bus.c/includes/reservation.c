#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reservation.h"

struct bus
{
    int number;
    int vacancies;
    char origin[50];
    char destination[50];
};

struct tickets
{
    char passengerName[50];
    char origin[50];
    char destination[50];
    char busName[50];

    Tickets *next;
};

struct ticket
{
    Tickets *first;
};

Ticket *start()
{
    Ticket *t = (Ticket *)malloc(sizeof(Ticket));
    if (t == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }
    t->first = NULL;

    return t;
}

void makeReservation(Ticket *l, char *name, char *origin, char *destination)
{
    Tickets *t = (Tickets *)malloc(sizeof(Tickets));
    if (t == NULL)
    {
        printf("Erro na alocação!\n");
        exit(1);
    }
    strcpy(t->passengerName, name);
    strcpy(t->origin, origin);
    strcpy(t->destination, destination);
    t->next = l->first;
    l->first = t;

    writePassenger(name, origin, destination); // call the function to write data to a file
}

void writePassenger(char *name, char *origin, char *destination)
{
    FILE *f = fopen("../service/data.txt", "a");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fprintf(f, "Nome: %s\nOrigem: %s\nDestino: %s\n\n", name, origin, destination);
    fclose(f);
}