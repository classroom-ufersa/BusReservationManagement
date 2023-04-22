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
};

Tickets *makeReservation(char *name, char *origin, char *destination)
{
    Tickets *t = (Tickets *)malloc(sizeof(Tickets));
    strcpy(t->passengerName, name);
    strcpy(t->origin, origin);
    strcpy(t->destination, destination);

    writePassenger(name, origin, destination); // call the function to write data to a file

    return t;
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