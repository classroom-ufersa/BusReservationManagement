#include "bus.h"

struct bus // defininido a estrutura onibus
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
    Bus *bus = (Bus *)malloc(sizeof(Bus));
    for (bus = b; bus != NULL; bus = bus->next)
    {
        printf("\nNumero do onibus: %d\tNumero de vagas: %d\tOrigem-Destino: %s -> %s", bus->number, bus->vacancies, bus->origin, bus->destination);
    }
}