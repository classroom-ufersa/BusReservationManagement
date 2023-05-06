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

void showBus(Bus *b)
{
    Bus *bus = (Bus *)malloc(sizeof(Bus));
    for (bus = b; bus != NULL; bus = bus->next)
    {
        printf("\nNumero do onibus: %d\tNumero de vagas: %d\tOrigem-Destino: %s -> %s", bus->number, bus->vacancies, bus->origin, bus->destination);
    }
}

void showAvaliableVacancies(Bus *b, int num)
{
    int found = 0;
    Bus *bus = (Bus *)malloc(sizeof(Bus));
    for (bus = b; bus != NULL; bus = bus->next)
    {
        if (bus->number == num)
        {
            printf("\nVagas disponiveis para o onibus %d: %d\n", bus->number, bus->vacancies);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNumero do onibus inexistente!\n");
    }
}

void showPassengerQuantity(Bus *b, int vacancies, int num)
{
    int found = 0;
    Bus *bus = (Bus *)malloc(sizeof(Bus));
    for (bus = b; bus != NULL; bus = bus->next)
    {
        if (num == bus->number)
        {
            printf("\nQuantidade de passageiros presentes no onibus %d: %d\n", bus->number, vacancies - bus->vacancies);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nNumero do onibus inexistente!\n");
    }
}

void freeBus(Bus *b)
{
    Bus *bus = b;
    Bus *aux;
    while (bus != NULL)
    {
        aux = bus->next;
        free(bus);
        bus = aux;
    }
}