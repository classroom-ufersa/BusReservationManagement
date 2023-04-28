#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bus.h"

struct bus // Defininido a estrutura onibus
{
    int number;
    int vacancies;
    char origin[50];
    char destination[50];

    Bus *next;
};

Bus *startBus()
{
    return NULL;
}

Bus *registerBus(Bus *b, int number, int vacancies, char *origin, char *destination)
{
    Bus *newBus = (Bus *)malloc(sizeof(Bus));
    if (newBus == NULL)
    {
        exit(1);
    }
    newBus->number = number;
    newBus->vacancies = vacancies;
    strcpy(newBus->origin, origin);
    strcpy(newBus->destination, destination);
    newBus->next = b;

    return newBus;
}

void showAvaliableBus(Bus *b)
{
    printf("\nNumero do onibus: %d\nNumero de vagas: %d\nOrigem: %s\nDestino: %s", b->number, b->vacancies, b->origin, b->destination);
}